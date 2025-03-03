#include "../../include/Gestores/musicManager.h"
#include "../../include/Gestores/userManager.h"
#include "../../include/Gestores/genreManager.h"
#include "../../include/Entidades/user.h"
#include "../../include/IO/output.h"


typedef struct Query3 {
    int min_age;
    int max_age;
}*QUERY3;


void query3(GENREMANAGER genre_manager,QUERY3 query,int tem_S,FILE *output) {

    genre_manager_soma_likes(genre_manager,query->min_age,query->max_age);
    sort_genre_manager(genre_manager);
    int length = genre_manager_get_ln(genre_manager);
    int bool_escrita=0;
    for (int i=0;i<length;i++) {
        char* name_genre = genre_manager_get_name_genre(genre_manager,i);
        int likes = genre_manager_get_soma_likes(genre_manager,i);
        if (likes !=0) {
        write_in_result_str(output,name_genre,0,tem_S);
        write_in_result_int(output,likes,1,tem_S);
        bool_escrita =1;
        genre_manager_set_soma_likes_to_0(genre_manager,i);
        }
        free(name_genre);
    }
    if (bool_escrita==0) write_in_result_str(output,"",1,tem_S);
    free(query);
    if (output != stdout) fclose(output);


}

QUERY3 query3_create(char **info){
    QUERY3 query3 = malloc(sizeof(struct Query3));
    query3->max_age = atoi(info[2]);
    query3->min_age = atoi (info[1]);
    return query3;
}
