#ifndef COMANDA_H
#define COMANDA_H
#include <iostream>
#include <string>
#include <vector>
#include "../include/Produs.h"

class Comanda{
private:
    int pret;
    int avans;
    std::vector <Produs> produse;
    std::vector <ProdusSpecial> produse_speciale;
    std::string data_plasarii, data_ridicarii;
    Client client;

    float Aduna();
public:
    //CONSTRUCTOR
    Comanda(int p=0, int a=0, std::vector <Produs> pr={}, std::vector <ProdusSpecial> ps={}, std::string dp="", std::string dr="", Client c=Client());
    Comanda(Client c);
    //CC
    Comanda(const Comanda& other);
    //GETTERS

    //SETTERS
    void setPret();
    //OPERATORI
    //friend std::istream& operator>>(std::istream& is, Comanda& c);
    //METODE
    void AdaugaProdus(const Produs& p);
    void AdaugaProdusSpecial(const ProdusSpecial& p);
    //DESTRUCTOR
    ~Comanda(){}
};


#endif /*COMANDA_H*/