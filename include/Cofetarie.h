#ifndef COFETARIE_H
#define COFETARIE_H
#include <iostream>
#include <string>
#include <vector>
#include "../include/Comanda.h"
#include "../include/Produs.h"

class Cofetarie{
private:
    std::vector <Produs> produse;
    std::vector <ProdusSpecial> produse_speciale;
    std::vector <Comanda> comenzi;
    float cont_bancar; //unde tin minte ce suma a incasat cofetaria pe baza comenzilor si a achizitiilor in magazin
public:
    //CONSTRUCTOR
    Cofetarie(std::vector <Produs> p={}, std::vector <ProdusSpecial> ps={}, std::vector <Comanda> c={}, float cb=0);
    //CC
    Cofetarie(const Cofetarie& other);
    //GETTERS
    void getDenumiri();
    void getDenumiriDePost();
    void getDenumiriProduseFestive(std::vector <std::string> sarbatori);
    void getDenumiriFaraAlergeni(std::vector <std::string> ingrediente);
    float getPret(std::string denumire);
    int getNumar(std::string denumire);
    //float getBani();
    //SETTEERS

    //METODE
    void AdaugaProdus(const Produs& p);
    void AdaugaProdusSpecial(const ProdusSpecial& p);
    void AdaugaComanda(const Comanda& c);
    void AdaugaBani(float bani);
    void ModificaProdus(std::string denumire, const int nr);
    void Cuptor(std::string denumire, const int nr);
    float CalculeazaRestBaniComenzi(std::string nr_tel);
    Produs GasesteProdus(std::string denumire);
    ProdusSpecial GasesteProdusSpecial(std::string denumire);
    //DESTRUCTOR
    ~Cofetarie(){}
};

#endif /*COFETARIE_H*/