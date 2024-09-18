#include <iostream>
#include <rpg.h>
using namespace std;

int main(){
    
    Cinto cinto;
    Item ItemCriador;

    CriandoItem espada = {ItemCriador.Dano(ESPADA), ItemCriador.Nome(ESPADA), ItemCriador.Peso(ESPADA), ItemCriador.Cura(ESPADA), ItemCriador.Defesa(ESPADA)};
    CriandoItem PocaoDeCura = {ItemCriador.Dano(POCAODECURA), ItemCriador.Nome(POCAODECURA), ItemCriador.Peso(POCAODECURA), ItemCriador.Cura(POCAODECURA), ItemCriador.Defesa(POCAODECURA)};
    CriandoItem Machado = {ItemCriador.Dano(MACHADO), ItemCriador.Nome(MACHADO), ItemCriador.Peso(MACHADO), ItemCriador.Cura(MACHADO), ItemCriador.Defesa(POCAODECURA)};
    CriandoItem Varinha = {ItemCriador.Dano(VARINHA), ItemCriador.Nome(VARINHA), ItemCriador.Peso(VARINHA), ItemCriador.Cura(VARINHA), ItemCriador.Defesa(POCAODECURA)};
    CriandoItem PocaoDePoder = {ItemCriador.Dano(POCAODEPODER), ItemCriador.Nome(POCAODEPODER), ItemCriador.Peso(POCAODEPODER), ItemCriador.Cura(POCAODEPODER), ItemCriador.Defesa(POCAODECURA)};
    CriandoItem PocaoDeDefesa = {ItemCriador.Dano(POCAODEDEFESA), ItemCriador.Nome(POCAODEDEFESA), ItemCriador.Peso(POCAODEDEFESA), ItemCriador.Cura(POCAODEDEFESA), ItemCriador.Defesa(POCAODEDEFESA)};
    CriandoItem PocaoDaSorte = {ItemCriador.Dano(POCAODASORTE), ItemCriador.Nome(POCAODASORTE), ItemCriador.Peso(POCAODASORTE), ItemCriador.Cura(POCAODASORTE), ItemCriador.Defesa(POCAODECURA)};

    // cinto.Push(inimigo1);
    // cinto.Push(inimigo2);
    // cinto.Push(inimigo3);

    // cout << "Conteúdo do cinto:" << endl;
    // cinto.exibirCinto();

    // CriandoInimigo topInimigo;
    // cinto.Top(topInimigo);
    // cout << "Topo: Dano = " << topInimigo.dano << ", Barra de Vida = " << topInimigo.barraVida << endl;

    // CriandoInimigo popInimigo;
    // cinto.Pop(popInimigo);
    // cout << "Desempilhado: Dano = " << popInimigo.dano << ", Barra de Vida = " << popInimigo.barraVida << endl;

    // cinto.Clear();
    // cout << "Cinto esvaziado." << endl;
    // cinto.exibirCinto();

    return 0;


}


