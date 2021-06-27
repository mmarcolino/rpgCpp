#include <iostream>
#include <string.h>
#include "weapons.h"
#include "spells.h"
#include <cstdlib>
#include <unistd.h>
#include<ctime>
unsigned int sleep(unsigned int seconds);

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
    int maxUlti;
    int ultiPoints;

    int isPoisoned;

    int isConfused;

    int maxHp;

    int weaponIndex[7] = {-1, -1, -1, -1, -1, -1, -1};
    int spellIndex[7] = {-1, -1, -1, -1, -1, -1, -1};
    
    public:

    virtual int receiveDamagePhys(int damage) {}; // Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    virtual int receiveDamageMag(int damage) {}; // Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    virtual int receiveDamagePure(int damage) {};

    virtual int physicalDamageCalculator() {}; // Funcao que calcula o ataque fisico que sera dado

    virtual int magicalDamageCalculator(int escolha) {}; // Funcao que calcula o ataque magico que sera dado

    virtual int changeWeapon() {}; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    virtual int dodgeCalculator() {}; //Função para calcular a esquiva do personagem

    virtual void initializeClass() {};

    virtual int imprime() {};

    virtual int showMagicMenu() {};

    virtual int addUltiPoints() {};

    virtual int getUltiPoints() {};

    virtual int useUlti(ICharacter *enemie) {};

    virtual int bulKathos() {};

    virtual int addMana() {};

    virtual int returnHp() {};

    virtual int returnMaxHp (){};

    virtual void seeStats(ICharacter *p2) {};

    virtual void removePoison() {};

    virtual int getPoison() {};

    virtual void removeConfusion() {};

    virtual int getConfusion() {};

};




class Warrior : public ICharacter{
    
    private:

    int attributes [7] = {4000, 30, 100, 20, 80, 20, 20};

    Magic *magic; 
    Weapons *weapons;


    public:

    Warrior (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamagePhys(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamageMag(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamagePure(int damage) override;

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int imprime() override; // TESTE!!!!!!!!!!!!

    int showMagicMenu() override; 

    int addUltiPoints() override;

    int getUltiPoints() override;

    int useUlti(ICharacter *enemie) override;
    
    int addMana() override;

    int returnHp() override;

    int returnMaxHp () override;

    void seeStats(ICharacter *p2) override;

    void removePoison() override;

    int getPoison() override;

    void removeConfusion() override;

    int getConfusion() override;

    int bulKathos() override;

    ~Warrior (); //Função destrutora
};

class Thief : public ICharacter{

    private:

    int attributes [7] = {2800, 50, 50, 30, 40, 50, 80};
    Magic *magic; 
    Weapons *weapons;
    
    public:

    Thief (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamagePhys(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamageMag(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamagePure(int damage) override;

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override; 

    int addUltiPoints() override;

    int getUltiPoints() override;

    int useUlti(ICharacter *enemie) override;
    
    int addMana() override;

    int returnHp() override;

    int returnMaxHp () override;

    void seeStats(ICharacter *p2) override;

    void removePoison() override;

    int getPoison() override;

    void removeConfusion() override;

    int getConfusion() override;


    int bulKathos() override;

    ~Thief (); //Função destrutora
};

class Wizard : public ICharacter{
    private:

    int attributes [7] = {2500, 100, 40, 100, 30, 80, 40};
    Magic *magic; 
    Weapons *weapons;

    public:

    Wizard (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamagePhys(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamageMag(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamagePure(int damage) override;

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override; 

    int addUltiPoints() override;

    int getUltiPoints() override;

    int useUlti(ICharacter *enemie) override;
    
    int addMana() override;

    int returnHp() override;

    int returnMaxHp () override;

    void seeStats(ICharacter *p2) override;

    void removePoison() override;

    int getPoison() override;

    void removeConfusion() override;

    int getConfusion() override;

    int bulKathos() override;

    ~Wizard (); //Função destrutora
};

class Paladin : public ICharacter{
    private:

    int attributes [7] = {3200, 80, 60, 50, 60, 60, 60};
    Magic *magic; 
    Weapons *weapons;

    public:

    Paladin (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamagePhys(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamageMag(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamagePure(int damage) override;

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override; 

    int addUltiPoints() override;

    int getUltiPoints() override;

    int useUlti(ICharacter *enemie) override;
    
    int addMana() override;

    int returnHp() override;

    int returnMaxHp () override;

    void seeStats(ICharacter *p2) override;

    void removePoison() override;

    int getPoison() override;

    void removeConfusion() override;

    int getConfusion() override;

    int bulKathos() override;

    ~Paladin (); //Função destrutora
};

class Animal : public ICharacter{
    private:

    int attributes [7] = {3200, 30, 80, 20, 80, 20, 50};
    Magic *magic; 
    Weapons *weapons;

    public:

    Animal (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamagePhys(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamageMag(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamagePure(int damage) override;

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override; 

    int addUltiPoints() override;

    int getUltiPoints() override;

    int useUlti(ICharacter *enemie) override;
    
    int addMana() override;

    int returnHp() override;

    int returnMaxHp () override;

    void seeStats(ICharacter *p2) override;

    void removePoison() override;

    int getPoison() override;

    void removeConfusion() override;

    int getConfusion() override;

    int bulKathos() override;

    

    ~Animal (); //Função destrutora
};

class Troll : public ICharacter{
    private:

    int attributes [7] = {2800, 20, 100, 20, 80, 20, 20};
    Magic *magic; 
    Weapons *weapons;

    public:

    Troll (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamagePhys(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamageMag(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamagePure(int damage) override;

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override; 

    int addUltiPoints() override;

    int getUltiPoints() override;

    int useUlti(ICharacter *enemie) override;
    
    int addMana() override;

    int returnHp() override;

    int returnMaxHp () override;

    void seeStats(ICharacter *p2) override;

    void removePoison() override;

    int getPoison() override;

    void removeConfusion() override;

    int getConfusion() override;

    int bulKathos() override;

    ~Troll (); //Função destrutora
};

class Dragon : public ICharacter{
    private:

    int attributes [7] = {3000, 40, 100, 20, 50, 50, 30};
    Magic *magic; 
    Weapons *weapons;

    public:

    Dragon (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamagePhys(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamageMag(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

    int receiveDamagePure(int damage) override;

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override; 

    int addUltiPoints() override;

    int getUltiPoints() override;

    int useUlti(ICharacter *enemie) override;
    
    int addMana() override;

    int returnHp() override;

    int returnMaxHp () override;

    void seeStats(ICharacter *p2) override;

    void removePoison() override;

    int getPoison() override;

    void removeConfusion() override;

    int getConfusion() override;

    int bulKathos() override;

    ~Dragon (); //Função destrutora
};

class Zombie : public ICharacter{
    private:

    int attributes [7] = {2500, 20, 40, 20, 40, 80, 50};
    Magic *magic; 
    Weapons *weapons;

    public:

    Zombie (Magic *magic, Weapons *weapons);// Construtor de classe que da valor a todos os atributos acima

    int receiveDamagePhys(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele
    
    int receiveDamageMag(int damage) override;// Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por eles

    int receiveDamagePure(int damage) override;

    int physicalDamageCalculator() override; // Funcao que calcula o ataque fisico que sera dado

    int magicalDamageCalculator(int escolha) override; // Funcao que calcula o ataque magico que sera dado

    int changeWeapon() override; // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

    int dodgeCalculator() override; //Função para calcular a esquiva do personagem

    void initializeClass() override;

    int showMagicMenu() override; 

    int addUltiPoints() override;

    int getUltiPoints() override;

    int useUlti(ICharacter *enemie) override;
    
    int addMana() override;

    int returnHp() override;

    int returnMaxHp () override;

    void seeStats(ICharacter *p2) override;

    void removePoison() override;

    int getPoison() override;

    void removeConfusion() override;

    int getConfusion() override;

    int bulKathos() override;
    
    ~Zombie (); //Função destrutora
};
 
