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
    int CaiPutere;

public:
    Masina(string marca, string model, int anFabricatie, string culoare, bool reparata, int probleme[])
    {
        this->marca = marca;
        this->model = model;
        this->anFabricatie = anFabricatie;
        this->culoare = culoare;
        this->reparata = reparata;
        for(int i = 0; i <= 5; i++)
            this->probleme[i] = probleme[i];
        this->CalculManopera();
    }

    Masina()
    {
        this->marca = "Inexistenta";
        this->model = "";
        this->culoare = "";
        this->reparata = "Inexistenta";
        for(int i = 0; i <= 5; i++)
            this->probleme[i] = -1;
    }

    Masina(Masina& aux)
    {
        this->marca = aux.marca;
        this->model = aux.model;
        this->culoare = aux.culoare;
        this->reparata = aux.reparata;
        for (int i = 0; i <= 5; i++)
            this->probleme[i] = aux.probleme[i];
        this->manopera = aux.manopera;
        this->anFabricatie = aux.anFabricatie;
        this->CaiPutere = aux.CaiPutere;
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
        cout<<"Introduceti caii putere ai masinii"<<endl;
        in>>m.CaiPutere;
        cout<<"Alegeti serviciile dorite: "<<endl<<"1. Reparatie frane"<<endl<<"2. Schimb ulei"<<endl<<"3. Reparatie climatizare"<<endl<<"4. Tinichigerie"<<endl<<"5. ITP"<<endl<<"6. Soft arabesc"<<endl<<"0. Toate serviciile au fost adaugate"<<endl;
        int codProblema;
        in>> codProblema;
        for (int i = 0; i<=5;i++)
            m.probleme[i] = 0;
        while (codProblema != 0)
        {
            m.probleme[codProblema - 1] = 1;
            cout<<endl<<"Problema Adaugata"<<endl;
            in>>codProblema;
        }
        m.reparata = false;
        m.CalculManopera();
        return in;
    }

    friend ostream& operator<<(ostream& out, Masina& m)
    {
        if (m.reparata == false)
        {
            cout<<endl<<"Pentru masina "<<m.marca<<" "<<m.model<<" de culoare "<<m.culoare<<", din anul "<<m.anFabricatie<<" cu "<<m.CaiPutere<<" CP, se ofera urmatoarele servicii:"<<endl;
            if (m.probleme[0] == 1)
                cout<<"Reparatie frane"<<endl;
            if (m.probleme[1] == 1)
                cout<<"Schimb ulei"<<endl;
            if (m.probleme[2] == 1)
                cout<<"Reparatie climatizarea"<<endl;
            if (m.probleme[3] == 1)
                cout<<"Tinichigerie"<<endl;
            if (m.probleme[4] == 1)
                cout<<"ITP"<<endl;
            if (m.probleme[5] == 1)
                cout<<"Soft arabesc"<<endl;
            cout<<"Costul total fiind: "<<m.manopera<<" lei";
        }
        else
        {
            cout<<endl<<"Masina "<<m.marca<<" "<<m.model<<" de culoare "<<m.culoare<<", din anul "<<m.anFabricatie<<" cu "<<m.CaiPutere<<" CP, a fost reparata cu succes, iar costul total fiind de: "<<m.manopera<<" lei";
        }
        return out;
    }

    Masina& operator=(const Masina& aux)
    {
        marca = aux.marca;
        model = aux.model;
        culoare = aux.culoare;
        reparata = aux.reparata;
        for (int i = 0; i <= 5; i++)
            probleme[i] = aux.probleme[i];
        manopera = aux.manopera;
        anFabricatie = aux.anFabricatie;
        CaiPutere = aux.CaiPutere;
        return *this;
    }

    #pragma region "Getteri si Setteri"
    const string &getMarca() const {
        return marca;
    }

    void setMarca(const string &marca) {
        Masina::marca = marca;
    }

    const string &getModel() const {
        return model;
    }

    void setModel(const string &model) {
        Masina::model = model;
    }

    const string &getCuloare() const {
        return culoare;
    }

    void setCuloare(const string &culoare) {
        Masina::culoare = culoare;
    }

    bool isReparata() const {
        return reparata;
    }

    void setReparata(bool reparata) {
        Masina::reparata = reparata;
    }

    const int *getProbleme() const {
        return probleme;
    }

    int getManopera() const {
        return manopera;
    }

    void setManopera(int manopera) {
        Masina::manopera = manopera;
    }

    int getAnFabricatie() const {
        return anFabricatie;
    }

    void setAnFabricatie(int anFabricatie) {
        Masina::anFabricatie = anFabricatie;
    }

    int getCaiPutere() const {
        return CaiPutere;
    }

    void setCaiPutere(int caiPutere) {
        CaiPutere = caiPutere;
    }

#pragma endregion

    void CalculManopera()
    {
        int sumaTotala = 0;
        if (this->probleme[0] == 1)
            sumaTotala += 1000;
        if (this->probleme[1] == 1)
            sumaTotala += 100;
        if (this->probleme[2] == 1)
            sumaTotala += 500;
        if (this->probleme[3] == 1)
            sumaTotala += 2000;
        if (this->probleme[4] == 1)
            sumaTotala += 250;
        if (this->probleme[5] == 1)
            sumaTotala += 1500;
        this->manopera = sumaTotala;
    }

    void SoftArabesc()
    {
        cout<<endl<<"Cati caluti ii bagam verik?"<<endl;
        int bonus;
        cin>>bonus;
        this->CaiPutere += bonus;
    }

    ~Masina()
    {

    }
};
