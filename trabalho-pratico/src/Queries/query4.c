#include <stdlib.h>
#include "../../include/Gestores/artistManager.h"
#include "../../include/Utility/utility.h"
#include "../../include/IO/output.h"
#include <stdio.h>
#include <string.h>

typedef struct Query4 {
    char* first_date;
    char* last_date;
}*QUERY4;

QUERY4 query4_create(char **info){
    QUERY4 query = malloc(sizeof(struct Query4));
    if (info[1] == NULL) {
        query->first_date = NULL;
        query->last_date = NULL;
    }
    else {
        query->first_date = strdup(info[1]);
        query->last_date = strdup(info[2]);
    }
    return query;
}

void free_query4(QUERY4 query) {
    if (query->first_date != NULL) {
        free(query->first_date);
        free(query->last_date);
    }
    free(query);
}

void query4 (ARTIST_MANAGER artist_manager,QUERY4 query4,int tem_S,FILE *output) {

    int week_first = -1;
    int week_last = -1;
    if (query4->first_date != NULL) {
        week_first = GiveWeek(query4->first_date);
        week_last = GiveWeek(query4->last_date);
    }
    char *id_max = NULL;
    int max_top10 =0;
    int n_top10;
    int n_artists = artist_manager_array_get_ln(artist_manager);
    for(int i =0;i<n_artists;i++) {
        char *id = artist_manager_array_get_id(artist_manager,i);
        if ((n_top10 = artist_manager_see_top10(artist_manager,max_top10,id,id_max,week_first,week_last))) {
            free(id_max);
            id_max = strdup(id);
            max_top10 = n_top10;
        }
        free(id);
    }
    if(id_max == NULL) write_in_result_str(output,"",1,tem_S);
    else {
        char * id = artist_manager_get_id(artist_manager,id_max);
        char * type = artist_manager_get_type(id_max,artist_manager);
        write_in_result_str(output,id,0,tem_S);
        write_in_result_str(output,type,0,tem_S);
        write_in_result_int(output,max_top10,1,tem_S);
        free_query4(query4);
        free(id);
        free(id_max);   
        free(type);
    }
    if (output != stdout )fclose(output);
}