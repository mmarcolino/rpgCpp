#include <stdlib.h>

using namespace std;

class Magic{

protected:

int mp;
int magic[7] = {200, -400, -360, 400, -320, -280, -200};
int typeMagic[7] = {0, 1, 1, 0, 1, 1, 1};
int manaWaste[7] = {12, 12, 14, 16, 14, 12, 12};
std::string magicName[7] = {"Poção da Vida" , "Hálito de Fogo" , "Bio" , "Cura" , "Flama Gelada", "Intoxicação", "Tempestade"};

public:
Magic(); // Construtor de classe que da valor a todos os atributos acima
void initialMp(int maxMana);

int baseMagicDamage(int choice);

};