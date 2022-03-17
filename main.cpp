#include <iostream>
#include <stdlib.h>
#include "Masina.h"
#include "Angajat.h"
#include <fstream>
#include <stdio.h>
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
        contor++;
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

Angajat* citireFisierAngajati(int& nrAngajati)
{
    string aux;
    Masina* MasinaAux;
    bool auxBool;
    int auxInt, auxVector[5], nrMasini;
    ifstream f("C:\\Users\\Andrei\\CLionProjects\\Proiect1POO\\Angajati");
    f>>nrAngajati;
    Angajat* Angajati = new Angajat[nrAngajati];
    for (int i = 0; i < nrAngajati; i++)
    {
        f>>aux;
        Angajati[i].setNume(aux);
        f>>auxInt;
        Angajati[i].setSalariu(auxInt);
        f>>auxBool;
        Angajati[i].setIsAngajat(auxBool);
        f>>auxInt;
        Angajati[i].setNrMasiniReparate(auxInt);
        nrMasini = auxInt;
        MasinaAux = new Masina[nrMasini];
        for (int j = 0; j < nrMasini; j++)
        {
            f>>aux;
            MasinaAux[j].setMarca(aux);
            f>>aux;
            MasinaAux[j].setModel(aux);
            f>>aux;
            MasinaAux[j].setNrInmatriculare(aux);
            f>>aux;
            MasinaAux[j].setCuloare(aux);
            f>>auxBool;
            MasinaAux[j].setReparata(auxBool);
            for (int k = 0; k <= 5; k++)
                f>>auxVector[k];
            MasinaAux[j].setProbleme(auxVector);
            f>>auxInt;
            MasinaAux[j].setManopera(auxInt);
            f>>auxInt;
            MasinaAux[j].setAnFabricatie(auxInt);
            f>>auxInt;
            MasinaAux[j].setCaiPutere(auxInt);
        }
        Angajati[i].setMasiniReparate(MasinaAux);
    }
    f.close();
    return Angajati;
}

void scriereFisierMasiniReparate(Masina* MasiniReparate, int nrMasiniReparate)
{
   ofstream g("C:\\Users\\Andrei\\CLionProjects\\Proiect1POO\\MasiniReparateVeriku") ;
   g<<nrMasiniReparate<<endl;
   for (int i = 0; i <= nrMasiniReparate; i++)
   {
       g<<MasiniReparate[i].getMarca()<<" ";
       g<<MasiniReparate[i].getModel()<<" ";
       g<<MasiniReparate[i].getNrInmatriculare()<<" ";
       g<<MasiniReparate[i].getCuloare()<<" ";
       g<<MasiniReparate[i].isReparata()<<" ";
       const int* probleme = (MasiniReparate[i].getProbleme());
       for (int i = 0; i<=5; i++)
           g<<probleme[i]<<" ";
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
    g<<nrMasiniReparate<<endl;
    for (int i = 0; i < nrMasiniReparate; i++)
    {
        g<<MasiniReparate[i].getMarca()<<" ";
        g<<MasiniReparate[i].getModel()<<" ";
        g<<MasiniReparate[i].getNrInmatriculare()<<" ";
        g<<MasiniReparate[i].getCuloare()<<" ";
        g<<MasiniReparate[i].isReparata()<<" ";
        const int* probleme = (MasiniReparate[i].getProbleme());
        for (int i = 0; i<=5; i++)
            g<<probleme[i]<<" ";
        g<<MasiniReparate[i].getManopera()<<" ";
        g<<MasiniReparate[i].getAnFabricatie()<<" ";
        g<<MasiniReparate[i].getCaiPutere()<<" ";
        g<<endl;
    }
    g.close();
}

void scriereFisierAngajati(Angajat* Angajati, int nrAngajati)
{
    ofstream g("C:\\Users\\Andrei\\CLionProjects\\Proiect1POO\\Angajati");
    g<<nrAngajati<<endl;
    for (int i = 0; i < nrAngajati; i++)
    {
        g<<Angajati[i].getNume()<<" ";
        g<<Angajati[i].getSalariu()<<" ";
        g<<Angajati[i].isAngajat1()<<" ";
        g<<Angajati[i].getNrMasiniReparate()<<" ";
        Masina* aux = Angajati[i].getMasiniReparate();
        for (int j = 0; j < Angajati[i].getNrMasiniReparate(); j++)
        {
            g<<aux[i].getMarca()<<" ";
            g<<aux[i].getModel()<<" ";
            g<<aux[i].getNrInmatriculare()<<" ";
            g<<aux[i].getCuloare()<<" ";
            g<<aux[i].isReparata()<<" ";
            g<<aux[i].getProbleme()<<" ";
            g<<aux[i].getManopera()<<" ";
            g<<aux[i].getAnFabricatie()<<" ";
            g<<aux[i].getCaiPutere()<<" ";
        }
    }
    g.close();
}

int menu()
{
    //system("cls");
    cout<<"Bine ati venit la Veriku Service! "<<endl;
    cout<<"1. Adaugati o masina noua in service"<<endl;
    cout<<"2. Vizualizati masinile aflate momentan in service"<<endl;
    cout<<"3. Vizualizati masinile reparate de service-ul nostru"<<endl;
    cout<<"4. Schimbare status masini"<<endl;
    cout<<"5. Soft arabesc"<<endl;
    cout<<"6. Adaugare angajat"<<endl;
    cout<<"7. Concediere angajat"<<endl;
    cout<<"8. Afisare masini reparate de un angajat"<<endl;
    cout<<"0. Exit"<<endl;
    int optiune;
    cin>>optiune;
    while (optiune > 8)
    {
        cout<<endl<<"Optiune introdusa inexistenta!"<<endl;
        cin>>optiune;
    }
    return optiune;
}

int main() {
    int nrMasiniService = 0, nrMasiniReparate = 0, nrAngajati = 0;
    Masina aux[100];
    Masina *masiniService = citireFisierMasiniService(nrMasiniService);
    Masina *masiniReparate = citireFisierMasiniReparate(nrMasiniReparate);
    Angajat *angajati = citireFisierAngajati(nrAngajati);
    Angajat angajatAux[100];
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
                for (int i = 0; i < nrMasiniService - 1; i++)
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
                for (int i = 0; i < nrMasiniReparate; i++)
                    if(masiniReparate[i].isReparata() == 1)
                        cout<<masiniReparate[i];
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
                        Masina* aux = new Masina[nrMasiniReparate];
                        for (int i = 0; i<nrMasiniReparate; i++)
                            aux[i] = masiniReparate[i];
                        masiniReparate = new Masina[nrMasiniReparate + 1];
                        for (int i = 0; i<nrMasiniReparate; i++)
                            masiniReparate[i] = aux[i];
                        nrMasiniReparate++;
                        masiniReparate[nrMasiniReparate-1] = masiniService[i];
                        for(int j = i; j < nrMasiniService-1; j++)
                            masiniService[j] = masiniService[j+1];
                        nrMasiniService --;
                        Masina* vectorMasiniAux = new Masina[nrMasiniService];
                        for(int j = 0; j <nrMasiniService; j++)
                            vectorMasiniAux[j] = masiniService[j];
                        masiniService = new Masina[nrMasiniService];
                        for(int j = 0; j <nrMasiniService; j++)
                            masiniService[j] = vectorMasiniAux[j];
                    }
                if (ok == 0)
                    cout<<"Masina cu nr de inmatriculare "<<nrInmatriculare<<" nu a fost gasita"<<endl;
                cout<<endl<<"1. Schimbati statusul unei alte masini"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 2)
                    optiune = menu();
                else
                    optiune = 4;
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
                else
                    optiune = 5;
                break;
            }
            case 6:
            {
                cout<<endl<<"Ati ales optiunea de a adauga un angajat nou"<<endl;
                Angajat angajatNou;
                cin>>angajatNou;
                for (int i = 0; i < nrAngajati; i++)
                    angajatAux[i] = angajati[i];
                nrAngajati++;
                angajati = new Angajat[nrAngajati];
                for (int i = 0; i < nrAngajati - 1; i++)
                    angajati[i] = angajatAux[i];
                angajati[nrAngajati] = angajatNou;
                cout<<endl<<"Angajatul a fost adaugat cu succes!";
                cout<<endl<<"1. Adaugati un angajat nou"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 2)
                    optiune = menu();
                else
                    optiune = 6;
                break;
            }
            case 7:
            {
                cout<<endl<<"Ce angajat doriti sa concediati?"<<endl;
                string input;
                cin>>input;
                for (int i = 0; i < nrAngajati; i++)
                {
                    if (angajati[i].getNume() == input)
                    {
                        angajati[i].setIsAngajat(false);
                        cout<<endl<<"Angajatul a fost concediat! ";
                    }
                    else
                        cout<<endl<<"Angajatul nu a fost gasit!"<<endl;
                }
                cout<<endl<<"1. Adaugati un angajat nou"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 2)
                    optiune = menu();
                else
                    optiune = 7;
                break;

            }
            case 8:
            {
                cout<<endl<<"Introduceti numele angajatului: "<<endl;
                string input;
                cin>>input;
                for (int i = 0; i < nrAngajati; i++)
                {
                    if (angajati[i].getNume() == input)
                        angajati[i].getMasiniReparate();
                    else
                        cout<<endl<<"Angajatul nu a fost gasit!"<<endl;
                }
                cout<<endl<<"1. Afisati masinile reparate de un alt angajat"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 2)
                    optiune = menu();
                else
                    optiune = 8;
                break;
                break;
            }
        }
    }
    scriereFisierMasiniService(masiniService, nrMasiniService);
    scriereFisierMasiniReparate(masiniReparate, nrMasiniReparate);
    scriereFisierAngajati(angajati, nrAngajati);
    cout<<endl<<"O zi buna!";
    //int nrMasini;
    //Masina* serviceMasini;
    //serviceMasini = citireFisierMasiniReparate(nrMasini);
    //cout<<serviceMasini[0];
    return 0;
}
