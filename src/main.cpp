//Molnar Pilar Delfina

#include <iostream>
#include <ncurses.h>
#include <string>
#include <ctime>
#include <vector>
#include "Tren.h"
#include "Persona.h"


using namespace std;

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 30;

bool game_over;
bool salir;


int x,y;
int x_persona, y_persona;

void minijuego();

vector <string> paradas;

enum columnas { PARADA, AYUDA, CANTIDAD_COLUMNAS};
const int cantidadParadas = 17;
string paradasRoca [cantidadParadas] [CANTIDAD_COLUMNAS]= { 
{"KostekiSantillan", "Conocida como estacion Avellaneda."}, 
{"Sarandi", "Donde se encuentra la cancha de Arsenal."},
{"Dominico", "Donde se encuentra el parque de los trabajadores."},
{"Wilde", "Oscar Rebelde"}, 
{"DonBosco", "Donde se encuentra el nuevo Quilmes."}, 
{"Bernal", "La Universidad Nacional de Quilmes se encuentra aqui."},
{"Quilmes", "Hay una cerveza con este nombre. "}, 
//{"Ezpeleta", "Pertenece al partido de Quilmes. Limita con Berazategui y Florencio Varela."}, 
{"Berazategui", "Conocida (segun Wikipedia) como la <Capital Nacional de Vidrio>"}, 
{"Platanos", "El nombre de esta localidad es banana en neutro y plural."},
{"Hudson", "Suele haber barrios privados como ABRIL. Pertenece a Berazategui. "},
{"Pereyra", "Pertenece a Berazategui, aqui se encuentra el Parque Provincial ******* Iraola."},
{"VillaElisa", "Pertenece al partido de La Plata, tiene aguas termales."},
//{"CityBell", "El gentilicio de la gente que vive en este lugar es Citibelino"},
//{"Gonnet", "Su nombre viene del primer Ministro de Obras Publicas de la provincia."}, 
{"Ringuelet", "Ringue + (dejar en ingles)"},
//{"Tolosa", "Pertenece al partido de la plata, y tiene muchos monumentos como:" "Al Gaucho, el Reloj Solar, Monumento a la madre, etc."}
};

Tren MiTren;


Persona persona_01 (10,2);
Persona persona_02 (4,8);
Persona persona_03 (15,10);

void descontento();
void salirJuego();
void setup();
void input();
void update();
void draw ();
void perdiste ();

enum direcciones
{
DETENIDO,
IZQUIERDA,
DERECHA,
ABAJO,
ARRIBA

};
direcciones direccion;


bool salirMenu;
bool start;
bool instrucciones;
bool mini = false;

void inMenu();
void startJuego();
void instruccionesJuego();
void dibujo();



int main ()
 {
     srand (time (0));
     int eleccion = (rand () % cantidadParadas);

     string lasParadas = paradasRoca [eleccion] [PARADA];
     string laAyuda = paradasRoca [eleccion] [AYUDA];

     string paradaRandom = lasParadas;

    int cantidadCaracteresParada = paradaRandom.size();
    

for (int i = 0; i < cantidadCaracteresParada; i ++)
   {
       int index1 = (rand () % cantidadCaracteresParada );
       int index2 = (rand () % cantidadCaracteresParada );

        char auxiliar = paradaRandom [index1] = paradaRandom [index2];
        paradaRandom [index2] = auxiliar ;
   }
     
    cout<<R"(                      MMMMMMMMMMMMMMMMMMMMW0o;,,cxXMMMMMMMMMMMMMMMMMMMMM
                      MMMMMMMMMMMMMMMMMMMNOd:''',lxXWMMMMMMMMMMMMMMMMMMM
                      MMWWMMMMMMMMMMMMMMXko;;xOkl,cd0WMMMMMMMMMMMMWWWMMM
                      MMMMMMMMMMMMMMMMMXxl,;kXXXKl,:oOWMMMMMMMMMMMMMMMMM
                      MMMMMMMMMMMMMMMMKdc';kXXXXXKo';oONMMMMMMMMMMMMMMMM
                      MMMMMMMMMMMMMMW0o:':OX0kkkOKKd,,lkNMMMMMMMMMMMMMMM
                      MMMMMMMMMMMMMWOo;.:0XKl''.;kXXx,'cxXMMMMMMMMMMMMMM
                      MMMMMMMMMMWMNkl,.lKXXKl...,xXXXk,.:dKWMMMMMMMMMMMM
                      MMMMMMMMMMMNkl,,dKXXXKc...'xXXXXO:':dKWWMMMMMMMMMM
                      MMMMMMMWWMXxc''xXXXXNKc.. 'kXXXXX0c.;oOWMMMMMMMMMM
                      MMMMMMMMWKd:.'xXXXXXXXo.  ,OXXXXXXKc.,lkNMMMMMMMMM
                      MMMMMMMW0o;.,kXXXXXXXXd.  ;0XXXXXXXKl.'cxXMMMMMMMM
                      MMMMMMWOl,.;OXXXXXXXXXk'  cXXXXXXXXXKd..:dXWMMMMMM
                      MMMMMWkc,.:0XXXXXXXXXX0;.'oXXXXXXXXXXXx'.:dKMMMMMM
                      MMMMNkc'.lKXXXXXXXXNXXXOkOKNXXXXXXXXXXXk,.;oKMMMMM
                      MMMXxc..oKXXXXXXXXXXXXkllld0XXXXNXXXXXXXO;.:o0WMMM
                      MWXd:.'xXXXXXXXXXXXXXK:   .dXXXXXXXXXXXXX0c.;oONMM
                      WKo;.,kXXXXXXXXXXXXXXXxllco0XXXXXXXXXXXXXXKl.'ckNM
                      Ko;. ;lllllllllllllllllllllllllllllllllllllc. 'ckW)"<<endl;
cout<<R"(     __      _______ _____  _    _  _____   _____  ______ _______ ______ _____ _______ ______ _____  
     \ \    / /_   _|  __ \| |  | |/ ____| |  __ \|  ____|__   __|  ____/ ____|__   __|  ____|  __ \ 
      \ \  / /  | | | |__) | |  | | (___   | |  | | |__     | |  | |__ | |       | |  | |__  | |  | |
       \ \/ /   | | |  _  /| |  | |\___ \  | |  | |  __|    | |  |  __|| |       | |  |  __| | |  | |
        \  /   _| |_| | \ \| |__| |____) | | |__| | |____   | |  | |___| |____   | |  | |____| |__| |
         \/   |_____|_|  \_\\____/|_____/  |_____/|______|  |_|  |______\_____|  |_|  |______|_____/ )"<<endl;
  cout<<endl;
    cout << "                                               ATENCION"<<endl;
    cout << "                        No podras salir de esta interfaz hasta responder."<<endl;
    cout<< "                Pero, ya que una persona que se toma el tren, debe saber a dónde va..."<<endl;
    cout <<"                      Mientras veias el cartel de estaciones, se desconfiguró "<<endl;
    cout <<"            Y estan las letras desordenadas... Debes responder correctamente para seguir."<<endl;
    cout <<"               Las estaciones son del ramal <<Constitución - La Plata>>, sin incluirlos..."<<endl;
    cout<<endl;
    cout <<"Escribe 'ayuda' para obtener una pista y recuerda escribir con las mayusculas correspondientes y sin espacios."<<endl;
    cout <<"La estacion es: " <<paradaRandom <<endl;

string solucion;


   
   while(!mini)
   { 
    cout<<"Tu respuesta: ";
    cin>> solucion;

    if(solucion == lasParadas )
    {
        cout<<"Buen viaje!"<<endl;
        mini = TRUE;
        salir = TRUE;



    }
    else if (solucion == "ayuda")
    {
        cout << laAyuda << endl;
        cout<<endl;
    }
    
    
    else {
        cout<<"Prueba de nuevo.."<<endl;
        mini = FALSE;
    }
   }
system ("clear");
initscr ();
noecho();
curs_set (FALSE);
keypad (stdscr, TRUE);
nodelay (stdscr, TRUE);

if(LINES < ALTO || COLS < ANCHO){
endwin();
printf("La terminal tiene que tener como mìnimo %d%d\n\n", ANCHO, ALTO);
exit (1);
}
if (has_colors()== FALSE)
{
endwin ();
printf("Tu terminal no soporta color\n");
exit (1);

}

setup();

salir = false;

while (!salir) {

    while(!salirMenu)
    {
inMenu();
dibujo();
startJuego ();
instruccionesJuego ();
minijuego ();
    }

while(!game_over && !mini)
{    
input ();
update();
draw();
}

if (game_over)
{

perdiste();

}

}

endwin();

cout << endl;
return 0;
}

void dibujo(){

erase ();
box (stdscr, 0, 0);
mvprintw (7,38,"_/_/_/_/_/  _/_/_/    _/_/_/_/  _/      _/  ");
mvprintw (8,38,"   _/      _/    _/  _/        _/_/    _/   ");
mvprintw (9,38,"  _/      _/_/_/    _/_/_/    _/  _/  _/    ");
mvprintw (10,38," _/      _/    _/  _/        _/    _/_/     ");
mvprintw (11,38,"_/      _/    _/  _/_/_/_/  _/      _/      ");
mvprintw (12,38,"                                            ");
mvprintw (13,36,"    _/_/_/      _/_/      _/_/_/    _/_/    ");
mvprintw (14,36,"   _/    _/  _/    _/  _/        _/    _/   ");
mvprintw (15,36,"  _/_/_/    _/    _/  _/        _/_/_/_/    ");
mvprintw (16,36," _/    _/  _/    _/  _/        _/    _/     ");
mvprintw (17,36,"_/    _/    _/_/      _/_/_/  _/    _/      ");

mvprintw (25,45,"1. Start");
mvprintw (26,45,"2. Instrucciones");
mvprintw (27,45,"3. Salir");
mvprintw (28,45,"4. Metáfora artística");

mvprintw (14,80,"         ....S:t;t;tt;tt;tt;t;t.:.. ... 8;;t;;t;tt;t;;t;tt;:... .. .. .    ");
mvprintw (15,80,"  . ...      XS                .8       @8                 t          .  . ");
mvprintw (16,75,"  .     .  ttttttt8tSSSSSttttttttttX8tX@@@@SSX;tSSSSSSSSSSSXXX@8tX@@@@@@@SS .  ");
mvprintw (17,75,"     ...tX8@.8S;..S:;;    @:ttttttttttttttttttttttttttttttttttttttttttt;@;8. .  ");
mvprintw (18,75,"  . . ;8@ :......88:Sttttt8S8 % .;ttt;: .X ;;ttttt. S@S%t;ttt@X  .     ...8t: . ");
mvprintw (18,75,"  .  ttt.. . . %.t .  ..  8 t;88@8@8@:  %88@8@8t:.: 8 .. .. ttt . .   . 8%:     ");
mvprintw (20,75," .. @tttt.. : . %.t .   . ttttt. . .tt  tt.. . .S. ; X .   ..ttt     . . 8%: .  ");
mvprintw (21,75,"  . ttt  8 . . : %.t . . .  8.X8 ... Xt. @@.....%;. : @..  .. ttt . .   : 8t: . ");
mvprintw (22,75," . ttt. 8 . : . %.t .   . tttttttttttttttttttttttt : X .   . ttt .   . ..8%:    ");
mvprintw (23,75,". ;tttttt . . : %.t .  ..  8:ttttttttt..ttttttttt  ; @ . . : ttt .     . 8X;..  ");
mvprintw (24,75," . ;tttttttt . . %.t .   . S@.. .......   .....   . : X .   . ttt   .  .. 8t:   ");
mvprintw (25,75,"   t8tXt:;; .  : t.X .   .  8. .         .     .  . : @ ..  : ttt .     . 8%: . ");
mvprintw (26,75," . ttttttt ......t.%...... S@............ ..... ....t 8.......X;;.........8t: . ");
mvprintw (27,75,". t88t@%@tX@@@@@8XStX@@@@@XXtX@@@@X@@@@@@@@@X@@@@@@8tS@@@@@@@8XSX@@@@@@@@S8t . ");
mvprintw (28,75,"   ;;8:.: ::;:;:;  .::;:;:; .::;:::;:::;:;:;:::;:;:;  ;:;:;:;  .:::;:;:;:.8;;   ");
mvprintw (29,75," . tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt . ");
mvprintw (30,75," . 8t@XXXXXStXXXXtStSX@XStttXX@X@X@X@X@X@X@X@SXX@X@tSStXXXXtttSX@XStXXXXS%@..   ");
mvprintw (31,75,"   .ttt.....tttttttttt   tttttt S t S t S t S S t S ttttt: ttttt   tt....tt     ");
mvprintw (32,75," .  . ......:ttttttt.8 8.8S:.8..::::;:::::::::::::;ttttttttt :ttttttt..... .  . ");
mvprintw (33,75,"     .    .   :tttt.  tttt  ..::;:;:;;:;;:;:;:;:;;;:    tttt   ttttt  .   .  .  ");
mvprintw (34,75,"   .    .        .     ..   .  .  . .  .  . . . .   .    .  .    .. .    .      ");



refresh();
delay_output (DELAY);
}

void salirJuego()
{
salirMenu = TRUE;
salir = TRUE;
}

void inMenu ()
{
int opciones = getch();

switch (opciones)
{
case '1':
    start = TRUE;
    break;
case '2':
    instrucciones = TRUE;
    break;
case '3':
    salir=TRUE;
    game_over = TRUE;
    salirMenu = TRUE;
    break;
case '4':
    mini = TRUE;
    break;
default:
    break;
}
}


void startJuego()
{
while (start == TRUE)
{

for (int y = 10; y < 16; y++) mvhline (y , 40, ' ',40);

 mvaddch(9, 39, ACS_CKBOARD);
 mvaddch(9, 80, ACS_CKBOARD);
 mvaddch(16, 39, ACS_CKBOARD);
 mvaddch(16, 80, ACS_CKBOARD);
    
 mvhline(9, 40, ACS_CKBOARD, 40);
 mvhline(16, 40, ACS_CKBOARD, 40);

 mvvline(10, 39, ACS_CKBOARD, 6);
 mvvline(10, 80, ACS_CKBOARD, 6);
mvprintw ( 11,48, "¿Desea comenzar a jugar?");
mvprintw ( 13,59, "S/N");

int comenzar = getch();
if(comenzar == 'S' || comenzar == 's')
{
salirMenu = true;
start= false;
instrucciones =false;
comenzar = false; 
}

else if ( comenzar == 'n' || comenzar == 'N')
{
comenzar = FALSE;
start = FALSE;
salirMenu = FALSE;
game_over = FALSE; 
}

}
refresh();
}

void instruccionesJuego()
{

while (instrucciones == true)
{
  
   for (int z = 4; z < 21; z++) 
   mvhline (z , 15, '  ',87);

 mvaddch(4, 15, ACS_CKBOARD);
 mvaddch(5, 100, ACS_CKBOARD);
 mvaddch(20, 15, ACS_CKBOARD);
 mvaddch(20, 100, ACS_CKBOARD);
    
 mvhline(4, 15, ACS_CKBOARD, 86);
 mvhline(20, 15, ACS_CKBOARD, 86);

 mvvline(5, 15, ACS_CKBOARD, 15);
 mvvline(5, 100, ACS_CKBOARD, 15);


  mvprintw(8,17,"    El jugador debe manejar el tren con las flechas (ARRIBA, ABAJO, IZQUIERDA,");
  mvprintw(9,17,"DERECHA), y recoger con la locomotora a los pasajeros.");
  mvprintw(10,17,"    El jugador, tiene un lìmite de pasajeros marcado en la esquina superior ");
  mvprintw(11,17,"derecha, que si llega a la palabra FIN, perderá automáticamente.");
  mvprintw(12,17,"Para que esto no suceda, debe ir al ANDEN |   |y con la letra 'd', descargar gente.");
  mvprintw(13,17,"Aclaración: no mantener apretada la 'd', o perderá.");
  mvprintw(14,17,"ABORDEEEEN !!!");
  mvprintw(17,45,"¿Desea volver atrás?");
  mvprintw(18,54,"a/A");

int atras = getch();
if  (atras == 'A' || atras == 'a')
{
    instrucciones = FALSE;
}
}refresh ();
};

void minijuego ()
{  

while (mini == true)
{
  
   for (int j = 4 ; j < 30; j++) 
   mvhline (j , 15, ' ',90);

mvaddch(4, 20, ACS_CKBOARD);
mvaddch(4, 105, ACS_CKBOARD);
mvaddch(30, 20, ACS_CKBOARD);
mvaddch(30, 105, ACS_CKBOARD);
    
 mvhline(4, 15, ACS_CKBOARD, 90); //arriba
 mvhline(30, 15, ACS_CKBOARD, 90); //abajo

 mvvline(5, 15, ACS_CKBOARD, 25); //costados
 mvvline(5, 105, ACS_CKBOARD, 25);

mvprintw(6,25,"'Para Proust, la tabla horaria de la estación era la materialización de lo");
  mvprintw(7,29,"inevitable. Esta segun su razonamiento, introduce una precisión que ");
  mvprintw(8,30,"previamente no molesta a nadie, pero llegado el momento impone la ");
  mvprintw(9,31,"valorización de la más insignificante porción de tiempo.");
  mvprintw(10,35,"Ya no sólo valen las horas. También los minutos.'");
mvprintw(11,45,"-Marcel Proust (1871-1922)");
  mvprintw(14,18,"La temporalidad narrativa planteada por Proust, se define como: 'Una epoca de prisas',");
  mvprintw(15,18,"en la que el arte seria breve. El mundo se sofoca. La epoca de las prisas para Proust");
  mvprintw(16,18,"es la del ferrocarril que,  segun el,  mata a cualquier <contemplacion>.  La critica ");
  mvprintw(17,18,"epocal  de Proust  tambien se puede aplicar a cualquier epoca  <cinematografica>,  en");
  mvprintw(18,18,"la que la  realidad se descompone en  una veloz sucesion de imagenes.   La estrategia");
  mvprintw(19,18,"temporal  frente a esta epoca  de prisas consiste en ayudar que  el tiempo  recupere ");
  mvprintw(20,18,"su duracion.");
  
  mvprintw (22,18,"La propuesta de este juego, es reflejar como ponemos muchas veces el tiempo ");
  mvprintw (23,18,"en automatico: En esta época acelerada, donde hacemos las cosas meramente por");
  mvprintw (24,18,"inercia y no paramos a pensar en las circunstancias que nos rodean.");
  mvprintw (26,18,"Fuente:");
  mvprintw (27,18,"Byung-Chul Han - El aroma del tiempo. (pg. 67)");
  mvprintw(29,53,"¿Desea volver? v/V");

int volver = getch();
if  (volver == 'v' || volver == 'V')
{
    mini = FALSE;
    
}}
refresh ();
};


void setup()
{
game_over= false;
salirMenu = false;
start = false;
instrucciones = false;
mini = false;

MiTren.setup();

direccion = DETENIDO;

MiTren.setup();

x= ANCHO / 2;
y=ALTO/2;
srand (time(NULL));

x_persona = (rand () % (ANCHO -3)) +2;
y_persona = (rand () % (ALTO - 3)) +2;



}



void input()
{
int tecla = getch();


    
    switch (tecla)
    {        
    case KEY_UP:
        if (MiTren.getY() > 1) MiTren.setY(MiTren.getY() - 1);
        break;
    case KEY_DOWN:
        if (MiTren.getY() < ALTO - 4) MiTren.setY(MiTren.getY() + 1);
        break;
    case KEY_LEFT:
        if (MiTren.getX() > 1) MiTren.setX(MiTren.getX() - 1);
        break;
    case KEY_RIGHT:
        if (MiTren.getX() < ANCHO - 6)MiTren.setX(MiTren.getX() + 1);
        break;
    case 27:
        game_over = TRUE;
        break;
    case 'd':
        
        if (MiTren.getX() == 42 && MiTren.getY() == 36 ){
                MiTren.RestarPasajeros ();
        }
        break;
    case 'D':
        
        if (MiTren.getX() == 42 && MiTren.getY() == 36 ){
                MiTren.RestarPasajeros ();
        }
        break;
    default:
        break;
    }
}
// 36, 42


void update ()
{

MiTren.update();

if (MiTren.getPasajeros() >= 18 ) game_over = true;

if (MiTren.getLimite() >= 18) game_over = true;


persona_01.update();
persona_02.update();
persona_03.update();

persona_01.colision(MiTren);
persona_02.colision(MiTren);
persona_03.colision(MiTren);

switch (direccion)
{
case ARRIBA:
    y--;
    break;
case ABAJO:
    y++;
    break;
case IZQUIERDA:
    x--;
    break;
case DERECHA:
   x++;
   break;
default:
    break;
}

if (x >= ANCHO - 1 || x <= 0 || y >= ALTO - 1 || y <= 0)
        game_over = TRUE;

}



void draw()
{



erase ();
box (stdscr, 0, 0);
MiTren.draw();

mvprintw(0,80, "[Capacidad: 2 4 6 8 10 12 14 FIN ]");
//mvprintw(0,5, "[Descontento: |  |  |  |  |  |   |]");
mvprintw (20,0, "                                                   ");
mvprintw (21,0, "                 SXXXXXS:                          ");
mvprintw (22,0, "                ;Xtt%tt;;                          ");
mvprintw (23,0, "               .tt:888.@:8888888X:                 ");
mvprintw (24,0, "               .8X8   S;......:;8t.S               ");
mvprintw (25,0, "             .:;.@tSSS:..  .    88X88           |  ");
mvprintw (26,0, "            ;S 8:8888888.    .8 @;.% ;:         |  ");
mvprintw (27,0, "          t;.X        .  . :@ @. 8:8 8:@.       |  ");
mvprintw (28,0, "         8X8  ..    .     tt;.8S8:t@8 .;:.      |  ");
mvprintw (29,0, "       .t t .    .     .%;:@tt8X8%@t.:::S.;     |  ");
mvprintw (30,0, "        X.tX8888888888;;t%  ::t@%.t  @;XS:8      |  ");
mvprintw (31,0, "          :.;:;;;;;;;X8:   .   : .  . 8S:8.     |  ");
mvprintw (32,0, "           t t;S8X.X X8. .  .S88S..  .8S        V ");
mvprintw (33,0, "           ; X tSX:t 8S   .X.8%@S.t.  8X ");
mvprintw (34,0, "           ;;8.tXSt8;8%.  S8: .88.X8 .8S     ANDEN   ");
mvprintw (35,0, "           ;8;.....t88%  .8t   X8;:t  8X ");
mvprintw (36,0, "         .88@8$$S$$$$88$$$$X$$$$$$$$S8;8 |              |");
mvprintw (37,0, "           .@8tttttttt:t8t;;ttttt8:888:8888ttt8888@tttt8    ");
mvprintw (38,0, "           .@8tttttttt:t8t;;ttttt8:888:8888ttt8888@tttt8    ");
mvprintw (39,0, "                                                  ");

for (int i= 0; i < MiTren.getPasajeros(); i ++)
{
mvaddch ( 0, 91 + i, ACS_CKBOARD);
}







MiTren.draw();
persona_01.draw();
persona_02.draw();
persona_03.draw();


refresh ();
delay_output (DELAY);
}

void perdiste ()
{
for (int y = 10; y < 16; y++) mvhline (y , 40, ' ',40);
{
 mvaddch(9, 39, ACS_ULCORNER);
 mvaddch(9, 80, ACS_URCORNER);
 mvaddch(16, 39, ACS_LLCORNER);
 mvaddch(16, 80, ACS_LRCORNER);
    
 mvhline(9, 40, ACS_HLINE, 40);
 mvhline(16, 40, ACS_HLINE, 40);

 mvvline(10, 39, ACS_VLINE, 6);
 mvvline(10, 80, ACS_VLINE, 6);

mvprintw(12, 55, "PERDISTE");
mvprintw(13, 50, "DESEA VOLVER A JUGAR? (S/N)");

    int opcion = getch();
    
    if (opcion == 's' || opcion == 'S')
    {
        game_over = false;
        setup();
    }
    else if (opcion == 'n' || opcion == 'N')
    {
        salir = TRUE;
    }
    
}
}







