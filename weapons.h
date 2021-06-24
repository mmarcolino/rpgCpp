#include <stdlib.h>

using namespace std;

class Weapons{

private:

int weapons[7] = {300, 420,500,380,250,420,400};
int weaponDamage; //Dano da arma
int weaponLevel = 0; //Nível da arma


public:
Weapons(); // Construtor de classe que da valor a todos os atributos acima
void setInicialDamage();
void upgrade(int weaponArray[]);

};
