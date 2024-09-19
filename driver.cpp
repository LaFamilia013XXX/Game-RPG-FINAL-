#include <iostream>
#include <rpg.h>
using namespace std;

int main(){

    criandoItens();
    Cinto cinto;

    int opc, slot;
    CriandoItem itemSelecionado;
    CriandoItem itemRetirado;

    while(true){

        cout << endl;

        cinto.exibirCinto();

        cout << endl;

        cout << "Digite [1] adicionar espada, [2] adicionar pocaoDeCura, [3] retirar, [4] Replace, [5] Selecionar item: ";
        cin >> opc;
        cout << "Escolha o slot: ";
        cin >> slot;


        cout << "Item na mao: " << itemSelecionado.Nome << endl;
        
        switch (opc)
        {
        case 1:
            cinto.Insert(slot, espada_comum);
            break;
        case 2:
            cinto.Insert(slot, pocaoDeCura_comum);
            break;
        case 3:
            cinto.Delete(slot, itemRetirado);
            break;
        case 4:
            cinto.Replace(slot, pocaoDeDefesa_epico);
            break;
        case 5:
            cinto.Retrieve(slot, itemSelecionado);
        default:
            break;
        }

    }


    return 0;
};
