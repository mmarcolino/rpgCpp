#include "warrior.h"
#include <stdlib.h>

int main()
{

ICharacter *p1;

Weapons *wp1 = new Weapons();

Magic *mp1 = new Magic();

p1 = new Warrior(mp1, wp1);

p1->initializeClass();


ICharacter *p2;

Weapons *wp2 = new Weapons();

Magic *mp2 = new Magic();

p2 = new Warrior(mp2, wp2);

p2->initializeClass();


//int teste;

//teste = p1->physicalDamageCalculator();

//cout<<"\n"<<teste<<"\n";

//p2->receiveDamage(teste);

//p2->imprime();

//int damage = p1->showMagicMenu();

//cout<<"\n"<<damage<<"\n";

//if(damage != -2){ p2->receiveDamage(damage); }


p2->imprime();

p1->changeWeapon();

p1->changeWeapon();

p2->receiveDamage(p1->physicalDamageCalculator());

//p1->changeWeapon();

p2->imprime();


}