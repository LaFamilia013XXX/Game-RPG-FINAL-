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
enum TipoInimigo {
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

struct CriandoInimigo {
    string nome;
    int dano;
    int barraVida;
    int sqm_level;
    int lvl;
};

class Inimigo_generico {
    public:
        Inimigo_generico();

        int dano(TipoInimigo tipoInimigo) const;
        int barraVida(TipoInimigo tipoInimigo) const;
        string nome(TipoInimigo tipoInimigo) const;
        int sqm_lvl(TipoInimigo tipoInimigo) const;
        int lvl_inimigo(TipoInimigo tipoInimigo) const;

        void sofrendoDano(CriandoInimigo &inimigo, CriandoItem &item);
    private:
        CriandoInimigo inimigos[NUM_TIPOS_DE_INIMIGOS];
        void iniciandoInimigo();
};

// Mochila Usuario
class Mochila {
    public:
        Mochila();
        ~Mochila();
        bool Empty();
        bool Full();
        void Push(CriandoItem x);
        void Pop(CriandoItem &x);
        void Clear();
        void Top(CriandoItem &x);
        int Size();
        void exibirMochila();
    private:

        struct StackNode {
            CriandoItem Entry;
            StackNode *NextNode;
        };

        typedef StackNode *StackPointer;

        StackPointer top;
};

class List{
    public:
        List(int maxList, int maxPeso);
        ~List();
        bool Empty();
        bool full();
        bool fullPeso();
        void Insert (CriandoItem x, int p);
        void Delete(CriandoItem &x, int p);
        int Size();
        void Clear();
        void Retrieve(CriandoItem &x, int p);
        void Replace(CriandoItem x, int p, int &statusPeso);
        void ExibirList();
        int PesoAtual();
    private:
        struct ListNode{
            CriandoItem Entry;
            ListNode *NextNode;
        };

        typedef ListNode*  ListPointer;
        ListPointer head;
        int count;
        int Max;
        int PesoMax;
        int Peso = 0;
        void SetPosition(int p, ListPointer &current);

};

class Heroi {
    private:
        int vida;
        CriandoItem Mao;
        Mochila mochila;
        List cinto;
        string Nome;
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

























