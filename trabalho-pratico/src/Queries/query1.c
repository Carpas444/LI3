#include <stdio.h>
#include <glib.h>
#include "../../include/IO/output.h"
#include "../../include/Gestores/userManager.h"
#include "../../include/Gestores/artistManager.h"
#include "../../include/Utility/utility.h"

typedef struct Query1 {
    char* id;
}*QUERY1;

void free_query1(QUERY1 query) {
    free(query->id);
    free(query);
}

int query1(USER_MANAGER user_manager,ARTIST_MANAGER artist_manager,QUERY1 query, int tem_S,FILE *output) {


    int bool_user = 1;
    int bool_artist = 1;


    if (user_manager_test_exist(user_manager,query->id)) bool_user =0;
    else {
        char *email=user_manager_get_email(user_manager,query->id);
        write_in_result_str(output,email,0,tem_S);
        char *firstname=user_manager_get_firstname(user_manager,query->id);
        write_in_result_str(output,firstname,0,tem_S);
        char *lastname =user_manager_get_lastname(user_manager,query->id);
        write_in_result_str(output,lastname,0,tem_S);
        int age = user_manager_get_age(user_manager,query->id);
        write_in_result_int(output,age,0,tem_S);
        char *country=user_manager_get_country(user_manager,query->id);
        write_in_result_str(output,country,1,tem_S);
        free(email);
        free(firstname);
        free(lastname);
        free(country);
    }
    if (artist_manager_test_exist(artist_manager,query->id))  bool_artist =0;
    else {
        char *name = artist_manager_get_name(query->id,artist_manager);
        char *type = artist_manager_get_type(query->id,artist_manager);
        char *country = artist_manager_get_country(query->id,artist_manager);
        int num_albuns_indvidual = artist_manager_get_num_albuns_individual(query->id,artist_manager);
        double total_recipe = artist_manager_get_total_recipe(query->id,artist_manager);
        write_in_result_str(output,name,0,tem_S);
        write_in_result_str(output,type,0,tem_S);
        write_in_result_str(output,country,0,tem_S);
        write_in_result_int(output,num_albuns_indvidual,0,tem_S);
        write_in_result_double(output,total_recipe,1,tem_S);
        free(name);
        free(type);
        free(country);
    }

    
    if (!bool_user &&  !bool_artist) write_in_result_str(output,"",1,tem_S);
    free_query1(query);
    if (output != stdout)fclose(output);
    return 0;
}

QUERY1 query1_create(char **info){
    QUERY1 query = malloc(sizeof(struct Query1));
    query->id = strdup(info[1]);
    return query;
}