#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List minhaLista;

    int valor, opc = 0;

    int posicao;
    
    while(true){

        cout << "Escolha umas das opcoes: " << endl;
        cout << "[1] Adicionar novo item;" << endl;
        cout << "[2] Retirar ultimo item adicionado;" << endl;
        cout << "[3] Tamanho da Pilha;" << endl;
        cout << "[4] Limpar Pilha;" << endl;
        cout << "[5] Sair do sistea;" << endl;
        cout << "[6] trocar item de lugar; " << endl;
        cout << "[7] Exibir lista; " << endl;
        cout << "[8] Deletar determinada quantidade" << endl;
        cin >> opc;

         if(opc == 5){
            break;
        }

        switch (opc)
        {
        case 1:
            cout << "Digite o valor desejada: ";
            cin >> valor;
            cout << "Digite a posicao desejada: ";
            cin >> posicao;
            minhaLista.Insert(posicao, valor);
            break;
        case 2:
            cout << "Digite o valor desejada para realizar a exclusao: ";
            cin >> valor;
            cout << "Digite a posicao desejada para realizar a exclusao: ";
            cin >> posicao;
            minhaLista.Delete(posicao, valor);
            break;
        case 3:
            cout << "Tamanho da Lista: " << minhaLista.Size() << endl;
            break;
        case 4:
            minhaLista.Clear();
            cout << "Pilha destruida com sucesso!";
            break;
        case 6:
            cout << "Digite o valor desejada: ";
            cin >> valor;
            cout << "Digite a posicao desejada: ";
            cin >> posicao;
            minhaLista.Replace(posicao, valor);
            break;
        case 7:
            minhaLista.exibirList();
        case 8:
            cout << "Digite o quanto quer deletar: " << endl;
            cin >> valor;
            for(int i=0; i<minhaLista.Size(); i)
        default:
            break;
        }
    }

    return 0;
}
