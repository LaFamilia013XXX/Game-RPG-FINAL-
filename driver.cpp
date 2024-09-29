#include <iostream>
#include <rpg.h>
#include <random>
#include <cstdlib>

/*
O que falta fazer?

- Implementar todo o tramamento de input (cin>> opc) - (Gabriel);
- Documentar as funcoes principais do codigo;
- Ajustar ponto da historia ( matheuss )

 */

using namespace std;

void inicializarArmazem_itens(List &x, int tipoBau);
void criandoBau(List &bau, List &armazen);
void bau_encontrado(CriandoItem &ItemMao, List &armazem_itens_pocoes, List &armazem_itens_armas, List &cinto, Mochila &mochila);
void preenchendo_cinto(List &cinto);
void exibindo_hub(List &cinto, Mochila &mochila, CriandoItem &mao, int &vida, string &nome);
void gerenciando_cinto(CriandoItem &Mao, List &cinto, Mochila &mochila);
void CriandoInimigos(CriandoInimigo &inimigo, int &nivel_jogo, int &sqm_batalha);
void dandoDano(CriandoInimigo &inimigo, CriandoItem &item);
void exibindoInimigo(CriandoInimigo &inimigo);
void exibindoHubdeBatalha(Heroi &meuHeroi);
void acessandoCintoNaBatalha(List &cinto, CriandoItem &MaoHeroi, Mochila &mochila);
void CurandoPersonagem(Heroi &meuHeroi);
void dandoDanoNoHeroi(Heroi &meuHeroi, CriandoInimigo &Inimigo);
int gerandoNumeroAleatorio(int &x, int maxNumAle);
void enfrentandoInimigo(Heroi &meuHeroi, int &status_heroi, int &seekValue_proximo_passo, CriandoItem &ItemMao, List &armazem_itens_pocoes, List &armazem_itens_armas, int &inimigo_tipo, int &status_batalha, int &num_hits, int &nivel_jogo, int &sqm_batalha);
void adicionandoItemNaMochilaFINDBau(Mochila &mochila, List &cinto, CriandoItem &ItemMao, int &slot, int &statusPeso);
void verificandoPesoCinto(List &cinto, CriandoItem &Mao, int &slot, int &statusPeso);
void introducaoAomundo();
void introducaoGame();
void exibindoAtaque(Heroi &meuHeroi);
void apresentacaoInimigo(int &nivel_jogo);
void apresentacaoCadaSQM(int &sqm_batalha, int &nivel_jogo);
void fimDeJogo(string &nome);
void TratarErro();
void TrataduasOpcao(int &opc, int max_opc); 

int main(){

    system("cls");
    // Aqui voce esta definindo o nome do usuario;
    string nome_usuario = "desconhecido";

    cout << "Escolha o seu nome de usuario: "<<endl;
    cin >> nome_usuario; // Nome do usuário definido;

    system("cls");

    // introducaoGame();

    system("cls");

    while(true){

        criandoItens(); // Definindo os atributos dos itens;

        int nivel_jogo = 1;
        int sqm_batalha = 1;

        int seekValue_proximo_passo;
        int inimigo_tipo;
        int num_hits;

        int status_batalha;
        int status_heroi; // Defini se o heroi esta vivo ou nao, ou seja o jogo so ira continuar caso ele estiver vivo!

        int slot, opc;
        CriandoItem itemEscolhido;
        CriandoItem ItemMao;
        Heroi meuHeroi(100, "Matheus", 4, 100);

        preenchendo_cinto(meuHeroi.cintoHeroi());
        meuHeroi.maoHeroi() = vazio;

        List armazem_itens_armas(30, 10000); // Bau com os itens;
        List armazem_itens_pocoes(30, 10000); // Bau com as pocoes;

        inicializarArmazem_itens(armazem_itens_armas, 1); 
        inicializarArmazem_itens(armazem_itens_pocoes, 2);

        // Introducao ao mundo e a historia;

        // introducaoAomundo();

        cout << "Antes de iniciar sua jornada, voce ganhou um presente!  Escolha entre os dois tipos de bau que se abrem diante de voce, mas escolha com sabedoria!" << endl;
        cout << "O destino de OOO pode depender de suas decisoes..." << endl << endl;
        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
        cin >> opc;
        TratarErro();

        bau_encontrado(ItemMao, armazem_itens_pocoes, armazem_itens_armas, meuHeroi.cintoHeroi(), meuHeroi.mochilaHeroi()); // Funçao do BAU

        cout << "Certo, agora estamos prontos para continuar a nossa jornada!"<<endl<<endl;
        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
        cin >> opc;
        TratarErro();

        system("cls");

        status_heroi = 1;

        while(nivel_jogo <= 5){
            
            sqm_batalha = 1;
            
            system("cls");
            cout << "Voce acabou de chegar no lvl " << nivel_jogo << endl<<endl;
            cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
            cin >> opc;
            TratarErro();
            system("cls");

            while(sqm_batalha <= 5){

                system("cls");

                cout << "Voce esta indo em direcao ao sqm: " << sqm_batalha << endl<<endl;
                cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                cin >> opc;
                TratarErro();

                system("cls");

                apresentacaoCadaSQM(sqm_batalha, nivel_jogo);

                system("cls");

                CriandoInimigo inimig_deste_sqm;

                CriandoInimigos(inimig_deste_sqm, nivel_jogo, sqm_batalha);

                cout << "Voce esta no nivel: " << nivel_jogo << " e no sqm: " << sqm_batalha << endl;

                exibindo_hub(meuHeroi.cintoHeroi(), meuHeroi.mochilaHeroi(), meuHeroi.maoHeroi(), meuHeroi.vidaHeroi(), meuHeroi.exibindoNome());

                cout << "Pessione [1] para avancar para o proximo SQM"<<endl;
                cin >> opc;
                TrataduasOpcao(opc, 1);

                system("cls");

                gerandoNumeroAleatorio(seekValue_proximo_passo, 4);

                if(sqm_batalha == 5){
                    
                    system("cls");
                    cout << "Voce chegou ao final deste lvl, prepare-se para uma batalha epica contra: " << inimig_deste_sqm.nome << endl<<endl;
                    cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                    cin >> opc;
                    TratarErro();
                    system("cls");

                    apresentacaoInimigo(nivel_jogo);

                    enfrentandoInimigo(meuHeroi, status_heroi, seekValue_proximo_passo, ItemMao, armazem_itens_pocoes, armazem_itens_armas, inimigo_tipo, status_batalha, num_hits, nivel_jogo, sqm_batalha);
                    
                    if(status_heroi == 0){
                        break;
                    }

                    sqm_batalha = sqm_batalha + 1;

                }else{

                    if(seekValue_proximo_passo == 1){
                    
                        cout << "Com sorte, voce conseguiu passar sorrateiramente por " << inimig_deste_sqm.nome << " sem ser notado!" << endl;
                        cout << "Mas a sorte te acompanhou na busca pelo bau!  Que sorte a sua!" << endl << endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                        cin >> opc;
                        TratarErro();

                        system("cls");

                        bau_encontrado(ItemMao, armazem_itens_pocoes, armazem_itens_armas, meuHeroi.cintoHeroi(), meuHeroi.mochilaHeroi());

                        sqm_batalha = sqm_batalha + 1;

                    }

                    if(seekValue_proximo_passo == 2 || seekValue_proximo_passo == 3){
                        
                        system("cls");
                        cout << "Voce encontrou: " << inimig_deste_sqm.nome << " prepare-se para uma batalha epica!"<<endl<<endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                        cin >> opc;
                        TratarErro();
                        system("cls");

                        enfrentandoInimigo(meuHeroi, status_heroi, seekValue_proximo_passo, ItemMao, armazem_itens_pocoes, armazem_itens_armas, inimigo_tipo, status_batalha, num_hits, nivel_jogo, sqm_batalha);
                        
                        if(status_heroi == 0){
                            break;
                        }

                        sqm_batalha = sqm_batalha + 1;

                    }

                    if(seekValue_proximo_passo == 4){
                        
                        system("cls");

                        cout << "Com sorte, voce conseguiu passar sorrateiramente por " << inimig_deste_sqm.nome << " sem ser notado!" << endl;
                        cout << "Mas a sorte nao te acompanhou na busca pelo bau...  Que pena!" << endl << endl;
                        cout << "Porem essa e a sua chance de gerenciar os itens da Mochila e o Cinto, aproveite a oportunidade heroi!"<<endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                        cin >> opc;
                        TratarErro();

                        system("cls");

                        while(true){

                            exibindo_hub(meuHeroi.cintoHeroi(), meuHeroi.mochilaHeroi(), meuHeroi.maoHeroi(), meuHeroi.vidaHeroi(), meuHeroi.exibindoNome());

                            cout << "[1] Para acessar o gerenciador de cinto/mochila"<<endl<<"[2] Para sair do SQM atual."<<endl;
                            cin >> opc;
                            TrataduasOpcao(opc, 2);
                            system("cls");

                            if(opc == 1){
                                gerenciando_cinto(meuHeroi.maoHeroi(), meuHeroi.cintoHeroi(), meuHeroi.mochilaHeroi());
                            }else{
                                break;
                            }
                        }
                        

                        sqm_batalha = sqm_batalha + 1;

                    }

                }
            }

            if(status_heroi == 1){
                
                switch (nivel_jogo) {
                    case 1:
                        cout << "Parabens! Voce superou o Arcanjo e seu legado de lealdade cega!" << endl;
                        cout << "A justica prevaleceu sobre a tirania, e o reino de OOO agradece!" << endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl<<endl;
                        cin >> opc;
                        TratarErro();
                        break;
                    case 2:
                        cout << "Parabens! Voce enfrentou a furia do Paladino e provou que o poder nao se resume a forca bruta!" << endl;
                        cout << "A estrategia e a inteligencia foram suas armas, e voce provou ser digno de liderar!" << endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl<<endl;
                        cin >> opc;
                        TratarErro();
                        break;
                    case 3:
                        cout << "Parabens! Voce desvendou o enigma da Hidra e liberou-a da obsessao pelo conhecimento proibido!" << endl;
                        cout << "A magia e o conhecimento podem ser perigosos, mas voce provou que pode controla-los com sabedoria!" << endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl<<endl;
                        cin >> opc;
                        TratarErro();
                        break;
                    case 4:
                        cout << "Parabens! Voce desafiou o reino das trevas de Lilith e provou que a luz sempre vence as trevas!" << endl;
                        cout << "A esperanca renasceu em OOO, e o caminho para a liberdade esta mais proximo!" << endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl<<endl;
                        cin >> opc;
                        TratarErro();
                        break;
                    case 5:
                        cout << "Parabens! Voce superou a prova de Byuuri e mostrou que e digno de libertar OOO e God Monckey!" << endl;
                        cout << "A jornada foi longa e perigosa, mas voce provou ser um verdadeiro heroe!" << endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl<<endl;
                        cin >> opc;
                        TratarErro();
                        break;
                    default:
                        cout << "Parabens! Voce completou o nivel " << nivel_jogo << endl;
                        break;
                }

                nivel_jogo = nivel_jogo + 1;
            }

            if(status_heroi == 0){
                    break;
            }
            
        }

        if(status_heroi == 0){
            switch (nivel_jogo) {
                case 1:
                    cout << "Infelizmente voce nao foi pareo para o Arcanjo e sua guarda real!" << endl;
                    cout << "O reino de OOO ainda precisa de um heroe mais forte..." << endl<<endl;
                    cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                    cin >> opc;
                    TratarErro();
                    system("cls");
                    break;
                case 2:
                    cout << "A furia do Paladino se mostrou inabalavel!  Voce nao conseguiu superar sua estrategia e forca." << endl;
                    cout << "O mar de OOO ainda e dominado pelo medo..." << endl<<endl;
                    cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                    cin >> opc;
                    TratarErro();
                    system("cls");
                    break;
                case 3:
                    cout << "A Hidra e seus enigmas provaram ser muito fortes! Voce nao conseguiu desvendar os segredos da magia." << endl;
                    cout << "O conhecimento proibido permanece escondido..." << endl<<endl;
                    cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                    cin >> opc;
                    TratarErro();
                    system("cls");
                    break;
                case 4:
                    cout << "O reino das trevas de Lilith se mostrou implacavel! Voce nao conseguiu vencer a escuridão!" << endl;
                    cout << "A esperanca ainda luta para renascer em OOO..." << endl<<endl;
                    cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                    cin >> opc;
                    TratarErro();
                    system("cls");
                    break;
                case 5:
                    cout << "Byuuri, a divindade de OOO, te provou que ainda nao esta pronto para libertar o reino!" << endl;
                    cout << "A luta contra o mal continua..." << endl<<endl;
                    cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                    cin >> opc;
                    TratarErro();
                    system("cls");
                    break;
                default:
                    break;
            }

            cout << "Infelizmente voce perdeu! Voce parou no nivel: " << nivel_jogo << " no sqm " << sqm_batalha << endl <<endl;
            cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
            cin >> opc;
            TratarErro();
            system("cls");
        }

        if(status_heroi == 1){
            system("cls");
            fimDeJogo(nome_usuario);
            system("cls");
        }
        
        cout << "Deseja iniciar novamente: " << nome_usuario << " ?" << endl;
        cout << "[1] Sair do game"<<endl<<"[2] Jogar novamente"<<endl<<endl;
        cin >> opc;
        TrataduasOpcao(opc,2);

        if(opc == 1){
            system("cls");
            cout << "Jogo finalizado!" << endl;
            break;
        }
        if( opc == 2){
            system("cls");
            cout << "Jogo reiniciado!"<<endl;
            continue;
        }

    }
    
    return 0;
};


void exibindo_hub(List &cinto, Mochila &mochila, CriandoItem &mao, int &vida, string &nome){

    CriandoItem top;

    cout << "----------x----------" << endl << endl;

    cout << "---------------------" << endl;
    cout << "|     HEROI     |" << endl;
    cout << "---------------------" << endl;

    cout << "Nome: "<< nome <<endl;
    cout << "Vida: "<< vida <<endl;
    cout << "Item na mao: " << mao.Nome << endl << endl;

    cout << "---------------------" << endl;
    cout << "|     CINTO     |" << endl;
    cout << "---------------------" << endl;

    cinto.ExibirList();
    cout << "Peso no cinto: " << cinto.PesoAtual() << endl << endl;


    cout << "---------------------" << endl;
    cout << "|     MOCHILA     |" << endl;
    cout << "---------------------" << endl;

    if(!mochila.Empty()){
        mochila.Top(top);

        cout << "Ultimo item armazenado na mochila: " << top.Nome << endl;
    }else{
        cout << "Mochila vazia" << endl;
    }
    
    cout << endl;

    cout << "----------x----------" << endl << endl;

}

void preenchendo_cinto(List &cinto){
    cinto.Insert(vazio, 1);
    cinto.Insert(vazio, 2);
    cinto.Insert(vazio, 3);
    cinto.Insert(vazio, 4);
}   

void inicializarArmazem_itens(List &x, int tipoBau) {

    int retorno = 1;

    if(tipoBau == 1){
        x.Insert(espada_comum, 1);
        x.Insert(machado_comum, 2);
        x.Insert(Varinha_comum, 3);
        x.Insert(espada_comum, 4);

        x.Insert(machado_comum, 5);
        x.Insert(Varinha_comum, 6);
        x.Insert(espada_comum, 7);
        x.Insert(machado_comum, 8);

        // Adicionando 3 itens raros de cada tipo
        x.Insert(espada_raro, 9);
        x.Insert(machado_raro, 10);
        x.Insert(Varinha_raro, 11);

        x.Insert(espada_raro, 12);
        x.Insert(machado_raro, 13);
        x.Insert(Varinha_raro, 14);

        // Adicionando 2 itens lendários de cada tipo
        x.Insert(espada_lendario, 15);
        x.Insert(machado_lendario, 16);

        x.Insert(Varinha_lendario, 17);
        x.Insert(espada_lendario, 18);

        // Adicionando 1 item épico de cada tipo
        x.Insert(espada_epico, 19);
        x.Insert(machado_epico, 20);
        x.Insert(Varinha_epico, 21);

        // Adicionando os itens restantes para completar os 30 slots
        x.Insert(espada_comum, 22);
        x.Insert(machado_comum, 23);
        x.Insert(Varinha_comum, 24);
        x.Insert(espada_raro, 25);
        x.Insert(machado_raro, 26);
        x.Insert(Varinha_raro, 27);
        x.Insert(espada_lendario, 28);
        x.Insert(machado_lendario, 29);
        x.Insert(Varinha_lendario, 30);
    }
    else {
         x.Insert(vazio, 1);
        x.Insert(pocaoDeCura_comum, 2);
        x.Insert(vazio, 3);
        x.Insert(pocaoDeCura_raro, 4);

        x.Insert(pocaoDeCura_comum, 5);
        x.Insert(pocaoDeCura_comum, 6);
        x.Insert(pocaoDeCura_comum, 7);
        x.Insert(pocaoDeCura_comum, 8);

        x.Insert(pocaoDeCura_comum, 9);
        x.Insert(vazio, 10);
        x.Insert(pocaoDeCura_comum, 11);
        x.Insert(vazio, 12);

        // Adicionando 3 itens raros de cada tipo de poção
        x.Insert(vazio, 13);
        x.Insert(pocaoDeCura_comum, 14);
        x.Insert(vazio, 15);

        x.Insert(pocaoDeCura_raro, 16);
        x.Insert(pocaoDeCura_raro, 17);
        x.Insert(pocaoDeCura_raro, 18);

        x.Insert(pocaoDeCura_raro, 19);
        x.Insert(vazio, 20);
        x.Insert(pocaoDeCura_raro, 21);

        // Adicionando 2 itens lendários de cada tipo de poção
        x.Insert(vazio, 22);
        x.Insert(vazio, 23);

        x.Insert(pocaoDeCura_lendario, 24);
        x.Insert(pocaoDeCura_lendario, 25);

        x.Insert(vazio, 26);
        x.Insert(vazio, 27);

        // Adicionando 1 item épico de cada tipo de poção
        x.Insert(pocaoDeCura_lendario, 28);
        x.Insert(vazio, 29);
        x.Insert(pocaoDeCura_lendario, 30);
    }
}

void criandoBau(List &bau, List &armazen){
    
    for(int i=1; i<=bau.Size(); i++){

        random_device rd; 
        mt19937 gen(rd());

        uniform_int_distribution<> distrib(1, 30); // Números entre 1 e 30
        
        int seekValue = distrib(gen); 
        
        CriandoItem item_selecionado;
        armazen.Retrieve(item_selecionado, seekValue);
        
        bau.Insert(item_selecionado, i);
    }
}

void bau_encontrado(CriandoItem &ItemMao, List &armazem_itens_pocoes, List &armazem_itens_armas, List &cinto, Mochila &mochila){
    
    system("cls");

    List bau_armas(3, 1000); // Declarando Bau de itens;
    List bau_pocoes(3, 1000); // Declarando Bau de itens;
    int add_item_mochila; 
    CriandoItem exibindoItem; 

    criandoBau(bau_pocoes, armazem_itens_pocoes);
    criandoBau(bau_armas, armazem_itens_armas);

    int opc, slot, statusPeso;
    int retorno = 1;

    cout << ""<<endl;
    cout << "..."<<endl;

    cout << "Voce encontrou um bau, escolha qual deve ser o tipo dele:"<<endl<<"[1] - Pocoes"<<endl<<"[2] - Armas" <<endl;
    cin >> opc;
    TrataduasOpcao(opc, 2);

    switch (opc)
    {
    case 1:
           while(true){

                system("cls");

                cout << "Esse itens foram encontrados no bau, digite um valor para escolher o seu item!" << endl << endl;
                cout << "----x BAU x ----" << endl;
                    bau_pocoes.ExibirList();
                cout << "----x BAU x ----" << endl;
                cin >> slot;

                bau_pocoes.Retrieve(exibindoItem, slot);

                if(exibindoItem.Nome != "vazio"){
                    system("cls");
                
                        cout << "Decida o que voce ira fazer com este item?: "<< exibindoItem.Nome <<endl<<"[1] - Colocar no cinto "<<endl<<"[2] - Colocar na mochila "<<endl<<"[3] - Descartar item/bau"<<endl;
                        cin >> add_item_mochila;

                        system("cls");

                        switch (add_item_mochila)
                        {
                        case 1:

                            bau_pocoes.Retrieve(ItemMao, slot);
                                
                            cout << endl;
                            cinto.ExibirList();
                            cout << endl;

                            cout << "Selecione o slot ou item para substituir [ Caso ja tiver um item no lugar ele sera descartado ]: "<<endl;
                            cin >> slot;

                            // cinto.Replace(ItemMao, slot, statusPeso);

                            adicionandoItemNaMochilaFINDBau(mochila, cinto, ItemMao, slot, statusPeso);

                            system("cls");
                            return;

                            break;
                        case 2:
                            
                            bau_pocoes.Retrieve(ItemMao, slot);

                            mochila.Push(ItemMao);
                            system("cls");
                            return;

                            break;
                        case 3:
                            system("cls");
                            return;

                            break;
                        default:
                            break;
                        }
                    }else{
                        system("cls");
                        cout << "Este slot do bau esta vazio!"<<endl<<endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                        cin >> opc;
                        TratarErro();
                    }
                }
    case 2:
           while(true){

                system("cls");

                cout << "Esse itens foram encontrados no bau, digite um valor para escolher o seu item! ou [5] para descartar bau!" << endl << endl;
                cout << "----x BAU x ----" << endl;
                bau_armas.ExibirList();
                cout << "----x BAU x ----" << endl;
                cin >> slot;

                if(slot == 5){
                    return;
                    break;
                }

                bau_armas.Retrieve(exibindoItem, slot);

                if(exibindoItem.Nome != "vazio"){
                    system("cls");
                
                    cout << "Decida o que voce ira fazer com este item?: "<< exibindoItem.Nome <<endl<<"[1] - Colocar no cinto "<<endl<<"[2] - Colocar na mochila "<<endl<<"[3] - Descartar item/bau"<<endl;
                    cin >> add_item_mochila;

                    system("cls");

                    switch (add_item_mochila)
                    {
                    case 1:

                        bau_armas.Retrieve(ItemMao, slot);
                            
                        cout << endl;
                        cinto.ExibirList();
                        cout << endl;

                        cout << "Selecione o slot ou item para substituir [ Caso ja tiver um item no lugar ele sera descartado ]: "<<endl;
                        cin >> slot;

                        adicionandoItemNaMochilaFINDBau(mochila, cinto, ItemMao, slot, statusPeso);

                        system("cls");
                        return;

                        break;
                    case 2:

                        bau_armas.Retrieve(ItemMao, slot);

                        mochila.Push(ItemMao);
                        system("cls");
                        return;

                        break;
                    case 3:
                        system("cls");
                        return;

                        break;
                    default:
                        break;
                    }
                }else{
                    system("cls");
                    cout << "Este slot do bau esta vazio!"<<endl;
                    cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                    cin >> opc;
                    TratarErro();
                }
            }

    default:
        break;
    }

    return;

}

void gerenciando_cinto(CriandoItem &Mao, List &cinto, Mochila &mochila){

    system("cls");

    while(true){

        int statusPeso;
        int slot;
        int opc;
        CriandoItem exibindoItem, VerificandoItem;

        cout << "----Cinto----"<<endl;
        cinto.ExibirList();
        cout << "----Cinto----"<<endl;

        cout << "Pressione [5] para sair do gerenciador de cinto!"<<endl;

        cout << endl;

        cout << "Selecione o slot do item: " <<endl;
        cin >> slot;

        if(slot == 5){
            system("cls");
            return;
            break;
        }

        cinto.Retrieve(exibindoItem, slot);

        system("cls");

        if(exibindoItem.Nome == "vazio"){

            cout << "Decida o que voce ira fazer com este slot?: "<<endl<<"[1] Armazenar item da mao"<<endl<<"[2] Armazenar ultimo item colocado na mochila"<<endl;
            cin >> opc;
            TrataduasOpcao(opc, 2);

            system("cls");

            switch (opc)
            {
            case 1:

                if(Mao.Nome == "vazio"){
                    cout << "Sua mao esta vazia!" <<endl;
                    break;
                }
                if(Mao.Nome != "vazio"){

                    verificandoPesoCinto(cinto, Mao, slot, statusPeso);

                    system("cls");
                    break;
                }

                break;
            case 2:

                if(mochila.Empty()){
                    cout << "A mochila esta vazia!"<<endl;
                    break;
                }else{
                    mochila.Pop(VerificandoItem);

                    verificandoPesoCinto(cinto, Mao, slot, statusPeso);

                    if(statusPeso == 0){
                        mochila.Push(VerificandoItem);
                    }

                    system("cls");
                    break;
                }
            default:
                break;
            }
            

        }else{

        cinto.Replace(vazio, slot, statusPeso);

        cout << "Decida o que voce ira fazer com este item?: "<< exibindoItem.Nome <<endl<<"[1] - Colocar item na mao"<<endl<<"[2] - Colocar item no cinto"<<endl<<"[3] - Descartar item"<<endl;
        cin >> opc;
        TrataduasOpcao(opc, 3);

        system("cls");

        switch (opc)
        {
        case 1:
            Mao = exibindoItem;
            break;
        case 2:
            
            int slot_guardar;

            cout << "----Cinto----"<<endl;
            cinto.ExibirList();
            cout << "----Cinto----"<<endl;

            cout << "Decida o que voce ira fazer com este item: " << exibindoItem.Nome << endl<<endl;

            cout << "Selecione o slot do item: "<<endl;
            cin >> slot_guardar;

            cinto.Retrieve(VerificandoItem, slot_guardar);
            cinto.Replace(vazio, slot_guardar,statusPeso);

            if( VerificandoItem.Nome != "vazio"){
                
                system("cls");

                cout << "Ja existe um item alocado neste slot, deseja descartar ele?: "<<endl<<"[1] Sim"<<endl<<"[2] Nao"<<endl;
                cin >> opc;
                TrataduasOpcao(opc, 2);

                system("cls");

                if(opc == 1){

                    cinto.Replace(exibindoItem, slot_guardar, statusPeso);
                    if(statusPeso == 0){
                        cout << "O cinto esta pesado demais!" <<endl<<endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                        cin >> opc;
                        TratarErro();
                    }

                    break;
                }else{
                    cinto.Replace(exibindoItem, slot, statusPeso);
                    cinto.Replace(VerificandoItem, slot_guardar, statusPeso);
                    break;
                }
            }else {
                cinto.Replace(exibindoItem, slot_guardar, statusPeso);
                if(statusPeso == 0){
                    cout << "O cinto esta pesado demais!" <<endl<<endl;
                    cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                    cin >> opc;
                    TratarErro();
                }
                system("cls");
                break;
            }
            
        case 3:
            cinto.Replace(vazio, slot, statusPeso);
            cout << "Item " << exibindoItem.Nome <<" descartado com sucesso!"<<endl;
            break;
        default:
            break;
        }
    }
    } 
}

void CriandoInimigos(CriandoInimigo &inimigo, int &nivel_jogo, int &sqm_batalha){

    Inimigo_generico Atributo;

    if(nivel_jogo == 1){
        if(sqm_batalha != 5){
            switch (sqm_batalha)
                {
                case 1:
                    inimigo = { Atributo.nome(TIPO1), Atributo.dano(TIPO1), Atributo.barraVida(TIPO1), Atributo.sqm_lvl(TIPO1), Atributo.lvl_inimigo(TIPO1)};
                    break;
                case 2:
                    inimigo = { Atributo.nome(TIPO2), Atributo.dano(TIPO2), Atributo.barraVida(TIPO2), Atributo.sqm_lvl(TIPO2), Atributo.lvl_inimigo(TIPO2)};
                    break;
                case 3:
                    inimigo = { Atributo.nome(TIPO3), Atributo.dano(TIPO3), Atributo.barraVida(TIPO3), Atributo.sqm_lvl(TIPO3), Atributo.lvl_inimigo(TIPO3)};
                    break;
                case 4:
                    inimigo = { Atributo.nome(TIPO4), Atributo.dano(TIPO4), Atributo.barraVida(TIPO4), Atributo.sqm_lvl(TIPO4), Atributo.lvl_inimigo(TIPO4)};
                    break;
                default:
                    break;
                }
        }else{
            inimigo = { Atributo.nome(BOSS1), Atributo.dano(BOSS1), Atributo.barraVida(BOSS1), Atributo.sqm_lvl(BOSS1), Atributo.lvl_inimigo(BOSS1)};
        }
    }

    if(nivel_jogo == 2){
        if(sqm_batalha != 5){
            switch (sqm_batalha)
                {
                case 1:
                    inimigo = { Atributo.nome(TIPO5), Atributo.dano(TIPO5), Atributo.barraVida(TIPO5), Atributo.sqm_lvl(TIPO5), Atributo.lvl_inimigo(TIPO5)};
                    break;
                case 2:
                    inimigo = { Atributo.nome(TIPO6), Atributo.dano(TIPO6), Atributo.barraVida(TIPO6), Atributo.sqm_lvl(TIPO6), Atributo.lvl_inimigo(TIPO6)};
                    break;
                case 3:
                    inimigo = { Atributo.nome(TIPO7), Atributo.dano(TIPO7), Atributo.barraVida(TIPO7), Atributo.sqm_lvl(TIPO7), Atributo.lvl_inimigo(TIPO7)};
                    break;
                case 4:
                    inimigo = { Atributo.nome(TIPO8), Atributo.dano(TIPO8), Atributo.barraVida(TIPO8), Atributo.sqm_lvl(TIPO8), Atributo.lvl_inimigo(TIPO8)};
                    break;
                default:
                    break;
                }
        }else{
            inimigo = { Atributo.nome(BOSS2), Atributo.dano(BOSS2), Atributo.barraVida(BOSS2), Atributo.sqm_lvl(BOSS2), Atributo.lvl_inimigo(BOSS2)};
        }
    }

    if(nivel_jogo == 3){
        if(sqm_batalha != 5){
            switch (sqm_batalha)
                {
                case 1:
                    inimigo = { Atributo.nome(TIPO9), Atributo.dano(TIPO9), Atributo.barraVida(TIPO9), Atributo.sqm_lvl(TIPO9), Atributo.lvl_inimigo(TIPO9)};
                    break;
                case 2:
                    inimigo = { Atributo.nome(TIPO10), Atributo.dano(TIPO10), Atributo.barraVida(TIPO10), Atributo.sqm_lvl(TIPO10), Atributo.lvl_inimigo(TIPO10)};
                    break;
                case 3:
                    inimigo = { Atributo.nome(TIPO11), Atributo.dano(TIPO11), Atributo.barraVida(TIPO11), Atributo.sqm_lvl(TIPO11), Atributo.lvl_inimigo(TIPO11)};
                    break;
                case 4:
                    inimigo = { Atributo.nome(TIPO12), Atributo.dano(TIPO12), Atributo.barraVida(TIPO12), Atributo.sqm_lvl(TIPO12), Atributo.lvl_inimigo(TIPO12)};
                    break;
                default:
                    break;
                }
        }else{
            inimigo = { Atributo.nome(BOSS3), Atributo.dano(BOSS3), Atributo.barraVida(BOSS3), Atributo.sqm_lvl(BOSS3), Atributo.lvl_inimigo(BOSS3)};
        }
    }

    if(nivel_jogo == 4){
        if(sqm_batalha != 5){
            switch (sqm_batalha)
                {
                case 1:
                    inimigo = { Atributo.nome(TIPO13), Atributo.dano(TIPO13), Atributo.barraVida(TIPO13), Atributo.sqm_lvl(TIPO13), Atributo.lvl_inimigo(TIPO13)};
                    break;
                case 2:
                    inimigo = { Atributo.nome(TIPO14), Atributo.dano(TIPO14), Atributo.barraVida(TIPO14), Atributo.sqm_lvl(TIPO14), Atributo.lvl_inimigo(TIPO14)};
                    break;
                case 3:
                    inimigo = { Atributo.nome(TIPO15), Atributo.dano(TIPO15), Atributo.barraVida(TIPO15), Atributo.sqm_lvl(TIPO15), Atributo.lvl_inimigo(TIPO15)};
                    break;
                case 4:
                    inimigo = { Atributo.nome(TIPO16), Atributo.dano(TIPO16), Atributo.barraVida(TIPO16), Atributo.sqm_lvl(TIPO16), Atributo.lvl_inimigo(TIPO16)};
                    break;
                default:
                    break;
                }
        }else{
            inimigo = { Atributo.nome(BOSS4), Atributo.dano(BOSS4), Atributo.barraVida(BOSS4), Atributo.sqm_lvl(BOSS4), Atributo.lvl_inimigo(BOSS4)};
        }
    }

    if(nivel_jogo == 5){
        if(sqm_batalha != 5){
            switch (sqm_batalha)
                {
                case 1:
                    inimigo = { Atributo.nome(TIPO17), Atributo.dano(TIPO17), Atributo.barraVida(TIPO17), Atributo.sqm_lvl(TIPO17), Atributo.lvl_inimigo(TIPO17)};
                    break;
                case 2:
                    inimigo = { Atributo.nome(TIPO18), Atributo.dano(TIPO18), Atributo.barraVida(TIPO18), Atributo.sqm_lvl(TIPO18), Atributo.lvl_inimigo(TIPO18)};
                    break;
                case 3:
                    inimigo = { Atributo.nome(TIPO19), Atributo.dano(TIPO19), Atributo.barraVida(TIPO19), Atributo.sqm_lvl(TIPO19), Atributo.lvl_inimigo(TIPO19)};
                    break;
                case 4:
                    inimigo = { Atributo.nome(TIPO20), Atributo.dano(TIPO20), Atributo.barraVida(TIPO20), Atributo.sqm_lvl(TIPO20), Atributo.lvl_inimigo(TIPO20)};
                    break;
                default:
                    break;
                }
        }else{
            inimigo = { Atributo.nome(BOSS5), Atributo.dano(BOSS5), Atributo.barraVida(BOSS5), Atributo.sqm_lvl(BOSS5), Atributo.lvl_inimigo(BOSS5)};
        }
    }
    

}

void exibindoInimigo(CriandoInimigo &inimigo){


        cout << "----------x----------" <<endl<<endl;
        cout << "Nome: " << inimigo.nome <<endl;
        cout << "Dano: " << inimigo.dano <<endl;
        cout << "Barra vida: " << inimigo.barraVida <<endl;
        cout << "Tipo inimigo lvl: " << inimigo.lvl << endl;
        cout << "Tipo inimigo sqm: " << inimigo.sqm_level << endl;
        cout << "----------x----------" <<endl<<endl;

}

void exibindoHubdeBatalha(Heroi &meuHeroi){

    CriandoItem top;

    cout << "-----------------------" << endl;
    cout << "|  STATUS DO HEROI  |" << endl;
    cout << "-----------------------" << endl;
    cout << "Vida: " << meuHeroi.vidaHeroi() << endl;
    cout << "Mao: " << meuHeroi.maoHeroi().Nome << endl;
    cout << "-----------------------" << endl;

    cout << "-----------------------" << endl;
    cout << "|  MOCHILA  |" << endl;
    cout << "-----------------------" << endl;
    if(!meuHeroi.mochilaHeroi().Empty()){
        meuHeroi.mochilaHeroi().Top(top);
        cout << "Ultimo item armazenado na mochila: " << top.Nome << endl;
    }else{
        cout << "Mochila vazia" << endl;
    }
    cout << "-----------------------" << endl;

    cout << "-----------------------" << endl;
    cout << "|  CINTO  |" << endl;
    cout << "-----------------------" << endl;
    meuHeroi.cintoHeroi().ExibirList();
    cout << "Peso no cinto: " << meuHeroi.cintoHeroi().PesoAtual() << endl;
    cout << "-----------------------" << endl;


}

void acessandoCintoNaBatalha(List &cinto, CriandoItem &MaoHeroi, Mochila &mochila){
    
    system("cls"); // Limpando a tela;

    while(true){

        // Definindo as variaveis que serao usadas para o controle do cinto;
        int slot, opc, statusPeso, slot_guardar; 
        CriandoItem VerificandoItem, top, pegandoItemDaMochila; 

        // Menu de opções para o usuário;
        cout << "Escolha a sua opcao: "<<endl<<"[1] colocar item do cinto na mao"<<endl<<"[2] guardar item no cinto"<<endl<<"[3] sair do gerenciador de cinto na batalha"<<endl;
        cin >> opc;
        TrataduasOpcao(opc, 2);

        system("cls");

        switch (opc){
            case 1:
                cout << "---------------x------------" << endl;
                cinto.ExibirList(); // Exibindo os itens do cinto;
                cout << "---------------x------------" << endl;

                // Aqui o usuario irá definir o slot que será usado.
                cout << "Selecione o slot para colocar o item na mao! [caso ja tiver um item na mao ele sera descartado]"<<endl;
                cin >> slot;

                system("cls"); // Limpando a tela;

                // Aqui estou pegando o slot do cinto, onde irei verificar se ele está no status vazio;
                cinto.Retrieve(VerificandoItem, slot);

                // Caso for diferente de vazio, ele irá pegar o item do cinto e armazenar na mão;
                if(VerificandoItem.Nome != "vazio"){
                    cinto.Retrieve(MaoHeroi, slot);
                    cinto.Replace(vazio, slot, statusPeso); // Assim o cinto recebe o slot vazio.
                    system("cls");
                    cout << "Item adicionado na mao!"<<endl;
                }
                else{
                    // Aqui o usuário irá receber essa mensagem caso o slot estiver vazio.
                    cout << "O slot esta vazio!"<<endl;
                }
                
                break;
            case 2: 
                // Caso a mão do usuario não estiver vazia, ele irá poder adicionar o item da mão no cinto.
                if(MaoHeroi.Nome != "vazio"){

                    cout << "----Cinto----"<<endl;
                    cinto.ExibirList();
                    cout << "----Cinto----"<<endl;

                    cout << "Selecione o slot do item: "<<endl;
                    cin >> slot_guardar;

                    cinto.Retrieve(VerificandoItem, slot_guardar); // Aqui estou pegando o slot do cinto, onde irei verificar se ele está no status vazio;

                    // Caso for diferente de vazio, ele irá dar a opção do usuário descartar o item;
                    if( VerificandoItem.Nome != "vazio"){
                        
                        system("cls");

                        cout << "Ja existe um item alocado neste slot, deseja descartar ele?: "<<endl<<"[1] Sim"<<endl<<"[2] Nao"<<endl;
                        cin >> opc;
                        TrataduasOpcao(opc, 2);

                        system("cls");

                        if(opc == 1){
                            // Se sim, ele irá trocar o item do slot do cinto, assim sendo descartando o outro item;
                            // Aqui tbm verifico se o cinto esta cheio ou não, se sim, ele não irá adicionar o item no cinto.
                            cinto.Replace(MaoHeroi, slot_guardar, statusPeso);

                            if(statusPeso == 0){
                                system("cls");
                                cout << "O cinto esta pesado demais!" <<endl;
                            }else{
                                // Caso estiver com peso livre, ele irá adicionar o status vazio na mao do usuario;
                                MaoHeroi = vazio;
                                cout << "Item adicionado no cinto com sucesso!" <<endl;
                            }

                            system("cls");

                            break;
                        }else{
                            system("cls");
                            cout << "Operacao abortada!"<<endl;
                            break;             
                        }
                    }
                    else {
                        // ele irá trocar o item do slot do cinto, assim sendo descartando o outro item;
                        // Aqui tbm verifico se o cinto esta cheio ou não, se sim, ele não irá adicionar o item no cinto.
                        cinto.Replace(MaoHeroi, slot_guardar, statusPeso);

                        if(statusPeso == 0){
                                cout << "O cinto esta pesado demais!" <<endl<<endl;
                                cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                                cin >> opc;
                                TratarErro();
                            }else{
                                // Caso estiver com peso livre, ele irá adicionar o status vazio na mao do usuario;
                                MaoHeroi = vazio;
                                system("cls");
                                cout << "Item adicionado no cinto com sucesso!" <<endl; 
                                break;
                        }

                    }
                }else {
                    system("cls");
                    // Caso a mão estiver vazia, ele irá receber essa mensgame.
                    cout << "Sua mao esta vazia!"<<endl;
                }
                    
                break;
            case 3:
                
                // Verificando se a mochila está vazia, pois aqui o tiem da mochila sera enviado para o cinto.

                // if(!mochila.Empty()){
                    
                //     cout << "----Mochila----"<<endl;
                //     if(!mochila.Empty()){
                //         mochila.Top(top);

                //         cout << "Ultimo item armazenado na mochila: " << top.Nome << endl;
                //     }else{
                //         cout << "Mochila vazia" << endl;
                //     }
                //     cout << "----Mochila----"<<endl;


                //     cout << "-------------x----------"<<endl;
                //     cinto.ExibirList();
                //     cout << "-------------x----------"<<endl;

                //     cout << "Selecione o slot do item: "<<endl;
                //     cin >> slot_guardar;

                //     system("cls");

                //     cinto.Retrieve(VerificandoItem, slot_guardar);

                //      if( VerificandoItem.Nome != "vazio"){

                //         system("cls");

                //         cout << "Ja existe um item alocado neste slot, deseja descartar ele?: "<<endl<<"[1] Sim"<<endl<<"[2] Nao"<<endl;
                //         cin >> opc;

                //         system("cls");

                //         if(opc == 1){
                //             mochila.Pop(pegandoItemDaMochila);

                //             cinto.Replace(pegandoItemDaMochila, slot_guardar, statusPeso);

                //             if(statusPeso == 0){
                //                 system("cls");
                //                 mochila.Push(pegandoItemDaMochila);
                //                 cout << "O cinto esta pesado demais!" <<endl;
                //             }else{
                //                 cout << "Item adicionado no cinto!"<<endl;
                //                 cin >> opc;
                //                 break;
                //             }

                //             system("cls");

                //             break;
                //         }else{
                //             break;             
                //         }

                //      }else{
                //             mochila.Pop(pegandoItemDaMochila);

                //             cinto.Replace(pegandoItemDaMochila, slot_guardar, statusPeso);

                //             if(statusPeso == 0){
                //                 mochila.Push(pegandoItemDaMochila);
                //                 cout << "O cinto esta pesado demais!" <<endl;
                //                 break;
                //             }else{
                //                 cout << "Item adicionado no cinto!"<<endl;
                //                 break;
                //             }

                //             system("cls");
                //      }
                    

                // }else {
                //     system("cls");
                //     cout << "Sua mochila esta vazia!"<<endl;
                //     break;
                // }

                return;
            default:
                break;
        }
    }
}

void CurandoPersonagem(Heroi &meuHeroi){

    CriandoItem verificandoNome = meuHeroi.maoHeroi();
    string Nome = verificandoNome.Nome;

    if(Nome == "Vazio"){
        cout << "Sua mao esta vazia"<<endl;
    }

    if(Nome == "Pocao Cura - Comum"){
        meuHeroi.curandoHeroi(verificandoNome);
        meuHeroi.maoHeroi() = vazio;
        return;
    }
    if(Nome == "Pocao Cura - Raro"){
        meuHeroi.curandoHeroi(verificandoNome);
        meuHeroi.maoHeroi() = vazio;
        return;
    }
    if(Nome == "Pocao Cura - Lendario"){
        meuHeroi.curandoHeroi(verificandoNome);
        meuHeroi.maoHeroi() = vazio;
        return;
    }
    if(Nome == "Pocao Cura - Epico"){
        meuHeroi.curandoHeroi(verificandoNome);
        meuHeroi.maoHeroi() = vazio;
        return;
    }
    else{
        cout << "Este item nao e consumivel!"<<endl;
        return;
    }

}

void dandoDanoNoHeroi(Heroi &meuHeroi, CriandoInimigo &Inimigo){
    meuHeroi.dandoDanoNoHeroi(Inimigo);
}

int gerandoNumeroAleatorio(int &x, int maxNumAle){

    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<> distrib(1, maxNumAle); // Números entre 1 e 3
    
    x = distrib(gen);

    return x;
}

void dandoDano(CriandoInimigo &inimigo, CriandoItem &item){

    Inimigo_generico Atributo;
    
    Atributo.sofrendoDano(inimigo, item);

}

void enfrentandoInimigo(Heroi &meuHeroi, int &status_heroi, int &seekValue_proximo_passo, CriandoItem &ItemMao, List &armazem_itens_pocoes, List &armazem_itens_armas, int &inimigo_tipo, int &status_batalha, int &num_hits, int &nivel_jogo, int &sqm_batalha){

    int opc;

    if(status_heroi == 1){

            gerandoNumeroAleatorio(seekValue_proximo_passo, 3);

            system("cls");

            if(seekValue_proximo_passo == 2){

                system("cls");
                cout << "Voce encontrou um Bau bonus!"<<endl<<endl;
                cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                cin >> opc;
                TratarErro();
                system("cls");

                bau_encontrado(ItemMao, armazem_itens_pocoes, armazem_itens_armas, meuHeroi.cintoHeroi(), meuHeroi.mochilaHeroi()); // Função do BAU
            }
                
            CriandoInimigo Inimigo;

            CriandoInimigos(Inimigo, nivel_jogo, sqm_batalha);  

            system("cls");

            if(sqm_batalha == 5){
                cout << "Agora que voce chegou no sqm " << sqm_batalha << " Voce ira enfrentar o chefe deste nivel, sendo ele: "<<endl<<endl;
                exibindoInimigo(Inimigo);

                cout << endl<<endl;
                cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                cin >> opc;
                TratarErro();


            }else{
                exibindoInimigo(Inimigo);

                cout << endl<<endl;
                cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                cin >> opc;
                TratarErro();

            }
            
            system("cls");

            cout << "Voce ira entrar em modo batalha agora!: " << endl<<endl;
            cout << endl;
            cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
            cin >> opc;
            TratarErro();

            system("cls");

            status_batalha = 1;

            while(status_batalha == 1){
                
                exibindoHubdeBatalha(meuHeroi);

                cout << "Escolha sua acao: " << endl;
                cout << "[1] - Atacar inimigo [Lembre-se de colocar um item de ataque na mao]" << endl;
                cout << "[2] - Gerenciar cinto na batalha" << endl;
                cout << "[3] - Consumir item Cura [caso estiver na mao]" << endl;

                cin >> opc;
                TrataduasOpcao(opc, 3);

                switch (opc)
                {
                case 1:

                    system("cls");

                    if(status_batalha == 1){

                        exibindoAtaque(meuHeroi);
                        exibindoInimigo(Inimigo);
                        
                        cout << "Dar dano no inimigo: " <<endl<<endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                        cin >> opc;
                        TratarErro();

                        system("cls");

                        for(int i=0; i<2; i++){
                            dandoDano(Inimigo, meuHeroi.maoHeroi()); 

                            if(Inimigo.barraVida == 0){
                                status_batalha = 0;
                                cout << "Parabens voce derrotu o inimigo!"<<endl<<endl;

                                cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                                cin >> opc;
                                TratarErro();
                                break;
                            }

                        }
                    }
                    
                    if(status_batalha == 1){
                        exibindoAtaque(meuHeroi);;
                        exibindoInimigo(Inimigo);

                        cout << "Vez do inimigo: " <<endl<<endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                        cin >> opc;
                        TratarErro();


                        system("cls");

                        gerandoNumeroAleatorio(num_hits, 3);

                        for(int i=0; i<num_hits; i++){
                            dandoDanoNoHeroi(meuHeroi, Inimigo);

                            if(meuHeroi.vidaHeroi() == 0){
                                status_batalha = 0;
                                status_heroi = 0;
                                exibindoHubdeBatalha(meuHeroi);
                                cout << "Voce perdeu o jogo!"<<endl<<endl;
                                cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                                cin >> opc;
                                TratarErro();
                                system("cls");
                                break;
                            }
                        }

                        // Caso o heroi perder o game, o jogo nao ira duplicar os atributos novamente.
                        if(status_batalha == 1){
                            exibindoAtaque(meuHeroi);
                            exibindoInimigo(Inimigo);
                        }

                        cout << "Pressione qualquer para sair da rodada de ataque:"<<endl<<endl;
                        cout << "[Digite qualquer tecla continuar e pressione enter para continuar!]"<<endl;
                        cin >> opc;
                        TratarErro();

                    }
                    
                    system("cls");

                    break;
                case 2:

                    acessandoCintoNaBatalha(meuHeroi.cintoHeroi(), meuHeroi.maoHeroi(), meuHeroi.mochilaHeroi());
                    break;
                
                case 3:

                    system("cls");

                    CurandoPersonagem(meuHeroi);

                    break;
                    
                default:
                    break;
                }
            }

            cout << "Voce saiu do modo batalha!"<<endl;
            cin >> opc;
            TratarErro();

            system("cls");

        }
        else{
            system("cls");
            return;
        }

}

void adicionandoItemNaMochilaFINDBau(Mochila &mochila, List &cinto, CriandoItem &ItemMao, int &slot, int &statusPeso){

    system("cls");

    int opc;
    cinto.Replace(ItemMao, slot, statusPeso);

    if(statusPeso == 0){

        cout << "O cinto esta pesado demais!" <<endl;
        cout << "Deseja adicionar item na mochila ou descartar?: "<<endl<<"[1] Guardar na mochila"<<endl<<"[2] Descartar item"<<endl;
        cin >> opc;
        TratarErro();
        
        switch (opc)
        {
        case 1:
            mochila.Push(ItemMao);
            system("cls");
            cout << "Item adicionado na mochila com sucesso!"<<endl;
            system("cls");
            break;
        case 2:
            break;
        default:
            break;
        }

    }

}

void verificandoPesoCinto(List &cinto, CriandoItem &Mao, int &slot, int &statusPeso){

    int opc;
    cinto.Replace(Mao, slot, statusPeso);

    if(statusPeso == 1){
        Mao = vazio;
    }else{
        cout << "O cinto esta pesado demais!" <<endl;
        cin >> opc;
        TratarErro();
    }

}

void introducaoAomundo(){

    int opc;

    system("cls");

    cout << "Seja bem-vindo ao mundo de OOO, um reino onde a guerra e o combustivel da vida, e o mal e o bem dancam em uma valsa mortal." << endl;
    cout << "Aqui, a magia se entrelaça com a tecnologia, e a fe se mistura com a brutalidade. Voce esta pronto para enfrentar os desafios que OOO lhe reserva?" << endl << endl;
    cout << "[Digite qualquer tecla numerica para continuar!]"<<endl;
    cin >> opc;
    TratarErro();
    system("cls"); // Limpa a tela após a primeira parte da introdução

    system("cls");

    cout << "O Herdeiro Rebelde" << endl << endl; 
    cout << "[Digite qualquer tecla numerica para continuar!]"<<endl;
    cin >> opc;
    TratarErro();
    system("cls"); // Limpa a tela após o título

    cout << "Desde a infancia, fui acolhido pelo grandioso God Monckey, o rei de Sakhur, apos ser abandonado pelos meus pais." << endl;
    cout << "Ele me criou como um filho, me treinando para ser seu sucessor, um guerreiro digno de herdar seu trono." << endl; 
    cout << "Cresci em meio ao caos do mundo de OOO, forjado nas batalhas e nos ensinamentos do rei." << endl << endl;
    cout << "[Digite qualquer tecla numerica para continuar!]"<<endl;
    cin >> opc;
    TratarErro();
    system("cls"); // Limpa a tela após a primeira parte da história

    cout << "God Monckey ja tinha cinco filhos: o Paladino, capitao da frota imperial; o Arcanjo, sargento da guarda real; a Hidra, coronel e aspirante a General da frota de feiticeiros; e a rebelde Lilith, a Rainha das Trevas, que, apos se rebelar contra o pai, agora servia ao imperio como mercenaria." << endl;
    cout << "e por ultimo! porem a mais poderosa: Byuuri, uma divindade poderosa, sendo ela minha companheira desde a infancia, a mais forte entre os filhos do rei." << endl << endl;
    cout << "[Digite qualquer tecla numerica para continuar!]"<<endl;
    cin >> opc;
    TratarErro();
    system("cls"); // Limpa a tela após a segunda parte da história

    cout << "Em minhas missoes pelo reino, sempre em busca de provar meu valor e conquistar o mundo, me vi diante de uma batalha crucial: a destruicao de uma vila." << endl;
    cout << "No entanto, algo dentro de mim se rebelou, e eu salvei a vida de uma jovem donzela." << endl;
    cout << "Nesse momento, meu coracao se encheu de um amor que nunca senti antes, e a donzela me mostrou a verdade: minha luta era cruel e sem proposito." << endl;
    cout << "Tudo o que eu fazia em nome do reino era errado." << endl << endl;
    cout << "[Digite qualquer tecla numerica para continuar!]"<<endl;
    cin >> opc;
    TratarErro();
    system("cls"); // Limpa a tela após a terceira parte da história

    cout << "A partir daquele dia, me tornei um rebelde." << endl; 
    cout << "Tentei impedir as campanhas de conquista do reino, mas fui confrontado pelo meus irmaos e pelo proprio Rei God Monckey." << endl;
    cout << "Diante do conflito, escolhi me opor ao rei, pois percebi que minha lealdade estava errada." << endl;
    cout << "Minha luta por God Monckey e seus sonhos de dominacao era desonesta e cruel." << endl << endl;
    cout << "[Digite qualquer tecla numerica para continuar!]"<<endl;
    cin >> opc;
    TratarErro();
    system("cls"); // Limpa a tela após a quarta parte da história

    cout << "God Monckey, apesar da dor de ver seu filho rebelde, compreendia meu dilema." << endl;
    cout << "Ele me amava e me criou como um verdadeiro filho, mas seu coracao estava dividido entre o amor e o dever." << endl; 
    cout << "Ele sempre me viu como um herdeiro digno, mas a guerra o havia cegado para a crueldade de suas acoes." << endl << endl;
    cout << "[Digite qualquer tecla numerica para continuar!]"<<endl;
    cin >> opc;
    TratarErro();
    system("cls"); // Limpa a tela após a quinta parte da história

    cout << "Minha antiga companheira, Byuuri, tambem foi confrontada por minhas decisoes." << endl;
    cout << "Ela sempre esteve ao meu lado, mas seu vinculo com o rei era inabalavel." << endl; 
    cout << "Tentei convence-la a se juntar a mim, a abrir os olhos para a verdade, mas ela escolheu permanecer ao lado de seu pai." << endl;
    cout << "Sua decisao, tomada com pesar, era um reflexo do amor e da lealdade que sentia por God Monckey." << endl << endl;
    cout << "[Digite qualquer tecla numerica para continuar!]"<<endl;
    cin >> opc;
    TratarErro();
    system("cls"); // Limpa a tela após a sexta parte da história

    cout << "Agora, sou um fugitivo." << endl; 
    cout << "God Monckey, apesar de sua tristeza, decretou minha caca." << endl;
    cout << "Minha cabeca deveria ser colocada em sua mesa como um trofeu." << endl; 
    cout << "Mas, mesmo com a sentenca de morte pairando sobre mim, luto por aquilo que acredito: minha liberdade, meu povo e meu sangue." << endl << endl;
    cout << "[Digite qualquer tecla numerica para continuar!]"<<endl;
    cin >> opc;
    TratarErro();
    system("cls"); // Limpa a tela após a sétima parte da história

    cout << "Para conquistar minha redencao e impedir a tirania do rei, terei que derrotar inumeros inimigos, ate chegar ao proprio God Monckey e, finalmente, confronta-lo em um combate final." << endl;
    cout << "So assim, um novo rei podera ser coroado, e eu poderei viver em paz, livre da furia de meu antigo pai, mas tambem da sombra de seus erros." << endl << endl;
    cout << "[Digite qualquer tecla numerica para continuar!]"<<endl;
    cin >> opc;
    TratarErro();
    system("cls"); // Limpa a tela após a última parte da história

    system("cls");

}

void introducaoGame(){

    int opc;

    system("cls");

    cout << "Ola, Heroi!" << endl << endl;

    cout << "Prepare-se para embarcar em uma aventura epica no mundo de OOO, um reino onde a guerra e a lei e a magia e a tecnologia se entrelacam!" << endl << endl;

    cout << "Sua missao:" << endl << endl;

    cout << "Voce precisa provar seu valor, superar desafios e vencer batalhas para se tornar um heroe lendario!" << endl << endl;

    cout << "Como o jogo funciona:" << endl << endl;

    cout << "5 Niveis: O jogo e dividido em 5 niveis, cada um com seu proprio boss e seus capangas." << endl;
    cout << "5 Setores: Cada nivel e dividido em 5 setores, cada um com seus proprios desafios." << endl;
    cout << "Caminhos do Destino: Em cada setor, voce sera jogado entre 3 caminhos:" << endl;
    cout << "Encontrar um inimigo: Prepare-se para o combate!" << endl;
    cout << "Encontrar um bau: Uma chance de encontrar itens valiosos!" << endl;
    cout << "Caminho vazio: Um respiro na aventura!" << endl;
    cout << "Sorte e estrategia: A sorte determinara o que voce encontrara em cada setor, mas sua estrategia sera crucial para a vitoria!" << endl << endl;

    cout << "Gerenciando seu equipamento:" << endl << endl;

    cout << "Em cada setor, voce tera a chance de acessar seu cinto e gerenciar seus itens:" << endl;
    cout << "Opcao [1]: Gerenciar Cinto: Organize suas armas, pocoes e outros itens para enfrentar os desafios que o aguardam!" << endl;
    cout << "Opcao [2]: Avancar: Se estiver pronto, avance para o proximo setor e continue sua jornada!" << endl << endl;

    cout << "Lembre-se: Em cada setor, novas historias te aguardam.  Explore o mundo, lute contra seus inimigos, encontre tesouros e supere os desafios que OOO lhe reserva!" << endl << endl;

    cout << "[Digite qualquer tecla numerica para continuar!]"<<endl;
    cin >> opc;
    TrataduasOpcao(opc,2);

    system("cls");
}

void exibindoAtaque(Heroi &meuHeroi){

    CriandoItem top;

    cout << "-----------------------" << endl;
    cout << "|  STATUS DO HEROI  |" << endl;
    cout << "-----------------------" << endl;
    cout << "Vida: " << meuHeroi.vidaHeroi() << endl;
    cout << "Mao: " << meuHeroi.maoHeroi().Nome << endl;
    cout << "-----------------------" << endl << endl;
    
}

void apresentacaoInimigo(int &nivel_jogo){
    int opc;

    system("cls");

    switch (nivel_jogo)
        {
        case 1:
            cout << "O Legado do Arcanjo" << endl << endl;
            cout << "O Arcanjo, filho mais velho de God Monckey, te espera!" << endl << "Ele sempre foi um protetor leal, comandando a guarda real e jurando defender o reino com sua vida." << endl << "No entanto, sua lealdade cega o levou a cometer atos cruéis em nome do rei." << endl << "Prepare-se para enfrentar sua força e lealdade!"<<endl;
            cin >> opc;
            TratarErro();
            break;
        case 2:
            cout << "A Fúria do Paladino" << endl << endl;
            cout << "O Paladino, capitao da frota imperial, se coloca em seu caminho!" << endl << "Ele era um mestre da estrategia e da batalha naval, liderando inumeras conquistas e levando o medo ao coracao dos inimigos de God Monckey." << endl << "Sua ambicao o corrompeu, e ele buscava usurpar o trono para si." << endl << "Prepare-se para confrontar sua furia e provar que o poder nao se resume a forca bruta!" << endl;
            cin >> opc;
            TratarErro();
            break;
        case 3:
            cout << "O Enigma da Hidra" << endl << endl;
            cout << "A Hidra, uma poderosa feiticeira, te desafia!" << endl << "Ela comandava a frota de magos do reino, usando seus poderes para conquistar inimigos e defender o reino." << endl << "No entanto, seus poderes a corromperam, e ela se tornou obcecada por conhecimento proibido." << endl << "Prepare-se para enfrentar seus poderes, decifrar seus enigmas e liberta-la da escuridão!" << endl;
            cin >> opc;
            TratarErro();
            break;
        case 4:
            cout << "O Reino das Trevas de Lilith" << endl << endl;
            cout << "Lilith, a Rainha das Trevas, se levanta para te enfrentar!" << endl << "Ela foi a primeira filha de God Monckey a se rebelar contra ele, buscando o poder e a dominacao total, utilizando seus poderes obscuros para destruir tudo que estava em seu caminho." << endl << "Agora, ela lidera um exercito de criaturas das trevas." << endl << "Prepare-se para desafiar seus poderes de sombras!" << endl;
            cin >> opc;
            TratarErro();
            break;
        case 5:
            cout << "A Prova de Byuuri" << endl << endl;
            cout << "Byuuri, a divindade mais poderosa de OOO, te coloca a prova!" << endl << "Ela e a unica que compreende verdadeiramente God Monckey, e a unica que pode salva-lo da escuridão que o domina." << endl << "Apesar da amizade que sempre nutrimos, ela escolheu permanecer ao lado de seu pai." << endl << "Prepare-se para enfrentar a prova de Byuuri, use sua forca e sua inteligencia para libertar o reino e o proprio God Monckey." << endl << "Talvez, com sua vitoria, voce possa convencê-la a se juntar a sua causa." << endl;
            cin >> opc;
            TratarErro();
            break;
        default:
            break;
        }
}

void apresentacaoCadaSQM(int &sqm_batalha, int &nivel_jogo){

    int opc;
    
    if(nivel_jogo == 1){
        switch (sqm_batalha)
        {
        case 1:
            cout << "A Floresta Encantada" << endl << "Voce adentra uma floresta magica, onde os segredos do reino se escondem." << endl << "Um bau com itens valiosos te espera, mas cuidado com a Fenix, uma criatura lendaria que guarda um antigo segredo." << endl << endl;
            cin >> opc;
            TratarErro();
            break;
        case 2:
            cout << "O Campo de Batalha" << endl << "Voce chega a um campo de treinamento militar, onde os guerreiros de God Monckey aprimoravam suas habilidades." << endl << "Um caminho livre se abre diante de voce, mas um grupo de soldados te espera para uma luta brutal." << endl << endl;
            cin >> opc;
            TratarErro();
            break;
        case 3:
            cout << "A Torre do Conhecimento" << endl << "Uma torre antiga, onde os feiticeiros de OOO aprendiam magia, se levanta diante de voce." << endl << "Um bau com livros raros e pocoes pode ser seu, mas cuidado com o mago renegado que guarda um conhecimento proibido." << endl << endl;
            cin >> opc;
            TratarErro();
            break;
        case 4:
            cout << "O Vale dos Perdidos" << endl << "Voce chega a um vale desolado, onde os soldados derrotados de God Monckey foram deixados para morrer." << endl << "Um caminho livre se abre diante de voce, mas um fantasma vingativo vagueia pela regiao, a alma de um soldado que foi traido pelo rei." << endl << endl;
            cin >> opc;
            TratarErro();
            break;
        case 5:
            cout << "O Santuario do Arcanjo" << endl << "O santuario onde o Arcanjo orava, um local de grande poder magico, te espera." << endl << "Prepare-se para a batalha final contra o Arcanjo, que te confrontara com sua forca e suas crencas." << endl << endl;
            cin >> opc;
            TratarErro();
            break;
        default:
            break;
        }
    }

    if(nivel_jogo == 2){
        switch (sqm_batalha)
        {
        case 1:
            cout << "O Porto de Tempestades" << endl << "Um porto agitado e cheio de navios te recebe." << endl << "Um bau com mapas e municoes pode ser seu, mas cuidado com os piratas que te desafiarao para uma batalha naval." << endl << endl;
            cin >> opc;
            TratarErro();
            break;
        case 2:
            cout << "A Muralha de Ferro" << endl << "Voce chega a uma muralha impenetravel, construida para proteger o reino de OOO." << endl << "Um caminho livre se abre diante de voce, mas um grupo de soldados de elite vigia a muralha." << endl << endl;
            cin >> opc;
            TratarErro();
            break;
        case 3:
            cout << "O Labirinto das Sombras" << endl << "Voce entra em um labirinto subterraneo, onde os espiritos de marinheiros perdidos vagam." << endl << "Um bau com reliquias e tesouros pode ser seu, mas cuidado com o monstro marinho que se alimenta de almas perdidas." << endl << endl;
            cin >> opc;
            TratarErro();
            break;
        case 4:
            cout << "A Fortaleza do Paladino" << endl << "Uma fortaleza inexpugnavel, onde o Paladino planeja suas estrategias, se ergue diante de voce." << endl << "Um caminho livre se abre diante de voce, mas um grupo de espioes tenta sabotar sua missao." << endl << endl;
            cin >> opc;
            TratarErro();
            break;
        case 5:
            cout << "A Batalha Final" << endl << "O Paladino, com sua frota de navios, te espera para uma batalha naval epica." << endl << "Voce precisara de toda a sua habilidade e estrategia para derrota-lo e superar sua furia." << endl << endl;
            cin >> opc;
            TratarErro();
            break;
        default:
            break;
        }
    }

    if(nivel_jogo == 3){
        switch (sqm_batalha)
        {
        case 1:
            cout << "A Biblioteca Proibida" << endl << "Uma biblioteca antiga, onde livros de magia e conhecimento proibido sao guardados, se abre diante de voce." << endl << "Um bau com livros raros e itens magicos pode ser seu, mas cuidado com o guardião magico que protege o conhecimento da biblioteca." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        case 2:
            cout << "A Floresta do Silencio" << endl << "Uma floresta onde a magia e tao forte que silencia qualquer som, se estende diante de voce." << endl << "Um caminho livre se abre diante de voce, mas cuidado com o Pesadelo, uma criatura mitica que se alimenta de sonhos e pensamentos." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        case 3:
            cout << "A Cidade dos Espelhos" << endl << "Voce chega a uma cidade onde cada espelho reflete um mundo diferente, cheio de ilusoes e magia." << endl << "Um bau com artefatos magicos pode ser seu, mas cuidado com o espelho maligno que aprisiona as almas dos humanos." << endl << endl;
            cin >> opc; 
            TratarErro();

            break;
        case 4:
            cout << "O Labirinto da Hidra" << endl << "Um labirinto complexo, onde a Hidra esconde seus segredos, te espera." << endl << "Um caminho livre se abre diante de voce, mas cuidado com os magos, seus servos, que te desafiarao para um duelo magico." << endl << endl;
            cin >> opc;
            TratarErro(); 
            break;
        case 5:
            cout << "A Sala do Enigma" << endl << "A sala onde a Hidra realizava seus experimentos magicos te espera." << endl << "Prepare-se para um desafio complexo, cheio de enigmas e armadilhas magicas.  Derrote a Hidra e liberte-a da escuridão que a domina." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        default:
            break;
        }
    }

    if(nivel_jogo == 4){
        switch (sqm_batalha)
        {
        case 1:
            cout << "O Cemiterio dos Herois" << endl << "Um cemiterio onde os soldados de God Monckey mortos em batalha estao enterrados, te recebe." << endl << "Um bau com armas amaldicoadas e itens de poder obscuro pode ser seu, mas cuidado com o necromante que controla os mortos-vivos." << endl << endl;
            cin >> opc; 
            TratarErro();

            break;
        case 2:
            cout << "A Floresta da Noite Eterna" << endl << "Uma floresta onde a noite nunca termina, se estende diante de voce." << endl << "Um caminho livre se abre diante de voce, mas cuidado com o Demonio, uma criatura mitica que se alimenta de almas." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        case 3:
            cout << "O Castelo das Sombras" << endl << "Um castelo assombrado por fantasmas e criaturas das trevas te espera." << endl << "Um bau com itens magicos pode ser seu, mas cuidado com o vampiro que busca te transformar em um de seus servos." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        case 4:
            cout << "O Labirinto do Medo" << endl << "Um labirinto que se alimenta de seus medos e te leva para um mundo de pesadelos, te desafia." << endl << "Um caminho livre se abre diante de voce, mas cuidado com os monstros que se transformam em suas piores lembrancas." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        case 5:
            cout << "A Sala do Trono" << endl << "O salão do trono de Lilith, onde ela te espera para um confronto final, te espera." << endl << "Derrote Lilith e quebre o dominio das trevas que assola OOO." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        default:
            break;
        }
    }

    if(nivel_jogo == 5){
        switch (sqm_batalha)
        {
        case 1:
            cout << "O Jardim da Esperança" << endl << "Um jardim magico, onde as flores representam a esperança de um futuro melhor para OOO, te recebe." << endl << "Um bau com sementes de arvores magicas e itens de cura pode ser seu, mas cuidado com o guardião, um golem de pedra que protege o jardim." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        case 2:
            cout << "O Rio da Memoria" << endl << "Um rio onde as memorias do passado fluem, te espera." << endl << "Um caminho livre se abre diante de voce, mas cuidado com o demonio que se alimenta de memorias e tenta te levar para o passado." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        case 3:
            cout << "A Torre das Ilusoes" << endl << "Uma torre onde as ilusoes te levam para mundos falsos e te desafiam a encontrar o caminho certo, te espera." << endl << "Um bau com itens magicos pode ser seu, mas cuidado com o mago que te tenta com ilusoes e sonhos." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        case 4:
            cout << "A Montanha Sagrada" << endl << "A montanha onde os deuses de OOO residem, te espera." << endl << "Um caminho livre se abre diante de voce, mas cuidado com o anjo caido que busca destruir a montanha e o reino." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        case 5:
            cout << "O Salão de Julgamento" << endl << "O salão onde Byuuri te espera para a prova final, te espera." << endl << "Voce tera que enfrentar sua forca e sua sabedoria para provar que e digno de libertar OOO e God Monckey." << endl << endl;
            cin >> opc; 
            TratarErro();
            break;
        default:
            break;
        }
    }

}

void fimDeJogo(string &nome) {

    int opc;

    cout << "---------------------------------------------------------" << endl;
    cout << "            A GUERRA ACABOU!  O REINO FOI LIBERTO!     " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;

    cout << "Voce, o heroe lendario, enfrentou os desafios de OOO e venceu!" << endl;
    cout << "O Arcanjo, o Paladino, a Hidra, Lilith e ate mesmo Byuuri se curvaram diante de sua forca e determinacao!" << endl;
    cout << "A escuridão foi dissipada, e o reino finalmente pode respirar livre." << endl;
    cout << endl;

    cout << "A paz retorna a OOO, e os cidadaos te celebram como um salvador!" << endl;
    cout << "Seu nome: " <<nome<< " sera lembrado para sempre nas historias do reino." << endl;
    cout << endl;

    cout << "Mas a jornada de um heroe nunca termina..." << endl;
    cout << "Novas aventuras te aguardam, novas batalhas a serem travadas." << endl;
    cout << "O mundo precisa de sua protecao, e voce esta pronto para responder ao chamado?" << endl;
    cout << endl;

    cout << "---------------------------------------------------------" << endl;
    cout << "                A LUTA CONTINUA!                      " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;

    cin >> opc;
    TratarErro();
}

void TrataduasOpcao(int &opc, int max_opc) 
{

    if(opc >= 1 && opc <= max_opc){
        system("cls");
        return;
    }

    do{
        if (cin.fail()) {
            cout << "Por favor digite um valor valido." << endl;
            cin >> opc;
            TratarErro();
            continue;
        }else{
            cout << "Por favor escolha um numero entre 1 e " << max_opc << " para prosseguir." << endl;
            cin >> opc;

            if (opc < 1 || opc > max_opc) {
                continue;
            }else{
                system("cls");
                break;
            }
        }

    }
    while(true);

}
void TratarErro() {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void suaFuncao(int &opc){
    while (true)
    {
        cin >> opc;
        if(cin.fail()){
            cout << "Por favor digite  um valor valido"<< endl;
            TratarErro();
            continue;
        }
        if (opc <1 && opc > 2){
            cout<< "Por favor escolha um numero entre 1 e 2 para prosseguir"<< endl;

        }else{break;}

    }
}
