#include <conio.h>
#include "Alien.h"
#include <iostream>
#include <stdio.h>

//Nota Si el programa se quiere correr en Linux es necesario comentar la linea 1
// y descomentar los includes y funciones a continuaricón.

/*#include <termios.h>
#include <unistd.h>

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}*/

/* Proyecto Alien Attack
 * Imanol Muñiz Ramirez
 * A01701713
 * 01/12/22
 *
 */

using namespace std;
//Firmas de funciones. Abajo en su definición se describe que hacen
//Funcion que da la bienvenida al jugador
void bienvenida();
//Funcion que imprime las instrucciones del juego
void instructions();
//Funcion que manda crear cerebros
Brain creaBrain(float);
//Funcion que muestra y maneja la tienda de armas
Alien store(Alien);

/* Código principal que controla el manejo de clases y funciones
 *
 * @parametro
 * @return int: termino exitoso del programa
 */
int main(){

    bienvenida();
    instructions();
    //i es la condicion del ciclo while a continuacion
    int i=1;
    //comer la utilizaremos para guardar la desicion del usuario sobre los
    //comer y dejar el cerebro, ir a la tienda o cerrar el juego.
    char comer;
    //ali tipo Alien es creado con composicion de la clase Weapon
    Alien ali(12,1.0,Weapon("Beat",1,'x',0));
    //Ciclo while que nos va estar constantemente mostrando cerebros
    while (i==1){
        //Crea cerebro, manda la suerte de tu alien para retornar un cerebro
        //con inteligencia acorde a la suerte de tu alien
        Brain brain=creaBrain(ali.getLuck());
        //Se imprimen las estadisticas del cerebro
        brain.showAll();
        //Se imprimen las estadisticas de tu alien
        ali.showStats();
        //Se captura la decision del jugador
        comer=getch();
        //Se limpia la consola
        system("cls");
        //Menu de opciones
        if (comer=='e'){
            //Comer cerebro
            ali.eatBrain(brain);
        }
        else if(comer=='l'){
            //No comer
        }
        else if(comer=='s'){
            //Abrir la tienda
            ali=store(ali);
        }
        else if(comer=='q'){
            //Terminar el programa
            i=2;
        }
        else{
            //Default
            cout<<"Command unrecognized, try again\n\n";
        }
    }
    return 0;
}

/* Funcion que da la bienvenida al jugador
 *
 * @parametro
 * @return
 */
void bienvenida(){
cout<<"                          Alien Attack \n\n";
cout<<"     _                      _______                      _\n";
cout<<"  _dMMMb._              .adOOOOOOOOOba.              _,dMMMb_\n";
cout<<" dP'  ~YMMb            dOOOOOOOOOOOOOOOb            aMMP~  `Yb\n";
cout<<" V      ~\"Mb          dOOOOOOOOOOOOOOOOOb          dM\"~      V\n";
cout<<"          `Mb.       dOOOOOOOOOOOOOOOOOOOb       ,dM'\n";
cout<<"           `YMb._   |OOOOOOOOOOOOOOOOOOOOO|   _,dMP'\n";
cout<<"      __     `YMMM| OP'~\"YOOOOOOOOOOOP\"~`YO |MMMP'     __\n";
cout<<"    ,dMMMb.     ~~' OO     `YOOOOOP'     OO `~~     ,dMMMb.\n";
cout<<" _,dP~  `YMba_      OOb      `OOO'      dOO      _aMMP'  ~Yb._\n";
cout<<"\n";
cout<<"             `YMMMM `OOOo     OOO     oOOO'/MMMMP'\n";
cout<<"     ,aa.     `~YMMb `OOOb._,dOOOb._,dOOO'dMMP~'       ,aa.\n";
cout<<"   ,dMYYMba._         `OOOOOOOOOOOOOOOOO'          _,adMYYMb.\n";
cout<<"  ,MP'   `YMMba._      OOOOOOOOOOOOOOOOO       _,adMMP'   `YM.\n";
cout<<"  MP'        ~YMMMba._ YOOOOPVVVVVYOOOOP  _,adMMMMP~       `YM\n";
cout<<"  YMb           ~YMMMM `OOOOI`````IOOOOO'/MMMMP~           dMP\n";
cout<<"   `Mb.           `YMMMb`OOOI,,,,,IOOOO'dMMMP'           ,dM'\n";
cout<<"     `'                  `OObNNNNNdOO'                   `'\n";
cout<<"                           `~OOOOO~'  \n\n";
cout<<"                    Press ENTER to continue \n";
    getch();
    system("cls");
};

/* Funcion que crea cerebros aleatorios que se pueden comer
 *
 * @parametro float luc: suerte del alien que influye en la creación
 * de cerebros mejores
 * @return Brain: cerebro que se puede comer
 */
Brain creaBrain(float luc){
    //Cast
    int enteroLuck=(int)luc;
    //Se calcula la inteligencia del cerebro a crear
    int inte=rand()%(20+enteroLuck)-(10+enteroLuck/2);
    //Se calcula la suerte del cerebro a crear
    float luck=rand()%10;
    //Se calcula la resistencia del cerebro a crear
    int resistence=rand()%10;
    //Se crea el cerebro con el constructor de la clase Brain
    Brain brain(inte,luck,resistence);
    return brain;
};

/* Funcion que imprime y trabaja la tienda
 *
 * @parametro Alien ali: Estado actual del alien
 * @return Alien: Estado del alien al dejar la tienda
 */
Alien store(Alien ali){
    system("cls");
    char opcion;
    //Creamos las opciones de armas
    Weapon arrweapons[9];
    arrweapons[0]=Weapon("Rock",2,'q',20);
    arrweapons[1]=Weapon("Bite",3,'w',60);
    arrweapons[2]=Weapon("Gun",4,'e',100);
    arrweapons[3]=Weapon("Laser",5,'r',150);
    arrweapons[4]=Weapon("Telekinesis",6,'t',200);
    arrweapons[5]=Weapon("U.F.O",7,'y',320);
    arrweapons[6]=Weapon("Planet Invasion",8,'u',450);
    arrweapons[7]=Weapon("God Entity",10,'i',700);
    //El arma 8 la igualamos a nuestra arma actual para despues
    //comparaciones futuras
    arrweapons[8]=ali.getWeapon();
    //Instrucciones y muestra de caracteristicas de tu alien
    cout<<"Get a new weapon\n"<<"Pick the letter next the weapon to buy it with Alien's inteligence\n"<<"Press [x] to get back to the game \n\n";
    ali.showStats();
    //Impresion del menu de aramas
    cout<<"\nRock Damage: 2 [q] "<<"Bite Damage: 3 [w] "<<"Gun Damage: 4 [e] "<<"Laser Damage: 5 [r] \n";
    cout<<"Price: 20          Price: 60          Price: 100        Price: 150\n\n";
    cout<<"Telekinesis Damage: 6 [t] "<<"U.F.O Damage: 7 [y] "<<"Planet Invasion Damage: 8 [u] "<<"God Entity: 10 [i] \n";
    cout<<"Price: 200                Price: 320          Price: 450                    Price: 700\n";
    opcion=getch();
    //Salir de la tienda
    if(opcion=='x'){
        system("cls");
        return ali;
    }
    //Ciclo para verificar si existe un arma con el id marcado
    //por el usuario
    for(int i=0;i<9;i++){
        //Comparacion de Ids
        if(opcion==arrweapons[i].getId()){
            //Comparacion de daños de armas para evitar comprar
            //multiples veces la misma arma
            if(ali.getWeaponDamage()==arrweapons[i].getDamage()){
                cout<<"You already have this weapon. Press ENTER to continue\n";
                getch();
                ali=store(ali);
                break;
            }
            //Evitar comprar armas con menor daño
            else if(ali.getWeaponDamage()>arrweapons[i].getDamage()){
                cout<<"The weapon you already have is better. You can't buy this one. Press ENTER to continue\n";
                getch();
                ali=store(ali);
                break;
            }
            //Si nos alcanza asignar los nuevos valores a nuestro alien
            else if(ali.getInteligence()>=arrweapons[i].getPrice()){
                //El atributo weapon de ali se le asigna una variable tipo Weapon
                //por agragación
                ali.setWeapon(arrweapons[i]);
                ali.setInteligence(ali.getInteligence()-arrweapons[i].getPrice());
                ali.showStats();
                ali.setWeaponId();
                cout<<"Press ENTER to continue\n";
                getch();
                system("cls");
                return ali;
            }
            //Evitar comprar armas que no nos alcance
            else{
                cout<<"You don't have enough inteligence to afford this weapon. Press ENTER to continue\n";
                ali.showStats();
                getch();
                ali=store(ali);
                break;
            }
        }
        //Evitar que el usuario ponga una opcion inexistente
        else if(i==8){
            cout<<"The letter you pressed is not assigned to any weapon in store. Press ENTER to continue\n";
            getch();
            ali=store(ali);
            break;
        }
    }
    system("cls");
    //Retornar un alien con el nuevo armamento
    return ali;
};

/* Función que imprime las instrucciones del manejo del programa
 *
 * @parametro
 * @return
 */
void instructions(){
    //Imprimir instrucciones
    cout<<"Instructions\n\n";
    cout<<"Eat Brains to gain stats\n";
    cout<<"Be careful, there are brains that will damage yours\n";
    cout<<"You can only eat the brains which have less resistence than your weapon's damage\n";
    cout<<"You can earn inteligence and luck, with inteligence you can ugpgrade your weapons\n";
    cout<<"With luck there will appear better barins\n";
    cout<<"Press [e] to eat, [l] to leave, [s] to visit the store or [q] to quit the game.\n";
    cout<<"Press ENTER to continue\n";
    getch();
    system("cls");
}

