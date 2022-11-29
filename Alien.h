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
    //Metodos particualares de la clase
    void restar1Damage();
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
    id='g';
    price=0;
};

Weapon::Weapon(std::string nam, int dam, char idd, int pri){
    name=nam;
    damage=dam;
    id=idd;
    price=pri;
};
//Definicion getters clase Weapon
std::string Weapon::getWeaponname(){
    return name;
};

int Weapon::getDamage(){
    return damage;
}

char Weapon::getId(){
    return id;
}

int Weapon::getPrice(){
    return price;
}
//NOTA: Para la clase Weapon no utilizare setters pues no se modificaran una vez creados

//Definicion metodo setId de la clase Weapon
void Weapon::setId(){
    id='x';
}

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
void Alien::setWeapon(std::string nam, int dam,char idd,int pri){
    weapon=Weapon(nam,dam,idd,pri);
};

void Alien::setWeapon(Weapon weap){
    weapon=weap;
};

//Definicion getters clase Alien
std::string Alien::getWeaponName(){
    return weapon.getWeaponname();
};

int Alien::getWeaponDamage(){
    return weapon.getDamage();
};
Weapon Alien::getWeapon(){
    return weapon;
}

//Definicion metodo eatBrain de clase Alien
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

//Definicion metodo muerte de clase Alien
void Alien::showStats(){
    std::cout<<"These are your alien new stats: \n";
    std::cout<<"Inteligence: "<<getInteligence()<<". Luck: "<<getLuck()<<". Weapon: "<<getWeaponName()<<". Damage: "<<getWeaponDamage()<<".\n";
};

void Alien::setWeaponId(){
    weapon.setId();
}

void Alien::muerte(){
    std::cout<<"Your Alien died\n";
    exit(1);
};

#endif // ALIEN_H_INCLUDED
