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
};


#endif /*COMANDA_H*/