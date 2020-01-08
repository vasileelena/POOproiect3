#include <iostream>
#include <vector>

using namespace std;

class masinaSport{
protected:
    int an;
    string descriere;
public:
    masinaSport(){
        an = 0;
    }

    masinaSport(int an): an(an){}

    masinaSport(const masinaSport & ob) {
        an = ob.an;
    }

    masinaSport & operator =(const masinaSport & ob){
        if(this != &ob){
            an = ob.an;
        }
        return *this;
    }

    ~masinaSport() {
        an = 0;
    }

    friend istream & operator >> (istream &, masinaSport &);
    virtual void afisare() const = 0;
};

class Coupe : public masinaSport{
public:
    Coupe(): masinaSport(){
        descriere = "Modele in doua usi";
    }
    Coupe(int an, string descr = "Modele in doua usi;"): masinaSport(an){ descriere = descr; }
    Coupe(const Coupe & ob): masinaSport(ob) {
        descriere = ob.descriere;
    }
    Coupe & operator = (const Coupe & ob){
        if(this != &ob){
            masinaSport::operator=(ob);
            descriere = ob.descriere;
        }
        return *this;
    }
    ~Coupe(){
        descriere = "";
    }
    friend istream & operator >> (istream &, Coupe &);
    void afisare() const{
        cout << "Masina sport Coupe: " << descriere << "\nan: " << an << endl;
    }
};

class HotHatch : public masinaSport{
public:
    HotHatch(): masinaSport(){
        descriere = "Modele hatckback de clasa mica si compacta cu motoare performante;";
    }
    HotHatch(int an, string descr = "Modele hatckback de clasa mica si compacta cu motoare performante;"): masinaSport(an){ descriere = descr; }
    HotHatch(const HotHatch & ob): masinaSport(ob) {
        descriere = ob.descriere;
    }
    HotHatch & operator = (const HotHatch & ob){
        if(this != &ob){
            masinaSport::operator=(ob);
            descriere = ob.descriere;
        }
        return *this;
    }
    ~HotHatch(){
        descriere = "";
    }
    friend istream & operator >> (istream &, HotHatch &);
    void afisare() const{
        cout << "Masina sport HotHatch: " << descriere << "\nan: " << an << endl;
    }
};

class Cabrio : public masinaSport{
public:
    Cabrio(): masinaSport(){
        descriere = "Modele decapotabile cu acoperis metalic sau din material textil;";
    }
    Cabrio(int an, string descr = "Modele decapotabile cu acoperis metalic sau din material textil;"): masinaSport(an){ descriere = descr; }
    Cabrio(const Cabrio & ob): masinaSport(ob) {
        descriere = ob.descriere;
    }
    Cabrio & operator = (const Cabrio & ob){
        if(this != &ob){
            masinaSport::operator=(ob);
            descriere = ob.descriere;
        }
        return *this;
    }
    ~Cabrio(){
        descriere = "";
    }
    friend istream & operator >> (istream &, Cabrio &);
    void afisare() const{
        cout << "Masina sport Cabrio: " << descriere << "\nan: " << an << endl;
    }
};

class SuperSport : public masinaSport{
    int pret;
public:
    SuperSport(): masinaSport(){
        descriere = "Masini de viteza;";
        pret = -1;
    }
    SuperSport(int an, int pret = -1, string descr = "Masini de viteza;"): masinaSport(an), pret(pret){ descriere = descr; }
    SuperSport(const SuperSport & ob): masinaSport(ob) {
        pret = ob.pret;
        descriere = ob.descriere;
    }
    SuperSport & operator = (const SuperSport & ob){
        if(this != &ob){
            masinaSport::operator=(ob);
            pret = ob.pret;
            descriere = ob.descriere;
        }
        return *this;
    }
    ~SuperSport(){
        descriere = "";
        pret = 0;
    }
    friend istream & operator >> (istream &, SuperSport &);
    void afisare() const{
        cout << "Masina sport SuperSport: " << descriere << "\nan: " << an << "\npret: $" << pret << endl;
    }
    int get_pret(){ return pret; }
};

istream & operator >> (istream &in, masinaSport &ob){
    if(ob.an == 0){
        cout << "Introduceti anul masinii: ";
        in >> ob.an;
    }
    return in;
}

istream & operator >> (istream &in, Coupe &ob){
    in >> (masinaSport&)ob;
    return in;
}

istream & operator >> (istream &in, HotHatch &ob){
    in >> (masinaSport&)ob;
    return in;
}

istream & operator >> (istream &in, Cabrio &ob){
    in >> (masinaSport&)ob;
    return in;
}

istream & operator >> (istream &in, SuperSport &ob){
    in >> (masinaSport&)ob;
    cout << "Introduceti pretul de vanzare: ";
    in >> ob.pret;
    try{
        if(ob.pret < 2500)
            throw(ob.pret);
        } catch(int){
            cout << "Pretul minim din expozitie este $2500. Pretul masinii va fi setat cu pretul minim!\n";
            ob.pret = 2500;
        }
    try{
        if(ob.pret > 100000)
            throw(ob.pret);
        } catch(int){
            cout << "Pretul maxim din expozitie este $100.000. Pretul masinii va fi setat cu pretul maxim!\n";
            ob.pret = 100000;
        }
    return in;
}

template <class T>
class Expozitie{
    int nr_total_masini;
    vector <T*> stoc;
public:
    Expozitie(){
        nr_total_masini = 0;
        stoc.clear();
    }

    void adaugare_stoc(int alegere){
        T* masina;
        T* aux;
        switch(alegere){
        case 1:
            masina = dynamic_cast <Coupe*>(aux); ///pe unele compilatoare nu merge cu dynamic_cast
            masina = new Coupe;
            nr_total_masini++;
            cin >> (Coupe&)(*masina);
            stoc.push_back(masina);
            break;
        case 2:
            masina = dynamic_cast<HotHatch*>(aux);///pe unele compilatoare nu merge cu dynamic_cast
            masina = new HotHatch;
            nr_total_masini++;
            cin >> (HotHatch&)(*masina);
            stoc.push_back(masina);
            break;
        case 3:
            masina = dynamic_cast<Cabrio*>(aux);///pe unele compilatoare nu merge cu dynamic_cast
            masina = new Cabrio;
            nr_total_masini++;
            cin >> (Cabrio&)(*masina);
            stoc.push_back(masina);
            break;
        case 0: break;
        default: break;
        }
    }
    void afisare_expo(){
        if(nr_total_masini == 0){
            cout << "\nExpozitia nu are inca masini!\n";
            return;
        }
        cout << endl;
        for(int i = 0; i < nr_total_masini; i++){
            cout << i+1 << ") ";
            stoc[i]->afisare();
        }
    }
    ~Expozitie(){
        nr_total_masini = 0;
        stoc.clear();
    }
};

template <>
class Expozitie<SuperSport>{
    int nr_total_masini;
    int nr_masini_vandute;
    vector <SuperSport*> stoc;
    vector <pair<SuperSport*, int> > vandute;
public:
    Expozitie(){
        nr_total_masini = 0;
        nr_masini_vandute = 0;
        stoc.clear();
        vandute.clear();
    }

    void adaugare_stoc(int alegere){
        SuperSport* masina;
        masina = new SuperSport;
        nr_total_masini++;
        cin >> (SuperSport&)(*masina);
        stoc.push_back(masina);
    }

    void vanzare(int index){
        if(nr_total_masini == 0 || index > nr_total_masini){
            cout << "Nu exista pe stoc " << index << " masini!\n";
            return;
        }
        int i = index - 1;
        vandute.push_back(make_pair(stoc[i], stoc[i]->get_pret()) );
        stoc.erase(stoc.begin() + i);
        nr_masini_vandute++;
        nr_total_masini--;
    }

    void afisare_expo(){
        if(nr_total_masini != 0){
            cout << "\nMasinile SuperSport:\n";
            for(int i = 0; i < nr_total_masini; i++){
                cout << i+1 << ") ";
                stoc[i]->afisare();
            }
        }
    }
    void afisare_vandute(){
        if(nr_masini_vandute == 0){
            cout << "\nNu au fost vandute masini!\n";
            return;
        }
        cout << "\nMasinile SuperSport vandute:\n";
        for(int i = 0; i < nr_masini_vandute; i++){

            cout << "\nPretul de vanzare: $" << vandute[i].second << endl;
            cout << i+1 << ") ";
            vandute[i].first->afisare();
        }
    }

    Expozitie operator -=(int index){
        vanzare(index);
        return *this;
    }

    friend istream & operator >>(istream &, Expozitie<SuperSport>&);

    ~Expozitie(){
        nr_total_masini = 0;
        nr_masini_vandute = 0;
        stoc.clear();
        vandute.clear();
    }
};

int main()
{
    Expozitie <masinaSport> exp;
    Expozitie <SuperSport> expSs;
    int x;
    cout << "Alegeti optiunea dorita:\n";
    cout << "1. Adaugare masina Coupe in expozitie;\n";
    cout << "2. Adaugare masina HotHatch in expozitie;\n";
    cout << "3. Adaugare masina Cabrio in expozitie;\n";
    cout << "4. Adaugare masina SuperSport in expozitie;\n";
    cout << "5. Afisarea portofoliului expozitiei;\n";
    cout << "6. Cumpararea unei masini SuperSport;\n";
    cout << "7. Afisarea masinilor SuperSport vandute;\n";
    cout << "0. Inchiderea programului.\n";
    while(x){
        cout << "Introduceti optiunea: ";
        cin >> x;
        switch(x){
            case 1: exp.adaugare_stoc(1);
                    break;
            case 2: exp.adaugare_stoc(2);
                    break;
            case 3: exp.adaugare_stoc(3);
                    break;
            case 4: expSs.adaugare_stoc(4);
                    break;
            case 5: exp.afisare_expo();
                    expSs.afisare_expo();
                    break;
            case 6: cout << "Introduceti numarul masinii pe care doriti sa o achizitionati: ";
                    int i;
                    cin >> i;
                    expSs -= i;
                    break;
            case 7: expSs.afisare_vandute();
                    break;
            case 0: break;
            default: break;
        }
    }
    return 0;
}
