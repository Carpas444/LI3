#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/Validações/validacaoLogUsers.h"
#include "../../include/appManager.h"
#include "../../include/Utility/utility.h"


int validaLog_user(char** user,MASTER_MANAGER master_manager){

    if (user[7] == NULL) return 1;
    char *musics_id = strdup(user[7]);
    char *aux = musics_id;
    int valido = 1;
    char **id=calloc(100,sizeof(char*));
    int length_id=100;
    int i;
    for(i=0;valido ==1 && (id[i] = strsep(&aux,",")) != NULL;i++) {
        if(i==length_id -1) {
            id = realloc(id,sizeof(id)*2);
            length_id = length_id *2;
        }
        if (music_manager_test_exist(get_music_manager(master_manager),id[i])) valido =0;
    }
    if (valido == 1) {
        char * birth_date = strdup(user[4]);
        char * aux_birth_date = birth_date;
        int age = GiveAge(birth_date);
        for(int j=0;j<i;j++) {
            char* genre = music_manager_get_genre(get_music_manager(master_manager),id[j]);
            genre_manager_likes(get_genre_manager(master_manager),genre,age);
            free(genre);
        }
        free(aux_birth_date);
    }
    free(id);
    free(musics_id);
    return valido;
}