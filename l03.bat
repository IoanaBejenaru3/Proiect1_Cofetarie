@REM @echo off
g++ -c -o obj/Cofetarie.o src/Cofetarie.cpp
g++ -c -o obj/Produs.o src/Produs.cpp
g++ -c -o obj/Client.o src/Client.cpp
g++ -c -o obj/Comanda.o src/Comanda.cpp
g++ -c -o main.o main.cpp
g++ -o main main.o obj/Cofetarie.o obj/Produs.o obj/Comanda.o obj/Client.o -g
@REM main.exe < input.txt
@REM pause
@REM @echo on