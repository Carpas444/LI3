

#ifndef ALBUM_H
#define ALBUM_h

typedef struct Album *ALBUM;

/// @brief  Cria uma estrutura do tipo ALBUM
/// @param  info Um array de strings com toda a informação necessaŕia para criar um álbum
/// @return Um álbum
ALBUM album_create(char** info);

/// @brief "Dá" 'free' a uma estrutura do tipo ALBUM
/// @param album O álbum a que se pretende "dar" 'free'
void album_free(ALBUM album);

/// @brief  Getter do id de um álbum
/// @param  album O álbum do qual se pretende o id (de álbum)
/// @return O id do álbum
char * album_get_id_album(ALBUM album);

/// @brief  Getter do id de artista de um álbum
/// @param  album O álbum do qual se pretende o id de artista
/// @return O id de artista do álbum
char *album_get_artists_id(ALBUM album);

#endif