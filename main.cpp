#include "classArmas.h"
#include "classMonstros.h"
#include "classHumanos.h"
#include "classMagia.h"

Animal::Animal()
{

    hp = 3200;
    maxMana = 30;
    physicalStrenght = 80;
    magicalStrenght = 20;
    armor = 80;
    magicResistance = 20;
    agility = 50;
    
    weaponIndex[0] = 0;

}

Troll::Troll()
{

    hp = 2800;
    maxMana = 20;
    physicalStrenght = 100;
    magicalStrenght = 20;
    armor = 80;
    magicResistance = 20;
    agility = 20;

    weaponIndex[0] = 3;
    weaponIndex[1] = 4;


}

Dragon::Dragon()
{

    hp = 3000;
    maxMana = 40;
    physicalStrenght = 100;
    magicalStrenght = 20;
    armor = 50;
    magicResistance = 50;
    agility = 30;

    weaponIndex[0] = 0;

}

Zombie::Zombie()
{

    hp = 2500;
    maxMana = 20;
    physicalStrenght = 40;
    magicalStrenght = 20;
    armor = 40;
    magicResistance = 80;
    agility = 50;

    weaponIndex[0] = 0;
    weaponIndex[1] = 3;
    weaponIndex[2] = 4;

}

Warrior::Warrior()
{

    hp = 4000;
    maxMana = 30;
    physicalStrenght = 100;
    magicalStrenght = 20;
    armor = 80;
    magicResistance = 20;
    agility = 20;
    
    weaponIndex[0] = 2;
    weaponIndex[1] = 3;

}

Thief::Thief()
{

    hp = 2800;
    maxMana = 50;
    physicalStrenght = 50;
    magicalStrenght = 30;
    armor = 40;
    magicResistance = 50;
    agility = 80;

    weaponIndex[0] = 3;
    weaponIndex[1] = 4;
    weaponIndex[2] = 5;
    weaponIndex[3] = 6;
}

Wizard::Wizard()
{

    hp = 2500;
    maxMana = 100;
    physicalStrenght = 40;
    magicalStrenght = 100;
    armor = 30;
    magicResistance = 80;
    agility = 40;

    weaponIndex[0] = 1;
    weaponIndex[1] = 4;

}


Paladin::Paladin()
{

    hp = 3200;
    maxMana = 80;
    physicalStrenght = 60;
    magicalStrenght = 50;
    armor = 60;
    magicResistance = 60;
    agility = 60;

    weaponIndex[0] = 1;
    weaponIndex[1] = 5;

}

// CLASSES AUXILIARES //

Weapons::Weapons()
{

weaponLevel = 0;
weaponDamage = 0;
    
}


Magic::Magic(int mpUser) // mpUser = Maximo de mana da classe
{
mp = mpUser;    
}

int Magic::baseMagicDamage(int choice) // DANO BASE DE MAGIA (SEM FORCA MAGICA DO PERSONAGEM) A SER CALCULADO
{

    int damage = 0;

    if(this->mp > this->manaWaste[choice])
    {
        this->mp -= this->manaWaste[choice];
        damage = magic[choice];

        return damage;
    }


    else
    {
        return -1; // CASO NAO HAJA PONTOS DE MANA SUFICIENTE, RETORNA -1 PARA INDICAR.
    }

}


//        


int main()
{









}