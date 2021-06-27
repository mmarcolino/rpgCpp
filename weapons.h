#include <stdlib.h>

using namespace std;

class Weapons{

protected:

int weapons[7] = {250, 300, 380, 400, 420, 420, 500}; 
int weaponId[7] = {0, 1, 2, 3, 4, 5, 6};
int weaponDamage = 0; //Dano da arma
int weaponLevel = 0; //Nível da arma
std::string weaponName[7] = {"Cajado" , "Garra letal" , "Porrete" , "Esfera de ataque" , "Tridente sagrado", "Besta", "Espada barroca"};
string currentWeaponName;

friend class Warrior;
friend class Paladin;
friend class ICharacter;


public:
Weapons(); // Construtor de classe que da valor a todos os atributos acima
void setInicialDamage(int index);
int upgrade(int weaponArray[]);
int returnDamage();
};

Weapons :: Weapons()
{
    
}


int Weapons :: returnDamage()
{
    return weaponDamage;
}


void Weapons :: setInicialDamage(int index)
{

    this->weaponDamage = this->weapons[index];
    this->currentWeaponName = this->weaponName[index];

}

int Weapons :: upgrade (int weaponArray[])
{
    if(weaponArray[weaponLevel + 1] != -1)
    {
        weaponLevel ++;
        weaponDamage = weapons[weaponArray[weaponLevel]];

        this->currentWeaponName = weaponName[weaponArray[weaponLevel]];
        
        return 1;
    }   

    return 0;
}