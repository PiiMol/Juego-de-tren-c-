#include "Tren.h"



/////////////// SETUP ///////////////////

void Tren :: setup()
{ 
m_x = 60;
m_y = 20;

m_pasajeros = 1;
m_Limite = 15;

}


/////////////// UPDATE //////////////////


void Tren :: update ()
{
if (m_pasajeros <= 0)
{
    m_Limite ++;
    m_pasajeros = 1;
}
}

////////////////// DRAW /////////////////////////

void Tren :: draw ()
{
mvaddch(m_y,m_x, '<');
mvaddch(m_y,m_x +1, '[');
mvaddch(m_y,m_x +2, ']' );
mvaddch(m_y,m_x +3, ACS_CKBOARD);
mvaddch(m_y,m_x +4, ACS_CKBOARD);
mvaddch(m_y,m_x +5, ACS_CKBOARD);
mvaddch(m_y,m_x +6, ACS_CKBOARD);
mvaddch(m_y,m_x +7, ACS_CKBOARD);
mvaddch(m_y,m_x +8, ACS_CKBOARD);
mvaddch(m_y,m_x +9, ACS_CKBOARD);
mvaddch(m_y,m_x +10, ACS_CKBOARD);
mvaddch(m_y,m_x +11, ACS_CKBOARD);
mvaddch(m_y,m_x +12, ACS_CKBOARD);
mvaddch(m_y,m_x +13, ACS_CKBOARD);

mvaddch (m_y +1 , m_x +1, ACS_DEGREE);
mvaddch (m_y +1 , m_x +3, ACS_DEGREE);
mvaddch (m_y +1 , m_x +5, ACS_DEGREE);
mvaddch (m_y +1 , m_x +7, ACS_DEGREE);
mvaddch (m_y +1 , m_x +9, ACS_DEGREE);
mvaddch (m_y +1 , m_x +11, ACS_DEGREE);
mvaddch (m_y +1 , m_x +13, ACS_DEGREE);
}

///////////////////// GENERALES /////////////////////////

void Tren :: setX (int x) { m_x = x; }
void Tren :: setY (int y) { m_y = y; }

int Tren :: getX () { return m_x;}
int Tren :: getY () { return m_y;}

void Tren:: setPasajeros (int pasajeros) {m_pasajeros = pasajeros;}
int Tren :: getPasajeros () {return m_pasajeros;}

void Tren :: setLimite (int limite) { m_Limite = limite;}
int Tren :: getLimite () {return m_Limite;}

int Tren:: Sumarpasajeros () { return m_pasajeros ++;}
int Tren:: RestarPasajeros () { return m_pasajeros --;}



