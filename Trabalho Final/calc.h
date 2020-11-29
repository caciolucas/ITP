

/**
 * @file calc.h
 * @brief Definição das funções usadas para para os cálculos das simulações.
 * @details Prototipa as funções que calculam as taxas b e k e os valores dos 
 * vetores S, I e R da simulação.
 */

/**
 * Recebe os valores necessários para calcular o valor da iteração atual de S
 * @param[in] SLessOne Valor de S na posição anterior no vetor S do cenario
 * @param[in] hNumber Valor de h (intervalo de tempo)
 * @param[in] bNumber Valor de b (taxa de contágio de um indivíduo)
 * @param[in] ILessOne Valor de I na posição anterior no vetor I do cenario
 */
double calcS(
    double SLessOne,
    double hNumber,
    double bNumber,
    double ILessOne);

/**
 * Recebe os valores necessários para calcular o valor da iteração atual de I
 * @param[in] ILessOne Valor de I na posição anterior no vetor I do cenario
 * @param[in] hNumber Valor dd h (intervalo de tempo)
 * @param[in] bNumber Valor de b (taxa de contágio de um indivíduo)
 * @param[in] SLessOne Valor de S na posição anterior no vetor S do cenario
 * @param[in] kNumber Valor de k (probabilidade que um indivíduo se recupere)
 */
double calcI(
    double ILessOne,
    double hNumber,
    double bNumber,
    double SLessOne,
    double kNumber);

/**
 * Recebe os valores necessários para calcular o valor da iteração atual de R
 * @param[in] RLessOne Valor de R na posição anterior no vetor R do cenario
 * @param[in] hNumber Valor de h (intervalo de tempo)
 * @param[in] kNumber Valor de k (probabilidade que um indivíduo se recupere)
 * @param[in] ILessOne Valor de I na posição anterior no vetor I do cenario
 */
double calcR(
    double RLessOne,
    double hNumber,
    double kNumber,
    double ILessOne);

/**
 * Recebe os valores necessários para calcular o valor que representa o comportamento de contágio (b)
 * @param[in] n_bNumber Valor de n_b (número de pessoas suscetíveis que se infectaram em um intervalo de tempo t_b)
 * @param[in] T_bNumber Valor de t_b (intervalo de tempo da observação),
 * @param[in] S_b0Number Valor de S_b0 (número de pessoas suscetíveis no início da observação)
 * @param[in] I_b0Number Valor de I_b0 (número de pessoas infecatadas no início da observação) 
 */
double calcB(
    double n_bNumber,
    double T_bNumber,
    double S_b0Number,
    double I_b0Number);
/**
 * Recebe os valores necessários para calcular o valor que representa o comportamento de contágio (b)
 * @param[in] m_kNumber Valor de m_k (quantidade de individuos que se recuperaram no intervalo)
 * @param[in] n_kNumber Valor de n_k (quantidade total de individuos no intervalo da observação)
 * @param[in] T_kNumber Valor de T_k (intervalo de tempo da observação),
 */
double calcK(
    double m_kNumber,
    double n_kNumber,
    double T_kNumber);