#include "include/Produs.h"
#include "include/Comanda.h"
#include "include/Client.h"
#include "include/Cofetarie.h"
#include <iostream>

int main()
{
    Produs p1=Produs();
    std::cout<<p1.getPret();
    std::cout<<std::endl<<"Hello!";
    return 0;
}