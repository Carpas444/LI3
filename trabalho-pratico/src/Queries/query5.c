#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../include/Gestores/musicManager.h"
#include "../../include/Gestores/userManager.h"
#include "../../include/Gestores/genreManager.h"
#include "../../include/recomendador.h"
#include "../../include/IO/output.h"

typedef struct Query5 {
    char* user_id;
    int nr_users;
}*QUERY5;

QUERY5 query5_create(char **info){
    QUERY5 query5 = malloc(sizeof(struct Query5));
    query5->nr_users = atoi(info[2]);
    query5->user_id = strdup(info[1]);
    return query5;
}

void query5_free(QUERY5 query5){
    free(query5->user_id);
    free(query5);
}

int query5(USER_MANAGER user_manager,MUSIC_MANAGER music_manager,GENREMANAGER genre_manager,QUERY5 query,int tem_S,FILE *output) {


    if (user_manager_test_exist(user_manager,query->user_id)) {
        write_in_result_str(output,"",1,tem_S);
        if (output != stdout )fclose(output);
        query5_free(query);
        return -1;
    }
    unsigned int ln_array;
    char **users_id_array = user_manager_get_key_as_array(user_manager,&ln_array);
    int n_genres = genre_manager_get_ln(genre_manager);
    char *genres[n_genres];
    int *matrizClass[ln_array];
    for(int i=0;i<ln_array;i++) {
        const int *user_views_genre = user_manager_get_views_genre(user_manager,users_id_array[i]);
        matrizClass[i] = calloc(n_genres,sizeof(int));
        for (int j =0; user_views_genre != NULL && j<n_genres;j++){
            matrizClass[i][j] = user_views_genre[j];
        }
    }
    for (int i=0;i<n_genres;i++){
        genres[i] = genre_manager_get_name_genre_static(genre_manager,i);
    }
    
    char **recomendados = recomendaUtilizadores(query->user_id,matrizClass,users_id_array,genres,ln_array,n_genres,query->nr_users);

    int bool_escrita=0;
    
    for(int i=0;recomendados != NULL && i< query->nr_users;i++){
        write_in_result_str(output,recomendados[i],1,tem_S);
        bool_escrita =1;
    }
    if (bool_escrita==0) write_in_result_str(output,"",1,tem_S);
    query5_free(query);
    free(users_id_array);
    for (int i=0;i<n_genres;i++){
        free(genres[i]);
    }
    if (output != stdout )fclose(output);
    free(recomendados);
    for(int i=0;i<ln_array;i++){
        free(matrizClass[i]);
    }
    return 0;
}

