#include <iostream>

using namespace std;

class Guerreiro
{
    private:
    int hp; //Pontos de vida
    int mp; //Pontos de mana
    int fisicalStrengh; //Força porradeiro
    int magicalStengh;  //Força mágica
    int armor;  //Armadura
    int magicResistance; //Resistência à magia
    int agility; //Agilidade

    int *weapons; //Vetor das armas
    int weaponDemage; //Dano da arma
    int weaponLevel; //Nível da arma
    int *spells; //Magias/Encantamentos

    public:
    Guerreiro();

    void receivedDamage(int demage); //Calcula o dano sofrido pelo jogador

    int fisicalDemageCalculator(); //Calcula o dano físico que o jogador irá causar

    int magicalDemageCalculator(); //Caclucla o dano mágico que o jogador irá causar

    int useSpell(int spells[]); //Função para escolher diferentes magias.

    int changeWeapon(int weapons[]); //Função para escolher armas diferentes.
};

class Ladrao
{
    private:
    int hp; //Pontos de vida
    int mp; //Pontos de mana
    int fisicalStrengh; //Força porradeiro
    int magicalStengh;  //Força mágica
    int armor;  //Armadura
    int magicResistance; //Resistência à magia
    int agility; //Agilidade

    int *weapons; //Vetor das armas
    int weaponDemage; //Dano da arma
    int weaponLevel; //Nível da arma
    int *spells; //Magias/Encantamentos

    public:
    Ladrao();

    void receivedDamage(int demage); //Calcula o dano sofrido pelo jogador

    int fisicalDemageCalculator(); //Calcula o dano físico que o jogador irá causar

    int magicalDemageCalculator(); //Caclucla o dano mágico que o jogador irá causar

    int useSpell(int spells[]); //Função para escolher diferentes magias.

    int changeWeapon(int weapons[]); //Função para escolher armas diferentes.
};

class Mago
{
    private:
    int hp; //Pontos de vida
    int mp; //Pontos de mana
    int fisicalStrengh; //Força porradeiro
    int magicalStengh;  //Força mágica
    int armor;  //Armadura
    int magicResistance; //Resistência à magia
    int agility; //Agilidade

    int *weapons; //Vetor das armas
    int weaponDemage; //Dano da arma
    int weaponLevel; //Nível da arma
    int *spells; //Magias/Encantamentos

    public:
    Mago();

    void receivedDamage(int demage); //Calcula o dano sofrido pelo jogador

    int fisicalDemageCalculator(); //Calcula o dano físico que o jogador irá causar

    int magicalDemageCalculator(); //Caclucla o dano mágico que o jogador irá causar

    int useSpell(int spells[]); //Função para escolher diferentes magias.

    int changeWeapon(int weapons[]); //Função para escolher armas diferentes.
};

class Paladino
{
    private:
    int hp; //Pontos de vida
    int mp; //Pontos de mana
    int fisicalStrengh; //Força porradeiro
    int magicalStengh;  //Força mágica
    int armor;  //Armadura
    int magicResistance; //Resistência à magia
    int agility; //Agilidade

    int *weapons; //Vetor das armas
    int weaponDemage; //Dano da arma
    int weaponLevel; //Nível da arma
    int *spells; //Magias/Encantamentos

    public:
    Paladino();

    void receivedDamage(int demage); //Calcula o dano sofrido pelo jogador

    int fisicalDemageCalculator(); //Calcula o dano físico que o jogador irá causar

    int magicalDemageCalculator(); //Caclucla o dano mágico que o jogador irá causar

    int useSpell(int spells[]); //Função para escolher diferentes magias.

    int changeWeapon(int weapons[]); //Função para escolher armas diferentes.
};
