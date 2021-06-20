#include <stdlib.h>

using namespace std;

class Magic{

private:

int mp;
int magic[7] = {200, -400, -360, 400, -320, -280, -200};
int typeMagic[7] = {0, 1, 1, 0, 1, 1, 1};
int manaWaste[7] = {12, 12, 14, 16, 14, 12, 12};

public:
Magic(int mpUser); // Construtor de classe que da valor a todos os atributos acima

int baseMagicDamage(int choice);

};
