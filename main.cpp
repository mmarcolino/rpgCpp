#include "declarations.h"

unsigned int sleep(unsigned int seconds);
int main()
{
    int random1;

    int random2;

    int random3;

    //Declaração de variáveis
    int phDamageP1, phDamageP2, mgDamageP1, mgDamageP2;
    int verifyPhAttackP1 = 0;  //Variável para conferir se o player 2 foi atacado por corpo-a-corpo
    int verifyMgAttackP1 = 0;  //Variável para conferir se o player 1 foi atacado por magia
    int verifyPhAttackP2 = 0;  //Variável para conferir se o player 2 foi atacado corpo-a-corpo
    int verifyMgAttackP2 = 0;  //Variável para conferir se o player 1 foi atacado por magia
    int verifyBulKathosP1 = 0; //Variável para conferir se o player 2 foi atacado com a arma especial
    int verifyBulKathosP2 = 0; //Variável para conferir se o player 1 foi atacado com a arma especial

    //******************************************Declara player 1***************************************
    ICharacter *p1;

    Weapons *wp1 = new Weapons();

    Magic *mp1 = new Magic();

    //Imprime menu
    int menuP1; //Variável para controlar o menu do player 1.
    cout << string( 100, '\n' );
    cout 
    << "\n"
    << "Player-1, escolha sua classe:"
    << " "
    << "1- Guerreiro, 2- Ladrao, 3- Mago, 4- Paladino, 5- Animal, 6- Troll, 7- Dragao, 8- Zumbi."
    << "\n\n\n\n\n\n\n\n\n\n";

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
    cout << string( 100, '\n' );
    cout 
    << "\n"
    << "Player-2, escolha sua classe:"
    << " "
    << "1- Guerreiro, 2- Ladrao, 3- Mago, 4- Paladino, 5- Animal, 6- Troll, 7- Dragao, 8- Zumbi."
    << "\n\n\n\n\n\n\n\n\n\n:";

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
        p2 = new Paladin (mp2, wp2); //Paladino
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

        srand(time(0));

        random1 = (rand() % 5) + 1;

        random2 = (rand() % 4) + 1;

        //  if (verifyPhAttackP2 > 0)
        //     {
        //         verifyPhAttackP2 = 0;
        //         p1->receiveDamagePhys(phDamageP2);
        //     }
            
        //     if (verifyMgAttackP2 > 0)
        //     {
        //         verifyMgAttackP2 = 0;
        //         cout<<"TESTE :"<<mgDamageP2<<"\n\n";
        //         p1->receiveDamageMag(mgDamageP2);
        //     }


        if (p1 -> imprime() > 0 && p2 -> imprime() > 0)
        {

            random3 = (rand() % 4 ) + 1;

            int magicMenu, blessingChanceP1, verifyWeapon, roundsP1;

            //Chance da arma especial
            blessingChanceP1 = (rand()% 100 ) + 1;

            //Imprime menu
            int p1Action;
            cout << string( 100, '\n' );

            // if(p1->getPoison() == 1){ cout<<"OPA: "<<p1->imprime()<<"\n\n";}

            if( p1->getBleed() == 1){ p1->receiveDamagePure(30); cout<<"\n\n\n-+-+-+ SANGRAMENTO (-30 DE VIDA!) -+-+-+-\n\n"; if(random3 == 2){ p1->removeBleed(); cout<<"\n\n\n-+-+-+ SANGRAMENTO ACABOU! -+-+-+-\n\n\n\n"; }   }

            if( p1->getPoison() == 1){ p1->receiveDamagePure(50); cout<<"\n\n\n-+-+-+ ENVENENADO! (-50 DE VIDA!) -+-+-+-\n\n"; if(random1 == 2){ p1->removePoison(); cout<<"\n\n\n-+-+-+ VENENO ACABOU! -+-+-+-\n\n\n\n"; }   }
        
            // cout<<"OPA: "<<p1->imprime()<<"\n\n";

        while(1){
            
            cout 
            << "\nPlayer-1, escolha sua acao:\n"
            << " "
            << "\n1- Ataque fisico\n2- Usar magia\n3- Upgrade de arma\n4- Status\n5- Ataque especial";
            if (p1-> getUltiPoints() == p1 -> getMaxUltiPoints())
            {
                cout << "*(Ulti Disponivel)";
            }
            
            cout << "\n\n\n\n\n\n\n\n\n\n:";

           

            
            int chest;

            cin >> p1Action;

            chest = p1Action;

            random2 = (rand() % 3) + 1;

            if( p1->getConfusion() == 1){ cout<<"\n\n\n-+-+-+ VOCE FICOU CONFUSO E NAO CONSEGUIU COMPLETAR A ACAO -+-+-+-\n\n"; sleep(3); p1Action = 10; if(random2 == 1){ p1->removeConfusion(); p1Action = chest; cout<<"\n\n\n-+-+-+ VOCE SAIU DA CONFUSAO! -+-+-+-\n\n\n\n"; sleep(3); }   }

            switch (p1Action)
            {
            case 1: //Atacar físico
                if (blessingChanceP1 < 5)
                {
                    phDamageP1 = p1 -> bulKathos();
                    p2->receiveDamagePhys(phDamageP1);
                    verifyBulKathosP1 ++;
                    p1->addMana(); //Função para adcionar 10 de mana em cada round. 
                    p1->addUltiPoints();
                    break;
                }

                else
                {
                    phDamageP1 = p1->physicalDamageCalculator();
                    verifyPhAttackP1 ++;
                    p2->receiveDamagePhys(phDamageP1);
                    p1->addMana(); //Função para adcionar 10 de mana em cada round. 
                    p1->addUltiPoints();
                    break;
                }

            case 2: // usar magia

                magicMenu = p1->showMagicMenu(p2);
                if (magicMenu > 0)
                {
                    mgDamageP1 = magicMenu;
                    verifyMgAttackP1;
                    p2->receiveDamageMag(magicMenu);
                }
                
                if(magicMenu == -2){continue;}
                p1->addUltiPoints();
                break;

            case 3: // Upar arma

                verifyWeapon = p2->changeWeapon();
                if (verifyWeapon == 1)
                {
                    p2->addMana(); //Função para adcionar 10 de mana em cada round. 
                    p2->addUltiPoints();
                    break;
                }
                
                else
                continue;

            case 4: //Status
                p1->seeStats(p2);
                cout << string( 100, '\n' );
                continue;

            case 5: //Ulti
                if(p1 -> getUltiPoints() == p1 -> getMaxUltiPoints())
                {
                    p1 -> useUlti(p2, roundsP1);
                    break;
                }

                else
                {
                    cout << "-+-+-+- Ulti indisponivel -+-+-+-";
                       sleep(3);
                    continue;
                }

            case 10:
                p1->addUltiPoints();
                break;

            default:
                break;
            }
            break;
        }
            roundsP1 = p1->countRounds();
        }
        else //Caso o player 1 seja derrotado
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
        
        //************************TURNO PLAYER 2*******************************************

        random1 = ((rand() % 5) + 1);

        random3 = ((rand() % 4) + 1);

        //Sleep(1000);

            // if (verifyPhAttackP1 > 0) 
            // {
            //     verifyPhAttackP1 = 0;
            //     p2->receiveDamagePhys(phDamageP1);
            // }

            // cout<<"EU TO MALUCO  "<<verifyMgAttackP1<<"\n";

            // if (verifyMgAttackP1 > 0)
            // {
            //     verifyMgAttackP1 = 0;
            //     cout<<"TESTE :"<<mgDamageP1<<"\n\n";
            //     p2->receiveDamageMag(mgDamageP1);
            // }

        if (p1 -> imprime() > 0 && p2 -> imprime() > 0)
        {
            int magicMenu, blessingChanceP2, verifyWeapon, roundsP2;

            //Chance da arma especial
            blessingChanceP2 = (rand()% 100) + 1;
            
            int p2Action;

            //Imprime menu
            cout << string( 100, '\n' );

            if( p2->getBleed() == 1){ p2->receiveDamagePure(30); cout<<"\n\n\n-+-+-+ SANGRAMENTO (-30 DE VIDA!) -+-+-+-\n\n"; if(random3 == 2){ p2->removeBleed(); cout<<"\n\n\n-+-+-+ SANGRAMENTO ACABOU! -+-+-+-\n\n\n\n"; }   }

            if( p2->getPoison() == 1){ p2->receiveDamagePure(50); cout<<"\n\n\n-+-+-+ ENVENENADO! (-50 DE VIDA!) -+-+-+-\n\n"; if(random1 == 2){ p2->removePoison(); cout<<"\n\n\n-+-+-+ VENENO ACABOU! -+-+-+-\n\n\n\n"; }   }
        
        while(1){
            
            cout 
            <<"\nPlayer-2, escolha sua acao:\n"
            << " "
            << "\n1- Ataque fisico\n2- Usar magia\n3- Upgrade de arma\n4- Status\n5- Ataque especial";
            if (p2-> getUltiPoints() == p2 -> getMaxUltiPoints())
            {
                cout << "*(Ulti Disponivel)";
            }
            
            cout << "\n\n\n\n\n\n\n\n\n\n:";
            


            cin >> p2Action;

            int chest2;

            chest2 = p2Action;
            
            random2 = (rand() % 3) + 1;

            if( p2->getConfusion() == 1){ cout<<"\n\n\n-+-+-+ VOCE FICOU CONFUSO E NAO CONSEGUIU COMPLETAR A ACAO -+-+-+-\n\n"; sleep(3); p2Action = 10; if(random2 == 1){ p2->removeConfusion(); p2Action = chest2; cout<<"\n\n\n-+-+-+ VOCE SAIU DA CONFUSAO! -+-+-+-\n\n\n\n"; sleep(3); }   }

            switch (p2Action)
            {
            case 1: //Atacar físico
                if (blessingChanceP2 < 5)
                {
                    phDamageP1 = p2 -> bulKathos();
                    verifyBulKathosP1 ++;
                    p1->receiveDamagePhys(phDamageP1);
                    p2->addMana(); //Função para adcionar 10 de mana em cada round. 
                    p2->addUltiPoints();
                    break;
                }
                else
                {
                    phDamageP1 = p2->physicalDamageCalculator();
                    verifyPhAttackP2 ++;
                    p1->receiveDamagePhys(phDamageP1);
                    p2->addMana(); //Função para adcionar 10 de mana em cada round. 
                    p2->addUltiPoints();
                    break;
                }

            case 2: // usar magia

                magicMenu = p2->showMagicMenu(p1);
                if (magicMenu > 0)
                {
                    mgDamageP2 = magicMenu;

                    p1->receiveDamageMag(mgDamageP2);

                    //cout<<"TESTE :"<<mgDamageP2<<"\n\n";
                    verifyMgAttackP2;
                }

                if(magicMenu == -2){continue;}
                p2->addUltiPoints();
                break;

            case 3: // Upar arma
                verifyWeapon = p2->changeWeapon();
                if (verifyWeapon == 1)
                {
                    p2->addMana(); //Função para adcionar 10 de mana em cada round. 
                    p2->addUltiPoints();
                    break;
                }
                
                else
                continue;

            case 4: //Status
                p2->seeStats(p1);
                cout << string( 100, '\n' );
                continue;

            case 5: //Ulti
                if(p2-> getUltiPoints() == p2 -> getMaxUltiPoints())
                {
                    p2 -> useUlti(p1, roundsP2);
                    break;
                }

                else
                {
                    cout << "-+-+-+- Ulti indisponivel -+-+-+-";
                       sleep(3);
                    continue;
                }

            case 10:
                p2->addUltiPoints();
                break;


            default:
                break;
            }
            break;
        }
            roundsP2 = p2->countRounds();
        }

        else //Caso o player dois seja derrotado
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
        
    }
    
}