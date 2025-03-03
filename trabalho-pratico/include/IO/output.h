#include <stdio.h>

#ifndef OUTPUT_H
#define OUTPUT_H

typedef struct File *FICHEIRO;

/// @brief  Cria um ficheiro para escrever os resultados das queries
/// @param  command_number O número do comando que está a ser executado
/// @return O ficheiro criado pela função
FILE *create_result_file(int command_number);

/// @brief Escreve, num ficheiro, informação do tipo int
/// @param FILE* O ficheiro onde é escrita a informação passada no argumento seguinte
/// @param info A informação (neste caso, do tipo int) que se pretende escrever no ficheiro
/// @param lastline Um valor booleano apenas para indicar se esta é a última linha a ser escrita ou não
/// @param tem_S Um valor booleano apenas para indicar se o separador de informação deverá ser '=' ou ';'
void write_in_result_int (FILE* output, int info, int lastline, int tem_S);

/// @brief Escreve, num ficheiro, informação do tipo char* (string)
/// @param FILE* O ficheiro onde é escrita a informação passada no argumento seguinte
/// @param info A informação (neste caso, do tipo char* (string)) que se pretende escrever no ficheiro
/// @param lastline Um valor booleano apenas para indicar se esta é a última linha a ser escrita ou não
/// @param tem_S Um valor booleano apenas para indicar se o separador de informação deverá ser '=' ou ';'
void write_in_result_str (FILE* output, char* info, int lastline, int tem_S);

/// @brief Escreve, num ficheiro, informação do tipo double
/// @param FILE* O ficheiro onde é escrita a informação passada no argumento seguinte
/// @param info A informação (neste caso, do tipo double) que se pretende escrever no ficheiro
/// @param lastline Um valor booleano apenas para indicar se esta é a última linha a ser escrita ou não
/// @param tem_S Um valor booleano apenas para indicar se o separador de informação deverá ser '=' ou ';'
void write_in_result_double (FILE* output, double info, int lastline, int tem_S);

#endif