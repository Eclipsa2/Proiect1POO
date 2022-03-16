//
// Created by Andrei on 3/16/2022.
//
#include <iostream>
#include "Masina.h"
using namespace std;

class Angajat{
private:
    string nume;
    Masina* MasiniReparate;
    int salariu;
    bool isAngajat;

public:
    Angajat(string nume, int salariu)
    {
        this->nume = nume;
        this->salariu = salariu;
        this->isAngajat = true;
    }
    Angajat()
    {
        this->nume = "inexistent";
        this->salariu = -1;
        this->isAngajat = false;
        this->MasiniReparate = NULL;
    }
    Angajat(Angajat& aux)
    {
        this->nume = aux.nume;
        this->MasiniReparate = aux.MasiniReparate;
        this->salariu = aux.salariu;
        this->isAngajat = aux.isAngajat;
    }
    friend istream& operator>>(istream& in, Angajat& a)
    {
        cout<<"Introduceti numele noului angajat: ";
        in>>a.nume;
        cout<<endl<<"Introduceti salariul noului angajat: ";
        in>>a.salariu;
        a.isAngajat = true;
        return in;
    }
    friend istream& operator<<(istream& in, Angajat& a)
    {
        //De modificat aici
    }
    #pragma region Getteri si Setteri
    const string &getNume() const {
        return nume;
    }

    void setNume(const string &nume) {
        Angajat::nume = nume;
    }

    Masina *getMasiniReparate() const {
        return MasiniReparate;
    }

    void setMasiniReparate(Masina *masiniReparate) {
        MasiniReparate = masiniReparate;
    }

    int getSalariu() const {
        return salariu;
    }

    void setSalariu(int salariu) {
        Angajat::salariu = salariu;
    }

    bool isAngajat1() const {
        return isAngajat;
    }

    void setIsAngajat(bool isAngajat) {
        Angajat::isAngajat = isAngajat;
    }

#pragma endregion
};

