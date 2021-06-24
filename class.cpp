#include <class.h>

Warrior :: Warrior() //Funçaõ construtora da classe
{
    srand(time(0)); //Seed do gerador de números aleátorios

    //Atributos
    this -> hp = attributes [0]; 
    this -> physicalStrenght = attributes [1];
    this -> magicalStrenght = attributes [2];
    this -> armor = attributes [3];
    this -> magicalResistance = attributes [4];
    this -> agility = attributes [5];
    this -> maxMana = attributes [6];
}

int Warrior :: dodgeCalculator(int agility) //Função para calcular a esquiva
{

    int dodge = (rand() % 100) + 1; //Sorteia um número de 1 a 100 

    if (dodge < this->agility/2) //O personagem esquiva se a porcentagen for menor que a agilidade 
    return 1;

    else 
    return 0;
}

int Warrior :: receiveDamage(int damage) //função para calcular o dano recebido
{
    if (dodgeCalculator(this->agility) == 1) //Função para calcular a esquiva
    return 0;

    int effectiveDamage = damage - (damage * (this->armor/100)); //Absorção de dano

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}

int Warrior :: physicalDamageCalculator (Weapons *qeapons) //Função para calcular o dano físico infligido no inimigo
{

}

int Warrior :: magicalDamageCalculator (Magic *magic) //Função para calcular o dano mágico infligido no inimigo
{

}

void Warrior :: changeWeapon(Weapons *weapons) //Função para a troca de armas
{

}

Warrior :: ~Warrior() //Função para destruir o personagem
{
    
};

