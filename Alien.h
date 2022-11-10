#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#include <iostream>

class Human_brain{
private:
    int resistance;
    int level;
    int inteligence;

public:
    Human_brain() : resistance(0), level(0), inteligence(0){};
    Human_brain(int res, int lev, int inte):resistance(res), level(lev), inteligence(inte){};

    int get_resistance();
    int get_level();
    int get_inteligence();

    void set_resistance(int);
    void set_level(int);
    void set_inteligence(int);

    void show_all();
};

int Human_brain::get_resistance(){
    return resistance;
}
int Human_brain::get_level(){
    return level;
}
int Human_brain::get_inteligence(){
    return inteligence;
}


void Human_brain::set_resistance(int new_resistance){
    resistance=new_resistance;
}

void Human_brain::set_level(int new_level){
    level=new_level;
}

void Human_brain::set_inteligence(int new_inteligence){
    inteligence=new_inteligence;
}

void Human_brain::show_all(){
    std::cout<<"Resistance "<<resistance<<"\n";
    std::cout<<"Level "<<level<<"\n";
    std::cout<<"Inteligence "<<inteligence<<"\n";
}

class Alien{
private:
    int strenght;
    int luck;
    int inteligence;
    std::string name;

public:
    Alien() : strenght(0), luck(0), inteligence(0), name(""){};
    Alien(int stren, int luc, int inte, std::string nam):strenght(stren), luck(luc), inteligence(inte), name(nam){};

    int get_strenght();
    int get_luck();
    int get_inteligence();
    std::string get_name();

    void set_strenght(int);
    void set_luck(int);
    void set_inteligence(int);
    void set_name(std::string);

    void eat_brain();
};

int Alien::get_strenght(){
    return strenght;
}
int Alien::get_luck(){
    return luck;
}
int Alien::get_inteligence(){
    return inteligence;
}

std::string Alien::get_name(){
    return name;
}

void Alien::set_strenght(int new_strenght){
    strenght=new_strenght;
}

void Alien::set_luck(int new_luck){
    luck=new_luck;
}

void Alien::set_inteligence(int new_inteligence){
    inteligence=new_inteligence;
}

void Alien::set_name(std::string new_name){
    name=new_name;
}

class Weapon{
private:
    int damage;
    int inteligence_cost;
    std::string name;

public:
    Weapon(): damage(0), inteligence_cost(0), name(""){};
    Weapon(int dam, int inte, std::string nam):damage(dam), inteligence_cost(inte), name(nam){};

    int get_damage();
    int get_inteligence_cost();
    std::string get_name();

    void set_damage(int);
    void set_inteligence_cost(int);
    void set_name(std::string);
};

int Weapon::get_damage(){
    return damage;
}
int Weapon::get_inteligence_cost(){
    return inteligence_cost;
}

std::string Weapon::get_name(){
    return name;
}

void Weapon::set_damage(int new_damage){
    damage=new_damage;
}

void Weapon::set_inteligence_cost(int new_inteligence_cost){
    inteligence_cost=new_inteligence_cost;
}

void Weapon::set_name(std::string new_name){
    name=new_name;
}
#endif // ALIEN_H_INCLUDED
