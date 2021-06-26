#include "class.h"

Warrior :: Warrior(Magic *magic, Weapons *weapons)
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

    this -> magic = magic;
    this -> weapons = weapons;

    magic -> initialMp(this-> maxMana);

    weaponIndex[0] = 2;
    weaponIndex[1] = 6;

    spellIndex[0] = 6;

}

int Warrior :: dodgeCalculator() //Função para calcular a esquiva
{

    int dodge = (rand() % 100) + 1; //Sorteia um número de 1 a 100 

    if (dodge < this->agility/2) //O personagem esquiva se a porcentagen for menor que a agilidade 
    return 1;

    else 
    return 0;
}

int Warrior :: receiveDamage(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->armor)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}

int Warrior :: physicalDamageCalculator () //Função para calcular o dano físico infligido no inimigo
{
    int damage = (rand() % 200) + 1;

    cout<<"\n"<< damage << "\n";

    damage += this -> weapons ->  returnDamage () - 200;

    float strengh = this -> physicalStrenght;

    damage *= 1 + (strengh / 100);

    return damage;
}

int Warrior :: magicalDamageCalculator (int escolha) //Função para calcular o dano mágico infligido no inimigo
{
    int damage = magic->baseMagicDamage(escolha);
    
    float magicalStrengh = this-> magicalStrenght;

    if (damage != -1)
    {
        damage *= 1 + (magicalStrengh / 100);

        return damage;
    }
    
    else
    cout << "\n" << "Pontos de mana insuficientes" << "\n";
}

int Warrior :: changeWeapon() //Função para a troca de armas
{
    return weapons -> upgrade(weaponIndex);
}

void Warrior :: initializeClass()
{
    weapons->setInicialDamage(weaponIndex[0]);
    magic->initialMp(maxMana);
}


void Warrior :: imprime()
{

cout<<"\n"<<this->hp<<"\n";


}



int Warrior :: showMagicMenu() // IF diferente de 0 executar receive damage no main
{

    cout << string( 100, '\n' );

    cout<<"-+-+-+-+-+-+-+-+- SELECIONAR MAGIA -+-+-+-+-+-+-+-+-";

    int counter = 0;

    cout<<"\n\n";

    for(int i : this->spellIndex)
    {
        if(i == -1){ break; }

        counter++;

        cout<<counter<<". "<<magic->magicName[i]<<"\n";
        

    }

    int breaker = 0;

    int answer = 0;

    while(1){

        cout<<": ";

        cin>>answer;

        for(int i = 0; i < counter; i++ )
        {

            if(answer - 1 == i){ breaker = 1; break;}

        }

        if(breaker == 1){ break; }

        else{ cout<<"OPCAO INVALIDA! TENTE NOVAMENTE\n"; }

    }


    if(magic->typeMagic[answer - 1] == 0){ hp += magic->magic[answer - 1]; return 0; } 

    else if(magic->typeMagic[answer - 1] == 1)
    {
        magicalDamageCalculator(answer - 1);
    }


    cout<<"\n\n";

    return answer - 1;

}

int Warrior :: addMana()
{
    int extraMana = magic->manaAfterRound();

    if(extraMana > maxMana)
    {
        magic->mp = maxMana;
    }

}

Warrior :: ~Warrior() //Função para destruir o personagem
{
    delete magic;
    delete weapons;
    

};
