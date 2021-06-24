#include <class.h>

Warrior :: Warrior(Magic *magic, Weapons *weapons)
{
    this -> hp = attributes [0];
    this -> physicalStrenght = attributes [1];
    this -> magicalStrenght = attributes [2];
    this -> armor = attributes [3];
    this -> magicalResistance = attributes [4];
    this -> agility = attributes [5];
    this -> maxMana = attributes [6];

    this -> magic = magic;
    this -> weapons = weapons;

    magic -> initialMp(this-> maxMana);

}
