#include "../../include/Gestores/artistManager.h"

#ifndef QUERY4_H

#define QUERY4_H

typedef struct Query4 *QUERY4;

/// @brief  Cria uma estrutura do tipo QUERY4
/// @param  info O array de strings com a informação necessária para criar uma estrutura do tipo QUERY4
/// @return A estrutura do tipo QUERY4 criada pela função
QUERY4 query4_create(char **info);

/// @brief Calcula o resultado da query4
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param query4 A estrutura do tipo QUERY4
/// @param tem_S Um valor booleano apenas para indicar se o separador de informação deverá ser '=' ou ';'
/// @param  output ficheiro aonde sera escrito o output da query;
void query4 (ARTIST_MANAGER artist_manager,QUERY4 query4,int tem_S,FILE *output);

#endif 