#include "../../include/Gestores/userManager.h"
#include "../../include/Gestores/artistManager.h"

#ifndef QUERY1_H
#define QUERY1_H

typedef struct Query1 *QUERY1;

/// @brief Calcula o resultado da query1
/// @param user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param query1 A estrutura do tipo QUERY1 
/// @param tem_S Um valor booleano apenas para indicar se o separador de informação deverá ser '=' ou ';'
/// @param  output ficheiro aonde sera escrito o output da query;
void query1(USER_MANAGER user_manager, ARTIST_MANAGER artist_manager, QUERY1 query1, int tem_S,FILE *output);

/// @brief  Cria uma estrutura do tipo QUERY1
/// @param  info O array de strings com a informação necessária para criar uma estrutura do tipo QUERY1
/// @return A estrutura do tipo QUERY1 criada pela função
QUERY1 query1_create(char **info);

#endif