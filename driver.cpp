#include <iostream>
#include <rpg.h>
using namespace std;

int main(){
    string nome;

    cout << "Seja bem vindo ao Universo crazy, está pronto para embarcar nessa nova aventura? você irá desvendar novos elementos, estes serão usados para te tornar um heroi mais forte, mas não se engane durante esta jornada haverá inimigos a todo momento, tome cuido para não abrir a caixa errada e ter que ir para um duelo cara a cara sem mesmo estar preparado!! Vamos nessa!!!" <<endl;

    //criando meu heroi
    Heroi meuHeroi1 ("Mago",170,100,120,40,30,"Flamecaller"); // ome // hp // ataque // defesa //agilidade // luck // especial
    Heroi meuHeroi2 ("Arqueira",150,80,100,0,30,"Multi Arrow ");
    Heroi meuHeroi3 ("Bruxa",170,90,120,40,35,"Dark Hex");
    Heroi meuHeroi4 ("Bárbaro",200,90,120,40,35,"Fury Sword");

meuHeroi1.MostrandoTudo();
meuHeroi2.MostrandoTudo();
meuHeroi3.MostrandoTudo();
meuHeroi4.MostrandoTudo();


 



}


