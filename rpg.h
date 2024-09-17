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

// Estruturas de orgnaização






class Mochila
 {
    public:
        bool vazio(); //meu Empty se esta vazio ou quantos itens tem
        bool cheio(); // tira os itens para serem usados
        void InserirItens(int x); // coloca itens na mochila
        void RemoverItens(int &x);//remove os itens da mochila
        void Size();
        void Top(); // mostra o primeiro elemento da pilha que esta no topo
        void Clear(); // limpa os elementos da pilha
    private:

};
/*-------------------------------------------------------------------------------------------------------*/
class Cinto
{
    public:
        Cinto();
        ~Cinto();
        bool Empty(); // verifica se esta vazio
        int Size(); // quantidade de sl
        void VerItens(); // quais itens tem no cinto
        void RemoverItens(int &x); // meu pop usado para retirar itens do topo da pilha e usá-los ou descartá-los
        void InserirItens(int x); // meu push para inserir itens no topo da pilha
        bool Capacidade(); //
        void peso(); // 
        void Slots(); // quais estão sendo usados e quais estão vazios
    private:
};


/*-------------------------------------------------------------------------------------------------------*/
class Heroi
{
    public:
    Heroi(int hp, int ataque,
    int defesa, 
    int agilidade, 
    int luck, 
    string especial);

    ~Heroi(); //destrutor
    private:
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