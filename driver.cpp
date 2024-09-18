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


    return 0;


};


