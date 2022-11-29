#include "Persona.h"

Persona:: Persona (int x, int y)
{
m_x = x;
m_y = y;
}

void Persona :: update ()
{
m_y = m_y + 0.15f;

if (m_y >= 39)
{
m_x = rand () % 119 +1 ;
m_y = 1;
}
}

void Persona :: draw ()
{
mvaddch (m_y, m_x+1, 'O');
mvaddch (m_y+1, m_x, '-');
mvaddch (m_y+1, m_x+2, '-');
mvaddch (m_y+1, m_x+1, '|');
mvaddch (m_y+2, m_x, '|');
mvaddch (m_y+2, m_x+2, '|');
}

void Persona :: colision (Tren &rTren){
if (m_x >= rTren.getX() && m_x <= rTren.getX() + 4 && m_y >= rTren.getY () && m_y <= rTren.getY() +2)
{
rTren.Sumarpasajeros ();

m_x = rand () % 119 +1;
m_y = 1;

}

}