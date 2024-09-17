#include "rpg.h"
#include <iostream>
using namespace std;
#ifndef RPG_H
#define RPG_H


Inimigo_generico::Inimigo_generico(){
    iniciandoInimigo();
}

void Inimigo_generico::iniciandoInimigo() {
    // Inimigos Simples do Mapa;
    inimigos[TIPO1] = {10, 100};
    inimigos[TIPO2] = {13, 130};
    inimigos[TIPO3] = {16, 160};
    inimigos[TIPO4] = {19, 190};
    inimigos[TIPO5] = {22, 220};
    inimigos[TIPO6] = {25, 250};
    inimigos[TIPO7] = {28, 280};
    inimigos[TIPO8] = {31, 310};
    inimigos[TIPO9] = {34, 340};
    inimigos[TIPO10] = {37, 370};
}

int Inimigo_generico::dano(TipoInimigo tipoInimigo) const {
    return inimigos[tipoInimigo].dano;
}

int Inimigo_generico::barraVida(TipoInimigo tipoInimigo) const {
    return inimigos[tipoInimigo].barraVida;
}



















#endif