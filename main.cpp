#include <iostream>
#include <stdlib.h>
#include "Masina.h"
#include "Angajat.h"
#include <fstream>

using namespace std;

Masina* citireFisierMasiniReparate(int& nrMasiniService)
{
    string aux;
    bool reparata;
    int auxInt, auxVector[5];
    ifstream f("C:\\Users\\Andrei\\CLionProjects\\Proiect1POO\\MasiniReparateVeriku");
    f>>nrMasiniService;
    Masina* MasiniService = new Masina[nrMasiniService];
    int contor = 0;
    while (contor < nrMasiniService)
    {
        f>>aux;
        MasiniService[contor].setMarca(aux);
        f>>aux;
        MasiniService[contor].setModel(aux);
        f>>aux;
        MasiniService[contor].setNrInmatriculare(aux);
        f>>aux;
        MasiniService[contor].setCuloare(aux);
        f>>reparata;
        MasiniService[contor].setReparata(reparata);
        for (int i = 0; i<=5; i++)
        {
            f>>auxVector[i];
        }
        MasiniService[contor].setProbleme(auxVector);
        f>>auxInt;
        MasiniService[contor].setManopera(auxInt);
        f>>auxInt;
        MasiniService[contor].setAnFabricatie(auxInt);
        f>>auxInt;
        MasiniService[contor].setCaiPutere(auxInt);
        contor ++;
    }
    return MasiniService;
    f.close();
}

Masina* citireFisierMasiniService(int& nrMasiniService)
{
    string aux;
    bool reparata;
    int auxInt, auxVector[5];
    ifstream f("C:\\Users\\Andrei\\CLionProjects\\Proiect1POO\\MasiniServiceVeriku");
    f>>nrMasiniService;
    Masina* MasiniService = new Masina[nrMasiniService];
    int contor = 0;
    while (contor < nrMasiniService)
    {
        f>>aux;
        MasiniService[contor].setMarca(aux);
        f>>aux;
        MasiniService[contor].setModel(aux);
        f>>aux;
        MasiniService[contor].setNrInmatriculare(aux);
        f>>aux;
        MasiniService[contor].setCuloare(aux);
        f>>reparata;
        MasiniService[contor].setReparata(reparata);
        for (int i = 0; i<=5; i++)
        {
            f>>auxVector[i];
        }
        MasiniService[contor].setProbleme(auxVector);
        f>>auxInt;
        MasiniService[contor].setManopera(auxInt);
        f>>auxInt;
        MasiniService[contor].setAnFabricatie(auxInt);
        f>>auxInt;
        MasiniService[contor].setCaiPutere(auxInt);
        contor ++;
    }
    f.close();
    return MasiniService;
}

void scriereFisierMasiniReparate(Masina* MasiniReparate, int nrMasiniReparate)
{
   ofstream g("C:\\Users\\Andrei\\CLionProjects\\Proiect1POO\\MasiniReparateVeriku") ;
   g<<nrMasiniReparate;
   for (int i = 0; i < nrMasiniReparate; i++)
   {
       g<<MasiniReparate[i].getMarca()<<" ";
       g<<MasiniReparate[i].getModel()<<" ";
       g<<MasiniReparate[i].getNrInmatriculare()<<" ";
       g<<MasiniReparate[i].getCuloare()<<" ";
       g<<MasiniReparate[i].isReparata()<<" ";
       g<<MasiniReparate[i].getProbleme()<<" ";
       g<<MasiniReparate[i].getManopera()<<" ";
       g<<MasiniReparate[i].getAnFabricatie()<<" ";
       g<<MasiniReparate[i].getCaiPutere()<<" ";
       g<<endl;
   }
   g.close();
}

void scriereFisierMasiniService(Masina* MasiniReparate, int nrMasiniReparate)
{
    ofstream g("C:\\Users\\Andrei\\CLionProjects\\Proiect1POO\\MasiniServiceVeriku") ;
    g<<nrMasiniReparate;
    for (int i = 0; i < nrMasiniReparate; i++)
    {
        g<<MasiniReparate[i].getMarca()<<" ";
        g<<MasiniReparate[i].getModel()<<" ";
        g<<MasiniReparate[i].getNrInmatriculare()<<" ";
        g<<MasiniReparate[i].getCuloare()<<" ";
        g<<MasiniReparate[i].isReparata()<<" ";
        g<<MasiniReparate[i].getProbleme()<<" ";
        g<<MasiniReparate[i].getManopera()<<" ";
        g<<MasiniReparate[i].getAnFabricatie()<<" ";
        g<<MasiniReparate[i].getCaiPutere()<<" ";
        g<<endl;
    }
    g.close();
}

int menu()
{
    system("cls");
    cout<<"Bine ati venit la Vericu Service! "<<endl;
    cout<<"1. Adaugati o masina noua in service"<<endl;
    cout<<"2. Vizualizati masinile aflate momentan in service"<<endl;
    cout<<"3. Vizualizati masinile reparate de service-ul nostru"<<endl;
    cout<<"4. Schimbare status masini"<<endl;
    cout<<"5. Soft arabesc"<<endl;
    cout<<"0. Exit"<<endl;
    int optiune;
    cin>>optiune;
    while (optiune > 5)
    {
        cout<<endl<<"Optiune introdusa inexistenta!"<<endl;
        cin>>optiune;
    }
    return optiune;
}

int main() {
    int nrMasiniService = 0, nrMasiniReparate = 0;
    Masina aux[100];
    Masina *masiniService;
    Masina *masiniReparate;
    int optiune = menu();
    while (optiune != 0)
    {
        switch (optiune)
        {
            case 1:
            {
                cout<<endl<<"Ati ales optiunea de adaugare a unei masini noi"<<endl;
                for (int i = 0; i < nrMasiniService; i++)
                    aux[i] = masiniService[i];
                nrMasiniService++;
                masiniService = new Masina[nrMasiniService];
                for (int i = 0; i < nrMasiniService; i++)
                    masiniService[i] = aux[i];
                cin>>masiniService[nrMasiniService -1];
                cout<<endl<<"Masina noua a fost adaugata cu succes!";
                cout<<endl<<"1. Adaugati inca o masina noua"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 2)
                    optiune = menu();
                break;
            }
            case 2:
            {
               cout<<"Urmatoarele masini se afla momentan in Service-ul lui Veriku: "<<endl;
               for (int i = 0; i < nrMasiniService; i++)
                   if(masiniService[i].isReparata() == false)
                       cout<<masiniService[i];
                cout<<endl<<"1. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 1)
                    optiune = menu();
                break;
            }
            case 3:
            {
                cout<<"Urmatoarele masini au fost reparate de Veriku: "<<endl;
                for (int i = 0; i < nrMasiniService; i++)
                    if(masiniService[i].isReparata() == false)
                        cout<<masiniService[i];
                cout<<endl<<"1. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 1)
                    optiune = menu();
                break;
            }
            case 4:
            {
                cout<<endl<<"Ati ales optiunea de a repara masina"<<endl;
                string nrInmatriculare;
                int ok = 0;
                cout<<endl<<"Introduceti numarul de inmatriculare al masinii reparate: ";
                cin>>nrInmatriculare;
                for (int i = 0; i <nrMasiniService; i++)
                    if (masiniService[i].getNrInmatriculare() == nrInmatriculare)
                    {
                        masiniService[i].setReparata(true);
                        ok = 1;
                    }
                if (ok == 0)
                    cout<<"Masina cu nr de inmatriculare "<<nrInmatriculare<<" nu a fost gasita"<<endl;
                cout<<endl<<"1. Schimbati statusul unei alte masini"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 2)
                    optiune = menu();
                break;
            }
            case 5:
            {
                cout<<endl<<"Ati ales specialitatea casei"<<endl;
                string nrInmatriculare;
                int ok = 0;
                cout<<endl<<"Introduceti numarul de inmatriculare al masinii reparate: ";
                cin>>nrInmatriculare;
                for (int i = 0; i <nrMasiniService; i++)
                    if (masiniService[i].getNrInmatriculare() == nrInmatriculare)
                    {
                        masiniService[i].SoftArabesc();
                        ok = 1;
                    }
                if (ok == 0)
                    cout<<"Masina cu nr de inmatriculare "<<nrInmatriculare<<" nu a fost gasita"<<endl;
                cout<<endl<<"1. Resoftare masina noua"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 2)
                    optiune = menu();
                break;
                break;
            }
        }
    }
    cout<<endl<<"O zi buna!";
    //int nrMasini;
    //Masina* serviceMasini;
    //serviceMasini = citireFisierMasiniReparate(nrMasini);
    //cout<<serviceMasini[0];
    return 0;
}
