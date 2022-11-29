#pragma once
#include <iostream>
#include <ncurses.h>
#include "Tren.h"

using namespace std;

class Persona
{
public: 
Persona (int x, int y);
void update ();
void draw ();

void colision (Tren &rTren);

int getX();
int getY();

private:
float m_x;
float m_y;


};