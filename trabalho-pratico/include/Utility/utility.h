#include <stdlib.h>

#ifndef UTILITY_H
#define UTILITY_H

/// @brief Remove um (ou dois) símbolos de uma string
/// @param str A string de onde se pretende remover o(s) símbolo(s)
/// @param simb1 O/um dos símbolo(s) que se pretende remover
/// @param simb2 O/um dos símbolo(s) que se pretende remover 
void rmSimbolo(char* str, char simb1, char simb2);

/// @brief Transforma um array num array 2D
/// @param info O array que se pretende transformar
/// @param size_inital O tamanho do array que se pretende transformar
/// @param simbs O símbolo pela qual a informação deve ser separada
/// @return O array 2D resultante desta função
char **ArrayToArray2D (char* info, int size_inital, char* simbs);

/// @brief  Calcula o número de segundos de um determinado tempo (expresso em hh:mm:ss)
/// @param  time O tempo que se pretende converter a segundos
/// @return O valor convertido, em segundos
int GiveSeconds(char* time);

/// @brief  Calcula, dada uma data de nascimento, a idade atual de um user
/// @param  date A data de nascimento de um user
/// @return A idade de um user
int GiveAge(char* date);

/// @brief Transforma um valor de duração(int) numa string formatada (char*)
/// @param duration O valor que se pretende converter de int para char*
/// @return Uma string formatada pronta a ser escrita onde necessário
char* GiveDisco(int duration);

/// @brief Transforma uma string num array de strings
/// @param src A string original que se pretende dividir
/// @param dest O array de strings resultante
/// @param simb O símbolo pelo qual as strings devem ser separadas
/// @param numpos O número de posições que se quer que o array tenha
void sepString (char* src, char** dest, char* simb, int numpos);

/// @brief Subtrai 7 dias a uma data
/// @param date A data a que se pretende subtrair 7 dias
/// @return A nova data com menos 7 dias do que a data original
char *Sub7Days(char *date);

/// @brief Calcula qual o número da semana de uma determinada data, em comparação com o dia 09/09/2024
/// @param date A data de que se pretende calcular a semana
/// @return O número da semana da data
double GiveWeek(char * date);

/// @brief Algoritmo de ordenação de um array (QuickSort)
/// @param base Pointer para o array
/// @param low O primeiro valor do array
/// @param high O último valor do array
/// @param size Tamanho de um elemento do array
/// @param cmp Função de comparação para o qsort_r
/// @param arg Argumento extra para uma melhor comparação/ordenação
void qsort_r(void* base, int low, int high, size_t size, int (*cmp)(const void*, const void*,void*),void *arg);

/// @brief Troca os valores de dois ints
/// @param a Um dos ints a trocar de valor
/// @param b Um dos ints a trocar de valor
void swap2(int *a, int *b);

/// @brief Ordena um array de índices com base noutro array de ints
/// @param arr Array de ints
/// @param indexes O array que se pretende ordenar com base nos valores do array arr
/// @param size Tamanho de arr
void sortIndexes(int arr[], int indexes[], int size);
//EXEMPLO: arr = [3,8,9,1], indexes(início) = [0,1,2,3] ===> indexes(final) = [2,1,0,3]
#endif