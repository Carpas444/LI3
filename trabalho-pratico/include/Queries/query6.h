#include "../../include/Gestores/historyManager.h"
#include "../../include/Gestores/musicManager.h"
#include "../../include/Gestores/artistManager.h"
#include "../../include/Gestores/userManager.h"

#ifndef QUERY6_H
#define QUERY6_H

typedef struct Query6 *QUERY6;

/// @brief  Cria uma estrutura do tipo QUERY6
/// @param  info O array de strings com a informação necessária para criar uma estrutura do tipo QUERY6
/// @return A estrutura do tipo QUERY6 criada pela função
QUERY6 query6_create (char** info);

/// @brief  Calcula o resultado da query6
/// @param history_manager O gestor de históricos. É necessário para se aceder à HashTable de históricos
/// @param music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param query6 A estrutura do tipo QUERY6
/// @param  tem_S Um valor booleano apenas para indicar se o separador de informação deverá ser '=' ou ';'
/// @param  output ficheiro aonde sera escrito o output da query;
/// @return Um int que serve apenas caso se pretenda terminar o processo mais cedo do que o expectável
int query6(HISTORY_MANAGER history_manager, MUSIC_MANAGER music_manager,ARTIST_MANAGER artist_manager,USER_MANAGER user_manager, QUERY6 query6,int tem_S,FILE*output);

#endif