

/**
 * @file calc.c
 * @brief Implementação das funções usadas para para os cálculos das simulações.
 * @details Define as funções que calculam as taxas b e k e os valores dos 
 * vetores S, I e R da simulação.
 */
#include "calc.h"
double calcB(double n_bNumber, double T_bNumber, double S_b0Number, double I_b0Number)
{
    return n_bNumber / (T_bNumber * S_b0Number * I_b0Number);
}

double calcK(double m_kNumber, double n_kNumber, double T_kNumber)
{
    return m_kNumber / (n_kNumber * T_kNumber);
}
double calcS(
    double SLessOne, double hNumber, double bNumber, double ILessOne)
{
    return SLessOne - hNumber * bNumber * SLessOne * ILessOne;
}

double calcI(
    double ILessOne, double hNumber, double bNumber, double SLessOne, double kNumber)
{
    return ILessOne + hNumber * (bNumber * SLessOne * ILessOne - kNumber * ILessOne);
}

double calcR(
    double RLessOne, double hNumber, double kNumber, double ILessOne)
{
    return RLessOne + hNumber * kNumber * ILessOne;
}
