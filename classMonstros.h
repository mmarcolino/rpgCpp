#include <stdlib.h>

using namespace std;

class Animal{

private:

int hp; // Pontos de Vida
int mp; // Pontos de Mana
int forcaFis; // Forca fisica da classe
int forcaMag; // Forca magica da classe
int armorClass; // Armadura da classe (resistencia a dano fisico)
int magicResistance; // Resistencia a dano magico
int agility; // Probabilidade de esquiva


int *armasDisponiveis; // Vetor de controle citando os indices das armas que podem ser utilizadas pela classe 

int danoArma; // Variavel que controla o dano que a arma carregada da

int nivelArma; // Variavel que cita em que nivel de arma o player esta. Se o vetor de armas dele for por ex. [1,3,5,7] o nivelArma = 2 seria equivalente ao indice 2 do vetor (5)

int *magiasDisponiveis; // Vetor que mostra quais magias o jogador podera utilizar dependendo da classe escolhida


public:
Animal(); // Construtor de classe que da valor a todos os atributos acima

void recebeDano(int damage); // Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

int calculaAtaqueFisico(); // Funcao que calcula o ataque fisico que sera dado

int calculaAtaqueMagico(); // Funcao que calcula o ataque magico que sera dado

int usarMagia(); // Se a magia escolhida for de cura a funcao vai retornar -1. Se nao, ela retorna o dano a ser aplicado no inimigo 

void trocarArma(int armasArray[]); // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

};



class Troll{

private:

int hp; // Pontos de Vida
int mp; // Pontos de Mana
int forcaFis; // Forca fisica da classe
int forcaMag; // Forca magica da classe
int armorClass; // Armadura da classe (resistencia a dano fisico)
int magicResistance; // Resistencia a dano magico
int agility; // Probabilidade de esquiva


int *armasDisponiveis; // Vetor de controle citando os indices das armas que podem ser utilizadas pela classe 

int danoArma; // Variavel que controla o dano que a arma carregada da

int nivelArma; // Variavel que cita em que nivel de arma o player esta. Se o vetor de armas dele for por ex. [1,3,5,7] o nivelArma = 2 seria equivalente ao indice 2 do vetor (5)

int *magiasDisponiveis; // Vetor que mostra quais magias o jogador podera utilizar dependendo da classe escolhida


public:
Troll(); // Construtor de classe que da valor a todos os atributos acima

void recebeDano(int damage); // Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

int calculaAtaqueFisico(); // Funcao que calcula o ataque fisico que sera dado

int calculaAtaqueMagico(); // Funcao que calcula o ataque magico que sera dado

int usarMagia(); // Se a magia escolhida for de cura a funcao vai retornar -1. Se nao, ela retorna o dano a ser aplicado no inimigo 

void trocarArma(int armasArray[]); // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

};



class Dragao{

private:

int hp; // Pontos de Vida
int mp; // Pontos de Mana
int forcaFis; // Forca fisica da classe
int forcaMag; // Forca magica da classe
int armorClass; // Armadura da classe (resistencia a dano fisico)
int magicResistance; // Resistencia a dano magico
int agility; // Probabilidade de esquiva


int *armasDisponiveis; // Vetor de controle citando os indices das armas que podem ser utilizadas pela classe 

int danoArma; // Variavel que controla o dano que a arma carregada da

int nivelArma; // Variavel que cita em que nivel de arma o player esta. Se o vetor de armas dele for por ex. [1,3,5,7] o nivelArma = 2 seria equivalente ao indice 2 do vetor (5)

int *magiasDisponiveis; // Vetor que mostra quais magias o jogador podera utilizar dependendo da classe escolhida


public:
Dragao(); // Construtor de classe que da valor a todos os atributos acima

void recebeDano(int damage); // Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

int calculaAtaqueFisico(); // Funcao que calcula o ataque fisico que sera dado

int calculaAtaqueMagico(); // Funcao que calcula o ataque magico que sera dado

int usarMagia(); // Se a magia escolhida for de cura a funcao vai retornar -1. Se nao, ela retorna o dano a ser aplicado no inimigo 

void trocarArma(int armasArray[]); // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

};





class Zumbi{

private:

int hp; // Pontos de Vida
int mp; // Pontos de Mana
int forcaFis; // Forca fisica da classe
int forcaMag; // Forca magica da classe
int armorClass; // Armadura da classe (resistencia a dano fisico)
int magicResistance; // Resistencia a dano magico
int agility; // Probabilidade de esquiva


int *armasDisponiveis; // Vetor de controle citando os indices das armas que podem ser utilizadas pela classe 

int danoArma; // Variavel que controla o dano que a arma carregada da

int nivelArma; // Variavel que cita em que nivel de arma o player esta. Se o vetor de armas dele for por ex. [1,3,5,7] o nivelArma = 2 seria equivalente ao indice 2 do vetor (5)

int *magiasDisponiveis; // Vetor que mostra quais magias o jogador podera utilizar dependendo da classe escolhida


public:
Zumbi(); // Construtor de classe que da valor a todos os atributos acima

void recebeDano(int damage); // Funcao que recebe como parametro o CalculaAtaque() do oponente para distribuir o dano causado por ele

int calculaAtaqueFisico(); // Funcao que calcula o ataque fisico que sera dado

int calculaAtaqueMagico(); // Funcao que calcula o ataque magico que sera dado

int usarMagia(); // Se a magia escolhida for de cura a funcao vai retornar -1. Se nao, ela retorna o dano a ser aplicado no inimigo 

void trocarArma(int armasArray[]); // Funcao encarregada por fazer o upgrade de arma do personagem, recebe o 

};