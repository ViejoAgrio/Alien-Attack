#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#include <iostream>

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
public:
    //Constructores
    Weapon();
    Weapon(std::string, int);
    //Getters
    std::string getWeaponname();
    int getDamage();
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
    int getWeaponId();
    //Setters de clase que compone a la clase Alien con sobrecarga
    void setWeapon(std::string,int);
    void setWeapon(Weapon);
    //Metodos particulares de la clase
    void eatBrain(Brain);
    void upgradeWeapon(Weapon&);
    void muerte();
};
//Definicion constructores clase Ser
Ser::Ser(int inte, float luc){
    inteligence=inte;
    luck=luc;
};
//Definicion getters clase Ser
int Ser::getInteligence(){
    return inteligence;
};

float Ser::getLuck(){
    return luck;
};
//Definicion setters clase Ser
void Ser::setInteligence(int inte){
    inteligence=inte;
};

void Ser::setLuck(float luc){
    luck=luc;
};

//Definicion constructores clase Weapon
Weapon::Weapon(){
    name="";
    damage=0;
};

Weapon::Weapon(std::string nam, int dam){
    name=nam;
    damage=dam;
};
//Definicion getters clase Weapon
std::string Weapon::getWeaponname(){
    return name;
};

int Weapon::getDamage(){
    return damage;
}
//NOTA: Para la clase Weapon no utilizare setters pues no se modificaran una vez creados

//Definicion constructores clase Brain
Brain::Brain(){
    inteligence=0;
    luck=0.0;
    resistence=0;
};

Brain::Brain(int inte,float luc,int res){
    inteligence=inte;
    luck=luc,
    resistence=res;
};
//Definicion getters clase Brain
int Brain::getResistence(){
    return resistence;
};
//NOTA: Para la clase Brain no utilizare setters pues no se modificaran una vez creados

//Definicion constructores clase Alien
Alien::Alien(){
    inteligence=0;
    luck=0;
    weapon=Weapon();
};

Alien::Alien(int inte, float luc, Weapon weap){
    inteligence=inte;
    luck=luc;
    weapon=weap;
};

//Definicion setters clase Alien
void Alien::setWeapon(std::string nam, int dam){
    weapon=Weapon(nam,dam);
};

void Alien::setWeapon(Weapon weap){
    weapon=weap;
};

//Definicion getters clase Alien
std::string Alien::getWeaponName(){
    return weapon.getWeaponname();
};

//Definicion metodo eatBrain de clase Alien
void Alien::eatBrain(Brain bra){
    if (bra.getResistence()<=weapon.getDamage()){
        setInteligence(getInteligence()+bra.getInteligence());
    }
    else{
        setInteligence(getInteligence()-10);
        std::cout<<"You couldn't eat this barin";
        if (getInteligence()<1){
            muerte();
        }
    }
};

/*void Alien::upgradeWeapon(Weapon &weaponArray){
    setWeapon(weaponArray);
    setInteligence(getInteligence()-getWeaponId());
};*/

//Definicion metodo muerte de clase Alien
void Alien::muerte(){
    std::cout<<"Your Alien died";
};

#endif // ALIEN_H_INCLUDED
