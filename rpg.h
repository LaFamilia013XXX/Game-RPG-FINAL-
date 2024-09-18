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


// Criando os Itens do RPG;
enum Tipo {
    POCAODECURA, // Cura o Heroi
    POCAODEPODER, // da um UPP em tudo (HP, Ataque, Defesa, Agilidade e Luck)
    POCAODEDEFESA, // aumenta tmeporariamente a defesa (escudo do heroi)
    POCAODASORTE, // aumenta a sorte de dar crítico e/ou esquivar de um inimigo
    ESPADA, // para o Barbaro
    MACHADO, // para o Barbaro
    VARINHA, //do mago
    NUM_TIPOS_DE_ITENS
};

struct CriandoItem {
    int Dano;
    string Nome;
    int Peso;
    int Cura;
    int Defesa;
};

class Item {
    public:
        Item();
        int Dano(Tipo tipo) const;
        string Nome(Tipo tipo) const;
        int Peso(Tipo tipo) const;
        int Cura(Tipo tipo) const;
        int Defesa(Tipo tipo) const;
    private:
        CriandoItem itens[NUM_TIPOS_DE_ITENS];
        void IniciandoItem();
        
};


// Estruturas de organização

// Mochila Usuario
const int MaxList = 100;
class List {
    public:
        List();
        ~List();
        bool Empty();
        bool Full();
        void Insert(int p, int x);
        void Delete(int p, int &x);
        void Retrieve(int p, int &x);
        void Replace(int p, int x);
        void Clear();
        int Size();
        void exibirList();
    private:
        int count;
        int Entry[MaxList+1]; 

};

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

const int MaxStack = 4;
class Cinto {
    public:
        Cinto();
        ~Cinto();
        bool Empty();
        bool Full();
        void Push(CriandoItem x);
        void Pop(CriandoItem &x);
        void Clear();
        void Top(CriandoItem &x);
        int Size();
        void exibirCinto();
    private:
        int top;
        CriandoItem Entry[MaxStack]; // Armazena itens de `CriandoItem`
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