#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <vector>

//pentru comenzi vom idendifica clientii dupa nr de telefon deoarece acesta este generat unic
//in timp ce pot exista mai multi oameni cu acelasi nume

class Client{
private:
    std::string nume;
    std::string prenume;
    std::string numar_telefon;
public:
    //CONSTRUCTOR
    Client(std::string nume="", std::string prenume="", std::string nr_tel="");
    //CC
    Client(const Client& other);
    //GETTERS
    std::string getTelefon();
    //SETTERS
    
};


#endif /*CLIENT_H*/