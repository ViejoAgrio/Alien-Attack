#include <iostream>
#include "Alien.h"

using namespace std;

int main(){
    Alien marciano(5,4,3,"Marcian");
    cout<<marciano.get_strenght()<<"\n";
    cout<<marciano.get_luck()<<"\n";
    cout<<marciano.get_inteligence()<<"\n";
    cout<<marciano.get_name()<<"\n";
    marciano.set_strenght(1);
    marciano.set_luck(1);
    marciano.set_inteligence(1);
    marciano.set_name("Pedro");
    cout<<marciano.get_strenght()<<"\n";
    cout<<marciano.get_luck()<<"\n";
    cout<<marciano.get_inteligence()<<"\n";
    cout<<marciano.get_name()<<"\n";
    Human_brain brain1(1,2,3);
    brain1.show_all();
    Weapon weapon1(3,1,"Knife");
    cout<<weapon1.get_damage()<<"\n";
    cout<<weapon1.get_inteligence_cost()<<"\n";
    cout<<weapon1.get_name()<<"\n";
    weapon1.set_damage(3);
    weapon1.set_inteligence_cost(0);
    weapon1.set_name("rock");
    cout<<weapon1.get_damage()<<"\n";
    cout<<weapon1.get_inteligence_cost()<<"\n";
    cout<<weapon1.get_name()<<"\n";
    return 0;
}
