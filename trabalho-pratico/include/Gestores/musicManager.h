#include "../../include/Entidades/music.h"
#include <glib.h>


#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

typedef struct MusicManager *MUSIC_MANAGER;

/// @brief  Verifica se uma música existe na HashTable de músicas
/// @param  music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @param  id O id da música que pretendemos verificar se existe na HashTable de músicas
/// @return Uma estrutura do tipo MUSIC
MUSIC music_manager_lookup(MUSIC_MANAGER music_manager, char* id);

/// @brief  Cria uma estrutura do tipo MUSIC_MANAGER
/// @return Uma estrutura do tipo MUSIC_MANAGER criada pela função
MUSIC_MANAGER music_manager_create();

/// @brief Usando outras funções, cria e adiciona uma música à HashTable de músicas
/// @param music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @param info O array de strings com toda a informação necessária para criar uma música
void music_manager_add (MUSIC_MANAGER music_manager, char ** info);

/// @brief "Dá" 'free' a uma estrutura do tipo MUSIC_MANAGER
/// @param music_manager A estrutura a que se pretende "dar" 'free'
void music_manager_free (MUSIC_MANAGER music_manager);

/// @brief  Verifica se uma música existe na HashTable de músicas
/// @param music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @param id O id da música que se pretende verificar se está na HashTable de músicas
/// @return Um int que serve apenas como valor booleano
int music_manager_test_exist(MUSIC_MANAGER music_manager, char* id);

/// @brief  Função auxiliar à getter do(s) id('s) de artista(s) de uma música
/// @param  music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @param  id O id da música da qual se pretende calcular o id de artista
/// @return O(s) id('s) de artista(s) da música
char *music_manager_get_artists_id(MUSIC_MANAGER music_manager, char* id);

/// @brief  Função auxiliar à getter do género de uma música
/// @param  music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @param  id O id da música da qual se pretende determinar o género
/// @return O género da música
char * music_manager_get_genre(MUSIC_MANAGER music_manager, char* id);

/// @brief  Função auxiliar à getter da duração de uma música
/// @param  music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @param  id O id da música da qual se pretende determinar a duração
/// @return A duração da música
int music_manager_get_duration(MUSIC_MANAGER music_manager, char* id);

/// @brief  Função auxiliar à getter do id de álbum de uma música
/// @param  music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @param  id O id da música da qual se pretende determinar o id de álbum
/// @return O id de álbum
char* music_manager_get_album_id(MUSIC_MANAGER music_manager, char* id);

/// @brief  Calcula, num array de músicas, qual é o artista mais ouvido (tendo em conta a duração dos históricos de cada uma)
/// @param  arrayMusicas O array de músicas
/// @param  arrayMusicasHistDuracao O array da duração dos históricos correspondentes às músicas
/// @param  len O comprimento dos arrays (são iguais no contexto desta função)
/// @param  music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @return O id do artista mais ouvido
char* get_most_listened_artist(char** arrayMusicas, int* arrayMusicasHistDuracao, int len, MUSIC_MANAGER music_manager);

/// @brief  Calcula, num array de músicas, qual é o género mais ouvido (tendo em conta a duração dos históricos de cada uma)
/// @param  arrayMusicas O array de músicas
/// @param  arrayMusicasHistDuracao O array da duração dos históricos correspondentes às músicas
/// @param  len O comprimento dos arrays (são iguais no contexto desta função)
/// @param  music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @return O nome do género mais ouvido
char* get_most_listened_genre(char** arrayMusicas, int* arrayMusicasHistDuracao, int len, MUSIC_MANAGER music_manager);

/// @brief  Calcula, num array de músicas, qual é o álbum favorito (tendo em conta a duração dos históricos de cada uma)
/// @param  arrayMusicas O array de músicas
/// @param  arrayMusicasHistDuracao O array da duração dos históricos correspondentes às músicas
/// @param  len O comprimento dos arrays (são iguais no contexto desta função)
/// @param  music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @return O id do álbum favorito
char* get_favorite_album(char** arrayMusicas, int* arrayMusicasHistDuracao, int len, MUSIC_MANAGER music_manager);

/// @brief  Calcula, num array de músicas, o tempo total de audição de um determinado artista
/// @param  artist_id O id de artista para o qual se pretende calcular o tempo total de audição
/// @param  arrayMusicas O array de músicas
/// @param  arrayHistsDuration O array da duração dos históricos correspondentes às músicas
/// @param  len O comprimento dos arrays (são iguais no contexto desta função)
/// @param  music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @return O tempo total de audição do artista
int get_total_artist_listime(char* artist_id, char** arrayMusicas, int* arrayHistsDuration, int len, MUSIC_MANAGER music_manager);

/// @brief  Calcula, num array de músicas, o número de músicas de um determinado artista
/// @param  artist_id O id de artista para o qual se pretende calcular o número de músicas ouvidas
/// @param  arrayMusicas O array de músicas
/// @param  len O comprimento do array
/// @param  music_manager O gestor de músicas. É necessário para se aceder à HashTable de músicas
/// @return O número de músicas de um determinado artista ouvidas num array de músicas
int get_total_artist_number(char* artist_id, char** arrayMusicas, int len, MUSIC_MANAGER music_manager);

#endif