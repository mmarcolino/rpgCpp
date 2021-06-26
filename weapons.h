#include <stdlib.h>

using namespace std;

class Weapons{

protected:

int weapons[7] = {250, 300, 380, 400, 420, 420, 500}; 
int weaponDamage = 0; //Dano da arma
int weaponLevel = 0; //Nível da arma


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

}

int Weapons :: upgrade (int weaponArray[])
{
    if(weaponArray[weaponLevel + 1] != -1)
    {
        weaponLevel ++;
        weaponDamage = weapons[weaponArray[weaponLevel]];
        
        return 1;
    }   

    return 0;
}