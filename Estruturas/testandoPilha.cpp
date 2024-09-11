#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack minhaLista;

    int valor, opc = 0;
    int x;
    
    while(true){

        cout << "Escolha umas das opcoes: " << endl;
        cout << "[1] Adicionar novo item;" << endl;
        cout << "[2] Retirar ultimo item adicionado;" << endl;
        cout << "[3] Tamanho da Pilha;" << endl;
        cout << "[4] Limpar Pilha;" << endl;
        cout << "[5] Sair do sistea;" << endl;
        cin >> opc;

         if(opc == 5){
            break;
        }


        switch (opc)
        {
        case 1:
            cout << "Digite o valor: ";
            cin >> valor;
            minhaLista.Push(valor);
            break;
        case 2:
            minhaLista.Pop(x);
            cout << "Valor retirado com sucesso: " << x << " !";
            break;
        case 3:
            cout << "Tamanho da Pilha: " << minhaLista.Size() << endl;
            break;
        case 4:
            minhaLista.Clear();
            cout << "Pilha destruida com sucesso!";
            break;
        
        default:
            break;
        }

    }

   
    return 0;
}
