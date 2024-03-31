#include "../include/Produs.h"
#include "../include/Comanda.h"
#include "../include/Client.h"
#include "../include/Cofetarie.h"
#include <string>
#include <locale>

//CONSTRUCTOR
Cofetarie::Cofetarie(std::vector <Produs> p, std::vector <ProdusSpecial> ps, std::vector <Comanda> c, float cb): produse{p}, produse_speciale{ps}, comenzi{c}, cont_bancar{cb} {}

//CC
Cofetarie::Cofetarie(const Cofetarie& other): produse{other.produse}, comenzi{other.comenzi}, produse_speciale{other.produse_speciale}, cont_bancar{other.cont_bancar} {}

//GETTERS
void Cofetarie::getDenumiri()
{   
    std::cout << "Produsele disponibile in cofetarie sunt: " << std::endl;
    for(auto produs: this->produse)
        std::cout << "-" << produs.getDenumire() << std::endl;
      for(auto produs: this->produse_speciale)
        std::cout << "-" << produs.getDenumire() << std::endl;
    std::cout << std::endl;
}

void Cofetarie::getDenumiriDePost()
{
    for(auto produs: this->produse)
        if(produs.getPost()==1 && produs.getNumar())
            std::cout << "-" << produs.getDenumire() << std::endl;
      for(auto produs: this->produse_speciale)
        if(produs.getPost()==1  && produs.getNumar())
            std::cout << "-" << produs.getDenumire() << std::endl;
    std::cout << std::endl;
}

// void Cofetarie::getDenumiriFaraAlergeni(std::vector <std::string> ingrediente)
// {
//     for(auto produs: this->produse)
        
// }

float Cofetarie::getPret(std::string denumire)
{
    for(auto produs: this->produse)
        if(produs.getDenumire()==denumire)
              return produs.getPret();
    return -1;  //in cazul in care acel produs nu exista
}

 int Cofetarie::getNumar(std::string denumire)
 {
    for(auto produs: this->produse)
        if(produs.getDenumire()==denumire)
              return produs.getNumar();
    return -1;  //in cazul in care acel produs nu exista
 }

/*float Cofetarie::getBani(){return this->cont_bancar;}*/

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

void Cofetarie::ModificaProdus(std::string denumire, const int nr)
{
    for(auto produs: this->produse)
        if(produs.getDenumire()==denumire)
            {produs-=nr; return;}
    return;
}

std::string upper(std::string denumire)
{
    std::string denumire_noua;
    denumire_noua=denumire;
    for(char& c : denumire_noua)
        c = std::toupper(c);
    return denumire_noua;
}

void Cofetarie::Cuptor(std::string denumire, const int nr)
{
    denumire=upper(denumire);
     for(auto produs: this->produse)
        if(upper(produs.getDenumire())==denumire)
            {   
                produs+=nr;
                return;
            }
    return; //in cazul in care acel produs nu exista
}

float Cofetarie::CalculeazaRestBaniComenzi(std::string nr_tel)
{
    float suma=0;
    for(auto comanda : comenzi)
        if(comanda.getNrTel()==nr_tel && comanda.getStatus()==1)
                suma+=comanda.Diferenta();
    return suma;
}