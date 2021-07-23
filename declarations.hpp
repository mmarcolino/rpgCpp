#include "class.h" 

Warrior :: Warrior(Magic *magic, Weapons *weapons)
{
    srand(time(0)); //Seed do gerador de números aleátorios

    //Atributos
    this -> hp = attributes [0]; 
    this -> maxMana = attributes [1];
    this -> physicalStrenght = attributes [2];
    this -> magicalStrenght = attributes [3];
    this -> armor = attributes [4];
    this -> magicalResistance = attributes [5];
    this -> agility = attributes [6];
    this -> maxUlti = 70;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this->isPoisoned = 0;
    this->isConfused = 0;
    this-> rounds = 0;

    this->numberRound = -1;

    this->classname = "Guerreiro";

    this-> maxHp = attributes[0];

    magic -> initialMp(this-> maxMana);

    weaponIndex[0] = 2;
    weaponIndex[1] = 6;

    spellIndex[0] = 6;

}

int Warrior :: dodgeCalculator() //Função para calcular a esquiva
{

    int dodge = (rand() % 100) + 1; //Sorteia um número de 1 a 100 

    if (dodge < this->agility/2){cout<<"-+-+-+- ESQUIVOU! -+-+-+-"; sleep(2); return 1;}

    else 
    return 0;
}

int Warrior :: receiveDamagePhys(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->armor / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}

int Warrior :: receiveDamageMag(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->magicalResistance / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}


int Warrior :: receiveDamagePure(int damage)
{

    if (damage > this -> hp)
            this -> hp = 0;

    else{ this->hp -= damage;}

}



int Warrior :: physicalDamageCalculator (ICharacter *enemie) //Função para calcular o dano físico infligido no inimigo
{
    int damage = (rand() % 200) + 1;

    damage += this -> weapons ->  returnDamage () - 200;

    float strengh = this -> physicalStrenght;

    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

   sleep(1);

   int random = (rand() % 6) + 1;

   if(random == 4)
   {
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; enemie->addBleed();   }

    }


    return damage;
}

int Warrior :: magicalDamageCalculator (int escolha) //Função para calcular o dano mágico infligido no inimigo
{
    int damage = magic->baseMagicDamage(escolha);
    
    float magicalStrengh = this-> magicalStrenght;

    if (damage != -1)
    {
        damage *=  1 + (magicalStrengh / 100.0);



        cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

        sleep(3);


        return damage;
    }
    
    else
    cout << "\n" << "Pontos de mana insuficientes" << "\n";

    return -1;
}

int Warrior :: changeWeapon() //Função para a troca de armas
{
    int a = weapons -> upgrade(weaponIndex);

    sleep(2);

    return a;
}

void Warrior :: initializeClass()
{
    weapons->setInicialDamage(weaponIndex[0]);
    magic->initialMp(maxMana);
}


int Warrior :: imprime()
{

//cout<<"\n HP "<<this->hp<<"\n";

    return hp;
}



int Warrior :: showMagicMenu(ICharacter *p2) // IF diferente de 0 executar receive damage no main
{

    while(1){

    cout << string( 100, '\n' );


    cout<<"-+-+-+-+-+-+-+-+- SELECIONAR MAGIA -+-+-+-+-+-+-+-+-";

    int counter = 0;

    cout<<"\n\n";

    cout<<"0. Voltar"<<"\n";

    for(int i : this->spellIndex)
    {
        if(i == -1){ break; }

        counter++;

        cout<<counter<<". "<<magic->magicName[i]<<"\n";
        

    }

    int breaker = 0;

    int answer = 0;


    while(1){
        cout<<"\n";
        cout<<": ";

        cin>>answer;

        if(answer == 0){ return -2;} // !!!!!!!!!!!!!! IMPORTANTE

        for(int i = 0; i < counter; i++ )
        {

            if(answer - 1 == i){ breaker = 1; break;}

        }

        if(breaker == 1){ break; }

        else{ cout<<"OPCAO INVALIDA! TENTE NOVAMENTE\n"; }

    }

    if(magic->mp > magic->manaWaste[ spellIndex[answer-1] ])
    {

 
        if(magic->typeMagic[ spellIndex[answer-1] ] == 0){ 
            
            hp += magic->magic[answer - 1]; magic->mp -= magic->manaWaste[ spellIndex[answer-1] ]; 
            cout<<"\n-+-+-+ CUROU "<<magic->magic[answer - 1]<<" -+-+-+-\n\n";  
            
            if(this->hp > this->maxHp){ hp = maxHp;}

                sleep(3);

            return 0; 
            } 


    }

    int random = 0;

    int damage = 0;

    if(magic->typeMagic[ spellIndex[answer-1] ] != 0 && magic->mp > magic->manaWaste[ spellIndex[answer-1] ] )
    {

        if( magic->typeMagic[ spellIndex[answer-1] ] == 2){ random = (rand() % 5) + 1; if(random == 3 || random == 2){ p2->addPoison(); cout<<"\n\n-+-+-+- ENVENENADO -+-+-+-\n\n";} }

         if( magic->typeMagic[ spellIndex[answer-1] ] == 3){ random = (rand() % 7) + 1; if(random == 3 || random == 2){ p2->addConfusion(); cout<<"\n\n-+-+-+- VOCE ESTA CONFUSO -+-+-+-\n\n";} }

        damage = magicalDamageCalculator(spellIndex[answer-1]);
        return damage;
    }


    if (magic->mp < magic->manaWaste[ spellIndex[answer-1] ]){cout<<"\n-+-+ MANA INSUFICIENTE -+-+-\n"; return -2;}
    }

   
    
    cout<<"\n";
}

int Warrior :: addMana()
{
    int extraMana = magic->manaAfterRound();

    if(extraMana > maxMana)
    {
        this->magic->mp = maxMana;
    }

}

void Warrior :: seeStats(ICharacter *p2)
{
    float porcentagem = (float)(this->hp) / (float)(this->maxHp); 

    float lifeDivisor = this->maxHp / 10;

    porcentagem *= 100;

    int counter = 1;

    cout << string( 100, '\n' );

    cout<<"+- STATUS PLAYER ( "<<this->classname<<" ) -+";

    cout << string(3, '\n');

    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= this->hp) { break; }

        else{counter++; cout<<"#"; lifeDivisor += this->maxHp / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<(int)(porcentagem)<<"%"<<" ( "<<this->hp<<"hp ) "<<"\n\n";
    
    cout<<"-Mana Points: "<<this->magic->mp<<"\n\n";

    cout<<"-Ulti Points" << "(MAX-" << this->maxUlti <<"): "<<this->ultiPoints<<"\n\n";

    cout<<"-Arma atual: "<<weapons->currentWeaponName<<" ( Dano: "<<weapons->weaponDamage<<" )"<<"\n\n\n";

    cout<<"-Envenenado: ";

    if(this->getPoison() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}

       cout<<"-Sangrando: ";

    if(this->getBleed() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}


    cout<<"-----------------------------------------------------------------------------\n\n";

    cout<<"HP INIMIGO:\n\n";

    counter = 1;

    porcentagem = (float)(p2->returnHp()) / (float)(p2->returnMaxHp()); 

    lifeDivisor = p2->returnMaxHp()  / 10;

    porcentagem *= 100;


    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= p2->imprime()) { break; }

        else{counter++; cout<<"#"; lifeDivisor += p2->returnMaxHp() / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<"\n\n";

    int keyPressed;

    while(1)
    {

        cout<<"\n\n\n\nDIGITE 0 PARA SAIR\n\n";

        cout<<"\n:";

        cin>>keyPressed;

        if(keyPressed == 0){ break; }



    }


}

int Warrior :: returnHp()
{
    return this->hp;
}

int Warrior :: returnMaxHp()
{
    return this->maxHp;
}


int Warrior :: addUltiPoints()
{
    if (ultiPoints < maxUlti)
    {
        ultiPoints += 10;
    }
    
}

int Warrior :: getUltiPoints()
{
    return this -> ultiPoints;
}

int Warrior :: getMaxUltiPoints()
{
    return this -> maxUlti;
}

int Warrior :: useUlti(ICharacter *enemie)
{
    int ultiDamage = 0;

    cout << "\nGuerreiro ativa ""Boxe Furioso!"" !\n\n";

    sleep(2);

    int random = 0;

    int contador = 1;

    while(1)
    {

        cout << string( 100, '\n' );

        ultiDamage += 250; 

        cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
            <<"         COMBO "<<contador<<"x ("<<ultiDamage<<") ";
            cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

        random = (rand() % 7) + 1;

        if(random == 5){ break ;}

        contador++;

        sleep(2);

    }





    enemie->receiveDamagePhys(ultiDamage);

    cout<<"\n\n-+-+-+- "<<ultiDamage<<" DE DANO FEITO -+-+-+-\n\n";

    sleep(3);

    this->ultiPoints = 0;
    
    return ultiDamage;
}

int Warrior :: bulKathos()
{
    int damage = 700, critical;
    float strengh = this -> physicalStrenght;

    critical = (rand () % 3);

    if (critical == 3)
    damage *= 2 + (strengh / 100);

    else
    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO (BUL-KHATOS: ESPADA LENDARIA) -+-+-+-\n\n";

    sleep(3);

    return damage;
}

void Warrior :: removePoison()
{

    this->isPoisoned = 0;

}

int Warrior :: getPoison()
{
    return this->isPoisoned;
}

int Warrior :: addPoison()
{
    this->isPoisoned = 1;
    return 0;
}

void Warrior :: removeConfusion()
{

    this->isConfused = 0;

}

int Warrior :: getConfusion()
{
    return this->isConfused;
}

void Warrior :: addConfusion()
{
    this->isConfused = 1;
}

int Warrior :: removeBleed()
{
    this->isBleeding = 0;
    return 0;
}

int Warrior :: getBleed()
{
    return this->isBleeding;
}

int Warrior :: addBleed()
{
    this->isBleeding = 1;
    return 0;
}

int Warrior :: getNumberRound()
{
    return this->numberRound;
}

int Warrior :: returnDamageEnemy()
{
    return this->weapons->weaponDamage;
}


string Warrior :: returnWeaponStringEnemy()
{
    return this->weapons->currentWeaponName;
}


void Warrior :: changeEnemyWeaponLevel()
{
    this->weapons->weaponLevel = 0;

    this->weapons->weaponDamage = weapons->weapons[ weaponIndex[0] ];

    this->weapons->currentWeaponName = weapons->weaponName[ weaponIndex[0] ];
}




Warrior :: ~Warrior() //Função para destruir o personagem
{
    delete magic;
    delete weapons;
    

};


//************************************************************************** PALADINOS //***************************************************** 

Paladin :: Paladin(Magic *magic, Weapons *weapons)
{
    srand(time(0));; //Seed do gerador de números aleátorios

    //Atributos
    this -> hp = attributes [0]; 
    this -> maxMana = attributes [1];
    this -> physicalStrenght = attributes [2];
    this -> magicalStrenght = attributes [3];
    this -> armor = attributes [4];
    this -> magicalResistance = attributes [5];
    this -> agility = attributes [6];
    this -> maxUlti = 80;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this ->isPoisoned = 0;
    this ->isConfused = 0;
    this ->rounds = 0;

    this->classname = "Paladino";

    this->numberRound = -1;




    this-> maxHp = attributes[0];

    magic -> initialMp(this-> maxMana);

    weaponIndex[0] = 4;
    weaponIndex[1] = 5;

    spellIndex[0] = 0;
    spellIndex[1] = 4;
    spellIndex[2] = 6;

}

int Paladin :: dodgeCalculator() //Função para calcular a esquiva
{

    int dodge = (rand() % 100) + 1; //Sorteia um número de 1 a 100 

    if (dodge < this->agility/2){cout<<"-+-+-+- ESQUIVOU! -+-+-+-"; sleep(2); return 1;} //O personagem esquiva se a porcentagen for menor que a agilidade 

    else 
    return 0;
}

int Paladin :: receiveDamagePhys(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->armor / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}

int Paladin :: receiveDamageMag(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->magicalResistance / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}


int Paladin :: receiveDamagePure(int damage)
{

    if (damage > this -> hp)
            this -> hp = 0;

    else{ this->hp -= damage;}

}



int Paladin :: physicalDamageCalculator (ICharacter *enemie) //Função para calcular o dano físico infligido no inimigo
{
    int damage = (rand() % 200) + 1;

    damage += this -> weapons ->  returnDamage () - 200;

    float strengh = this -> physicalStrenght;

    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

   sleep(1);

   int random = (rand() % 6) + 1;

   if(random == 4)
   {
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; enemie->addBleed();   }

    }


    return damage;
}

int Paladin :: magicalDamageCalculator (int escolha) //Função para calcular o dano mágico infligido no inimigo
{
    int damage = magic->baseMagicDamage(escolha);
    
    float magicalStrengh = this-> magicalStrenght;

    if (damage != -1)
    {
        damage *=  1 + (magicalStrengh / 100.0);



        cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

        sleep(3);


        return damage;
    }
    
    else
    cout << "\n" << "Pontos de mana insuficientes" << "\n";

    return -1;
}

int Paladin :: changeWeapon() //Função para a troca de armas
{
    int a = weapons -> upgrade(weaponIndex);

    sleep(2);

    return a;
}

void Paladin :: initializeClass()
{
    weapons->setInicialDamage(weaponIndex[0]);
    magic->initialMp(maxMana);
}


int Paladin :: imprime()
{

//cout<<"\n HP "<<this->hp<<"\n";

    return hp;
}



int Paladin :: showMagicMenu(ICharacter *p2) // IF diferente de 0 executar receive damage no main
{

    while(1){

    cout << string( 100, '\n' );


    cout<<"-+-+-+-+-+-+-+-+- SELECIONAR MAGIA -+-+-+-+-+-+-+-+-";

    int counter = 0;

    cout<<"\n\n";

    cout<<"0. Voltar"<<"\n";

    for(int i : this->spellIndex)
    {
        if(i == -1){ break; }

        counter++;

        cout<<counter<<". "<<magic->magicName[i]<<"\n";
        

    }

    int breaker = 0;

    int answer = 0;


    while(1){
        cout<<"\n";
        cout<<": ";

        cin>>answer;

        if(answer == 0){ return -2;} // !!!!!!!!!!!!!! IMPORTANTE

        for(int i = 0; i < counter; i++ )
        {

            if(answer - 1 == i){ breaker = 1; break;}

        }

        if(breaker == 1){ break; }

        else{ cout<<"OPCAO INVALIDA! TENTE NOVAMENTE\n"; }

    }

    if(magic->mp > magic->manaWaste[ spellIndex[answer-1] ])
    {

        if(magic->typeMagic[ spellIndex[answer-1] ] == 0){ 
            
            hp += magic->magic[answer - 1]; magic->mp -= magic->manaWaste[ spellIndex[answer-1] ]; 
            cout<<"\n-+-+-+ CUROU "<<magic->magic[answer - 1]<<" -+-+-+-\n\n";  
            
            if(this->hp > this->maxHp){ hp = maxHp;}

                sleep(3);

            return 0; 
            } 

    }

    int random = 0;

    int damage = 0;

    if(magic->typeMagic[ spellIndex[answer-1] ] != 0 && magic->mp > magic->manaWaste[ spellIndex[answer-1] ] )
    {

        if( magic->typeMagic[ spellIndex[answer-1] ] == 2){ random = (rand() % 5) + 1; if(random == 3 || random == 2){ p2->addPoison(); cout<<"\n\n-+-+-+- ENVENENADO -+-+-+-\n\n";} }

         if( magic->typeMagic[ spellIndex[answer-1] ] == 3){ random = (rand() % 7) + 1; if(random == 3 || random == 2){ p2->addConfusion(); cout<<"\n\n-+-+-+- VOCE ESTA CONFUSO -+-+-+-\n\n";} }

        damage = magicalDamageCalculator(spellIndex[answer-1]);
        return damage;
    }


    if (magic->mp < magic->manaWaste[ spellIndex[answer-1] ]){cout<<"\n-+-+ MANA INSUFICIENTE -+-+-\n"; return -2;}
    }

   
    
    cout<<"\n";
}

int Paladin :: addMana()
{
    int extraMana = magic->manaAfterRound();

    if(extraMana > maxMana)
    {
        this->magic->mp = maxMana;
    }

}

void Paladin :: seeStats(ICharacter *p2)
{
    float porcentagem = (float)(this->hp) / (float)(this->maxHp); 

    float lifeDivisor = this->maxHp / 10;

    porcentagem *= 100;

    int counter = 1;

    cout << string( 100, '\n' );

    cout<<"+- STATUS PLAYER ( "<<this->classname<<" ) -+";

    cout << string(3, '\n');

    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= this->hp) { break; }

        else{counter++; cout<<"#"; lifeDivisor += this->maxHp / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<(int)(porcentagem)<<"%"<<" ( "<<this->hp<<"hp ) "<<"\n\n";
    
    cout<<"-Mana Points: "<<this->magic->mp<<"\n\n";

    cout<<"-Ulti Points" << "(MAX-" << this->maxUlti <<"): "<<this->ultiPoints<<"\n\n";
    
    cout<<"-Arma atual: "<<weapons->currentWeaponName<<" ( Dano: "<<weapons->weaponDamage<<" )"<<"\n\n\n";

    cout<<"-Envenenado: ";

    if(this->getPoison() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}

    cout<<"-Sangrando: ";

    if(this->getBleed() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}


    cout<<"-----------------------------------------------------------------------------\n\n";

    cout<<"HP INIMIGO:\n\n";

    counter = 1;

    porcentagem = (float)(p2->returnHp()) / (float)(p2->returnMaxHp()); 

    lifeDivisor = p2->returnMaxHp()  / 10;

    porcentagem *= 100;


    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= p2->imprime()) { break; }

        else{counter++; cout<<"#"; lifeDivisor += p2->returnMaxHp() / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<"\n\n";

    int keyPressed;

    while(1)
    {

        cout<<"\n\n\n\nDIGITE 0 PARA SAIR\n\n";

        cout<<"\n:";

        cin>>keyPressed;

        if(keyPressed == 0){ break; }



    }


}

int Paladin :: returnHp()
{
    return this->hp;
}

int Paladin :: returnMaxHp()
{
    return this->maxHp;
}


int Paladin :: addUltiPoints()
{
    if (ultiPoints < maxUlti)
    {
        ultiPoints += 10;
    }
    
}

int Paladin :: getUltiPoints()
{
    return this -> ultiPoints;
}

int Paladin :: getMaxUltiPoints()
{
    return this -> maxUlti;
}

int Paladin :: useUlti(ICharacter *enemie)
{
    int ultiDamage = 1000;

    cout << "\nPaladino ativa > Aposta Divina < !\n";

    if(enemie->imprime() % 2 == 1){ cout<<"\n\n: SUCESSO NA APOSTA! "; enemie->receiveDamagePure( (int) (enemie->imprime() / 2)  ) ; cout<<"Metade da vida inimiga foi ceifada\n\n"; }

    else{ cout<<"\n\n: FALHA NA APOSTA!\n\n";}

    sleep(3);

    this->ultiPoints = 0;
    
    return 0;
}

int Paladin :: bulKathos()
{
    int damage = 700, critical;
    float strengh = this -> physicalStrenght;

    critical = (rand () % 3);

    if (critical == 3)
    damage *= 2 + (strengh / 100);

    else
    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO (BUL-KATHOS: ESPADA LENDARIA) -+-+-+-\n\n";

    sleep(3);

    return damage;
}

void Paladin :: removePoison()
{

    this->isPoisoned = 0;

}

int Paladin :: getPoison()
{
    return this->isPoisoned;
}

int Paladin :: addPoison()
{
    this->isPoisoned = 1;
    return 0;
}

void Paladin :: removeConfusion()
{

    this->isConfused = 0;

}

int Paladin :: getConfusion()
{
    return this->isConfused;
}

void Paladin :: addConfusion()
{
    this->isConfused = 1;
}


int Paladin :: removeBleed()
{
    this->isBleeding = 0;
    return 0;
}

int Paladin :: getBleed()
{
    return this->isBleeding;
}

int Paladin :: addBleed()
{
    this->isBleeding = 1;
    return 0;
}


int Paladin :: getNumberRound()
{
    return this->numberRound;
}


int Paladin :: returnDamageEnemy()
{
    return this->weapons->weaponDamage;
}


string Paladin :: returnWeaponStringEnemy()
{
    return this->weapons->currentWeaponName;
}


void Paladin :: changeEnemyWeaponLevel()
{
    this->weapons->weaponLevel = 0;

    this->weapons->weaponDamage = weapons->weapons[ weaponIndex[0] ];

    this->weapons->currentWeaponName = weapons->weaponName[ weaponIndex[0] ];
}


Paladin :: ~Paladin() //Função para destruir o personagem
{
    delete magic;
    delete weapons;
    

};





//********************************************************************* THIEF *********************************************************** 







Thief :: Thief(Magic *magic, Weapons *weapons)
{
    srand(time(0));; //Seed do gerador de números aleátorios

    //Atributos
    this -> hp = attributes [0]; 
    this -> maxMana = attributes [1];
    this -> physicalStrenght = attributes [2];
    this -> magicalStrenght = attributes [3];
    this -> armor = attributes [4];
    this -> magicalResistance = attributes [5];
    this -> agility = attributes [6];
    this -> maxUlti = 40;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this->isPoisoned = 0;
    this->isConfused = 0;

    this->classname = "Ladrao";

    this->numberRound = -1;


    this-> maxHp = attributes[0];

    magic -> initialMp(this-> maxMana);

    weaponIndex[0] = 0;
    weaponIndex[1] = 2;
    weaponIndex[2] = 3;
    weaponIndex[3] = 5;
    

    spellIndex[0] = 5;
    spellIndex[1] = 6;


}

int Thief :: dodgeCalculator() //Função para calcular a esquiva
{

    int dodge = (rand() % 100) + 1; //Sorteia um número de 1 a 100 

    if (dodge < this->agility/2){cout<<"-+-+-+- ESQUIVOU! -+-+-+-"; sleep(2); return 1;} //O personagem esquiva se a porcentagen for menor que a agilidade 

    else 
    return 0;
}

int Thief :: receiveDamagePhys(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->armor / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}

int Thief :: receiveDamageMag(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->magicalResistance / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}


int Thief :: receiveDamagePure(int damage)
{

    if (damage > this -> hp)
            this -> hp = 0;

    else{ this->hp -= damage;}

}



int Thief :: physicalDamageCalculator (ICharacter *enemie) //Função para calcular o dano físico infligido no inimigo
{
    int damage = (rand() % 200) + 1;

    damage += this -> weapons ->  returnDamage () - 200;

    float strengh = this -> physicalStrenght;

    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

   sleep(1);

   int random = (rand() % 6) + 1;

   if(random == 4)
   {
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; enemie->addBleed();   }

    }


    return damage;
}

int Thief :: magicalDamageCalculator (int escolha) //Função para calcular o dano mágico infligido no inimigo
{
    int damage = magic->baseMagicDamage(escolha);
    
    float magicalStrengh = this-> magicalStrenght;

    if (damage != -1)
    {
        damage *=  1 + (magicalStrengh / 100.0);



        cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

        sleep(3);


        return damage;
    }
    
    else
    cout << "\n" << "Pontos de mana insuficientes" << "\n";

    return -1;
}

int Thief :: changeWeapon() //Função para a troca de armas
{
    int a = weapons -> upgrade(weaponIndex);

    sleep(2);

    return a;
}

void Thief :: initializeClass()
{
    weapons->setInicialDamage(weaponIndex[0]);
    magic->initialMp(maxMana);
}


int Thief :: imprime()
{

//cout<<"\n HP "<<this->hp<<"\n";

    return hp;
}



int Thief :: showMagicMenu(ICharacter *p2) // IF diferente de 0 executar receive damage no main
{

    while(1){

    cout << string( 100, '\n' );


    cout<<"-+-+-+-+-+-+-+-+- SELECIONAR MAGIA -+-+-+-+-+-+-+-+-";

    int counter = 0;

    cout<<"\n\n";

    cout<<"0. Voltar"<<"\n";

    for(int i : this->spellIndex)
    {
        if(i == -1){ break; }

        counter++;

        cout<<counter<<". "<<magic->magicName[i]<<"\n";
        

    }

    int breaker = 0;

    int answer = 0;


    while(1){
        cout<<"\n";
        cout<<": ";

        cin>>answer;

        if(answer == 0){ return -2;} // !!!!!!!!!!!!!! IMPORTANTE

        for(int i = 0; i < counter; i++ )
        {

            if(answer - 1 == i){ breaker = 1; break;}

        }
        if(breaker == 1){ break; }

        else{ cout<<"OPCAO INVALIDA! TENTE NOVAMENTE\n"; }

    }

    if(magic->mp > magic->manaWaste[ spellIndex[answer-1] ])
    {

        if(magic->typeMagic[ spellIndex[answer-1] ] == 0){ 
            
            hp += magic->magic[answer - 1]; magic->mp -= magic->manaWaste[ spellIndex[answer-1] ]; 
            cout<<"\n-+-+-+ CUROU "<<magic->magic[answer - 1]<<" -+-+-+-\n\n";  
            
            if(this->hp > this->maxHp){ hp = maxHp;}

                sleep(3);

            return 0; 
            } 

    }

    int random = 0;

    int damage = 0;

    if(magic->typeMagic[ spellIndex[answer-1] ] != 0 && magic->mp > magic->manaWaste[ spellIndex[answer-1] ] )
    {

        if( magic->typeMagic[ spellIndex[answer-1] ] == 2){ random = (rand() % 5) + 1; if(random == 3 || random == 2){ p2->addPoison(); cout<<"\n\n-+-+-+- ENVENENADO -+-+-+-\n\n";} }

         if( magic->typeMagic[ spellIndex[answer-1] ] == 3){ random = (rand() % 7) + 1; if(random == 3 || random == 2){ p2->addConfusion(); cout<<"\n\n-+-+-+- VOCE ESTA CONFUSO -+-+-+-\n\n";} }

        damage = magicalDamageCalculator(spellIndex[answer-1]);
        return damage;
    }


    if (magic->mp < magic->manaWaste[ spellIndex[answer-1] ]){cout<<"\n-+-+ MANA INSUFICIENTE -+-+-\n"; return -2;}
    }

   
    
    cout<<"\n";
}

int Thief :: addMana()
{
    int extraMana = magic->manaAfterRound();

    if(extraMana > maxMana)
    {
        this->magic->mp = maxMana;
    }

}

void Thief :: seeStats(ICharacter *p2)
{
    float porcentagem = (float)(this->hp) / (float)(this->maxHp); 

    float lifeDivisor = this->maxHp / 10;

    porcentagem *= 100;

    int counter = 1;

    cout << string( 100, '\n' );

    cout<<"+- STATUS PLAYER ( "<<this->classname<<" ) -+";

    cout << string(3, '\n');

    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= this->hp) { break; }

        else{counter++; cout<<"#"; lifeDivisor += this->maxHp / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<(int)(porcentagem)<<"%"<<" ( "<<this->hp<<"hp ) "<<"\n\n";
    
    cout<<"-Mana Points: "<<this->magic->mp<<"\n\n";

    cout<<"-Ulti Points" << "(MAX-" << this->maxUlti <<"): "<<this->ultiPoints<<"\n\n";
    
    cout<<"-Arma atual: "<<weapons->currentWeaponName<<" ( Dano: "<<weapons->weaponDamage<<" )"<<"\n\n\n";

    cout<<"-Envenenado: ";

    if(this->getPoison() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}

    cout<<"-Sangrando: ";

    if(this->getBleed() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}


    cout<<"-----------------------------------------------------------------------------\n\n";

    cout<<"HP INIMIGO:\n\n";

    counter = 1;

    porcentagem = (float)(p2->returnHp()) / (float)(p2->returnMaxHp()); 

    lifeDivisor = p2->returnMaxHp()  / 10;

    porcentagem *= 100;


    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= p2->imprime()) { break; }

        else{counter++; cout<<"#"; lifeDivisor += p2->returnMaxHp() / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<"\n\n";

    int keyPressed;

    while(1)
    {

        cout<<"\n\n\n\nDIGITE 0 PARA SAIR\n\n";

        cout<<"\n:";

        cin>>keyPressed;

        if(keyPressed == 0){ break; }



    }


}

int Thief :: returnHp()
{
    return this->hp;
}

int Thief :: returnMaxHp()
{
    return this->maxHp;
}


int Thief :: addUltiPoints()
{
    if (ultiPoints < maxUlti)
    {
        ultiPoints += 10;
    }
    
}

int Thief :: getUltiPoints()
{
    return this -> ultiPoints;
}

int Thief :: getMaxUltiPoints()
{
    return this -> maxUlti;
}

int Thief :: useUlti(ICharacter *enemie)
{

    cout<<"\n\n-=-=-=-=-=-=-=-=- LADRAO ATIVOU: PASSAR A MAO -=-=-=-=-=-=-=-=-\n\n";

   
    this->weapons->weaponDamage = enemie->returnDamageEnemy();

    this->weapons->currentWeaponName = enemie->returnWeaponStringEnemy();

    enemie->changeEnemyWeaponLevel();

    cout<<"\n\t"<<this->weapons->currentWeaponName<<" ROUBADA COM SUCESSO! ( "<<this->weapons->weaponDamage<<" dano )\n\n";

    cout<<"\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";

    this->ultiPoints = 0;

    sleep(3);

}

int Thief :: bulKathos()
{
    int damage = 700, critical;
    float strengh = this -> physicalStrenght;

    critical = (rand () % 3);

    if (critical == 3)
    damage *= 2 + (strengh / 100);

    else
    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO (BUL-KATHOS: ESPADA LENDARIA) -+-+-+-\n\n";

    sleep(3);

    return damage;
}

void Thief :: removePoison()
{

    this->isPoisoned = 0;

}

int Thief :: getPoison()
{
    return this->isPoisoned;
}

int Thief :: addPoison()
{
    this->isPoisoned = 1;
    return 0;
}

void Thief :: removeConfusion()
{

    this->isConfused = 0;

}

int Thief :: getConfusion()
{
    return this->isConfused;
}

void Thief :: addConfusion()
{
    this->isConfused = 1;
}


int Thief :: removeBleed()
{
    this->isBleeding = 0;
    return 0;
}

int Thief :: getBleed()
{
    return this->isBleeding;
}

int Thief :: addBleed()
{
    this->isBleeding = 1;
    return 0;
}


int Thief :: getNumberRound()
{
    return this->numberRound;
}


int Thief :: returnDamageEnemy()
{
    return this->weapons->weaponDamage;
}


string Thief :: returnWeaponStringEnemy()
{
    return this->weapons->currentWeaponName;
}


void Thief :: changeEnemyWeaponLevel()
{
    this->weapons->weaponLevel = 0;

    this->weapons->weaponDamage = weapons->weapons[ weaponIndex[0] ];

    this->weapons->currentWeaponName = weapons->weaponName[ weaponIndex[0] ];
}


Thief :: ~Thief() //Função para destruir o personagem
{
    delete magic;
    delete weapons;
    

};



//************************************************************************ ZOMBIE *******************************************************************/ 


Zombie :: Zombie(Magic *magic, Weapons *weapons)
{
    srand(time(0));; //Seed do gerador de números aleátorios

    //Atributos
    this -> hp = attributes [0]; 
    this -> maxMana = attributes [1];
    this -> physicalStrenght = attributes [2];
    this -> magicalStrenght = attributes [3];
    this -> armor = attributes [4];
    this -> magicalResistance = attributes [5];
    this -> agility = attributes [6];
    this -> maxUlti = 40;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this->isPoisoned = 0;
    this->isConfused = 0;

    this->classname = "Zumbi";

    this->numberRound = -1;

    this-> maxHp = attributes[0];

    magic -> initialMp(this-> maxMana);

    weaponIndex[0] = 0;
    weaponIndex[1] = 1;
    weaponIndex[2] = 2;

    spellIndex[0] = 5;


}

int Zombie :: dodgeCalculator() //Função para calcular a esquiva
{

    int dodge = (rand() % 100) + 1; //Sorteia um número de 1 a 100 

    if (dodge < this->agility/2){cout<<"-+-+-+- ESQUIVOU! -+-+-+-"; sleep(2); return 1;} //O personagem esquiva se a porcentagen for menor que a agilidade 

    else 
    return 0;
}

int Zombie :: receiveDamagePhys(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->armor / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}

int Zombie :: receiveDamageMag(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->magicalResistance / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}


int Zombie :: receiveDamagePure(int damage)
{

    if (damage > this -> hp)
            this -> hp = 0;

    else{ this->hp -= damage;}

}



int Zombie :: physicalDamageCalculator (ICharacter *enemie) //Função para calcular o dano físico infligido no inimigo
{
    int damage = (rand() % 200) + 1;

    damage += this -> weapons ->  returnDamage () - 200;

    float strengh = this -> physicalStrenght;

    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

   sleep(1);

   int random = (rand() % 6) + 1;

   if(random == 4)
   {
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; enemie->addBleed();   }

    }


    return damage;
}

int Zombie :: magicalDamageCalculator (int escolha) //Função para calcular o dano mágico infligido no inimigo
{
    int damage = magic->baseMagicDamage(escolha);
    
    float magicalStrengh = this-> magicalStrenght;

    if (damage != -1)
    {
        damage *=  1 + (magicalStrengh / 100.0);



        cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

        sleep(3);


        return damage;
    }
    
    else
    cout << "\n" << "Pontos de mana insuficientes" << "\n";

    return -1;
}

int Zombie :: changeWeapon() //Função para a troca de armas
{
    int a = weapons -> upgrade(weaponIndex);

    sleep(2);

    return a;
}

void Zombie :: initializeClass()
{
    weapons->setInicialDamage(weaponIndex[0]);
    magic->initialMp(maxMana);
}


int Zombie :: imprime()
{

//cout<<"\n HP "<<this->hp<<"\n";

    return hp;
}



int Zombie :: showMagicMenu(ICharacter *p2) // IF diferente de 0 executar receive damage no main
{

    while(1){

    cout << string( 100, '\n' );


    cout<<"-+-+-+-+-+-+-+-+- SELECIONAR MAGIA -+-+-+-+-+-+-+-+-";

    int counter = 0;

    cout<<"\n\n";

    cout<<"0. Voltar"<<"\n";

    for(int i : this->spellIndex)
    {
        if(i == -1){ break; }

        counter++;

        cout<<counter<<". "<<magic->magicName[i]<<"\n";
        

    }

    int breaker = 0;

    int answer = 0;


    while(1){
        cout<<"\n";
        cout<<": ";

        cin>>answer;

        if(answer == 0){ return -2;} // !!!!!!!!!!!!!! IMPORTANTE

        for(int i = 0; i < counter; i++ )
        {

            if(answer - 1 == i){ breaker = 1; break;}

        }

        if(breaker == 1){ break; }

        else{ cout<<"OPCAO INVALIDA! TENTE NOVAMENTE\n"; }

    }

    if(magic->mp > magic->manaWaste[ spellIndex[answer-1] ])
    {

        if(magic->typeMagic[ spellIndex[answer-1] ] == 0){ 
            
            hp += magic->magic[answer - 1]; magic->mp -= magic->manaWaste[ spellIndex[answer-1] ]; 
            cout<<"\n-+-+-+ CUROU "<<magic->magic[answer - 1]<<" -+-+-+-\n\n";  
            
            if(this->hp > this->maxHp){ hp = maxHp;}

                sleep(3);

            return 0; 
            } 

    }

    int random = 0;

    int damage = 0;

    if(magic->typeMagic[ spellIndex[answer-1] ] != 0 && magic->mp > magic->manaWaste[ spellIndex[answer-1] ] )
    {

        if( magic->typeMagic[ spellIndex[answer-1] ] == 2){ random = (rand() % 5) + 1; if(random == 3 || random == 2){ p2->addPoison(); cout<<"\n\n-+-+-+- ENVENENADO -+-+-+-\n\n";} }

         if( magic->typeMagic[ spellIndex[answer-1] ] == 3){ random = (rand() % 7) + 1; if(random == 3 || random == 2){ p2->addConfusion(); cout<<"\n\n-+-+-+- VOCE ESTA CONFUSO -+-+-+-\n\n";} }

        damage = magicalDamageCalculator(spellIndex[answer-1]);
        return damage;
    }


    if (magic->mp < magic->manaWaste[ spellIndex[answer-1] ]){cout<<"\n-+-+ MANA INSUFICIENTE -+-+-\n"; return -2;}
    }

   
    
    cout<<"\n";
}

int Zombie :: addMana()
{
    int extraMana = magic->manaAfterRound();

    if(extraMana > maxMana)
    {
        this->magic->mp = maxMana;
    }

}

void Zombie :: seeStats(ICharacter *p2)
{
    float porcentagem = (float)(this->hp) / (float)(this->maxHp); 

    float lifeDivisor = this->maxHp / 10;

    porcentagem *= 100;

    int counter = 1;

    cout << string( 100, '\n' );

    cout<<"+- STATUS PLAYER ( "<<this->classname<<" ) -+";

    cout << string(3, '\n');

    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= this->hp) { break; }

        else{counter++; cout<<"#"; lifeDivisor += this->maxHp / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<(int)(porcentagem)<<"%"<<" ( "<<this->hp<<"hp ) "<<"\n\n";
    
    cout<<"-Mana Points: "<<this->magic->mp<<"\n\n";

    cout<<"-Ulti Points" << "(MAX-" << this->maxUlti <<"): "<<this->ultiPoints<<"\n\n";
    
    cout<<"-Arma atual: "<<weapons->currentWeaponName<<" ( Dano: "<<weapons->weaponDamage<<" )"<<"\n\n\n";

    cout<<"-Envenenado: ";

    if(this->getPoison() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}

    cout<<"-Sangrando: ";

    if(this->getBleed() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}


    cout<<"-----------------------------------------------------------------------------\n\n";

    cout<<"HP INIMIGO:\n\n";

    counter = 1;

    porcentagem = (float)(p2->returnHp()) / (float)(p2->returnMaxHp()); 

    lifeDivisor = p2->returnMaxHp()  / 10;

    porcentagem *= 100;


    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= p2->imprime()) { break; }

        else{counter++; cout<<"#"; lifeDivisor += p2->returnMaxHp() / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<"\n\n";

    int keyPressed;

    while(1)
    {

        cout<<"\n\n\n\nDIGITE 0 PARA SAIR\n\n";

        cout<<"\n:";

        cin>>keyPressed;

        if(keyPressed == 0){ break; }



    }


}

int Zombie :: returnHp()
{
    return this->hp;
}

int Zombie :: returnMaxHp()
{
    return this->maxHp;
}


int Zombie :: addUltiPoints()
{
    if (ultiPoints < maxUlti)
    {
        ultiPoints += 10;
    }
    
}

int Zombie :: getUltiPoints()
{
    return this -> ultiPoints;
}

int Zombie :: getMaxUltiPoints()
{
    return this -> maxUlti;
}

int Zombie :: useUlti(ICharacter *enemie)
{

    if( this->numberRound == -1){ 
        
        
            this->numberRound = 0;   this->ultiPoints = 0;          
    
    
            cout<<"\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
            <<"ZUMBI USOU SUA ULT E VOLTARA A VIDA SE MORRER NOS PROXIMOS 5 ROUNDS!"
            <<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";

            sleep(2);
            }


    if( this->numberRound > -1 && this->numberRound < 4)
    {

        this->numberRound++;
        
        if(this->hp == 0){ 
            
        this->hp = (int)(this->maxHp / 5);  
        
            cout<<"\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
            <<"         ZUMBI USOU NECROMANCIA PARA VOLTAR A VIDA!"
            <<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";

            sleep(2);
        
         }


    }

    if(this->numberRound == 4){ this->numberRound = -1; 
    
        cout<<"\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
        <<"            EFEITO DA NECROMANCIA ACABOU!"
        <<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";
    
    
    }


}

int Zombie :: bulKathos()
{
    int damage = 700, critical;
    float strengh = this -> physicalStrenght;

    critical = (rand () % 3);

    if (critical == 3)
    damage *= 2 + (strengh / 100);

    else
    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO (BUL-KATHOS: ESPADA LENDARIA) -+-+-+-\n\n";

    sleep(3);

    return damage;
}

void Zombie :: removePoison()
{

    this->isPoisoned = 0;

}

int Zombie :: getPoison()
{
    return this->isPoisoned;
}

int Zombie :: addPoison()
{
    this->isPoisoned = 1;
    return 0;
}

void Zombie :: removeConfusion()
{

    this->isConfused = 0;

}

int Zombie :: getConfusion()
{
    return this->isConfused;
}

void Zombie :: addConfusion()
{
    this->isConfused = 1;
}


int Zombie :: removeBleed()
{
    this->isBleeding = 0;
    return 0;
}

int Zombie :: getBleed()
{
    return this->isBleeding;
}

int Zombie :: addBleed()
{
    this->isBleeding = 1;
    return 0;
}


int Zombie :: getNumberRound()
{
    return this->numberRound;
}


int Zombie :: returnDamageEnemy()
{
    return this->weapons->weaponDamage;
}


string Zombie :: returnWeaponStringEnemy()
{
    return this->weapons->currentWeaponName;
}


void Zombie :: changeEnemyWeaponLevel()
{
    this->weapons->weaponLevel = 0;

    this->weapons->weaponDamage = weapons->weapons[ weaponIndex[0] ];

    this->weapons->currentWeaponName = weapons->weaponName[ weaponIndex[0] ];
}


Zombie :: ~Zombie() //Função para destruir o personagem
{
    delete magic;
    delete weapons;
    

};


//********************************************** ANIMAL ***************************************/ 


Animal :: Animal(Magic *magic, Weapons *weapons)
{
    srand(time(0));; //Seed do gerador de números aleátorios

    //Atributos
    this -> hp = attributes [0]; 
    this -> maxMana = attributes [1];
    this -> physicalStrenght = attributes [2];
    this -> magicalStrenght = attributes [3];
    this -> armor = attributes [4];
    this -> magicalResistance = attributes [5];
    this -> agility = attributes [6];
    this -> maxUlti = 70;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this ->isPoisoned = 0;
    this ->isConfused = 0;
    this ->rounds = 0;

    this->classname = "Animal";



    this-> maxHp = attributes[0];

    magic -> initialMp(this-> maxMana);

    weaponIndex[0] = 1;

    spellIndex[0] = 2;

}

int Animal :: dodgeCalculator() //Função para calcular a esquiva
{

    int dodge = (rand() % 100) + 1; //Sorteia um número de 1 a 100 

    if (dodge < this->agility/2){cout<<"-+-+-+- ESQUIVOU! -+-+-+-"; sleep(2); return 1;} //O personagem esquiva se a porcentagen for menor que a agilidade 

    else 
    return 0;
}

int Animal :: receiveDamagePhys(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->armor / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}

int Animal :: receiveDamageMag(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->magicalResistance / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}


int Animal :: receiveDamagePure(int damage)
{

    if (damage > this -> hp)
            this -> hp = 0;

    else{ this->hp -= damage;}

}



int Animal :: physicalDamageCalculator (ICharacter *enemie) //Função para calcular o dano físico infligido no inimigo
{
    int damage = (rand() % 200) + 1;

    damage += this -> weapons ->  returnDamage () - 200;

    float strengh = this -> physicalStrenght;

    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

   sleep(1);

   int random = (rand() % 6) + 1;

   if(random == 4)
   {
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; enemie->addBleed();   }

    }


    return damage;
}

int Animal :: magicalDamageCalculator (int escolha) //Função para calcular o dano mágico infligido no inimigo
{
    int damage = magic->baseMagicDamage(escolha);
    
    float magicalStrengh = this-> magicalStrenght;

    if (damage != -1)
    {
        damage *=  1 + (magicalStrengh / 100.0);



        cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

        sleep(3);


        return damage;
    }
    
    else
    cout << "\n" << "Pontos de mana insuficientes" << "\n";

    return -1;
}

int Animal :: changeWeapon() //Função para a troca de armas
{
    int a = weapons -> upgrade(weaponIndex);

    sleep(2);

    return a;
}

void Animal :: initializeClass()
{
    weapons->setInicialDamage(weaponIndex[0]);
    magic->initialMp(maxMana);
}


int Animal :: imprime()
{

//cout<<"\n HP "<<this->hp<<"\n";

    return hp;
}



int Animal :: showMagicMenu(ICharacter *p2) // IF diferente de 0 executar receive damage no main
{

    while(1){

    cout << string( 100, '\n' );


    cout<<"-+-+-+-+-+-+-+-+- SELECIONAR MAGIA -+-+-+-+-+-+-+-+-";

    int counter = 0;

    cout<<"\n\n";

    cout<<"0. Voltar"<<"\n";

    for(int i : this->spellIndex)
    {
        if(i == -1){ break; }

        counter++;

        cout<<counter<<". "<<magic->magicName[i]<<"\n";
        

    }

    int breaker = 0;

    int answer = 0;


    while(1){
        cout<<"\n";
        cout<<": ";

        cin>>answer;

        if(answer == 0){ return -2;} // !!!!!!!!!!!!!! IMPORTANTE

        for(int i = 0; i < counter; i++ )
        {

            if(answer - 1 == i){ breaker = 1; break;}

        }

        if(breaker == 1){ break; }

        else{ cout<<"OPCAO INVALIDA! TENTE NOVAMENTE\n"; }

    }

    if(magic->mp > magic->manaWaste[ spellIndex[answer-1] ])
    {

        if(magic->typeMagic[ spellIndex[answer-1] ] == 0){ 
            
            hp += magic->magic[answer - 1]; magic->mp -= magic->manaWaste[ spellIndex[answer-1] ]; 
            cout<<"\n-+-+-+ CUROU "<<magic->magic[answer - 1]<<" -+-+-+-\n\n";  
            
            if(this->hp > this->maxHp){ hp = maxHp;}

                sleep(3);

            return 0; 
            } 

    }

    int random = 0;

    int damage = 0;

    if(magic->typeMagic[ spellIndex[answer-1] ] != 0 && magic->mp > magic->manaWaste[ spellIndex[answer-1] ] )
    {

        if( magic->typeMagic[ spellIndex[answer-1] ] == 2){ random = (rand() % 5) + 1; if(random == 3 || random == 2){ p2->addPoison(); cout<<"\n\n-+-+-+- ENVENENADO -+-+-+-\n\n";} }

         if( magic->typeMagic[ spellIndex[answer-1] ] == 3){ random = (rand() % 7) + 1; if(random == 3 || random == 2){ p2->addConfusion(); cout<<"\n\n-+-+-+- VOCE ESTA CONFUSO -+-+-+-\n\n";} }

        damage = magicalDamageCalculator(spellIndex[answer-1]);
        return damage;
    }


    if (magic->mp < magic->manaWaste[ spellIndex[answer-1] ]){cout<<"\n-+-+ MANA INSUFICIENTE -+-+-\n"; return -2;}
    }

   
    
    cout<<"\n";
}

int Animal :: addMana()
{
    int extraMana = magic->manaAfterRound();

    if(extraMana > maxMana)
    {
        this->magic->mp = maxMana;
    }

}

void Animal :: seeStats(ICharacter *p2)
{
    float porcentagem = (float)(this->hp) / (float)(this->maxHp); 

    float lifeDivisor = this->maxHp / 10;

    porcentagem *= 100;

    int counter = 1;

    cout << string( 100, '\n' );

    cout<<"+- STATUS PLAYER ( "<<this->classname<<" ) -+";

    cout << string(3, '\n');

    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= this->hp) { break; }

        else{counter++; cout<<"#"; lifeDivisor += this->maxHp / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<(int)(porcentagem)<<"%"<<" ( "<<this->hp<<"hp ) "<<"\n\n";
    
    cout<<"-Mana Points: "<<this->magic->mp<<"\n\n";

    cout<<"-Ulti Points" << "(MAX-" << this->maxUlti <<"): "<<this->ultiPoints<<"\n\n";
    
    cout<<"-Arma atual: "<<weapons->currentWeaponName<<" ( Dano: "<<weapons->weaponDamage<<" )"<<"\n\n\n";

    cout<<"-Envenenado: ";

    if(this->getPoison() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}

    cout<<"-Sangrando: ";

    if(this->getBleed() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}


    cout<<"-----------------------------------------------------------------------------\n\n";

    cout<<"HP INIMIGO:\n\n";

    counter = 1;

    porcentagem = (float)(p2->returnHp()) / (float)(p2->returnMaxHp()); 

    lifeDivisor = p2->returnMaxHp()  / 10;

    porcentagem *= 100;


    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= p2->imprime()) { break; }

        else{counter++; cout<<"#"; lifeDivisor += p2->returnMaxHp() / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<"\n\n";

    int keyPressed;

    while(1)
    {

        cout<<"\n\n\n\nDIGITE 0 PARA SAIR\n\n";

        cout<<"\n:";

        cin>>keyPressed;

        if(keyPressed == 0){ break; }



    }


}

int Animal :: returnHp()
{
    return this->hp;
}

int Animal :: returnMaxHp()
{
    return this->maxHp;
}


int Animal :: addUltiPoints()
{
    if (ultiPoints < maxUlti)
    {
        ultiPoints += 10;
    }
    
}

int Animal :: getUltiPoints()
{
    return this -> ultiPoints;
}

int Animal :: getMaxUltiPoints()
{
    return this -> maxUlti;
}

int Animal :: useUlti(ICharacter *enemie)
{

    cout << "\nAnimal ativa > Gozdilla < !\n";

    this->physicalStrenght *= 1.2;

    spellIndex[1] = 1;

    spellIndex[2] = 3;

    sleep(3);

    this->ultiPoints = 0;
    
    return 0;
}

int Animal :: bulKathos()
{
    int damage = 700, critical;
    float strengh = this -> physicalStrenght;

    critical = (rand () % 3);

    if (critical == 3)
    damage *= 2 + (strengh / 100);

    else
    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO (BUL-KATHOS: ESPADA LENDARIA) -+-+-+-\n\n";

    sleep(3);

    return damage;
}

void Animal :: removePoison()
{

    this->isPoisoned = 0;

}

int Animal :: getPoison()
{
    return this->isPoisoned;
}

int Animal :: addPoison()
{
    this->isPoisoned = 1;
    return 0;
}

void Animal :: removeConfusion()
{

    this->isConfused = 0;

}

int Animal :: getConfusion()
{
    return this->isConfused;
}

void Animal :: addConfusion()
{
    this->isConfused = 1;
}


int Animal :: removeBleed()
{
    this->isBleeding = 0;
    return 0;
}

int Animal :: getBleed()
{
    return this->isBleeding;
}

int Animal :: addBleed()
{
    this->isBleeding = 1;
    return 0;
}



int Animal :: getNumberRound()
{
    return this->numberRound;
}


int Animal :: returnDamageEnemy()
{
    return this->weapons->weaponDamage;
}


string Animal :: returnWeaponStringEnemy()
{
    return this->weapons->currentWeaponName;
}


void Animal :: changeEnemyWeaponLevel()
{
    this->weapons->weaponLevel = 0;

    this->weapons->weaponDamage = weapons->weapons[ weaponIndex[0] ];

    this->weapons->currentWeaponName = weapons->weaponName[ weaponIndex[0] ];
}










Animal :: ~Animal() //Função para destruir o personagem
{
    delete magic;
    delete weapons;
    

};


/**************************************************** DRAGAO **************************************************************/ 


Dragon :: Dragon(Magic *magic, Weapons *weapons)
{
    srand(time(0));; //Seed do gerador de números aleátorios

    //Atributos
    this -> hp = attributes [0]; 
    this -> maxMana = attributes [1];
    this -> physicalStrenght = attributes [2];
    this -> magicalStrenght = attributes [3];
    this -> armor = attributes [4];
    this -> magicalResistance = attributes [5];
    this -> agility = attributes [6];
    this -> maxUlti = 70;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this ->isPoisoned = 0;
    this ->isConfused = 0;
    this ->rounds = 0;

    this->classname = "Dragao";



    this-> maxHp = attributes[0];

    magic -> initialMp(this-> maxMana);

    weaponIndex[0] = 1;

    spellIndex[0] = 1;

}

int Dragon :: dodgeCalculator() //Função para calcular a esquiva
{

    int dodge = (rand() % 100) + 1; //Sorteia um número de 1 a 100 

    if (dodge < this->agility/2){cout<<"-+-+-+- ESQUIVOU! -+-+-+-"; sleep(2); return 1;} //O personagem esquiva se a porcentagen for menor que a agilidade 

    else 
    return 0;
}

int Dragon :: receiveDamagePhys(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->armor / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}

int Dragon :: receiveDamageMag(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->magicalResistance / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}


int Dragon :: receiveDamagePure(int damage)
{

    if (damage > this -> hp)
            this -> hp = 0;

    else{ this->hp -= damage;}

}



int Dragon :: physicalDamageCalculator (ICharacter *enemie) //Função para calcular o dano físico infligido no inimigo
{
    int damage = (rand() % 200) + 1;

    damage += this -> weapons ->  returnDamage () - 200;

    float strengh = this -> physicalStrenght;

    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

   sleep(1);

   int random = (rand() % 6) + 1;

   if(random == 4)
   {
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; enemie->addBleed();   }

    }


    return damage;
}

int Dragon :: magicalDamageCalculator (int escolha) //Função para calcular o dano mágico infligido no inimigo
{
    int damage = magic->baseMagicDamage(escolha);
    
    float magicalStrengh = this-> magicalStrenght;

    if (damage != -1)
    {
        damage *=  1 + (magicalStrengh / 100.0);



        cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

        sleep(3);


        return damage;
    }
    
    else
    cout << "\n" << "Pontos de mana insuficientes" << "\n";

    return -1;
}

int Dragon :: changeWeapon() //Função para a troca de armas
{
    int a = weapons -> upgrade(weaponIndex);

    sleep(2);

    return a;
}

void Dragon :: initializeClass()
{
    weapons->setInicialDamage(weaponIndex[0]);
    magic->initialMp(maxMana);
}


int Dragon :: imprime()
{

//cout<<"\n HP "<<this->hp<<"\n";

    return hp;
}



int Dragon :: showMagicMenu(ICharacter *p2) // IF diferente de 0 executar receive damage no main
{

    while(1){

    cout << string( 100, '\n' );


    cout<<"-+-+-+-+-+-+-+-+- SELECIONAR MAGIA -+-+-+-+-+-+-+-+-";

    int counter = 0;

    cout<<"\n\n";

    cout<<"0. Voltar"<<"\n";

    for(int i : this->spellIndex)
    {
        if(i == -1){ break; }

        counter++;

        cout<<counter<<". "<<magic->magicName[i]<<"\n";
        

    }

    int breaker = 0;

    int answer = 0;


    while(1){
        cout<<"\n";
        cout<<": ";

        cin>>answer;

        if(answer == 0){ return -2;} // !!!!!!!!!!!!!! IMPORTANTE

        for(int i = 0; i < counter; i++ )
        {

            if(answer - 1 == i){ breaker = 1; break;}

        }

        if(breaker == 1){ break; }

        else{ cout<<"OPCAO INVALIDA! TENTE NOVAMENTE\n"; }

    }

    if(magic->mp > magic->manaWaste[ spellIndex[answer-1] ])
    {

        if(magic->typeMagic[ spellIndex[answer-1] ] == 0){ 
            
            hp += magic->magic[answer - 1]; magic->mp -= magic->manaWaste[ spellIndex[answer-1] ]; 
            cout<<"\n-+-+-+ CUROU "<<magic->magic[answer - 1]<<" -+-+-+-\n\n";  
            
            if(this->hp > this->maxHp){ hp = maxHp;}

                sleep(3);

            return 0; 
            } 

    }

    int random = 0;

    int damage = 0;

    if(magic->typeMagic[ spellIndex[answer-1] ] != 0 && magic->mp > magic->manaWaste[ spellIndex[answer-1] ] )
    {

        if( magic->typeMagic[ spellIndex[answer-1] ] == 2){ random = (rand() % 5) + 1; if(random == 3 || random == 2){ p2->addPoison(); cout<<"\n\n-+-+-+- ENVENENADO -+-+-+-\n\n";} }

         if( magic->typeMagic[ spellIndex[answer-1] ] == 3){ random = (rand() % 7) + 1; if(random == 3 || random == 2){ p2->addConfusion(); cout<<"\n\n-+-+-+- VOCE ESTA CONFUSO -+-+-+-\n\n";} }

        damage = magicalDamageCalculator(spellIndex[answer-1]);
        return damage;
    }


    if (magic->mp < magic->manaWaste[ spellIndex[answer-1] ]){cout<<"\n-+-+ MANA INSUFICIENTE -+-+-\n"; return -2;}
    }

   
    
    cout<<"\n";
}

int Dragon :: addMana()
{
    int extraMana = magic->manaAfterRound();

    if(extraMana > maxMana)
    {
        this->magic->mp = maxMana;
    }

}

void Dragon :: seeStats(ICharacter *p2)
{
    float porcentagem = (float)(this->hp) / (float)(this->maxHp); 

    float lifeDivisor = this->maxHp / 10;

    porcentagem *= 100;

    int counter = 1;

    cout << string( 100, '\n' );

    cout<<"+- STATUS PLAYER ( "<<this->classname<<" ) -+";

    cout << string(3, '\n');

    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= this->hp) { break; }

        else{counter++; cout<<"#"; lifeDivisor += this->maxHp / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<(int)(porcentagem)<<"%"<<" ( "<<this->hp<<"hp ) "<<"\n\n";
    
    cout<<"-Mana Points: "<<this->magic->mp<<"\n\n";

    cout<<"-Ulti Points" << "(MAX-" << this->maxUlti <<"): "<<this->ultiPoints<<"\n\n";
    
    cout<<"-Arma atual: "<<weapons->currentWeaponName<<" ( Dano: "<<weapons->weaponDamage<<" )"<<"\n\n\n";

    cout<<"-Envenenado: ";

    if(this->getPoison() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}

    cout<<"-Sangrando: ";

    if(this->getBleed() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}


    cout<<"-----------------------------------------------------------------------------\n\n";

    cout<<"HP INIMIGO:\n\n";

    counter = 1;

    porcentagem = (float)(p2->returnHp()) / (float)(p2->returnMaxHp()); 

    lifeDivisor = p2->returnMaxHp()  / 10;

    porcentagem *= 100;


    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= p2->imprime()) { break; }

        else{counter++; cout<<"#"; lifeDivisor += p2->returnMaxHp() / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<"\n\n";

    int keyPressed;

    while(1)
    {

        cout<<"\n\n\n\nDIGITE 0 PARA SAIR\n\n";

        cout<<"\n:";

        cin>>keyPressed;

        if(keyPressed == 0){ break; }



    }


}

int Dragon :: returnHp()
{
    return this->hp;
}

int Dragon :: returnMaxHp()
{
    return this->maxHp;
}


int Dragon :: addUltiPoints()
{
    if (ultiPoints < maxUlti)
    {
        ultiPoints += 10;
    }
    
}

int Dragon :: getUltiPoints()
{
    return this -> ultiPoints;
}

int Dragon :: getMaxUltiPoints()
{
    return this -> maxUlti;
}

int Dragon :: useUlti(ICharacter *enemie)
{
    cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

    cout << "\nDragao ativa > Furia ancia < !\n";

    cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";


    this->agility *= 1.2;

    int ultiDamage = 1000;

    enemie->addConfusion();

    sleep(3);

    this->ultiPoints = 0;
    
    return 0;
}

int Dragon :: bulKathos()
{
    int damage = 700, critical;
    float strengh = this -> physicalStrenght;

    critical = (rand () % 3);

    if (critical == 3)
    damage *= 2 + (strengh / 100);

    else
    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO (BUL-KATHOS: ESPADA LENDARIA) -+-+-+-\n\n";

    sleep(3);

    return damage;
}

void Dragon :: removePoison()
{

    this->isPoisoned = 0;

}

int Dragon :: getPoison()
{
    return this->isPoisoned;
}

int Dragon :: addPoison()
{
    this->isPoisoned = 1;
    return 0;
}

void Dragon :: removeConfusion()
{

    this->isConfused = 0;

}

int Dragon :: getConfusion()
{
    return this->isConfused;
}

void Dragon :: addConfusion()
{
    this->isConfused = 1;
}


int Dragon :: removeBleed()
{
    this->isBleeding = 0;
    return 0;
}

int Dragon :: getBleed()
{
    return this->isBleeding;
}

int Dragon :: addBleed()
{
    this->isBleeding = 1;
    return 0;
}


int Dragon :: getNumberRound()
{
    return this->numberRound;
}


int Dragon :: returnDamageEnemy()
{
    return this->weapons->weaponDamage;
}


string Dragon :: returnWeaponStringEnemy()
{
    return this->weapons->currentWeaponName;
}


void Dragon :: changeEnemyWeaponLevel()
{
    this->weapons->weaponLevel = 0;

    this->weapons->weaponDamage = weapons->weapons[ weaponIndex[0] ];

    this->weapons->currentWeaponName = weapons->weaponName[ weaponIndex[0] ];
}





Dragon :: ~Dragon() //Função para destruir o personagem
{
    delete magic;
    delete weapons;
    

};

/**************************************************** MAGO **************************************************/ 


Wizard :: Wizard(Magic *magic, Weapons *weapons)
{
    srand(time(0));; //Seed do gerador de números aleátorios

    //Atributos
    this -> hp = attributes [0]; 
    this -> maxMana = attributes [1];
    this -> physicalStrenght = attributes [2];
    this -> magicalStrenght = attributes [3];
    this -> armor = attributes [4];
    this -> magicalResistance = attributes [5];
    this -> agility = attributes [6];
    this -> maxUlti = 60;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this ->isPoisoned = 0;
    this ->isConfused = 0;
    this ->rounds = 0;

    this->classname = "Mago";



    this-> maxHp = attributes[0];

    magic -> initialMp(this-> maxMana);

    weaponIndex[0] = 0;
    weaponIndex[1] = 4;

    spellIndex[0] = 0;
    spellIndex[1] = 2;
    spellIndex[2] = 3;
    spellIndex[3] = 4;
    spellIndex[4] = 5;
    spellIndex[5] = 6;
}

int Wizard :: dodgeCalculator() //Função para calcular a esquiva
{

    int dodge = (rand() % 100) + 1; //Sorteia um número de 1 a 100 

    if (dodge < this->agility/2){cout<<"-+-+-+- ESQUIVOU! -+-+-+-"; sleep(2); return 1;} //O personagem esquiva se a porcentagen for menor que a agilidade 

    else 
    return 0;
}

int Wizard :: receiveDamagePhys(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->armor / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}

int Wizard :: receiveDamageMag(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->magicalResistance / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}


int Wizard :: receiveDamagePure(int damage)
{

    if (damage > this -> hp)
            this -> hp = 0;

    else{ this->hp -= damage;}

}



int Wizard :: physicalDamageCalculator (ICharacter *enemie) //Função para calcular o dano físico infligido no inimigo
{
        int damage = (rand() % 200) + 1;

    damage += this -> weapons ->  returnDamage () - 200;

    float strengh = this -> physicalStrenght;

    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

   sleep(1);

   int random = (rand() % 6) + 1;

   if(random == 4)
   {
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; enemie->addBleed();   }

    }


    return damage;
}

int Wizard :: magicalDamageCalculator (int escolha) //Função para calcular o dano mágico infligido no inimigo
{
    int damage = magic->baseMagicDamage(escolha);
    
    float magicalStrengh = this-> magicalStrenght;

    if (damage != -1)
    {
        damage *=  1 + (magicalStrengh / 100.0);



        cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

        sleep(3);


        return damage;
    }
    
    else
    cout << "\n" << "Pontos de mana insuficientes" << "\n";

    return -1;
}

int Wizard :: changeWeapon() //Função para a troca de armas
{
    int a = weapons -> upgrade(weaponIndex);

    sleep(2);

    return a;
}

void Wizard :: initializeClass()
{
    weapons->setInicialDamage(weaponIndex[0]);
    magic->initialMp(maxMana);
}


int Wizard :: imprime()
{

//cout<<"\n HP "<<this->hp<<"\n";

    return hp;
}



int Wizard :: showMagicMenu(ICharacter *p2) // IF diferente de 0 executar receive damage no main
{

    while(1){

    cout << string( 100, '\n' );


    cout<<"-+-+-+-+-+-+-+-+- SELECIONAR MAGIA -+-+-+-+-+-+-+-+-";

    int counter = 0;

    cout<<"\n\n";

    cout<<"0. Voltar"<<"\n";

    for(int i : this->spellIndex)
    {
        if(i == -1){ break; }

        counter++;

        cout<<counter<<". "<<magic->magicName[i]<<"\n";
        

    }

    int breaker = 0;

    int answer = 0;


    while(1){
        cout<<"\n";
        cout<<": ";

        cin>>answer;

        if(answer == 0){ return -2;} // !!!!!!!!!!!!!! IMPORTANTE

        for(int i = 0; i < counter; i++ )
        {

            if(answer - 1 == i){ breaker = 1; break;}

        }

        if(breaker == 1){ break; }

        else{ cout<<"OPCAO INVALIDA! TENTE NOVAMENTE\n"; }

    }

    if(magic->mp > magic->manaWaste[ spellIndex[answer-1] ])
    {

        if(magic->typeMagic[ spellIndex[answer-1] ] == 0){ 
            
            hp += magic->magic[answer - 1]; magic->mp -= magic->manaWaste[ spellIndex[answer-1] ]; 
            cout<<"\n-+-+-+ CUROU "<<magic->magic[answer - 1]<<" -+-+-+-\n\n";  
            
            if(this->hp > this->maxHp){ hp = maxHp;}

                sleep(3);

            return 0; 
            } 

    }

    int random = 0;

    int damage = 0;

    if(magic->typeMagic[ spellIndex[answer-1] ] != 0 && magic->mp > magic->manaWaste[ spellIndex[answer-1] ] )
    {

        if( magic->typeMagic[ spellIndex[answer-1] ] == 2){ random = (rand() % 5) + 1; if(random == 3 || random == 2){ p2->addPoison(); cout<<"\n\n-+-+-+- ENVENENADO -+-+-+-\n\n";} }

         if( magic->typeMagic[ spellIndex[answer-1] ] == 3){ random = (rand() % 7) + 1; if(random == 3 || random == 2){ p2->addConfusion(); cout<<"\n\n-+-+-+- VOCE ESTA CONFUSO -+-+-+-\n\n";} }

        damage = magicalDamageCalculator(spellIndex[answer-1]);
        return damage;
    }


    if (magic->mp < magic->manaWaste[ spellIndex[answer-1] ]){cout<<"\n-+-+ MANA INSUFICIENTE -+-+-\n"; return -2;}
    }

   
    
    cout<<"\n";
}

int Wizard :: addMana()
{
    int extraMana = magic->manaAfterRound();

    if(extraMana > maxMana)
    {
        this->magic->mp = maxMana;
    }

}

void Wizard :: seeStats(ICharacter *p2)
{
    float porcentagem = (float)(this->hp) / (float)(this->maxHp); 

    float lifeDivisor = this->maxHp / 10;

    porcentagem *= 100;

    int counter = 1;

    cout << string( 100, '\n' );

    cout<<"+- STATUS PLAYER ( "<<this->classname<<" ) -+";

    cout << string(3, '\n');

    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= this->hp) { break; }

        else{counter++; cout<<"#"; lifeDivisor += this->maxHp / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<(int)(porcentagem)<<"%"<<" ( "<<this->hp<<"hp ) "<<"\n\n";
    
    cout<<"-Mana Points: "<<this->magic->mp<<"\n\n";

    cout<<"-Ulti Points" << "(MAX-" << this->maxUlti <<"): "<<this->ultiPoints<<"\n\n";
    
    cout<<"-Arma atual: "<<weapons->currentWeaponName<<" ( Dano: "<<weapons->weaponDamage<<" )"<<"\n\n\n";

    cout<<"-Envenenado: ";

    if(this->getPoison() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}

    cout<<"-Sangrando: ";

    if(this->getBleed() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}


    cout<<"-----------------------------------------------------------------------------\n\n";

    cout<<"HP INIMIGO:\n\n";

    counter = 1;

    porcentagem = (float)(p2->returnHp()) / (float)(p2->returnMaxHp()); 

    lifeDivisor = p2->returnMaxHp()  / 10;

    porcentagem *= 100;


    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= p2->imprime()) { break; }

        else{counter++; cout<<"#"; lifeDivisor += p2->returnMaxHp() / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<"\n\n";

    int keyPressed;

    while(1)
    {

        cout<<"\n\n\n\nDIGITE 0 PARA SAIR\n\n";

        cout<<"\n:";

        cin>>keyPressed;

        if(keyPressed == 0){ break; }



    }


}

int Wizard :: returnHp()
{
    return this->hp;
}

int Wizard :: returnMaxHp()
{
    return this->maxHp;
}


int Wizard :: addUltiPoints()
{
    if (ultiPoints < maxUlti)
    {
        ultiPoints += 10;
    }
    
}

int Wizard :: getUltiPoints()
{
    return this -> ultiPoints;
}

int Wizard :: getMaxUltiPoints()
{
    return this -> maxUlti;
}

int Wizard :: useUlti(ICharacter *enemie)
{
    cout << string( 100, '\n' );
    int ultiChoice = 0;
    int random = 0;
    int contador = 1;
    int ultiDamage = 50;
    cout
    << "O mago usa seus poderes para enfraquecer a fronteira entre o mundo físico e o espiritual"
    << "\n\n\n"
    << "Escolha seu alter ago\n"
    << "1- Crazy Diamond\n"
    << "2- Hermit Purple\n"
    << "3- Star Platinum\n\n\n:";


    while(1)
    {
        cin >> ultiChoice;
        switch (ultiChoice)
        {
        case 1:
            this -> hp += 500;
            cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
            cout << "Crazy Diamond gentilmente cura suas feridas com seu toque";
            cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

            sleep (2);
            break;

        case 2:
            this -> agility += 5; 
            cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
            cout << "Hermit Purple aumenta sua percepcao, voce se sente mais capaz de desviar de ataques";
            cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

            sleep(2);
            break;

        case 3:

        while(1){
            cout << string( 100, '\n' );

            ultiDamage += 50; 

            cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
                <<" ORA ORA ORA ORA "<<contador<<"x ("<<ultiDamage<<") ";
                cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

            random = (rand() % 10) + 1;

            if(random == 5){ break ;}

            contador++;

            sleep(2);
            }

            break;

        default:
            continue;
        
        }

        break;
    }



    enemie->receiveDamagePhys(ultiDamage);

    sleep(3);

    this->ultiPoints = 0;
    
    return ultiDamage;
}

int Wizard :: bulKathos()
{
    int damage = 700, critical;
    float strengh = this -> physicalStrenght;

    critical = (rand () % 3);

    if (critical == 3)
    damage *= 2 + (strengh / 100);

    else
    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO (BUL-KATHOS: ESPADA LENDARIA) -+-+-+-\n\n";

    sleep(3);

    return damage;
}

void Wizard :: removePoison()
{

    this->isPoisoned = 0;

}

int Wizard :: getPoison()
{
    return this->isPoisoned;
}

int Wizard :: addPoison()
{
    this->isPoisoned = 1;
    return 0;
}

void Wizard :: removeConfusion()
{

    this->isConfused = 0;

}

int Wizard :: getConfusion()
{
    return this->isConfused;
}

void Wizard :: addConfusion()
{
    this->isConfused = 1;
}


int Wizard :: removeBleed()
{
    this->isBleeding = 0;
    return 0;
}

int Wizard :: getBleed()
{
    return this->isBleeding;
}

int Wizard :: addBleed()
{
    this->isBleeding = 1;
    return 0;
}


int Wizard :: getNumberRound()
{
    return this->numberRound;
}


int Wizard :: returnDamageEnemy()
{
    return this->weapons->weaponDamage;
}


string Wizard :: returnWeaponStringEnemy()
{
    return this->weapons->currentWeaponName;
}


void Wizard :: changeEnemyWeaponLevel()
{
    this->weapons->weaponLevel = 0;

    this->weapons->weaponDamage = weapons->weapons[ weaponIndex[0] ];

    this->weapons->currentWeaponName = weapons->weaponName[ weaponIndex[0] ];
}





Wizard :: ~Wizard() //Função para destruir o personagem
{
    delete magic;
    delete weapons;
    

};


// /*********************************************************************** TROLL **************************************/ 


Troll :: Troll(Magic *magic, Weapons *weapons)
{
    srand(time(0));; //Seed do gerador de números aleátorios

    //Atributos
    this -> hp = attributes [0]; 
    this -> maxMana = attributes [1];
    this -> physicalStrenght = attributes [2];
    this -> magicalStrenght = attributes [3];
    this -> armor = attributes [4];
    this -> magicalResistance = attributes [5];
    this -> agility = attributes [6];
    this -> maxUlti = 50;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this ->isPoisoned = 0;
    this ->isConfused = 0;
    this ->rounds = 0;

    this->classname = "Troll";



    this-> maxHp = attributes[0];

    magic -> initialMp(this-> maxMana);

    weaponIndex[0] = 0;
    weaponIndex[1] = 2;

    spellIndex[0] = 5;

}

int Troll :: dodgeCalculator() //Função para calcular a esquiva
{

    int dodge = (rand() % 100) + 1; //Sorteia um número de 1 a 100 

    if (dodge < this->agility/2){cout<<"-+-+-+- ESQUIVOU! -+-+-+-"; sleep(2); return 1;} //O personagem esquiva se a porcentagen for menor que a agilidade 

    else 
    return 0;
}

int Troll :: receiveDamagePhys(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->armor / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}

int Troll :: receiveDamageMag(int damageBase) //função para calcular o dano recebido
{
    if (dodgeCalculator() == 1) //Função para calcular a esquiva
    return 0;

    float damage = damageBase;

    float effectiveDamage2 = damage - (damage * (  (float) (this->magicalResistance / 2)  / (100.0) )); //Absorção de dano

    int effectiveDamage = effectiveDamage2;

    if (effectiveDamage > this -> hp)
    this -> hp = 0;

    else 
    this -> hp -= effectiveDamage;

    return effectiveDamage;
}


int Troll :: receiveDamagePure(int damage)
{

    if (damage > this -> hp)
            this -> hp = 0;

    else{ this->hp -= damage;}

}



int Troll :: physicalDamageCalculator (ICharacter *enemie) //Função para calcular o dano físico infligido no inimigo
{
        int damage = (rand() % 200) + 1;

    damage += this -> weapons ->  returnDamage () - 200;

    float strengh = this -> physicalStrenght;

    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

   sleep(1);

   int random = (rand() % 6) + 1;

   if(random == 4)
   {
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; enemie->addBleed();   }

    }


    return damage;
}

int Troll :: magicalDamageCalculator (int escolha) //Função para calcular o dano mágico infligido no inimigo
{
    int damage = magic->baseMagicDamage(escolha);
    
    float magicalStrengh = this-> magicalStrenght;

    if (damage != -1)
    {
        damage *=  1 + (magicalStrengh / 100.0);



        cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO -+-+-+-\n\n";

        sleep(3);


        return damage;
    }
    
    else
    cout << "\n" << "Pontos de mana insuficientes" << "\n";

    return -1;
}

int Troll :: changeWeapon() //Função para a troca de armas
{
    int a = weapons -> upgrade(weaponIndex);

    sleep(2);

    return a;
}

void Troll :: initializeClass()
{
    weapons->setInicialDamage(weaponIndex[0]);
    magic->initialMp(maxMana);
}


int Troll :: imprime()
{

//cout<<"\n HP "<<this->hp<<"\n";

    return hp;
}



int Troll :: showMagicMenu(ICharacter *p2) // IF diferente de 0 executar receive damage no main
{

    while(1){

    cout << string( 100, '\n' );


    cout<<"-+-+-+-+-+-+-+-+- SELECIONAR MAGIA -+-+-+-+-+-+-+-+-";

    int counter = 0;

    cout<<"\n\n";

    cout<<"0. Voltar"<<"\n";

    for(int i : this->spellIndex)
    {
        if(i == -1){ break; }

        counter++;

        cout<<counter<<". "<<magic->magicName[i]<<"\n";
        

    }

    int breaker = 0;

    int answer = 0;


    while(1){
        cout<<"\n";
        cout<<": ";

        cin>>answer;

        if(answer == 0){ return -2;} // !!!!!!!!!!!!!! IMPORTANTE

        for(int i = 0; i < counter; i++ )
        {

            if(answer - 1 == i){ breaker = 1; break;}

        }

        if(breaker == 1){ break; }

        else{ cout<<"OPCAO INVALIDA! TENTE NOVAMENTE\n"; }

    }

    if(magic->mp > magic->manaWaste[ spellIndex[answer-1] ])
    {

        if(magic->typeMagic[ spellIndex[answer-1] ] == 0){ 
            
            hp += magic->magic[answer - 1]; magic->mp -= magic->manaWaste[ spellIndex[answer-1] ]; 
            cout<<"\n-+-+-+ CUROU "<<magic->magic[answer - 1]<<" -+-+-+-\n\n";  
            
            if(this->hp > this->maxHp){ hp = maxHp;}

                sleep(3);

            return 0; 
            } 

    }

    int random = 0;

    int damage = 0;

    if(magic->typeMagic[ spellIndex[answer-1] ] != 0 && magic->mp > magic->manaWaste[ spellIndex[answer-1] ] )
    {

        if( magic->typeMagic[ spellIndex[answer-1] ] == 2){ random = (rand() % 5) + 1; if(random == 3 || random == 2){ p2->addPoison(); cout<<"\n\n-+-+-+- ENVENENADO -+-+-+-\n\n";} }

         if( magic->typeMagic[ spellIndex[answer-1] ] == 3){ random = (rand() % 7) + 1; if(random == 3 || random == 2){ p2->addConfusion(); cout<<"\n\n-+-+-+- VOCE ESTA CONFUSO -+-+-+-\n\n";} }

        damage = magicalDamageCalculator(spellIndex[answer-1]);
        return damage;
    }


    if (magic->mp < magic->manaWaste[ spellIndex[answer-1] ]){cout<<"\n-+-+ MANA INSUFICIENTE -+-+-\n"; return -2;}
    }

   
    
    cout<<"\n";
}

int Troll :: addMana()
{
    int extraMana = magic->manaAfterRound();

    if(extraMana > maxMana)
    {
        this->magic->mp = maxMana;
    }

}

void Troll :: seeStats(ICharacter *p2)
{
    float porcentagem = (float)(this->hp) / (float)(this->maxHp); 

    float lifeDivisor = this->maxHp / 10;

    porcentagem *= 100;

    int counter = 1;

    cout << string( 100, '\n' );

    cout<<"+- STATUS PLAYER ( "<<this->classname<<" ) -+";

    cout << string(3, '\n');

    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= this->hp) { break; }

        else{counter++; cout<<"#"; lifeDivisor += this->maxHp / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<(int)(porcentagem)<<"%"<<" ( "<<this->hp<<"hp ) "<<"\n\n";
    
    cout<<"-Mana Points: "<<this->magic->mp<<"\n\n";

    cout<<"-Ulti Points" << "(MAX-" << this->maxUlti <<"): "<<this->ultiPoints<<"\n\n";
    
    cout<<"-Arma atual: "<<weapons->currentWeaponName<<" ( Dano: "<<weapons->weaponDamage<<" )"<<"\n\n\n";

    cout<<"-Envenenado: ";

    if(this->getPoison() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}

    cout<<"-Sangrando: ";

    if(this->getBleed() == 1){cout<<"Sim\n\n"; }
    else{ cout<<"Nao\n\n";}


    cout<<"-----------------------------------------------------------------------------\n\n";

    cout<<"HP INIMIGO:\n\n";

    counter = 1;

    porcentagem = (float)(p2->returnHp()) / (float)(p2->returnMaxHp()); 

    lifeDivisor = p2->returnMaxHp()  / 10;

    porcentagem *= 100;


    cout<<"-HP: [";

     // # # # # # # # # # # 
    
    cout<<"#";
    while(1){

 
        if(lifeDivisor >= p2->imprime()) { break; }

        else{counter++; cout<<"#"; lifeDivisor += p2->returnMaxHp() / 10; }

    }

    for(int i = 0; i < 10 - counter; i++){ cout<<"-"; }

    cout<<"] "<<"\n\n";

    int keyPressed;

    while(1)
    {

        cout<<"\n\n\n\nDIGITE 0 PARA SAIR\n\n";

        cout<<"\n:";

        cin>>keyPressed;

        if(keyPressed == 0){ break; }



    }


}

int Troll :: returnHp()
{
    return this->hp;
}

int Troll :: returnMaxHp()
{
    return this->maxHp;
}


int Troll :: addUltiPoints()
{
    if (ultiPoints < maxUlti)
    {
        ultiPoints += 10;
    }
    
}

int Troll :: getUltiPoints()
{
    return this -> ultiPoints;
}

int Troll :: getMaxUltiPoints()
{
    return this -> maxUlti;
}

int Troll :: useUlti(ICharacter *enemie)
{
    int ultDamage = 800;

    cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

    cout << "\nTroll ativa > Mordida Mortal < !\n";

    cout<<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";


    enemie->addBleed();

    enemie->addPoison();

    sleep(3);

    this->ultiPoints = 0;

    return ultDamage;


}

int Troll :: bulKathos()
{
    int damage = 700, critical;
    float strengh = this -> physicalStrenght;

    critical = (rand () % 3);

    if (critical == 3)
    damage *= 2 + (strengh / 100);

    else
    damage *= 1 + (strengh / 100);

    cout<<"\n\n-+-+-+- "<<damage<<" DE DANO FEITO (BUL-KATHOS: ESPADA LENDARIA) -+-+-+-\n\n";

    sleep(3);

    return damage;
}

void Troll :: removePoison()
{

    this->isPoisoned = 0;

}

int Troll :: getPoison()
{
    return this->isPoisoned;
}

int Troll :: addPoison()
{
    this->isPoisoned = 1;
    return 0;
}

void Troll :: removeConfusion()
{

    this->isConfused = 0;

}

int Troll :: getConfusion()
{
    return this->isConfused;
}

void Troll :: addConfusion()
{
    this->isConfused = 1;
}


int Troll :: removeBleed()
{
    this->isBleeding = 0;
    return 0;
}

int Troll :: getBleed()
{
    return this->isBleeding;
}


int Troll :: addBleed()
{
    this->isBleeding = 1;
    return 0;
}


int Troll :: getNumberRound()
{
    return this->numberRound;
}


int Troll :: returnDamageEnemy()
{
    return this->weapons->weaponDamage;
}


string Troll :: returnWeaponStringEnemy()
{
    return this->weapons->currentWeaponName;
}


void Troll :: changeEnemyWeaponLevel()
{
    this->weapons->weaponLevel = 0;

    this->weapons->weaponDamage = weapons->weapons[ weaponIndex[0] ];

    this->weapons->currentWeaponName = weapons->weaponName[ weaponIndex[0] ];
}





Troll :: ~Troll() //Função para destruir o personagem
{
    delete magic;
    delete weapons;
    

};
