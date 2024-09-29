
#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;

void Escrever (string arq, string nome_usuario, int nivel_jogo)
{

 ofstream high_score(arq,ios::out);
    if(high_score.is_open())
    {
        high_score << nome_usuario <<" "<< nivel_jogo<<" "<<endl;
        high_score.close();
        cout<< "Foi salvo com sucesso!."<<endl;
        return;
    }
    else{cout<< "erro ao criar o arquivo"<<endl;}
}



int main(){
    string nome_usuario = "gabriel";
    int nivel_jogo = 10;

Escrever("High_Scores.txt",nome_usuario,nivel_jogo);

return 0;
}