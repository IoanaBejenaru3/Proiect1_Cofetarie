@rem Script de compilare pentru Laboratorul 3
@echo off
g++ -c -o Cofetarie.o Cofetarie.cpp
g++ -c -o main.o main.cpp
g++ -o main main.o Cofetarie.o
main.exe
pause
@echo on