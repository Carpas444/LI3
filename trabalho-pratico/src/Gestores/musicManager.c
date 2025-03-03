#include "../../include/Gestores/musicManager.h"
#include "../../include/Estruturas/arrayDinamico.h"
#include "../../include/Entidades/music.h"
#include "../../include/Utility/utility.h"
#include <glib.h>


typedef struct MusicManager{
    GHashTable *Musics;
}*MUSIC_MANAGER;


MUSIC_MANAGER music_manager_create() {

    // pointer da struct e criaçao da ghashtable
    MUSIC_MANAGER music_manager = malloc(sizeof(GHashTable*));
    music_manager->Musics = g_hash_table_new_full(g_str_hash,g_str_equal,free,(void *)music_free);
    return music_manager;
}

void music_manager_add (MUSIC_MANAGER music_manager,char ** info) {
    MUSIC music= music_create(info);
    char * id = music_get_id_music(music);
    g_hash_table_insert(music_manager->Musics,id,music);
}

MUSIC music_manager_lookup (MUSIC_MANAGER music_manager,char *id) {
    MUSIC music = g_hash_table_lookup(music_manager->Musics,id);
    return music;
}

void music_manager_free (MUSIC_MANAGER music_manager) {
    g_hash_table_destroy(music_manager->Musics);
    free(music_manager);
}

int music_manager_test_exist(MUSIC_MANAGER music_manager,char * id) {
    if(music_manager_lookup (music_manager,id) == NULL) return 1;
    else return 0;
}

char *music_manager_get_artists_id(MUSIC_MANAGER music_manager,char *id) {
    MUSIC music = music_manager_lookup (music_manager,id);
    return music_get_artists_id(music);
}

char * music_manager_get_genre(MUSIC_MANAGER music_manager,char * id) {
    return music_get_genre(music_manager_lookup(music_manager,id));
}

int music_manager_get_duration(MUSIC_MANAGER music_manager, char* id){
    return music_get_duration(music_manager_lookup(music_manager, id));
}

char* music_manager_get_album_id(MUSIC_MANAGER music_manager, char* id){
    return music_get_album_id(music_manager_lookup(music_manager, id));
}

char* get_most_listened_artist(char** arrayMusicas, int* arrayMusicasHistDuracao, int len, MUSIC_MANAGER music_manager){
    if(len == 1) return (music_manager_get_artists_id(music_manager, arrayMusicas[0]));

    int arrayDurArt[len];   for(int a = 0; a < len; a++) arrayDurArt[a] = 0;
        
    for(int i = 0; i < len; i++){
        char* artist1 = music_manager_get_artists_id(music_manager, arrayMusicas[i]);
        for(int j = i; j < len; j++){
            if(j == i) {arrayDurArt[i] = arrayMusicasHistDuracao[i];continue;}
            char* artist2 = music_manager_get_artists_id(music_manager, arrayMusicas[j]);
            if(strcmp(artist1, artist2) == 0) (arrayDurArt[i])+=arrayMusicasHistDuracao[j];
            free(artist2);
        }
        free(artist1);
    }
        
    int maxIndex = 0;
    for(int k = 1; k < len; k++){
        if(arrayDurArt[k] > arrayDurArt[maxIndex]) maxIndex = k;
    }

    return (music_manager_get_artists_id(music_manager, arrayMusicas[maxIndex]));
}

char* get_most_listened_genre(char** arrayMusicas, int* arrayMusicasHistDuracao, int len, MUSIC_MANAGER music_manager){
    if(len == 1) return(music_manager_get_genre(music_manager, arrayMusicas[0]));

    int arrayDurGenre[len]; for(int a = 0; a < len; a++) arrayDurGenre[a] = 0;

    for(int i = 0; i < len; i++){
        char* genre1 = music_manager_get_genre(music_manager, arrayMusicas[i]);
        for(int j = i; j < len; j++){
            if(j == i) {arrayDurGenre[i] = arrayMusicasHistDuracao[i];continue;}
            char* genre2 = music_manager_get_genre(music_manager, arrayMusicas[j]);
            if(strcmp(genre1, genre2) == 0) (arrayDurGenre[i])+=arrayMusicasHistDuracao[j];
            free(genre2);
        }
        free(genre1);
    }

    int maxIndex = 0;
    for(int k = 1; k < len; k++){
        if(arrayDurGenre[k] > arrayDurGenre[maxIndex]) maxIndex = k;
        else if(arrayDurGenre[k] == arrayDurGenre[maxIndex] && (strcmp(music_manager_get_genre(music_manager, arrayMusicas[k]), music_manager_get_genre(music_manager, arrayMusicas[maxIndex])) < 0)) maxIndex = k;
    }
    
    return(music_manager_get_genre(music_manager, arrayMusicas[maxIndex]));
}

char* get_favorite_album(char** arrayMusicas, int* arrayMusicasHistDuracao, int len, MUSIC_MANAGER music_manager){
    if(len == 1) return (music_manager_get_album_id(music_manager, arrayMusicas[0]));
    
    int arrayDurAlbum[len]; for(int a = 0; a < len; a++) arrayDurAlbum[a] = 0;

    for(int i = 0; i < len; i++){
        char* album1 = music_manager_get_album_id(music_manager, arrayMusicas[i]);
        for(int j = i; j < len; j++){
            if(j == i) {arrayDurAlbum[i] = arrayMusicasHistDuracao[i];continue;}
            char* album2 = music_manager_get_album_id(music_manager, arrayMusicas[j]);
            if(strcmp(album1, album2) == 0) (arrayDurAlbum[i])+=arrayMusicasHistDuracao[j];
            free(album2);
        }
        free(album1);
    }

    int maxIndex = 0;
    for(int k = 0; k < len; k++){
        if(arrayDurAlbum[k] > arrayDurAlbum[maxIndex]) maxIndex = k;
        //else if(arrayDurAlbum[k] == arrayDurAlbum[maxIndex] && )
    }
    return (music_manager_get_album_id(music_manager, arrayMusicas[maxIndex]));
}

int get_total_artist_listime(char* artist_id, char** arrayMusicas, int* arrayHistsDuration, int len, MUSIC_MANAGER music_manager){
    int total = 0;
    for(int i = 0; i < len; i++){
        char* artist2 = music_manager_get_artists_id(music_manager, arrayMusicas[i]);
        if(strcmp(artist_id, artist2) == 0) total += arrayHistsDuration[i];
        free(artist2);
    }
    return total;
}

int get_total_artist_number(char* artist_id, char** arrayMusicas, int len, MUSIC_MANAGER music_manager){
    int total = 0;
    for(int i = 0; i < len; i++){
        char* artists_id = music_manager_get_artists_id(music_manager, arrayMusicas[i]);
        char* copia = artists_id;
        char *id;
        while((id =strsep(&artists_id,",")) != NULL) {
            if (strcmp(artist_id,id) == 0 ) {
            if (i == 0) total++;
            else if (arrayMusicas[i-1] != arrayMusicas[i]) total++;
        }
        }
        free(copia);
    }
    return total;
}