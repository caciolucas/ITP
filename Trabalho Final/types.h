/**
 * @file types.h
 * @brief Estruturas, enums e variáveis globais
 * @details Define a estrutura que armazena o nome e o valor de uma parâmetro, *\ref item) define 
 * a variável global \ref inputValues que armazena todos os parâmetros para que possam ser acessados
 * em qualquer função e define o enum \ref paramIndex que relaciona o parâmetro com sua posição
 * no \ref inputValues
 */
typedef struct
{
    double value;  ///< Valor do parâmetro
    char name[20]; ///< Nome do parâmetro
} item;

item inputValues[15]; ///< Armazena os valores passados através do arquivo de entrada


///@name Posição dos vetores nos cenários
///@{
#define S 0 ///< Associa S com 0 para que se possa acessar o vetor de Sucetiveis com "cenario[S]"
#define I 1 ///< Associa I com 1 para que se possa acessar o vetor de Infectados com "cenario[I]"
#define R 2 ///< Associa R com 2 para que se possa acessar o vetor de Removidos com "cenario[R]"
#define D 3 ///< Associa D com 3 para que se possa acessar o vetor de Mortos com "cenario[D]"
///@}


/// Enum que relaciona o nome do parâmetro à sua posição no array inputValues
enum paramIndex
{
    S0 /// 0
    ,
    I0 /// 1
    ,
    R0 /// 2
    ,
    h /// 3
    ,
    N_b /// 4
    ,
    T_b /// 5
    ,
    S_b0 /// 6
    ,
    I_b0 /// 7
    ,
    m_k /// 8
    ,
    n_k /// 9
    ,
    T_k /// 10
    ,
    tempo_T_b2 /// 11
    ,
    T_b2 ///  12
    ,
    tempo_T_k2 /// 13
    ,
    T_k2 /// 14
};

