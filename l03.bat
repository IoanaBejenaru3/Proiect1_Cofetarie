@rem 
@echo off
g++ -c -o src/Cofetarie.o src/Cofetarie.cpp
g++ -c -o src/Produs.o src/Produs.cpp
g++ -c -o src/Client.o src/Client.cpp
g++ -c -o src/Comanda.o src/Comanda.cpp
g++ -c -o main.o main.cpp
g++ -o main main.o src/Cofetarie.o src/Produs.o src/Comanda.o src/Client.o 
main.exe
pause
@echo on