#include "../../include/Gestores/musicManager.h"
#include "../../include/Gestores/artistManager.h"

#ifndef QUERY2_H


#define QUERY2_H

typedef struct Query2 *QUERY2;

/// @brief  Calcula o resultado da query2
/// @param  artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param  query2 A estrutura do tipo QUERY2 
/// @param  tem_S Um valor booleano apenas para indicar se o separador de informação deverá ser '=' ou ';'
/// @param  output ficheiro aonde sera escrito o output da query;
/// @return Um int que serve apenas caso se pretenda terminar o processo mais cedo do que o expectável
int query2(ARTIST_MANAGER artist_manager, QUERY2 query2,int tem_S,FILE* output);

/// @brief  Cria uma estrutura do tipo QUERY2
/// @param  info O array de strings com a informação necessária para criar uma estrutura do tipo QUERY2
/// @return A estrutura do tipo QUERY2 criada pela função
QUERY2 query2_create (char **info);

#endif