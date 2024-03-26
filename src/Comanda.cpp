#include "../include/Produs.h"
#include "../include/Comanda.h"
#include "../include/Client.h"
#include "../include/Cofetarie.h"

//CONSTRUCTOR
Comanda::Comanda(int p, int a, std::vector <Produs> pr, std::string dp, std::string dr, Client c): pret{p}, avans{a}, produse{pr}, data_plasarii{dp}, data_ridicarii{dr}, client{c} {}

//CC
Comanda::Comanda(const Comanda& other): pret{other.pret}, avans{other.avans}, produse{other.produse}, data_plasarii{other.data_plasarii}, data_ridicarii{other.data_ridicarii}, client{other.client} {}

