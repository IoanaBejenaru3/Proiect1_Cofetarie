#include "include/Produs.h"
#include "include/Comanda.h"
#include "include/Client.h"
#include "include/Cofetarie.h"
#include <iostream>

void PreiaComanda(Cofetarie& cofetarie)
{
    std::cout << "Pentru a va prelua comanda avem nevoie de:" << std::endl;

    //VREM SA PRIMIM O COMANDA
    Client client;
    std::string denumire;

    std::cin>>client;
    Comanda comanda={client}; //am construit comanda doar cu clientul si urmeaza sa adaugam detaliile comenzii si sa le calculam
    int numar_produse, numar_produse_speciale, numar;
    std::cout << "Numarul de produse si de produse speciale in aceasta ordine: " << std::endl;
    std::cin >> numar_produse >> numar_produse_speciale;
    for(int i=0; i<numar_produse; i++)
    {
        std::cout << "Denumire: ";
        std::cin.get();
        std::getline(std::cin, denumire);
        std::cout << "Numar: ";
        std::cin >> numar;
        Produs p = cofetarie.GasesteProdus(denumire);
        p.setNumar(numar);
        comanda.AdaugaProdus(p);
    }
    for(int i=0; i<numar_produse_speciale; i++)
    {
        std::cout << "Denumire: ";
        std::cin.get();
        std::getline(std::cin, denumire);
        std::cout << "Numar:";
        std::cin >> numar;
        ProdusSpecial p = cofetarie.GasesteProdusSpecial(denumire);
        p.setNumar(numar);
        comanda.AdaugaProdusSpecial(p);
    }
    //acum ca am preluat o comanda trebuie sa ii calculam pretul total si sa intrebam clientul daca doreste sa dea un avans
    comanda.setPret();
    std::cout << "Pretul comenzii este " << comanda.getPret() << " RON. " << "Avansul dat de dumneavoastra este: ";
    float avans;
    std::cin >> avans;
    if(avans) cofetarie.AdaugaBani(avans);
    comanda.setAvans(avans);
    comanda.setStatus();
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
    std::cout << "Denumire: ";
    std::cin >> denumire;
    std::cout << std::endl;
    std::cout << "Numar: ";
    std::cin >> numar;
    int cate_produse = cofetarie.getNumar(denumire);
    if(cate_produse == 0) { std::cout<<"Ne pare rau. Nu mai sunt produse de acest tip momentan!"<<std::endl; return; }
    float pret = cofetarie.getPret(denumire);
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
void AdaugaDinCuptor(Cofetarie& cofetarie)
{
    std::string denumire;
    int nr;
    std::cin >> denumire >> nr;
    cofetarie.Cuptor(denumire,nr);
}

//aceasta functie ii spune unui client, care vine sa preia comanda, cat trebuie sa mai plateasca (pe baza pretului si avansului dat)
void CalculeazaRestBaniComenzi(Cofetarie& cofetarie)
{
   std::string nr_tel;
   std::cin >> nr_tel;
   float rest = cofetarie.CalculeazaRestBaniComenzi(nr_tel);
   std::cout<<"Restul de bani pe care trebuie sa il dati este: "<<rest<<" RON."<<std::endl;
}

//aceasta functie este pentru a-i prezenta clientului produsele care sunt de post si sunt valabile in cofetarie (adica numar!=0)
void AfiseazaProduseDePost(Cofetarie& cofetarie)
{
    std::cout << "Produsele de post disponibile in cofetarie sunt: " << std::endl;
    cofetarie.getDenumiriDePost();
}

//aceasta functie este pentru a-i prezenta clientului produsele care nu contin anumite ingrediente alergenice
void AfiseazaProduseFaraAlergeni(Cofetarie& cofetarie)
{
    int n;
    std::string denumire;
    std::vector <std::string> ingrediente;
    std::cout << "Numar de ingrediente alergenice: ";
    std::cin >> n;
    std::cout << std::endl << "Ingrediente: ";
    for(int i=0; i<n; i++)
        {
            std::cin >> denumire;
            ingrediente.push_back(denumire);
        }
    std::cout << "Produsele disponibile in cofetarie care nu contin alergenii mentionati:" << std::endl;
    cofetarie.getDenumiriFaraAlergeni(ingrediente);
}

//aceasta functie ii arata clientului ce produse avem in perioade festive

void AfiseazaProduseFestive(Cofetarie& cofetarie)
{
    int n;
    std::string denumire;
    std::vector <std::string> sarbatori;
    std::cout << "Numarul sarbatorilor: ";
    std::cin >> n;
    std::cout << "Denumiri: ";
    for(int i=0; i<n; i++)
        {
            std::cin >> denumire;
            sarbatori.push_back(denumire);
        }
    std::cout << "Produsele disponibile in cofetarie care se gasesc de aceste sarbatori:" << std::endl;
    cofetarie.getDenumiriProduseFestive(sarbatori);
}


int main()
{
    //CEEA CE AVEM IN COFETARIE
    Cofetarie cofetarie=Cofetarie();
    int numar_produse, numar_produse_speciale;
    std::cin >> numar_produse >> numar_produse_speciale;
    for(int i = 1; i <= numar_produse; i++)
    {
        Produs p1;
        std::cin>>p1;
        cofetarie.AdaugaProdus(p1);
    }
    for(int i = 1; i <= numar_produse_speciale; i++)
    {
        ProdusSpecial p2;
        std::cin>>p2;
        cofetarie.AdaugaProdusSpecial(p2);
    }
    cofetarie.getDenumiri();

    //METODELE DIN CADRUL CLASE COFETARIE PENTRU TESTARE:

    //PreiaComanda(cofetarie);
    //CumparareProdus(cofetarie);

    //PENTRU A VERIFICATE DACA SE UPDATEAZA NR DE PRODUSE DE TIP DENUMIRE
    //std::cout << cofetarie.getNumar("denumire_aleasa_din_cele_afisate") << std::endl;
    //AdaugaDinCuptor(cofetarie);
    //std::cout << cofetarie.getNumar("denumire_aleasa_din_cele_afisate") << std::endl;

    //CalculeazaRestBaniComenzi(cofetarie);
    //AfiseazaProduseDePost(cofetarie);
    //AfiseazaProduseFaraAlergeni(cofetarie);
    //AfiseazaProduseFestive(cofetarie);
    return 0;
}