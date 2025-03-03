#include <stdio.h>
#include <glib.h>
#include "../../include/IO/output.h"
#include "../../include/Gestores/musicManager.h"
#include "../../include/Gestores/artistManager.h"
#include "../../include/Entidades/user.h"
#include "../../include/Utility/utility.h"

typedef struct Query2 {
    int N;
    char *countryInput;
}*QUERY2;

void free_query2(QUERY2 query) {
    if (query->countryInput !=NULL) free(query->countryInput);
    free(query);
}

int query2(ARTIST_MANAGER artist_manager,QUERY2 query2, int tem_S,FILE *output) {
    int bool_escrita = 0;
    int lenArrayArtID = artist_manager_array_get_ln(artist_manager);
    for(int i = 0; i < lenArrayArtID && query2->N != 0; i++){
        char *id = artist_manager_array_get_id(artist_manager,i);
        char* countryArtist = artist_manager_get_country(id,artist_manager);
        char* name = artist_manager_get_name(id,artist_manager);
        char* type = artist_manager_get_type(id,artist_manager);
        char* discography = GiveDisco(artist_manager_get_discography(id,artist_manager));
        if (query2->countryInput == NULL || strcmp(countryArtist, query2->countryInput) == 0){
            write_in_result_str(output,name,0,tem_S);
            write_in_result_str(output,type,0,tem_S);
            write_in_result_str(output,discography,0,tem_S);
            write_in_result_str(output,countryArtist,1,tem_S);
            bool_escrita = 1; query2->N--;
        }
        free(name); free(countryArtist); free(discography); free(type);free(id);
    }
    if(bool_escrita == 0) write_in_result_str(output, "", 1,tem_S);
    if (output != stdout)fclose(output);
    free_query2(query2);
    return 0;
}

QUERY2 query2_create (char **info) {
    QUERY2 query2 = malloc(sizeof(struct Query2));
    query2->N = atoi(info[1]);
    if (info[2] == NULL) query2->countryInput = NULL;
    else query2->countryInput= strdup(info[2]);
    return query2;
}
