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
    int cont_bancar; //unde tin minte ce suma a incasat cofetaria pe baza comenzilor si a achizitiilor in magazin
public:
};

#endif /*COFETARIE_H*/