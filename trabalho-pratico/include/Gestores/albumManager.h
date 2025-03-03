#include "../../include/Entidades/album.h"
#ifndef ALBUM_MANAGER_H
#define ALBUM_MANAGER_H

typedef struct AlbumManager *ALBUM_MANAGER;

/// @brief  Cria uma estrutura do tipo ALBUM_MANAGER
/// @return Uma estrutura do tipo ALBUM_MANAGER criada pela função
ALBUM_MANAGER album_manager_create();

/// @brief Usando três outras funções, cria e adiciona um álbum à HashTable de álbuns
/// @param album_manager O gestor de álbuns. É necessário para se aceder à HashTable de álbuns
/// @param info Um array de strings com toda a informação necessária para se criar um álbum
void album_manager_add(ALBUM_MANAGER album_manager,char ** info);

/// @brief Procura um álbum ha HashTable de álbuns
/// @param album_manager album_manager O gestor de álbuns. É necessário para se aceder à HashTable de álbuns
/// @param id O id do álbum que se pretende procurar
/// @return O álbum (caso exista, senão devolve NULL)
ALBUM album_manager_lookup (ALBUM_MANAGER album_manager, char *id);

/// @brief "Dá" 'free' a uma estrutura do tipo ALBUM_MANAGER
/// @param album_manager A estrutura a que se pretende "dar" 'free'
void album_manager_free(ALBUM_MANAGER album_manager);

/// @brief  Cria um array de strings com os id's de todos os álbuns
/// @param  album_manager É o gestor de álbuns. É necessário para se aceder à HashTable de álbuns
/// @param  ln É o comprimento do array
/// @return Um array de strings, em que cada uma é um id de um álbum
char** album_manager_get_key_as_array(ALBUM_MANAGER album_manager, unsigned int *ln);

/// @brief  Função auxiliar à getter do(s) id('s) de artista(s) de um álbum
/// @param  album_manager É o gestor de álbuns. É necessário para se aceder à HashTable de álbuns
/// @param  id O id do álbum de que se pretende os id('s) do(s) artista(s)
/// @return Uma string com o(s) id('s) do(s) artista(s) (separados por ',')
char* album_manager_get_artists_id (ALBUM_MANAGER album_manager, char * id);


#endif