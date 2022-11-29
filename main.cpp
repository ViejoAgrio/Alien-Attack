#include <iostream>
#include <conio.h>
#include "Alien.h"

using namespace std;

void bienvenida();
void instructions();
Brain creaBrain(float);
Alien store(Alien);

int main(){

    bienvenida();
    instructions();
    int i=1;
    char comer;
    Alien ali(12,1.0,Weapon("Beat",1,'x',0));
    while (i==1){
        Brain brain=creaBrain(ali.getLuck());
        brain.showAll();
        ali.showStats();
        comer=getch();
        system("cls");
        if (comer=='e'){
            ali.eatBrain(brain);
        }
        else if(comer=='l'){

        }
        else if(comer=='s'){
            ali=store(ali);
        }
        else if(comer=='q'){
            i=2;
        }
        else{
            cout<<"Command unrecognized, try again\n\n";
        }
    }


    //Creamos un objeto de tipo Alien

    return 0;
}

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

Brain creaBrain(float luc){
    int enteroLuck=(int)luc;
    int inte=rand()%(20+enteroLuck)-(10+enteroLuck/2);
    float luck=rand()%10;
    int resistence=rand()%10;
    Brain brain(inte,luck,resistence);
    return brain;
};

Alien store(Alien ali){
    system("cls");
    char opcion;
    //ali.setWeaponId();
    Weapon arrweapons[9];
    arrweapons[0]=Weapon("Rock",2,'q',20);
    arrweapons[1]=Weapon("Bite",3,'w',60);
    arrweapons[2]=Weapon("Gun",4,'e',100);
    arrweapons[3]=Weapon("Laser",5,'r',150);
    arrweapons[4]=Weapon("Telekinesis",6,'t',200);
    arrweapons[5]=Weapon("U.F.O",7,'y',320);
    arrweapons[6]=Weapon("Planet Invasion",8,'u',450);
    arrweapons[7]=Weapon("God Entity",10,'i',700);
    arrweapons[8]=ali.getWeapon();
    cout<<"Get a new weapon\n"<<"Pick the letter next the weapon to buy it with Alien's inteligence\n"<<"Press [x] to get back to the game \n\n";
    ali.showStats();
    cout<<"\nRock Damage: 2 [Q] "<<"Bite Damage: 3 [W] "<<"Gun Damage: 4 [E] "<<"Laser Damage: 5 [R] \n";
    cout<<"Price: 20          Price: 60          Price: 100        Price: 150\n\n";
    cout<<"Telekinesis Damage: 6 [T] "<<"U.F.O Damage: 7 [Y] "<<"Planet Invasion Damage: 8 [U] "<<"God Entity: 10 [I] \n";
    cout<<"Price: 200                Price: 320          Price: 450                    Price: 700\n";
    opcion=getch();
    if(opcion=='x'){
        system("cls");
        return ali;
    }
    for(int i=0;i<9;i++){
        if(opcion==arrweapons[i].getId()){
            if(ali.getWeaponDamage()==arrweapons[i].getDamage()){
                cout<<"You already have this weapon. Press ENTER to continue\n";
                getch();
                ali=store(ali);
                break;
            }
            else if(ali.getWeaponDamage()>arrweapons[i].getDamage()){
                cout<<"The weapon you already have is better. You can't buy this one. Press ENTER to continue\n";
                getch();
                ali=store(ali);
                break;
            }
            else if(ali.getInteligence()>=arrweapons[i].getPrice()){
                ali.setWeapon(arrweapons[i]);
                ali.setInteligence(ali.getInteligence()-arrweapons[i].getPrice());
                ali.showStats();
                ali.setWeaponId();
                cout<<"Press ENTER to continue\n";
                getch();
                system("cls");
                return ali;
            }
            else{
                cout<<"You don't have enough inteligence to afford this weapon. Press ENTER to continue\n";
                ali.showStats();
                getch();
                ali=store(ali);
                break;
            }
        }
        else if(i==8){
            cout<<"The letter you pressed is not assigned to any weapon in store. Press ENTER to continue\n";
            getch();
            ali=store(ali);
            break;
        }
    }
    system("cls");
    return ali;
};

void instructions(){
    cout<<"Instructions\n\n";
    cout<<"Eat Brains to gain stats\n";
    cout<<"Be careful, there are brains that will damage yours\n";
    cout<<"You can only eat the brains which have less resistence than your weapon's damage\n";
    cout<<"You can earn inteligence and luck, with inteligence you can ugpgrade your weapons\n";
    cout<<"With luck there will appear better barins\n";
    cout<<"Press [E] to eat, [L] to leave, [S] to visit the store or [Q] to quit the game.\n";
    cout<<"Press ENTER to continue\n";
    getch();
    system("cls");
}
