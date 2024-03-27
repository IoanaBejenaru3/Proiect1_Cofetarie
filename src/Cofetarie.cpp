#include "../include/Produs.h"
#include "../include/Comanda.h"
#include "../include/Client.h"
#include "../include/Cofetarie.h"

//CONSTRUCTOR
Cofetarie::Cofetarie(std::vector <Produs> p, std::vector <ProdusSpecial> ps, std::vector <Comanda> c, float cb): produse{p}, produse_speciale{ps}, comenzi{c}, cont_bancar{cb} {}

//CC
Cofetarie::Cofetarie(const Cofetarie& other): produse{other.produse}, comenzi{other.comenzi}, produse_speciale{other.produse_speciale}, cont_bancar{other.cont_bancar} {}

//GETTERS
void Cofetarie::getDenumiri()
{
    std::cout<<"Produsele disponibile in cofetarie sunt: ";
    for(auto produs: this->produse)
        std::cout<<produs.getDenumire()<<',';
      for(auto produs: this->produse_speciale)
        std::cout<<produs.getDenumire()<<',';
    std::cout<<std::endl;
}

float Cofetarie::getPret(std::string denumire)
{
    for(auto produs: this->produse)
        if(produs.getDenumire()==denumire)
              return produs.getPret();  
}

 int Cofetarie::getNumar(std::string denumire)
 {
    for(auto produs: this->produse)
        if(produs.getDenumire()==denumire)
              return produs.getNumar();
 }

 float Cofetarie::getBani(){return this->cont_bancar;}

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

void Cofetarie::AdaugaComanda(const Comanda& c)
{
    this->comenzi.push_back(c);
}

void Cofetarie::AdaugaBani(float bani)
{
    this->cont_bancar+=bani;
}

void Cofetarie::ModificaProdus(std::string denumire, int nr)
{
    for(auto produs: this->produse)
        if(produs.getDenumire()==denumire)
            produs-=nr;
}