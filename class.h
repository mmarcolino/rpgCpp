#include <iostream>
#include <string.h>
#include "weapons.h"
#include "spells.h"
#include <cstdlib>
#include<ctime>

using namespace std;

class ICharacter{

    protected:

    int hp; // Pontos de Vida
    int physicalStrenght; // Forca fisica da classe
    int armor; // Armadura da classe (resistencia a dano fisico)
    int magicalStrenght; // Forca magica da classe
    int magicalResistance; // Resistencia a dano magico
    int agility; // Probabilidade de esquiva
    int maxMana;

    int weaponIndex[7] = {-1, -1, -1, -1, -1, -1, -1};
    int spellIndex[7] = {-1, -1, -1, -1, -1, -1, -1};
    public:

    virtual int receiveDamage(int damage) {}; // Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    virtual int physicalDamageCalculator() {}; // Funcao que calcula o ataque fisico que sera dado

    virtual int magicalDamageCalculator(int escolha) {}; // Funcao que calcula o ataque magico que sera dado

    virtual int changeWeapon() {}; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    virtual int dodgeCalculator() {}; //Função para calcular a esquiva do personagem

    virtual void initializeClass() {};

    virtual void imprime() {};

    virtual int showMagicMenu() {};

};




class Warrior : public ICharacter{
    
    private:

    int attributes [7] = {4000, 30, 100, 20, 80, 20, 20};

    Magic *magic; 
    Weapons *weapons;


    public:

    Warrior (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamage(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    void imprime() override; // TESTE!!!!!!!!!!!!

    int showMagicMenu() override;

    ~Warrior (); //Função destrutora
};

class Thief : public ICharacter{

    private:

    int attributes [7] = {2800, 50, 50, 30, 40, 50, 80};
    Magic *magic; 
    Weapons *weapons;
    
    public:

    Thief (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamage(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override;

    ~Thief (); //Função destrutora
};

class Wizard : public ICharacter{
    private:

    int attributes [7] = {2500, 100, 40, 100, 30, 80, 40};
    Magic *magic; 
    Weapons *weapons;

    public:

    Wizard (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamage(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override;

    ~Wizard (); //Função destrutora
};

class Paladin : public ICharacter{
    private:

    int attributes [7] = {3200, 80, 60, 50, 60, 60, 60};
    Magic *magic; 
    Weapons *weapons;

    public:

    Paladin (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamage(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override;

    ~Paladin (); //Função destrutora
};

class Animal : public ICharacter{
    private:

    int attributes [7] = {3200, 30, 80, 20, 80, 20, 50};
    Magic *magic; 
    Weapons *weapons;

    public:

    Animal (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamage(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override;

    

    ~Animal (); //Função destrutora
};

class Troll : public ICharacter{
    private:

    int attributes [7] = {2800, 20, 100, 20, 80, 20, 20};
    Magic *magic; 
    Weapons *weapons;

    public:

    Troll (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamage(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override;

    ~Troll (); //Função destrutora
};

class Dragon : public ICharacter{
    private:

    int attributes [7] = {3000, 40, 100, 20, 50, 50, 30};
    Magic *magic; 
    Weapons *weapons;

    public:

    Dragon (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamage(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override;

    ~Dragon (); //Função destrutora
};

class Zombie : public ICharacter{
    private:

    int attributes [7] = {2500, 20, 40, 20, 40, 80, 50};
    Magic *magic; 
    Weapons *weapons;

    public:

    Zombie (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamage(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override;
    
    ~Zombie (); //Função destrutora
};
 
