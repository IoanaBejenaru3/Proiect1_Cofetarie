#ifndef PRODUS_H
#define PRODUS_H
#include <iostream>
#include <string>
#include <vector>
#include "../include/Client.h"

//voi implementa in cadrul acestui proiect si conceptul de "mostenire"
//ma bazez pe faptul ca in cadrul cofetariei exista produse care sunt aduse doar in anumite conditii,
//la ocazii speciale (spre exemplu prajituri pentru anumite sarbatori - sfintii, prajituri de Valentine's Day, prajituri de Craciun...)


class Produs{
private:
protected:
    std::string denumire;
    std::vector <std::string> ingrediente_alergenice; 
    int numar;
    bool de_post;
    float pret;

public:
    //CONSTRUCTOR
    Produs(std::string den="", std::vector <std::string> ingr_alerg={}, int nr=0, bool post=0, float pret=0);
    //CC
    Produs(const Produs& other);
    //GETTERS
    float getPret();
    bool getPost();
    std::string getDenumire();
    int getNumar();
    //SETTERS
    
    //SUPRAINCARCAREA OPERATORILOR
    //operatorul +=
    Produs& operator+=(const int nr);
    //operatorul ++
    Produs& operator++();
    //operatorul --
    Produs& operator--();
    //operatorul -=
    Produs& operator-=(const int nr);
    //operatorul >>
    friend std::istream& operator>>(std::istream& is, Produs& p);
    //operatorul <<
    friend std::ostream& operator<<(std::ostream& os, const Produs& p);

    //METODE
    bool TestAlergeni(std::vector <std::string> alergeni);
    //DESTRUCTOR
    ~Produs() {}

};

class ProdusSpecial: public Produs{
private:
    std::string festivitate;
    std::string perioada_valabilitate;
public:
    //CONSTRUCTOR
    ProdusSpecial(std::string den="", std::vector <std::string> ingr_alerg={}, int nr=0, bool post=0, float pret=0, std::string festivitate="", std::string perioada="");
    //CC
    ProdusSpecial(const ProdusSpecial& other);
    //GETTERS
    //SETTERS

    //SUPRAINCARCAREA OPERATORILOR
    friend std::istream& operator>>(std::istream& is, ProdusSpecial& p);
    friend std::ostream& operator<<(std::ostream& os, const ProdusSpecial& p);
    //METODE


    //DESTRUCTOR
    ~ProdusSpecial(){}
};


#endif /*PRODUS_H*/