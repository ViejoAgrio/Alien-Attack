#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#include <iostream>
/* Proyecto Alien Attack
 * Imanol Muñiz Ramirez
 * A01701713
 * 01/12/22
 *
 */

 /* Clase Ser tiene los métodos genericos para el manejo de seres
  * tiene 2 clases que son especializaciones de seres:
  * Alien y Brain
  *
  *
  */

//Definicion clase Ser
class Ser{
protected:
    int inteligence;
    float luck;
public:
    //Constructores
    Ser(){};
    Ser(int, float);
    //Getters
    int getInteligence();
    float getLuck();
    //Setters
    void setInteligence(int);
    void setLuck(float);
};

//Definicion clase Weapon
class Weapon{
private:
    std::string name;
    int damage;
    char id;
    int price;
public:
    //Constructores
    Weapon();
    Weapon(std::string, int,char,int);
    //Getters
    std::string getWeaponname();
    int getDamage();
    char getId();
    int getPrice();
    //Setter
    void setId();
};

//Definicion clase Brain con herencia de clase Ser
class Brain:public Ser{
private:
    int resistence;
public:
    //Constructores
    Brain();
    Brain(int,float,int);
    //Getters
    int getResistence();
    //Metodos particulares
    void showAll();
};

//Definicion clase Alien con herencia de clase Ser
class Alien:public Ser{
private:
    Weapon weapon;
public:
    //Constructores
    Alien();
    Alien(int,float,Weapon);
    //Getters
    std::string getWeaponName();
    int getWeaponDamage();
    int getWeaponId();
    Weapon getWeapon();
    //Setters de clase que compone a la clase Alien con sobrecarga
    void setWeapon(std::string,int,char,int);
    void setWeapon(Weapon);
    //Metodos particulares de la clase
    void eatBrain(Brain);
    void showStats();
    void setWeaponId();
    void muerte();
};
//Definicion constructores clase Ser

/* Constructor que recibe valores para llenar los valoes instancia
 *
 * @parametro int inte: numero de inteligencia del ser, float luck: numero de suerte que tiene el ser
 *
 * @return Objeto empleado
 */

Ser::Ser(int inte, float luc){
    inteligence=inte;
    luck=luc;
};
//Definicion getters clase Ser

/* Getter inteligence
 *
 * @parametro
 *
 * @return int numero de inteligencia del ser
 */
int Ser::getInteligence(){
    return inteligence;
};

/* Getter luck
 *
 * @parametro
 *
 * @return float numero de suerte del ser
 */
float Ser::getLuck(){
    return luck;
};
//Definicion setters clase Ser

/* Setter inteligence
 *
 * @parametro int: inteligencia del ser
 *
 * @return
 */
void Ser::setInteligence(int inte){
    inteligence=inte;
};

/* Setter Luck
 *
 * @parametro int: suerte del ser
 *
 * @return
 */
void Ser::setLuck(float luc){
    luck=luc;
};

/* Constructor que recibe valores para llenar los valoes instancia
 *
 * @parametro int inte: numero de inteligencia del ser, float luck: numero de suerte que tiene el ser
 *
 * @return Objeto empleado
 */

//Definicion constructores clase Weapon

/* Constructor por default
 *
 * @parametro
 *
 * @return Objeto empleado
 */
Weapon::Weapon(){
    name="";
    damage=0;
    id='g';
    price=0;
};
/* Constructor que recibe valores para llenar los valoes instancia
 *
 * @parametro string nam: nombre del arma, int dam: daño del arma
 * char idd: identificador del arma en la tienda, int pri: precio
 * @return Objeto empleado
 */
Weapon::Weapon(std::string nam, int dam, char idd, int pri){
    name=nam;
    damage=dam;
    id=idd;
    price=pri;
};
//Definicion getters clase Weapon

/* Getter inteligence
 *
 * @parametro
 *
 * @return string nombre del arma
 */
std::string Weapon::getWeaponname(){
    return name;
};

/* Getter inteligence
 *
 * @parametro
 *
 * @return int daño del arma
 */
int Weapon::getDamage(){
    return damage;
}

/* Getter inteligence
 *
 * @parametro
 *
 * @return char id del arma de la tienda
 */
char Weapon::getId(){
    return id;
}

/* Getter inteligence
 *
 * @parametro
 *
 * @return int precio del arma en la tienda
 */
int Weapon::getPrice(){
    return price;
}
//NOTA: Para la clase Weapon no utilizare mas que 1 setter pues no se modificara otro atributo una vez creados

//Definicion metodo setId de la clase Weapon

/* Setter id del arma con 'x'
 *
 * @parametro
 *
 * @return
 */
void Weapon::setId(){
    id='x';
}

//Definicion constructores clase Brain

/* Constructor por default
 *
 * @parametro
 *
 * @return Objeto Brain
 */
Brain::Brain(){
    inteligence=0;
    luck=0.0;
    resistence=0;
};
/* Constructor que recibe valores para llenar los valoes instancia
 *
 * @parametro int inte: numero de inteligencia del cerebro, float luc: numero de suerte que tiene el cerebro
 * int res: numero de resistencia del cerebro
 * @return Objeto Brain
 */
Brain::Brain(int inte,float luc,int res){
    inteligence=inte;
    luck=luc,
    resistence=res;
};
//Definicion getters clase Brain
/* Getter resistence
 *
 * @parametro
 *
 * @return int: número de resistencia del cerebro
 */
int Brain::getResistence(){
    return resistence;
};

/* Metodo que muestra en pantalla dibujo y estadisticas del cerebro
 *
 * @parametro
 *
 * @return
 */
void Brain::showAll(){
std::cout<<"A new brain has appeared\n\n";
std::cout<<"    _---~~(~~-_\n";
std::cout<<"    _{        )   )\n";
std::cout<<"  ,   ) -~~- ( ,-' )_\n";
std::cout<<" (  `-,_..`., )-- '_,)\n";
std::cout<<"( ` _)  (  -~( -_ `,  }\n";
std::cout<<"(_-  _  ~_-~~~~`,  ,' )\n";
std::cout<<"  `~ -^(    __;-,((()))\n";
std::cout<<"        ~~~~ {_ -_(())\n";
std::cout<<"               `  }\n";
std::cout<<"                 { } \n\n";
std::cout<<"Inteligence: "<<getInteligence()<<" luck: "<<getLuck()<<" resistence: "<<getResistence()<<"\n";
std::cout<<"Eat or Leave?\n";
};
//NOTA: Para la clase Brain no utilizare setters pues no se modificaran una vez creados


//Definicion constructores clase Alien

/* Constructor default
 *
 * @parametro
 *
 * @return Objeto Alien
 */
Alien::Alien(){
    inteligence=0;
    luck=0;
    weapon=Weapon();
};

/* Constructor que recibe valores para llenar los valoes instancia
 *
 * @parametro int inte: numero de inteligencia del ser, float luck: numero de suerte que tiene el ser
 * Weapon weap arma que posee el Alien
 * @return Objeto Alien
 */
Alien::Alien(int inte, float luc, Weapon weap){
    inteligence=inte;
    luck=luc;
    weapon=weap;
};

//Definicion setters clase Alien

/* Setter weapon
 *
 * @parametro string nam: nombre del arma, int dam: daño del arma
 * char idd: identificador del arma en la tienda, int pri: precio
 * @return
 */
void Alien::setWeapon(std::string nam, int dam,char idd,int pri){
    weapon=Weapon(nam,dam,idd,pri);
};

/* Setter weapon
 *
 * @parametro Weapon weap: arma del alien
 * @return
 */
void Alien::setWeapon(Weapon weap){
    weapon=weap;
};

/* Metodo que asigna 'x' como Id al arma del alien
 *
 * @parametro
 * @return
 */
void Alien::setWeaponId(){
    weapon.setId();
}

//Definicion getters clase Alien
/* Metodo que retorna el nombre del arma del alien
 *
 * @parametro
 * @return string nombre del arma del alien
 */
std::string Alien::getWeaponName(){
    return weapon.getWeaponname();
};

/* Metodo que retorna el daño del arma del alien
 *
 * @parametro
 * @return int: daño del arma del alien
 */
int Alien::getWeaponDamage(){
    return weapon.getDamage();
};

/* Getter Weapon
 *
 * @parametro
 * @return Weapon: arma del alien
 */
Weapon Alien::getWeapon(){
    return weapon;
}

//Definicion metodo eatBrain de clase Alien

/* Metodo que determina que sucede cuando se intenta comer un cerebro
 *
 * @parametro Brain bra: cerebro que se intenta comer
 * @return string nombre del arma del alien
 */
void Alien::eatBrain(Brain bra){
    if (bra.getResistence()<=weapon.getDamage()){
        setInteligence(getInteligence()+bra.getInteligence());
        setLuck(getLuck()+bra.getLuck()*0.05);
    }
    else{
        setInteligence(getInteligence()-10);
        std::cout<<"You couldn't eat this brain\n\n";
        if (getInteligence()<1){
            muerte();
        }
    }
};

//Definicion metodo showStats de clase Alien
/* Metodo que escribe en pantalla todos los atributos del Alien
 *
 * @parametro
 * @return
 */
void Alien::showStats(){
    std::cout<<"These are your alien new stats: \n";
    std::cout<<"Inteligence: "<<getInteligence()<<". Luck: "<<getLuck()<<". Weapon: "<<getWeaponName()<<". Damage: "<<getWeaponDamage()<<".\n";
};

//Definicion metodo muerte de clase Alien
/* Metodo que termina el programa cuando el alien muere
 *
 * @parametro
 * @return
 */
void Alien::muerte(){
    std::cout<<"Your Alien died\n";
    exit(1);
};


#endif // ALIEN_H_INCLUDED

