#include <stdlib.h>

using namespace std;

class Weapons{

private:

int weapons[7] = {250, 300, 380, 400, 420, 420, 500}; 
int weaponDamage; //Dano da arma
int weaponLevel = 0; //Nível da arma


public:
Weapons(); // Construtor de classe que da valor a todos os atributos acima
void setInicialDamage();
void upgrade(int weaponArray[]);

};
