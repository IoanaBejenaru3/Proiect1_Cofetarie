#include "../include/Produs.h"
#include <cstring>
#define BUF_SIZE 256 // Stil C
// constexpr int BUF_SIZE = 256; // stil C++11 sau C++14
//CONSTRUCTORI
Produs::Produs(std::string den, std::vector <std::string> ingr_alerg, int nr, bool post, float pret): denumire{den}, ingrediente_alergenice{ingr_alerg}, numar{nr}, de_post{post}, pret{pret} {}
ProdusSpecial::ProdusSpecial(std::string den, std::vector <std::string> ingr_alerg, int nr, bool post, float pret, std::string festivitate, std::string perioada):  Produs(den, ingr_alerg, nr, post, pret), festivitate{festivitate}, perioada_valabilitate{perioada} {}
//CC
Produs::Produs(const Produs& other):denumire{other.denumire}, ingrediente_alergenice{other.ingrediente_alergenice}, numar{other.numar}, de_post{other.de_post}, pret{other.pret} {}
ProdusSpecial::ProdusSpecial(const ProdusSpecial& other): Produs(other), festivitate{other.festivitate}, perioada_valabilitate{other.perioada_valabilitate} {}

//GETTERS
float Produs::getPret() {return this->pret;}
int Produs::getNumar() {return this->numar;}
std::string Produs::getDenumire() { return this->denumire; }

//SETTERS

//OPERATORI
Produs& Produs::operator+=(const int nr) {this->numar += nr; return *this;}

Produs& Produs::operator++() {this->numar += 1; return *this;}

Produs& Produs::operator--() {this->numar--; return *this;}

Produs& Produs::operator-=(const int nr) {this->numar-=nr; return *this;}

std::istream& operator>>(std::istream& is, Produs& p)
{
    int numar_ingrediente;
    std::string ing;
    // char denumire[BUF_SIZE];
    // denumire[BUF_SIZE-1] = '\0';
    // fgets(denumire, BUF_SIZE-1, stdin);
    // denumire[strlen(denumire)-1] = '\0';
    // printf("Denumire = %s\n", denumire);
    is.get(); // ignore \n
    std::getline(is, p.denumire);
    is >> numar_ingrediente;
    for(int i = 0; i < numar_ingrediente; i++)
    {
        is >> ing;
        p.ingrediente_alergenice.push_back(ing);
    }
    is>>p.numar;
    is>>p.de_post;
    is>>p.pret;
    //printf("numar = %d\tde_post = %d\tpret = %.2f\n", p.numar, p.de_post, p.pret);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Produs& p)
{
    os<<"Denumirea produsului este: "<<p.denumire<<std::endl;
    os<<"Ingrdientele alergenice sunt: ";
    for(auto ingr:p.ingrediente_alergenice)
        os<<ingr<<" ";
    os<<std::endl;
    os<<"Produse ramase: "<<p.numar<<std::endl;
    if(p.de_post) os<<"Produsul este DE POST.";
    else os<<"Produsul NU este de post.";
    os<<std::endl;
    os<<"Pretul produsului este "<<p.pret<<"RON/bucata.";
    os<<std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, ProdusSpecial& p)
{
    is>>static_cast<Produs&>(p);
    is.get();
    std::getline(is, p.festivitate);
    is>>p.perioada_valabilitate;
    return is;
}

std::ostream& operator<<(std::ostream& os, const ProdusSpecial& p)
{
    os<<static_cast<const Produs&>(p);
    os<<"Festivitatea: "<<p.festivitate<<" pe perioada "<<p.perioada_valabilitate;
    os<<std::endl;
    return os;
}