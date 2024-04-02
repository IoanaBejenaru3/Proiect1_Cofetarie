#include "../include/Produs.h"
#include "../include/Comanda.h"
#include "../include/Client.h"
#include "../include/Cofetarie.h"

//CONSTRUCTOR
Comanda::Comanda(float p, float a, std::vector <Produs> pr, std::vector <ProdusSpecial> ps, bool status, Client c): pret{p}, avans{a}, produse{pr}, produse_speciale{ps}, status{status}, client{c} {}
Comanda::Comanda(Client c) : pret{0}, avans{0}, produse{}, produse_speciale{}, status{0}, client{c} {}
//CC
Comanda::Comanda(const Comanda& other): pret{other.pret}, avans{other.avans}, produse{other.produse}, status{other.status}, client{other.client} {}

//GETTERS

std::string Comanda::getNrTel()
{
    return this->client.getTelefon();
}

float Comanda::getPret() { return this->pret; }

bool Comanda::getStatus()
{
    return this->status;
}

//SETTERS
void Comanda::setPret()
{
    this->pret=Aduna();
}

void Comanda::setAvans(const float avans)
{
    this->avans=avans;
}

 void Comanda::setStatus()
 {
    this->status=1;
 }

//OPERATORI

//METODE
float Comanda::Aduna() 
{   
    float suma=0;
    for(auto produs : produse) 
        suma+=produs.getPret()*produs.getNumar();
    for(auto produs_special : produse_speciale)
        suma+=produs_special.getPret()*produs_special.getNumar();  //in cazul comenzilor numarul va reprezenta cate din acele produse vrea clientul
    return suma;
}

float Comanda::Afla()
{
    return this->pret-this->avans;
}

void Comanda::AdaugaProdus(const Produs& p)
{
    this->produse.push_back(p);
}

void Comanda::AdaugaProdusSpecial(const ProdusSpecial& p)
{
    this->produse_speciale.push_back(p);
}

float Comanda::Diferenta()
{
    return Afla();
}