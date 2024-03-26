#include "../include/Produs.h"
#include "../include/Comanda.h"
#include "../include/Client.h"
#include "../include/Cofetarie.h"

//CONSTRUCTOR
Cofetarie::Cofetarie(std::vector <Produs> p, std::vector <ProdusSpecial> ps, std::vector <Comanda> c, int cb): produse{p}, produse_speciale{ps}, comenzi{c}, cont_bancar{cb} {}

//CC
Cofetarie::Cofetarie(const Cofetarie& other): produse{other.produse}, comenzi{other.comenzi}, produse_speciale{other.produse_speciale}, cont_bancar{other.cont_bancar} {}

//GETTERS
//SETTERS

//METODE
void Cofetarie::AdaugaProdus(const Produs& p) 
{
    this->produse.push_back(p);
}
void Cofetarie::AdaugaProdusSpecial(const ProdusSpecial& p)
{
    this->produse_speciale.push_back(p);
}