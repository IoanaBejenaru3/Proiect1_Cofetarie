#include "include/Produs.h"
#include "include/Comanda.h"
#include "include/Client.h"
#include "include/Cofetarie.h"
#include <iostream>

int main()
{
    // Cofetarie cofetarie=Cofetarie();
    // int numar_produse, numar_produse_speciale;
    // std::cin>>numar_produse>>numar_produse_speciale;
    // for(int i=1; i<=numar_produse; i++)
    // {
    //     Produs p;
    //     std::cin>>p;
    //     cofetarie.AdaugaProdus(p);
    // }
    // for(int i=1; i<=numar_produse_speciale; i++)
    // {
    //     ProdusSpecial p;
    //     std::cin>>p;
    //     cofetarie.AdaugaProdusSpecial(p);
    // }

    ProdusSpecial p;
    std::cin>>p;
    std::cout<<p;
    return 0;
}