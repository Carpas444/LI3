#include <stdio.h>
#include <glib.h>
#include <string.h>

typedef struct Album {
    char *id;
    char *artists_id;
}*ALBUM;

ALBUM album_create(char **info) {
    ALBUM album = malloc(sizeof(struct Album));
    album->id = strdup(info[0]);
    album->artists_id = strdup(info[2]);
    return album;
}

void album_free(ALBUM album) {
    free(album->id);
    free(album->artists_id);
    free(album);
}

char * album_get_id_album(ALBUM album) {
    char* id = strdup(album->id);
    return id;
}

char *album_get_artists_id(ALBUM album) {
    char* artists_id = strdup(album->artists_id);
    return artists_id;
}

