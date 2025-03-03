#include "../../include/Entidades/genre.h"

#ifndef GENREMANAGER_H

#define GENREMANAGER_H

typedef struct GenreManager *GENREMANAGER;

/// @brief  Cria uma estrutura do tipo GenreManager
/// @return Uma estrutura do tipo GenreManager
GENREMANAGER genre_manager_create();

/// @brief Adiciona um género ao array de géneros na estrutura do tipo GENREMANAGER
/// @param genre_manager A estrutura a que se adiciona o género
/// @param genre O género que se pretende adicionar à estrutura do tipo GENREMANAGER
void genre_manager_add(GENREMANAGER genre_manager, GENRE genre);

/// @brief Usando quatro outras funções, adiciona um like a um género, tendo em conta a idade do user que deu like
/// @param genre_manager O gestor de géneros. É usado para se aceder a esta estrutura e, consequentemente, ao seu array de géneros
/// @param genreS O género a que se pretende adicionar um like
/// @param age A idade do user que deu like no género
void genre_manager_likes(GENREMANAGER genre_manager,char*genreS,int age);

/// @brief Função auxiliar à set_soma_likes
/// @param genre_manager O gestor de géneros. É usado para se aceder a esta estrutura e, consequentemente, ao seu array de géneros
/// @param min A idade mínima a considerar para esta função
/// @param max A idade máxima a considerar para esta função
void genre_manager_soma_likes(GENREMANAGER genre_manager,int min , int max);

/// @brief Ordena um array de géneros pelo valor de likes
/// @param genre_manager O gestor de géneros. É usado para se aceder a esta estrutura e, consequentemente, ao seu array de géneros
void sort_genre_manager(GENREMANAGER genre_manager);

/// @brief "Dá" 'free' a uma estrutura do tipo GENREMANAGER
/// @param genre_manager A estrutura a que se pretende "dar" 'free'
void genre_manager_free(GENREMANAGER genre_manager);

/// @brief  Função auxiliar à getter do nome do género
/// @param  genre_manager O gestor de géneros. É usado para se aceder a esta estrutura e, consequentemente, ao seu array de géneros
/// @param  index O índice do array onde está o género de que se pretende o nome
/// @return O nome do género
char *genre_manager_get_name_genre(GENREMANAGER genre_manager,int index);

/// @brief Função auxiliar à getter do nome de um género
/// @param genre_manager O gestor de géneros. É usado para se aceder a esta estrutura e, consequentemente, ao seu array estático de géneros
/// @param index O índice do array a que se pretende aceder
/// @return O nome do género
char *genre_manager_get_name_genre_static(GENREMANAGER genre_manager,int index);

/// @brief  Função auxiliar à getter da soma de likes do género
/// @param  genre_manager O gestor de géneros. É usado para se aceder a esta estrutura e, consequentemente, ao seu array de géneros
/// @param  index O índice do array onde está o género de que se pretetende a soma de likes
/// @return A soma de likes do género
int genre_manager_get_soma_likes(GENREMANAGER genre_manager,int index);

/// @brief Função auxiliar à set_soma_likes_to_0
/// @param genre_manager O gestor de géneros. É usado para se aceder a esta estrutura e, consequentemente, ao seu array de géneros
/// @param index O índice a que se pretende aceder no array dinâmico de géneros
void genre_manager_set_soma_likes_to_0(GENREMANAGER genre_manager,int index);

/// @brief Calcula o índice onde está o género no array estático de géneros
/// @param genre_manager O gestor de géneros. É usado para se aceder a esta estrutura e, consequentemente, ao seu array de géneros
/// @param genreS O género de que se pretende saber o índice no array estático de géneros
/// @return O índice do array
int genre_manager_get_index_genre_static(GENREMANAGER genre_manager,char *genreS);

/// @brief Calcula o comprimento do array de géneros
/// @param genre_manager O gestor de géneros. É usado para se aceder a esta estrutura e, consequentemente, ao seu array de géneros
/// @return O comprimento do array
int genre_manager_get_ln(GENREMANAGER genre_manager);

#endif