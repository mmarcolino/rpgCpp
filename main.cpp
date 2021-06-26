#include "warrior.h"
#include <stdlib.h>

int main()
{

    ICharacter *p1;

    Weapons *wp1 = new Weapons();

    Magic *mp1 = new Magic();

    cout 
    << "Player-1, escolha sua classe:"
    << " "
    << "1- Guerreiro, 2- Ladrao, 3- Mago, 4- Paladino, 5- Animal, 6- Troll, 7- Dragao, 8- Zumbi."
    << "\n";

    int menuP1; //Variável para controlar o menu do player 1.

    switch (menuP1)
    {
    case 1:
        p1 = new Warrior (mp1, wp1); 
        p1 -> initializeClass();
        break;

    case 2:
        p1 = new Thief (mp1, wp1); 
        p1 -> initializeClass();
        break;

    case 3:
        p1 = new Wizard (mp1, wp1); 
        p1 -> initializeClass();
        break;
    
    case 4:
        p1 = new Paladin (mp1, wp1); 
        p1 -> initializeClass();
        break;
    
    case 5:
        p1 = new Animal(mp1, wp1); 
        p1 -> initializeClass();
        break;

    case 6:
        p1 = new Troll (mp1, wp1); 
        p1 -> initializeClass();
        break;

    case 7:
        p1 = new Dragon (mp1, wp1); 
        p1 -> initializeClass();
        break;

    case 8:
        p1 = new Zombie (mp1, wp1); 
        p1 -> initializeClass();
        break;

    default:
        cout << "Operacao invalida" << "\n";
        break;
    }

    ICharacter *p2;

    Weapons *wp2 = new Weapons();

    Magic *mp2 = new Magic();

    int menup2; //Variável para controlar o menu.

    switch (menup2)
    {
    case 1:
        p2 = new Warrior (mp2, wp2); 
        p2 -> initializeClass();
        break;

    case 2:
        p2 = new Thief (mp2, wp2); 
        p2 -> initializeClass();
        break;

    case 3:
        p2 = new Wizard (mp2, wp2); 
        p2 -> initializeClass();
        break;
    
    case 4:
        p2 = new Paladin (mp2, wp2); 
        p2 -> initializeClass();
        break;
    
    case 5:
        p2 = new Animal(mp2, wp2); 
        p2 -> initializeClass();
        break;

    case 6:
        p2 = new Troll (mp2, wp2); 
        p2 -> initializeClass();
        break;

    case 7:
        p2 = new Dragon (mp2, wp2); 
        p2 -> initializeClass();
        break;

    case 8:
        p2 = new Zombie (mp2, wp2); 
        p2 -> initializeClass();
        break;

    default:
        cout << "Operacao invalida" << "\n";
        break;
    }

    while(1)
    {
        if (p1 -> imprime() > 0 && p2 -> imprime() > 0)
        {
            
            p1->addMana(); //Função para adcionar 10 de mana em cada round. 
        }

        else
        {
            cout << "Player 1 derrotado!." << "\n";
            break;
        }
        
        if (p1 -> imprime() > 0 && p2 -> imprime() > 0)
        {
            
            p2->addMana(); //Função para adcionar 10 de mana em cada round.
        }

        else
        {
            cout << "Player 2 derrotado!." << "\n";
            break;
        }
        
    }
    
    //int teste;

    //teste = p1->physicalDamageCalculator();

    //cout<<"\n"<<teste<<"\n";

    //p2->receiveDamage(teste);

    p2->imprime();

    p1->showMagicMenu();

    p1->imprime();
}