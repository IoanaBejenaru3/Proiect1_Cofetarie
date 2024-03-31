#ifndef COMANDA_H
#define COMANDA_H
#include <iostream>
#include <string>
#include <vector>
#include "../include/Produs.h"

class Comanda{
private:
    float pret;
    float avans;
    std::vector <Produs> produse;
    std::vector <ProdusSpecial> produse_speciale;
    bool status; ///0 - preluata de client, 1 - comanda activa inca nu a fost preluata
    Client client;

    float Aduna();
    float Afla();
public:
    //CONSTRUCTOR
    Comanda(float p=0, float a=0, std::vector <Produs> pr={}, std::vector <ProdusSpecial> ps={}, bool status=1, Client c=Client());
    Comanda(Client c);
    //CC
    Comanda(const Comanda& other);
    //GETTERS
    std::string getNrTel();
    bool getStatus();
    //SETTERS
    void setPret();
    void setAvans(const float avans);
    void setStatus();
    //OPERATORI
    //friend std::istream& operator>>(std::istream& is, Comanda& c);
    //METODE
    void AdaugaProdus(const Produs& p);
    void AdaugaProdusSpecial(const ProdusSpecial& p);
    float Diferenta();
    //DESTRUCTOR
    ~Comanda(){}
};


#endif /*COMANDA_H*/