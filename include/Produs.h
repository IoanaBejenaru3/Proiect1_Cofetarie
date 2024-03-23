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
    std::string denumire;
    std::vector <std::string> ingrediente_alergenice; 
    int numar;
    bool de_post;
    float pret;
public:
    //CONSTRUCTOR
    Produs(std::string den="", std::vector <std::string> ingr_alerg={}, int nr=0, bool post=0, float pret=10);
    //CC
    Produs(const Produs& other);
    //GETTERS
    float getPret();
    //SETTERS

    //SUPRAINCARCAREA OPERATORILOR
    
    //operatorul +
    //Produs

    //DESTRUCTOR
    ~Produs() {std::cout<<"Destructor Produs\n";}

};

class ProdusSpecial: public Produs{
private:
    std::string festivitate;
    std::string perioada_valabilitate;
public:

};


#endif /*PRODUS_H*/