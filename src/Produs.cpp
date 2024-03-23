#include "../include/Produs.h"

Produs::Produs(std::string den, std::vector <std::string> ingr_alerg, int nr, bool post, float pret): denumire{den}, ingrediente_alergenice{ingr_alerg}, numar{nr}, de_post{post}, pret{pret} {}

Produs::Produs(const Produs& other):denumire{other.denumire}, ingrediente_alergenice{other.ingrediente_alergenice}, numar{other.numar}, de_post{other.de_post}, pret{other.pret} {}

float Produs::getPret() {return this->pret;}