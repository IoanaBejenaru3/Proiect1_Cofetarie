#include "../include/Produs.h"
#include "../include/Comanda.h"
#include "../include/Client.h"
#include "../include/Cofetarie.h"
#include <string>
#include <locale>

std::string upper(std::string denumire)  //aceasta functie evita erori: daca un citim de la tastatura amandina si produsul este salvat ca "Amandina"
{                                        //functia upper ne ajuta sa le vedem pe ambele ca fiind egale prin transformarea tuturor caracterelor in majuscule
    std::string denumire_noua;
    denumire_noua = denumire;
    for(char& c : denumire_noua)
        c = std::toupper(c);
    return denumire_noua;
}

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
    std::cout << std::endl;
    std::cout << "Produsele speciale disponibile in cofetarie sunt: " << std::endl;
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

void Cofetarie::getDenumiriProduseFestive(std::vector <std::string> sarbatori)
{
    for(auto produs : this->produse_speciale)
        for(auto denumire : sarbatori)
            if(produs.getFestivitate() == denumire)
                { std::cout << "-" << produs.getDenumire() << " : " << denumire << std::endl;}
}

void Cofetarie::getDenumiriFaraAlergeni(std::vector <std::string> ingrediente)
{
    for(auto produs: this->produse)
    {
        if(produs.TestAlergeni(ingrediente) == 1)
          {
            std::cout << "-" << produs.getDenumire();
            if(produs.getNumar() != 0) std::cout << " : valabil in cofetarie.";
            else std::cout <<" disponibil prin comanda.";
            std::cout << std::endl;
          }
    }
    for(auto produs: this->produse_speciale)
    {
        if(produs.TestAlergeni(ingrediente) == 1)
          {
            std::cout << "-" << produs.getDenumire();
            if(produs.getNumar() != 0) std::cout << " : valabil in cofetarie.";
            else std::cout <<" : disponibil prin comanda.";
            std::cout << std::endl;
          }
    }
    std::cout << std::endl;
}

float Cofetarie::getPret(std::string denumire)
{
    for(auto produs: this->produse)
        if(produs.getDenumire()==denumire)
              return produs.getPret();
    return -1;  //in cazul in care acel produs nu exista
}

 int Cofetarie::getNumar(std::string denumire)
 {
    denumire = upper(denumire);
    for(auto produs: this->produse)
        if(upper(produs.getDenumire()) == denumire)
              return produs.getNumar();
    for(auto produs: this->produse_speciale)
        if(upper(produs.getDenumire()) == denumire)
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
    this->cont_bancar += bani;
}

void Cofetarie::ModificaProdus(std::string denumire, const int nr)
{
    for(auto produs: this->produse)
        if(produs.getDenumire() == denumire)
            {produs -= nr; return;}
    return;
}

void Cofetarie::Cuptor(std::string denumire, const int nr)
{
    denumire = upper(denumire);
    for(int i = 0; i < this->produse.size(); i++)
        if(upper(produse[i].getDenumire()) == denumire)
            {   
                produse[i]+=nr;
                return;
            }
    for(int i = 0; i < this->produse_speciale.size(); i++)
        if(upper(produse_speciale[i].getDenumire()) == denumire)
            {   
                produse_speciale[i]+=nr;
                return;
            }
    return; //in cazul in care acel produs nu exista
}

float Cofetarie::CalculeazaRestBaniComenzi(std::string nr_tel)
{
    float suma = 0;
    for(auto comanda : comenzi)
        if(comanda.getNrTel()==nr_tel && comanda.getStatus()==1)
                suma+=comanda.Diferenta();
    return suma;
}

Produs Cofetarie::GasesteProdus(std::string denumire)
{
    Produs p;
    for(auto produs : produse)
        if(upper(produs.getDenumire()) == upper(denumire))
            return produs;
    return p;
}

ProdusSpecial Cofetarie::GasesteProdusSpecial(std::string denumire)
{
    denumire = upper(denumire);
    ProdusSpecial p;
    for(auto produs : produse_speciale)
        if(upper(produs.getDenumire()) == denumire)
            return produs;
    return p;
}

void Cofetarie::ModficarePret(std::string denumire, const float nr)
{
    denumire = upper(denumire);
    for(auto produs : produse)
        if(upper(produs.getDenumire()) == denumire)
            produs.setPret(nr);
    for(auto produs : produse_speciale)
        if(upper(produs.getDenumire()) == denumire)
            produs.setPret(nr);
    return;
}