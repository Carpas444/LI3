#include "../../include/Gestores/genreManager.h"

#ifndef QUERY3_H


#define QUERY3_H

typedef struct Query3 *QUERY3;

/// @brief Calcula o resultado da query2
/// @param genre_manager O gestor de géneros. É necessário para se aceder à estrutura de géneros
/// @param query3 A estrutura do tipo QUERY3
/// @param tem_S Um valor booleano apenas para indicar se o separador de informação deverá ser '=' ou ';'
/// @param output ficheiro aonde sera escrito o output da query;
void query3(GENREMANAGER genre_manager, QUERY3 query3, int tem_S,FILE *output);

/// @brief  Cria uma estrutura do tipo QUERY3
/// @param  info O array de strings com a informação necessária para criar uma estrutura do tipo QUERY3
/// @return A estrutura do tipo QUERY3 criada pela função
QUERY3 query3_create(char **info);
#endif