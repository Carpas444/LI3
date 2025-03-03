#include <stdio.h>
#include <string.h>
#include "../../include/Entidades/music.h"
#include "../../include/Utility/utility.h"
#include <stdlib.h>


typedef struct music {
    char *id;
    char *artist_id; // pode vir a ser um Array 2D
    char *album_id;
    int duration; // em segundos
    char *genre;

}*MUSIC;

MUSIC music_create (char **info){
    MUSIC music = malloc(sizeof(struct music));
    music->id = strdup(info[0]);
    if (info[2] != NULL) music->artist_id = strdup(info[2]);
    else music->artist_id = NULL;
    music->album_id = strdup(info[3]);
    int sec = GiveSeconds(info[4]);
    music->duration = sec;
    music->genre = strdup(info[5]);
    return music;
}

void music_free (MUSIC music) {
    free(music->id);
    free(music->artist_id);
    free(music->album_id);
    free(music->genre);
    free(music);
}

char *music_get_id_music(MUSIC music) {
    char* id = strdup(music->id);
    return id;
}

int music_get_duration (MUSIC music) {
    return music->duration;
}

char *music_get_genre(MUSIC music) {
    char* id = strdup(music->genre);
    return id;
}

char *music_get_artists_id(MUSIC music) {
    return strdup(music->artist_id);
}

char* music_get_album_id(MUSIC music){
    return strdup(music->album_id);
}