#include "../../include/Gestores/musicManager.h"
#include "../../include/Gestores/userManager.h"
#include "../../include/Gestores/genreManager.h"


#ifndef QUERY5_H

#define QUERY5_h

typedef struct Query5 *QUERY5;

/// @brief  Cria uma estrutura do tipo QUERY5
/// @param  info O array de strings com a informação necessária para criar uma estrutura do tipo QUERY5
/// @return A estrutura do tipo QUERY5 criada pela função
QUERY5 query5_create(char **info);

/// @brief Calcula o resultado da query5
/// @param user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @param genre_manager O gestor de géneros. É necessário para se aceder à estrutura de géneros 
/// @param query5 A estrutura do tipo QUERY5
/// @param tem_S tem_S Um valor booleano apenas para indicar se o separador de informação deverá ser '=' ou ';'
/// @param  output ficheiro aonde sera escrito o output da query;
/// @return Um int que serve apenas caso se pretenda terminar o processo mais cedo do que o expectável
int query5(USER_MANAGER user_manager,MUSIC_MANAGER music_manager,GENREMANAGER genre_manager,QUERY5 query5,int tem_S,FILE *output);

#endif