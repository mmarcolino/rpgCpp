#include <stdlib.h>

using namespace std;

class Animal{

private:

    int hp; // Pontos de Vida
    int physicalStrenght; // Forca fisica da classe
    int magicalStrenght; // Forca magica da classe
    int armor; // Armadura da classe (resistencia a dano fisico)
    int magicResistance; // Resistencia a dano magico
    int agility; // Probabilidade de esquiva
    int maxMana;

    int weaponIndex[7] = {0, 0, 0, 0, 0, 0, 0};




public:
Animal(); // Construtor de classe que da valor a todos os atributos acima

void recebeDano(int damage); // Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

int physicalDamageCalculator(Weapons *weapons); // Funcao que calcula o ataque fisico que sera dado

int magicalDamageCalculator(Magic *magic); // Funcao que calcula o ataque magico que sera dado

void changeWeapon(Weapons *weapons); // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

};



class Troll{

private:

    int hp; // Pontos de Vida
    int physicalStrenght; // Forca fisica da classe
    int magicalStrenght; // Forca magica da classe
    int armor; // Armadura da classe (resistencia a dano fisico)
    int magicResistance; // Resistencia a dano magico
    int agility; // Probabilidade de esquiva
    int maxMana;

    int weaponIndex[7] = {0, 0, 0, 0, 0, 0, 0};

public:
Troll(); // Construtor de classe que da valor a todos os atributos acima

void recebeDano(int damage); // Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

int physicalDamageCalculator(Weapons *weapons); // Funcao que calcula o ataque fisico que sera dado

int magicalDamageCalculator(Magic *magic); // Funcao que calcula o ataque magico que sera dado

void changeWeapon(Weapons *weapons); // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

};



class Dragon{

private:

    int hp; // Pontos de Vida
    int physicalStrenght; // Forca fisica da classe
    int magicalStrenght; // Forca magica da classe
    int armor; // Armadura da classe (resistencia a dano fisico)
    int magicResistance; // Resistencia a dano magico
    int agility; // Probabilidade de esquiva
    int maxMana;

    int weaponIndex[7] = {0, 0, 0, 0, 0, 0, 0};


public:
Dragon(); // Construtor de classe que da valor a todos os atributos acima

void recebeDano(int damage); // Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

int physicalDamageCalculator(Weapons *weapons); // Funcao que calcula o ataque fisico que sera dado

int magicalDamageCalculator(Magic *magic); // Funcao que calcula o ataque magico que sera dado

void changeWeapon(Weapons *weapons); // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

};





class Zombie{

private:

    int hp; // Pontos de Vida
    int physicalStrenght; // Forca fisica da classe
    int magicalStrenght; // Forca magica da classe
    int armor; // Armadura da classe (resistencia a dano fisico)
    int magicResistance; // Resistencia a dano magico
    int agility; // Probabilidade de esquiva
    int maxMana;

    int weaponIndex[7] = {0, 0, 0, 0, 0, 0, 0};

public:
Zombie(); // Construtor de classe que da valor a todos os atributos acima

void recebeDano(int damage); // Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

int physicalDamageCalculator(Weapons *weapons); // Funcao que calcula o ataque fisico que sera dado

int magicalDamageCalculator(Magic *magic); // Funcao que calcula o ataque magico que sera dado

void changeWeapon(Weapons *weapons); // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

};