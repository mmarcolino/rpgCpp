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
int getMp();

int baseMagicDamage(int choice);

};

//******************************************************************************************************//

int Magic :: getMp()
{
    return this->mp;
}


void Magic :: initialMp(int maxMana)
{
    this->mp = maxMana;
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