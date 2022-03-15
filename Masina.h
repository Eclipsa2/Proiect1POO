//
// Created by Andrei on 3/14/2022.
//
#include <iostream>
using namespace std;

class Masina{
private:
    string marca;
    string model;
    string culoare;
    bool reparata;
    int probleme[5];
    int manopera;
    int anFabricatie;
public:
    Masina(string marca, string model, int anFabricatie, string culoare, bool reparata, int probleme[])
    {
        this->marca = marca;
        this->model = model;
        this->anFabricatie = anFabricatie;
        this->culoare = culoare;
        this->reparata = reparata;
        for(int i = 0; i < 5; i++)
            this->probleme[i] = probleme[i];
    }
    Masina()
    {
        this->marca = "Inexistenta";
        this->model = "";
        this->culoare = "";
        this->reparata = "Inexistenta";
        for(int i = 0; i < 5; i++)
            this->probleme[i] = -1;
    }
    friend istream& operator>>(istream& in, Masina& m)
    {
        //string marca, model, culoare;
        //int manopera, anFabricatie;
        //int probleme[5];
        cout<<"Introduceti marca masinii"<<endl;
        in>>m.marca;
        cout<<"Introduceti modelul masinii"<<endl;
        in>>m.model;
        cout<<"Introduceti culoarea masinii"<<endl;
        in>>m.culoare;
        cout<<"Introduceti anul fabriecatiei masinii"<<endl;
        in>>m.anFabricatie;
        //cout<<""
        return in;

    }
};
