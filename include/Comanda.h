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
    std::string data_plasarii, data_ridicarii;
    Client client;
public:
    //CONSTRUCTOR
    Comanda(int p=0, int a=0, std::vector <Produs> pr={}, std::string dp="", std::string dr="", Client c=Client());
    //CC
    Comanda(const Comanda& other);
};


#endif /*COMANDA_H*/