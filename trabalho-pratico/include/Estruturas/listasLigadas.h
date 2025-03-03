#ifndef LISTAS_LIGADAS_H
#define LISTAS_LIGADAS_H

#include <stdlib.h>
typedef struct List *LIST;

/// @brief Funçao que cria uma struct List ou seja uma Lista Ligada
/// @param info informaçao inicial da lista
/// @return pointer da struct List
LIST list_create(void *info);


/// @brief Funçao que adiciona informaçao a Lista de forma ordenada
/// @param info informçao que se pretende adicionar
/// @param list lista aonde se pretende guardar a informaçao
/// @param comparar Funçao de comparaçao utiliza para poder colocar a informaçao de forma ordenada
/// @return o pointer do inicio da Lista
LIST list_add_sorted (void *info, LIST list,int (*comparar)(void*,void*));

/// @brief Funçao que avança o pointer da Lista um membro para a frente
/// @param list pointer que ira ser avançado
/// @return pointer do proximo membro da Lista
LIST list_next(LIST list);

/// @brief Funçao que devolve a informaçao guardada num mebro da Lista
/// @param list Pointer do membro que se pretende ir buscar informaçao
/// @return Informaçao guardada nesse membro
void *list_get_info(LIST list);

/// @brief Funçao que liberta a memoria utilizada pela a Lista Ligada
/// @param list Lista que se pretende libertar
/// @param free Funçao que ira libertar a memoria utiliza pelos membros da lista
void list_free(LIST list,void (*free)(void*));

#endif