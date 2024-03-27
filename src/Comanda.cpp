#include "../include/Produs.h"
#include "../include/Comanda.h"
#include "../include/Client.h"
#include "../include/Cofetarie.h"

//CONSTRUCTOR
Comanda::Comanda(float p, float a, std::vector <Produs> pr, std::vector <ProdusSpecial> ps, std::string dp, std::string dr, Client c): pret{p}, avans{a}, produse{pr}, produse_speciale{ps}, data_plasarii{dp}, data_ridicarii{dr}, client{c} {}
Comanda::Comanda(Client c) : pret{0}, avans{0}, produse{}, produse_speciale{}, data_plasarii{""}, data_ridicarii{""}, client{c} {}
//CC
Comanda::Comanda(const Comanda& other): pret{other.pret}, avans{other.avans}, produse{other.produse}, data_plasarii{other.data_plasarii}, data_ridicarii{other.data_ridicarii}, client{other.client} {}

//GETTERS

//SETTERS
void Comanda::setPret()
{
    this->pret=Aduna();
}

void Comanda::setAvans(const float avans)
{
    this->avans=avans;
}

//OPERATORI

//METODE
float Comanda::Aduna() 
{   
    float suma=0;
    for(auto produs : produse) 
        suma+=produs.getPret();
    for(auto produs_special : produse_speciale)
        suma+=produs_special.getPret();
    return suma;
}

void Comanda::AdaugaProdus(const Produs& p)
{
    this->produse.push_back(p);
}

void Comanda::AdaugaProdusSpecial(const ProdusSpecial& p)
{
    this->produse_speciale.push_back(p);
}