#ifndef MUSIC_H
#define MUSIC_H

typedef struct music *MUSIC;

/// @brief  Cria uma estrutura do tipo MUSIC
/// @param  info Um array de strings com toda a informação necessaŕia para criar um artista
/// @return Uma estrutura do tipo música
MUSIC music_create (char** info);

/// @brief "Dá" 'free' a uma estrutura do tipo MUSIC
/// @param  music A música a que se pretende "dar" 'free'
void music_free (MUSIC music);

/// @brief  Getter do id de uma música
/// @param  music A música de que se pretende o id
/// @return O id da música
char *music_get_id_music(MUSIC music);

/// @brief  Getter da duração de uma música
/// @param  music A música de que se pretendea duração
/// @return O valor da duração de uma música 
int music_get_duration (MUSIC music);

/// @brief  Getter do género de uma música
/// @param  music A música de que se pretende o género
/// @return O género da música
char *music_get_genre(MUSIC music);

/// @brief  Getter do id de artista de uma música
/// @param  music A música de que se pretende o id de artista
/// @return O id do artista da música
char *music_get_artists_id(MUSIC music);

/// @brief  Getter do id de álbum de uma música
/// @param  music A música de que se pretende o id de álbum 
/// @return O id de álbum da música
char* music_get_album_id(MUSIC music);

#endif 