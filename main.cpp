#include <iostream>
#include "Alien.h"

using namespace std;

int main(){
    //Creamos un objeto de tipo Alien
    Alien ali;
    /*Hacemos uso de composicion creando un objeto de tipo Weapon con la
    funcion setWeapon que utiliza el constructor de la clase Weapon.
    */
    ali.setWeapon("Bite",1);
    cout<<"El atributo del objeto ali de la Clase Alien de tipo Weapon tiene nombre: "<<ali.getWeaponName();
    return 0;
}
