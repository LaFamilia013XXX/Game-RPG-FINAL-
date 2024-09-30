// armas e pocoes
// vida, ataque, defesa, 
// #ifndef RPG_H
// #define RPG_H

#include <string>
using namespace std;

// Criando os Itens do RPG, cada nome de item e sua raridade terá valores diferentes;
enum Tipo {
    POCAODECURA_COMUM, // Cura o Heroi
    POCAODECURA_RARO, // Cura o Heroi
    POCAODECURA_LENDARIO, // Cura o Heroi
    POCAODECURA_EPICO, // Cura o Heroi

    POCAODEPODER_COMUM, // da um UPP em tudo (HP, Ataque, Defesa, Agilidade e Luck)
    POCAODEPODER_RARO, // da um UPP em tudo (HP, Ataque, Defesa, Agilidade e Luck)
    POCAODEPODER_LENDARIO, // da um UPP em tudo (HP, Ataque, Defesa, Agilidade e Luck)
    POCAODEPODER_EPICO, // da um UPP em tudo (HP, Ataque, Defesa, Agilidade e Luck)

    POCAODEDEFESA_COMUM, // aumenta tmeporariamente a defesa (escudo do heroi)
    POCAODEDEFESA_RARO, // aumenta tmeporariamente a defesa (escudo do heroi)
    POCAODEDEFESA_LENDARIO, // aumenta tmeporariamente a defesa (escudo do heroi)
    POCAODEDEFESA_EPICO, // aumenta tmeporariamente a defesa (escudo do heroi)
    
    POCAODASORTE_COMUM, // aumenta a sorte de dar crítico e/ou esquivar de um inimigo
    POCAODASORTE_RARO, // aumenta a sorte de dar crítico e/ou esquivar de um inimigo
    POCAODASORTE_LENDARIO, // aumenta a sorte de dar crítico e/ou esquivar de um inimigo
    POCAODASORTE_EPICO, // aumenta a sorte de dar crítico e/ou esquivar de um inimigo

    ESPADA_COMUM, // para o Barbaro
    ESPADA_RARO, // para o Barbaro
    ESPADA_LENDARIO, // para o Barbaro
    ESPADA_EPICO, // para o Barbaro

    MACHADO_COMUM, // para o Barbaro
    MACHADO_RARO, // para o Barbaro
    MACHADO_LENDARIO, // para o Barbaro
    MACHADO_EPICO, // para o Barbaro

    VARINHA_COMUM, //do mago
    VARINHA_RARO, //do mago
    VARINHA_LENDARIO, //do mago
    VARINHA_EPICO, //do mago
    VAZIO, // Inicializando item vazio

    NUM_TIPOS_DE_ITENS
};

// Struct que irá armazenar todos atributos do item;
struct CriandoItem {
    int Dano;
    string Nome;
    int Peso;
    int Cura;
    int Defesa;
};

class Item {
    public:
        Item(); // Construtor
        // Aqui estou definindo as funções que irão receber os valores, onde como parâmeto ele irão receber uma variável do tipo "Tipo".
        // onde ao colocar o tipo dela, ela irá receber os valores definido na função em rpg.cpp;
        int Dano(Tipo tipo) const; 
        string Nome(Tipo tipo) const;
        int Peso(Tipo tipo) const;
        int Cura(Tipo tipo) const;
        int Defesa(Tipo tipo) const;
    private:
        CriandoItem itens[NUM_TIPOS_DE_ITENS];
        void IniciandoItem();
        
};

// Criando Exports de variáveis globais, onde elas serão usadas no driver, para cada item e sua raridade;
//itens de diferentes classe que podem ser ganhados durante a partida
extern CriandoItem espada_comum;
extern CriandoItem espada_raro;
extern CriandoItem espada_lendario;
extern CriandoItem espada_epico;
extern CriandoItem machado_comum;
extern CriandoItem machado_raro;
extern CriandoItem machado_lendario;
extern CriandoItem machado_epico;
extern CriandoItem Varinha_comum;
extern CriandoItem Varinha_raro;
extern CriandoItem Varinha_lendario;
extern CriandoItem Varinha_epico;
extern CriandoItem pocaoDeCura_comum;
extern CriandoItem pocaoDeCura_raro;
extern CriandoItem pocaoDeCura_lendario;
extern CriandoItem pocaoDeCura_epico;
extern CriandoItem vazio;

// Essa será a função responsável para atribuir os valores de cada variável e item criadas aqui no .h, o qual serão chamados no driver.cpp;
void criandoItens();

// Criando os inimigos do RPG;
enum TipoInimigo { // apenas os tipos dos inimigos que podem surgir durante o jogo aleatoriamente
    TIPO1,
    TIPO2,
    TIPO3,
    TIPO4,
    TIPO5,
    TIPO6,
    TIPO7,
    TIPO8,
    TIPO9,
    TIPO10,
    TIPO11,
    TIPO12,
    TIPO13,
    TIPO14,
    TIPO15,
    TIPO16,
    TIPO17,
    TIPO18,
    TIPO19,
    TIPO20,
    BOSS1,
    BOSS2,
    BOSS3,
    BOSS4,
    BOSS5,
    NUM_TIPOS_DE_INIMIGOS
};

struct CriandoInimigo { // criacao do inimigo, todos os atributos que ele tem
    string nome; // nome do inimigo
    int dano; // dano do inimigo
    int barraVida; // vida do inimigo
    int sqm_level; //resistencia
    int lvl; 
};

class Inimigo_generico { // uma classe para inimigos
    public:
        Inimigo_generico(); //Inicializa um objeto da classe `Inimigo_generico` e chama a função para configurar os dados dos inimigos.
        int dano(TipoInimigo tipoInimigo) const; //Retorna o dano causado pelo inimigo.
        int barraVida(TipoInimigo tipoInimigo) const; //Retorna a barra de vida do inimigo
        string nome(TipoInimigo tipoInimigo) const; //Retorna o nome do inimigo.
        int sqm_lvl(TipoInimigo tipoInimigo) const; //Retorna o nível de SQM do inimigo
        int lvl_inimigo(TipoInimigo tipoInimigo) const; //Retorna o nível geral do inimigo

        void sofrendoDano(CriandoInimigo &inimigo, CriandoItem &item); //funcao para tomar dano
    private: //passando algumas coisas em private
        CriandoInimigo inimigos[NUM_TIPOS_DE_INIMIGOS];
        void iniciandoInimigo();  // inicia o inimigo
};

// Mochila Usuario
class Mochila {
    public:
        Mochila(); //construtor 
        ~Mochila(); //destrutor
        bool Empty(); // verifica esta vazia
        bool Full(); // verifica se está cheia
        void Push(CriandoItem x); // colocar elementos dentro da michila
        void Pop(CriandoItem &x); // retira elementos da mochila
        void Clear(); // limpa os elementos mantendo a estrutura
        void Top(CriandoItem &x); // verificar o que esta no topo da mochila
        int Size(); // tamanho da mochila, quantos itens..
        void exibirMochila(); // exibi a mochila
    private:

        struct StackNode { //logica da pilha com os ponteiros ensinado em aula
            CriandoItem Entry;
            StackNode *NextNode;
        };

        typedef StackNode *StackPointer;

        StackPointer top;
};

class List{ // criando uma estrutura de lista
    public:
        List(int maxList, int maxPeso);
        ~List();
        bool Empty();
        bool full();
        bool fullPeso();  // verifica o peso
        void Insert (CriandoItem x, int p); //insere itens 
        void Delete(CriandoItem &x, int p); // remove itens
        int Size(); //quantidade de itens
        void Clear(); 
        void Retrieve(CriandoItem &x, int p); // funcao que retorna um elemento
        void Replace(CriandoItem x, int p, int &statusPeso); 
        void ExibirList(); //exibe tudo
        int PesoAtual();
    private:
        struct ListNode{ //logica da lista
            CriandoItem Entry;
            ListNode *NextNode;
        };

        typedef ListNode*  ListPointer; // apenas renomeando
        ListPointer head; // ponteiro head
        int count; //contador
        int Max;
        int PesoMax;
        int Peso = 0;
        void SetPosition(int p, ListPointer &current);

};

class Heroi {// uma das classes principais, a do Heroi
    private:
        int vida; // vida do heroi
        CriandoItem Mao; //item na mao do heroi
        Mochila mochila;
        List cinto; //cinto que tem a estrutura de lista
        string Nome; // nome do heroi
    public:
        Heroi(int vidaInicial, string nome, int maxCinto, int pesoMaxCinto);
        int& vidaHeroi();
        Mochila& mochilaHeroi();
        List& cintoHeroi();
        CriandoItem& maoHeroi();
        string& exibindoNome();
        void curandoHeroi(CriandoItem &x);
        void dandoDanoNoHeroi(CriandoInimigo &x);
};

























