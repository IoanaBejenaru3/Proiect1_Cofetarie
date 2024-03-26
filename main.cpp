#include "include/Produs.h"
#include "include/Comanda.h"
#include "include/Client.h"
#include "include/Cofetarie.h"
#include <iostream>

void PreiaComanda()
{
    //VREM SA PRIMIM O COMANDA
    Client client;
    std::cin>>client;
    Comanda comanda={client}; //am construit comanda doar cu clientul si urmeaza sa adaugam detaliile comenzii si sa le calculam
    int numar_produse, numar_produse_speciale;
    std::cin>>numar_produse>>numar_produse_speciale;
    for(int i=1; i<=numar_produse; i++)
    {
        Produs p;
        std::cin>>p;
        comanda.AdaugaProdus(p);
    }
    for(int i=1; i<=numar_produse_speciale; i++)
    {
        ProdusSpecial p;
        std::cin>>p;
        comanda.AdaugaProdusSpecial(p);
    }
}


int main()
{
    //CEEA CE AVEM IN COFETARIE
    Cofetarie cofetarie=Cofetarie();
    int numar_produse, numar_produse_speciale;
    std::cin>>numar_produse>>numar_produse_speciale;
    for(int i=1; i<=numar_produse; i++)
    {
        Produs p;
        std::cin>>p;
        cofetarie.AdaugaProdus(p);
    }
    for(int i=1; i<=numar_produse_speciale; i++)
    {
        ProdusSpecial p;
        std::cin>>p;
        cofetarie.AdaugaProdusSpecial(p);
    }


    return 0;
}