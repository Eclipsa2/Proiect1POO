#include <iostream>
#include <stdlib.h>
#include "Masina.h"
using namespace std;

int menu()
{
    system("cls");
    cout<<"Bine ati venit la Vericu Service! "<<endl;
    cout<<"1. Adaugati o masina noua in service"<<endl;
    cout<<"2. Vizualizati masinile aflate momentan in service"<<endl;
    cout<<"3. Vizualizati masinile reparate de service-ul nostru"<<endl;
    cout<<"4. Modificare servicii ale unei masini"<<endl;
    cout<<"0. Exit"<<endl;
    int optiune;
    cin>>optiune;
    while (optiune > 4)
    {
        cout<<endl<<"Optiune introdusa inexistenta!"<<endl;
        cin>>optiune;
    }
    return optiune;
}

int main() {
    //Masina m1;
    //cin>>m1;
    //Masina m2 = m1;
    //cout<<m2;
    Masina *masiniService;
    int nrMasiniService = 0, nrMasiniReparate = 0;
    Masina *masiniReparate;
    int optiune = menu();
    while (optiune != 0)
    {
        switch (optiune)
        {
            case 1:
            {
                system("CLS");
                //Masina aux;
                //cin>>aux;
                //nrMasiniService++;
                //masiniService = new Masina[nrMasiniService+1];
                //masiniService[nrMasiniService] = aux;
                //cout<<masiniService[nrMasiniService];
                nrMasiniService++;
                masiniService = new Masina[nrMasiniService];
                cin>>masiniService[nrMasiniService -1];
                cout<<masiniService[nrMasiniService -1];
                break;
            }
        }
    }
    return 0;
}
