#ifndef COFETARIE_H
#define COFETARIE_H
#include <iostream>
#include <string>
#include <vector>

//voi implementa in cadrul acestui proiect si conceptul de "mostenire"
//ma bazez pe faptul ca in cadrul cofetariei exista produse care sunt aduse doar in anumite conditii,
//la ocazii speciale (spre exemplu prajituri pentru anumite sarbatori - sfintii, prajituri de Valentine's Day, prajituri de Craciun...)


class Produs{
private:
    std::string denumire;
    std::vector <std::string> igrediente_alergenice; 
    int numar;
    bool de_post;
    float pret;
public:
    //constructor
    Produs(std::string den="", std::vector <std::string> ingr_alerg={}, int nr=0, bool post=0, float pret=0): denumire{den}, igrediente_alergenice{ingr_alerg}, numar{nr}, de_post{post}, pret{pret} {std::cout<<"MERGE\n";}
    //cc
    Produs(const Produs& other): denumire{other.denumire}, igrediente_alergenice{other.igrediente_alergenice}, numar{other.numar}, de_post{other.de_post}, pret{other.pret} {}
    //getters
    int getNumar() const
    {
        return this->numar;
    } 
    //setters


    //destructor
    ~Produs() {std::cout<<"Destructor Produs\n";}

};

class ProdusSpecial: public Produs{
private:
    std::string festivitate;
    std::string perioada_valabilitate;
public:

};

class Client{
private:
    std::string nume;
    std::string prenume;
    std::string numar_telefon;
public:
};

class Comanda{
private:
    int pret;
    int avans;
    std::vector <Produs> produse;
    std::string data_plasarii, data_ridicarii;
    Client client;
public:
};

class Cofetarie{
private:
    std::vector <Produs> produse;
    std::vector <ProdusSpecial> produse_speciale;
    std::vector <Comanda> comenzi;
    int cont_bancar; //unde tin minte ce suma a incasat cofetaria pe baza comenzilor si a achizitiilor in magazin
public:
};

#endif /*COFETARIE_H*/