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
    this -> maxUlti = 100;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this->isPoisoned = 0;
    this->isConfused = 0;
    this-> rounds = 0;

    this->numberRound = -1;



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



int Warrior :: physicalDamageCalculator () //Função para calcular o dano físico infligido no inimigo
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
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; this->addBleed();   }

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
    return weapons -> upgrade(weaponIndex);
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

    cout<<"+- STATUS PLAYER  -+";

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

    sleep(3);
    
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
    this -> maxUlti = 100;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this ->isPoisoned = 0;
    this ->isConfused = 0;
    this ->rounds = 0;

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



int Paladin :: physicalDamageCalculator () //Função para calcular o dano físico infligido no inimigo
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
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; this->addBleed();   }

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
    return weapons -> upgrade(weaponIndex);
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

    cout<<"+- STATUS PLAYER  -+";

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
    this -> maxUlti = 20;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this->isPoisoned = 0;
    this->isConfused = 0;

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



int Thief :: physicalDamageCalculator () //Função para calcular o dano físico infligido no inimigo
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
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; this->addBleed();   }

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
    return weapons -> upgrade(weaponIndex);
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

    cout<<"+- STATUS PLAYER  -+";

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
    this -> maxUlti = 20;
    this -> ultiPoints = 0;
    this -> magic = magic;
    this -> weapons = weapons;
    this->isPoisoned = 0;
    this->isConfused = 0;

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



int Zombie :: physicalDamageCalculator () //Função para calcular o dano físico infligido no inimigo
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
       if (this->weaponIndex[ this->weapons->weaponLevel ] == 1 || this->weaponIndex[ this->weapons->weaponLevel ] == 5  ){  cout<<"\n\n-+-+-+- SANGRAMENTO -+-+-+-\n\n"; this->addBleed();   }

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
    return weapons -> upgrade(weaponIndex);
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

    cout<<"+- STATUS PLAYER  -+";

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
        
        
            this->numberRound = 0;             
    
    
            cout<<"\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
            <<"ZUMBI USOU SUA ULT E VOLTARA A VIDA SE MORRER NOS PROXIMOS 5 ROUNDS!"
            <<"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";

            sleep(2);
            }


    if( this->numberRound > -1 && this->numberRound < 6)
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

    if(this->numberRound == 6){ this->numberRound = -1;}




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
