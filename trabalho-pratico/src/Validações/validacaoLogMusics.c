#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/Validações/validacaoLogMusics.h"
#include "../../include/appManager.h"
#include "../../include/Utility/utility.h"


int validaLog_music(char** music,MASTER_MANAGER master_manager){
    char *artists_id = strdup(music[2]);
    char *aux = artists_id;
    int valido = 1;
    char **id = calloc(10,sizeof(char*));
    int length_id = 10; int i;
    ALBUM album;

    for(i = 0; (id[i] = strsep(&aux, ",")) != NULL; i++){
        if(i == length_id -1){
            id = realloc(id, sizeof(id)*2);
            length_id *= 2;
        }
        if(artist_manager_test_exist(get_artist_manager(master_manager), id[i])) valido = 0;
    }
    if(( album = album_manager_lookup(get_album_manager(master_manager),music[3])) == NULL) valido = 0; 

    if(valido == 1){
        for(int j = 0; j < i; j++){
            char* aux = strdup(music[4]);
            char* copia_aux = aux; // necessario pk como a funçao GiveSeconds utiliza a strsep e perdido o pointer. Assim e possivel dar free.
            int duration = GiveSeconds(aux);
            artist_manager_add_discography(get_artist_manager(master_manager),id[j], duration);
            free(copia_aux);
        }
    }
    free(id);
    free(artists_id);
    return valido; 
}
