#include "warrior.h"
int main()
{
    //Declaração de variáveis
    int phDamageP1, phDamageP2, mgDamageP1, mgDamageP2;
    int verifyPhAttackP1 = 0;  //Variável para conferir se o player 1 foi atacado por corpo-a-corpo
    int verifyMgAttackP1 = 0;  //Variável para conferir se o player 1 foi atacado por magia
    int verifyPhAttackP2 = 0;  //Variável para conferir se o player 2 foi atacado corpo-a-corpo
    int verifyMgAttackP2 = 0;  //Variável para conferir se o player 1 foi atacado por magia

    //******************************************Declara player 1***************************************
    ICharacter *p1;

    Weapons *wp1 = new Weapons();

    Magic *mp1 = new Magic();

    //Imprime menu
    int menuP1; //Variável para controlar o menu do player 1.
    cout 
    << "\n"
    << "Player-1, escolha sua classe:"
    << " "
    << "1- Guerreiro, 2- Ladrao, 3- Mago, 4- Paladino, 5- Animal, 6- Troll, 7- Dragao, 8- Zumbi."
    << "\n";

    cin >> menuP1;
    switch (menuP1)
    {
    case 1:
        p1 = new Warrior (mp1, wp1); //Guerreiro
        p1 -> initializeClass();
        break;

    case 2:
        // p1 = new Thief (mp1, wp1);  //Ladrao
        p1 -> initializeClass();
        break;

    case 3:
        //p1 = new Wizard (mp1, wp1); //Mago
        // p1 -> initializeClass();
        break;
    
    case 4:
        // p1 = new Paladin (mp1, wp1); //Paladino
        p1 -> initializeClass();
        break;
    
    case 5:
        // p1 = new Animal(mp1, wp1); //Animal
        p1 -> initializeClass();
        break;

    case 6:
        //p1 = new Troll (mp1, wp1); //Troll
        // p1 -> initializeClass();
        break;

    case 7:
        // p1 = new Dragon (mp1, wp1); //Dragão
        p1 -> initializeClass();
        break;

    case 8:
        // p1 = new Zombie (mp1, wp1); //Zumbi
        p1 -> initializeClass();
        break;

    default:
        cout << "Operacao invalida" << "\n";
        break;
    }
    //*****************************Declara player 2***************************************
    ICharacter *p2;

    Weapons *wp2 = new Weapons();

    Magic *mp2 = new Magic();

    //Imprime menu
    int menup2; //Variável para controlar o menu.
    cout 
    << "\n"
    << "Player-2, escolha sua classe:"
    << " "
    << "1- Guerreiro, 2- Ladrao, 3- Mago, 4- Paladino, 5- Animal, 6- Troll, 7- Dragao, 8- Zumbi."
    << "\n";

    cin >> menup2;
    switch (menup2)
    {
    case 1:
        p2 = new Warrior (mp2, wp2); //Guerreiro
        p2 -> initializeClass();
        break;

    case 2:
        // p2 = new Thief (mp2, wp2); //Ladrao
        p2 -> initializeClass();
        break;

    case 3:
        //p2 = new Wizard (mp2, wp2); //Mago
        // p2 -> initializeClass();
        break;
    
    case 4:
        // p2 = new Paladin (mp2, wp2); //Paladino
        p2 -> initializeClass();
        break;
    
    case 5:
        // p2 = new Animal(mp2, wp2); //Animal
        p2 -> initializeClass();
        break;

    case 6:
        //p2 = new Troll (mp2, wp2); //Troll
        // p2 -> initializeClass();
        break;

    case 7:
        // p2 = new Dragon (mp2, wp2); //Dragao
        p2 -> initializeClass();
        break;

    case 8:
        // p2 = new Zombie (mp2, wp2); //Zumbi
        p2 -> initializeClass();
        break;

    default:
        cout << "Operacao invalida" << "\n";
        break;
    }
    while(1)
    {
        //***********************TURNO PLAYER 1******************************************  
        if (p1 -> imprime() > 0 && p2 -> imprime() > 0)
        {
            int magicMenu;
            if (verifyPhAttackP2 > 0)
            {
                verifyPhAttackP2 = 0;
                p1->receiveDamagePhys(phDamageP2);
            }
            
            if (verifyMgAttackP2 > 0)
            {
                verifyMgAttackP2 = 0;
                p1->receiveDamageMag(mgDamageP2);
            }

            //Imprime menu
            int p1Action;
            cout 
            << "Player-1, escolha sua acao:\n"
            << " "
            << "\n1- Ataque fisico\n2- Usar magia\n3- Upgrade de arma\n4- Status\n5- Ataque especial\n"
            << "\n";

            cin >> p1Action;

            switch (p1Action)
            {
            case 1: //Atacar físico

                phDamageP1 = p1->physicalDamageCalculator();
                verifyPhAttackP1 ++;
                p1->addMana(); //Função para adcionar 10 de mana em cada round. 
                p1->addUltiPoints();
                break;

            case 2: // usar magia

                magicMenu = p1->showMagicMenu();
                if (magicMenu > 0)
                {
                    mgDamageP1 = magicMenu;
                    verifyMgAttackP1;
                }
                
                if(magicMenu == -2){continue;}
                break;

            case 3: // Upar arma

                p1->changeWeapon();
                p1->addMana(); //Função para adcionar 10 de mana em cada round. 
                break;

            case 4: //Status
                p1->seeStats(p2);
                continue;

            default:
                break;
            }
        }
        else //Caso o player 1 seja derrotado
        {
            cout << "Player 2 derrotado!" << "\n";

            delete p1;
            delete p2;
            delete mp1;
            delete wp1;
            delete mp2;
            delete wp2;

            break;
        }
        
        //************************TURNO PLAYER 2*******************************************
        if (p1 -> imprime() > 0 && p2 -> imprime() > 0)
        {
            int magicMenu;
            
            if (verifyPhAttackP1 > 0) 
            {
                verifyPhAttackP1 = 0;
                p2->receiveDamagePhys(phDamageP1);
            }

            if (verifyMgAttackP1 > 0)
            {
                verifyMgAttackP1 = 0;
                p2->receiveDamageMag(mgDamageP1);
            }

            int p2Action;
            //Imprime menu
            cout 
            << "Player-2, escolha sua acao:\n"
            << " "
            << "\n1- Ataque fisico\n2- Usar magia\n3- Upgrade de arma\n4- Status\n5- Ataque especial\n\n"
            << "\n";
            cin >> p2Action;

            switch (p2Action)
            {
            case 1: //Atacar físico

                phDamageP2 = p2->physicalDamageCalculator();
                verifyPhAttackP2 ++;
                p2->addMana(); //Função para adcionar 10 de mana em cada round. 
                break;

            case 2: // usar magia

                magicMenu = p2->showMagicMenu();
                if (magicMenu > 0)
                {
                    mgDamageP2 = magicMenu;
                    verifyMgAttackP2;
                }

                if(magicMenu == -2){continue;}

                break;

            case 3: // Upar arma

                p2->changeWeapon();
                p2->addMana(); //Função para adcionar 10 de mana em cada round. 
                break;

            case 4: //Status
                p2->seeStats(p1);
                continue;


            default:
                break;
            }
        }

        else //Caso o player dois seja derrotado
        {
            cout << "Player 1 derrotado!" << "\n";
            
            delete p1;
            delete p2;
            delete mp1;
            delete wp1;
            delete mp2;
            delete wp2;

            break;
        }
        
    }
    
}