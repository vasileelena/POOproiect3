# POOproiect3
## Cerinte de baza:
### Cerințe comune tuturor temelor:
- utilizarea sabloanelor

- utilizarea STL

- utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const

- utilizarea conceptelor de RTTI raportat la template-uri

- tratarea excepțiilor

- citirea informațiilor complete a n obiecte, memorarea și afișarea acestora
### Cerințe generale aplicate fiecărei teme din acest fișier:
- să se identifice și să se implementeze ierarhia de clase;

- clasele să conțină constructori, destructori, =, funcție prietena de citire a datelor;

-clasa de baza sa conțină funcție virtuala de afisare, rescrisa în clasele derivate, iar operatorul de citire să fie implementat ca funcție prieten (în clasele derivate să se facă referire la implementarea acestuia în clasa de baza).

## Tema 5:
În luna mai se organizeazătârgul mașinilor sport, astfel ca pasionatii se pot delecta cu modele din clasa COUPE,HOT-HATCH(modele hatckback de clasa mica și compacta cu motoare performante ce au la bază modele obișnuite), CABRIO(modele de capotabile cu
acoperiș metalic sau din material textil) și SUPERSPORT(masini de viteza gen AudiR8, BugattiVeyron, LexusLF-A, etc.). O parte din masinile supersport poate să fie vânduta chiar în cadrul expozitiei, dacă se tranzacția se face cu plata pe loc. 

Structura de date: **vector sau list<pair<masina,preț>>**(se rețin mașinile vândute și prețul de vanzare).

- Să se adauge toate campurile relevante pentru modelarea acestei probleme.

- Să se construiască clasa template **Expoziție** care sa conțină numarul total de mașini expuse (incrementat automat) și un vector de obiecte de tipul unei mașini, alocat dinamic.

- Să se construiască o specializare pentru tipul **SUPERSPORT** care sa conțină numarul total de masini supersport expuse(decrementat automat la vanzarea unei mașini), numar de mașini vândute (incrementat automat) și doi vectori de pointeri la obiecte de tip mașina supersport, două structuri alocate dinamic, prin care să se gestioneze automobilele din stoc și cele vandute. 

- Sa se supraincarce operatorul **-=** care sa actualizeze datele din clasa la vanzarea unei mașini.
