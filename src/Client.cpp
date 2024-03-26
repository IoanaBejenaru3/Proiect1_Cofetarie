#include "../include/Produs.h"
#include "../include/Comanda.h"
#include "../include/Client.h"
#include "../include/Cofetarie.h"

//CONSTRUCTOR
Client::Client(std::string nume, std::string prenume, std::string nr_tel): nume{nume}, prenume{prenume}, numar_telefon{nr_tel} {}

//CC
Client::Client(const Client& other): nume{other.nume}, prenume{other.prenume}, numar_telefon{other.numar_telefon} {}

//GETTERS
std::string Client::getTelefon() {return this->numar_telefon;}

//SETTERS


