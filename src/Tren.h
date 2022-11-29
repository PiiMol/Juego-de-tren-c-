#pragma once
#include <iostream>
#include <ncurses.h>

class Tren {
//////////////////// CLASE PUBLICA //////////////////////
public:
void menu ();
void setup ();
void draw ();
void update ();

void drawPersonas();
void setPasajeros (int pasajeros);

void setX (int x);
void setY (int y);


int getPasajeros ();
int Sumarpasajeros ();
int RestarPasajeros();


int getX ();
int getY ();

void setLimite(int Limite);
int getLimite();

///////////////////////////// CLASE PRIVADA /////////////////////////
private:

int m_x;
int m_y;
int m_pasajeros;
int m_Limite;


};