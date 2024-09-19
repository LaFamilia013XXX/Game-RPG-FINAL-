// armas e pocoes
// vida, ataque, defesa, 
#include <string>
using namespace std;

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
    BOSS1,
    BOSS2,
    BOSS3,
    BOSS4,
    BOSS5,
    NUM_TIPOS_DE_INIMIGOS
};

struct CriandoInimigo {
    int dano;
    int barraVida;
};

class Inimigo_generico {
    public:
        Inimigo_generico();
        int dano(TipoInimigo tipoInimigo) const;
        int barraVida(TipoInimigo tipoInimigo) const;
    
    private:
        CriandoInimigo inimigos[NUM_TIPOS_DE_INIMIGOS];
        void iniciandoInimigo();
};






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
extern CriandoItem pocaoSorte_comum;
extern CriandoItem pocaoSorte_raro;
extern CriandoItem pocaoSorte_lendario;
extern CriandoItem pocaoSorte_epico;
extern CriandoItem pocaoDeCura_comum;
extern CriandoItem pocaoDeCura_raro;
extern CriandoItem pocaoDeCura_lendario;
extern CriandoItem pocaoDeCura_epico;
extern CriandoItem pocaoDeDefesa_comum;
extern CriandoItem pocaoDeDefesa_raro;
extern CriandoItem pocaoDeDefesa_lendario;
extern CriandoItem pocaoDeDefesa_epico;
extern CriandoItem pocaoDePoder_comum;
extern CriandoItem pocaoDePoder_raro;
extern CriandoItem pocaoDePoder_lendario;
extern CriandoItem pocaoDePoder_epico;

// Essa será a função responsável para atribuir os valores de cada variável e item criadas aqui no .h, o qual serão chamados no driver.cpp;
void criandoItens();











// Estruturas de organização

// const int MaxList = 100;
// class List {
//     public:
//         List();
//         ~List();
//         bool Empty();
//         bool Full();
//         void Insert(int p, int x);
//         void Delete(int p, int &x);
//         void Retrieve(int p, int &x);
//         void Replace(int p, int x);
//         void Clear();
//         int Size();
//         void exibirList();
//     private:
//         int count;
//         int Entry[MaxList+1]; 

// };



// Mochila Usuario
class Mochila {
    public:
        Mochila();
        ~Mochila();
        bool Empty();
        bool Full();
        void Push(int x);
        void Pop(int &x);
        void Clear();
        void Top(int &x);
        int Size();
    private:

        struct StackNode {
            int Entry;
            StackNode *NextNode;
        };

        typedef StackNode *StackPointer;

        StackPointer top;
};

// const int MaxStack = 4;
// const int PesoMax = 100;
// class Cinto {
//     public:
//         Cinto();
//         ~Cinto();
//         bool Empty();
//         bool Full();
//         bool PesoMaximo();
//         void Push(CriandoItem x);
//         void Pop(CriandoItem &x);
//         void Clear();
//         void Top(CriandoItem &x);
//         int Size();
//         void exibirCinto();
//     private:
//         int top;
//         int peso = 0;
//         CriandoItem Entry[MaxStack]; // Armazena itens de `CriandoItem`
// };

const int MaxList = 4;
class Cinto {
    public:
        Cinto();
        ~Cinto();
        bool Empty();
        bool Full();
        bool PesoMaximo();
        void Insert(int p, CriandoItem x);
        void Delete(int p, CriandoItem &x);
        void Retrieve(int p, CriandoItem &x);
        void Replace(int p, CriandoItem x);
        void Clear();
        int Size();
        void exibirCinto();
    private:
        int count;
        CriandoItem Entry[MaxList+1]; 
};

const int MaxList = 70;
class ListaItens {
    public:
        ListaItens();
        ~ListaItens();
        bool Empty();
        bool Full();
        bool PesoMaximo();
        void Insert(int p, CriandoItem x);
        void Delete(int p, CriandoItem &x);
        void Retrieve(int p, CriandoItem &x);
        void Replace(int p, CriandoItem x);
        void Clear();
        int Size();
        void exibirListaItens();
    private:
        int count;
        CriandoItem Entry[MaxList+1]; 
};


/*-------------------------------------------------------------------------------------------------------*/
class Heroi
{
    public:
    Heroi(const string name,int hp, int ataque,
    int defesa, 
    int agilidade, 
    int luck, 
    string especial);
void MostrandoTudo();

    ~Heroi(); //destrutor
    private:
        const string Name;
        int HP;
        int Ataque;
        int Defesa;
        int Agilidade; 
        int Luck;
        string Especial;
};
/*-------------------------------------------------------------------------------------------------------*/

class Itens{
public: 
enum class Tipo 
{
    PocaodeCura, // Cura o Heroi
    PocaodoPoder, // da um UPP em tudo (HP, Ataque, Defesa, Agilidade e Luck)
    PocaodeDefesa, // aumenta tmeporariamente a defesa (escudo do heroi)
    PocaodaSorte, // aumenta a sorte de dar crítico e/ou esquivar de um inimigo
    Espada, // para o Barbaro
    Machado, // para o Barbaro
    Varinha //do mago
};

enum class Raridade
{
    Comum,
    Raro,
    Epico,
    Lendario
};

Itens(Tipo tipo, int Nivel, Raridade raridade); 
~Itens();

private:
Tipo tipo;
int Nivel; // irao do 1 ao 5
Raridade raridade;
};
/*-------------------------------------------------------------------------------------------------------*/



/*-------------------------------------------------------------------------------------------------------*/