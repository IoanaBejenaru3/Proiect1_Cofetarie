#include "include/Produs.h"
#include "include/Comanda.h"
#include "include/Client.h"
#include "include/Cofetarie.h"
#include <iostream>

void PreiaComanda(Cofetarie& cofetarie)
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
    //acum ca am preluat o comanda trebuie sa ii calculam pretul total si sa intrebam clientul daca doreste sa dea un avans
    comanda.setPret();
    std::cout<<"Avansul dat pentru comanda: ";
    int avans;
    std::cin>>avans;
    comanda.setAvans(avans);
    cofetarie.AdaugaComanda(comanda);
}

//aceasta functie simuleaza venirea unui client oarecare la cofetarie care vrea sa cumpere un produs
//in urma acestui lucru, trebuie sa modificam numarul de produse de tipul "denumire" si sa adaugam la contul bancar al cofetariei banii castigati
//de asemenea, trebuie sa avem grija in cazul in care numar>numarul de produse de tipul "denumire" existente in cofetarie sa ii dam doar cate exista
//plus denumirea citita va reprezenta un produs existent in cofetarie
void CumparareProdus(Cofetarie& cofetarie) 
{
    std::string denumire;
    int numar;
    std::cin>>denumire>>numar;
    int cate_produse=cofetarie.getNumar(denumire);
    if(cate_produse==0) {std::cout<<"Nu mai sunt produse de acest tip momentan!"<<std::endl; return;}
    float pret=cofetarie.getPret(denumire);
    if(numar > cate_produse)
    {
        cofetarie.ModificaProdus(denumire,cate_produse);
        cofetarie.AdaugaBani(cate_produse*pret);
    }
    else
    {
        cofetarie.ModificaProdus(denumire,numar);
        cofetarie.AdaugaBani(numar*pret);
    }
}

//aceasta functie simuleaza "scoaterea unor produse din cuptor", in sensul in care mai adaugam la numarul de produse de tip "denumire"
//--


int main()
{
    //CEEA CE AVEM IN COFETARIE
    Cofetarie cofetarie=Cofetarie();
    int numar_produse, numar_produse_speciale;
    std::cin>>numar_produse>>numar_produse_speciale;
    Produs p1;
    for(int i=1; i<=numar_produse; i++)
    {
        std::cin>>p1;
        cofetarie.AdaugaProdus(p1);
    }
    ProdusSpecial p2;
    for(int i=1; i<=numar_produse_speciale; i++)
    {
        std::cin>>p2;
        cofetarie.AdaugaProdusSpecial(p2);
    }
    cofetarie.getDenumiri();
    //PreiaComanda(cofetarie);
    //CumparareProdus(cofetarie);
    
    return 0;
}