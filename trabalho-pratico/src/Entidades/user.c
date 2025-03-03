#include <stdio.h>
#include <glib.h>
#include <string.h>
#include "../../include/Entidades/user.h"
#include "../../include/Utility/utility.h"
#include "../../include/Estruturas/arrayDinamico.h"

typedef struct user {
    char *username;
    char *email;
    char *first_name;
    char *last_name;
    int  age;
    char *country;
    char *sub_type;
    char *liked_musics_id;
    int * views_genre;
    ARRAYD user_history;
}*USER;


USER user_create(char **info) {
    USER user = malloc(sizeof(struct user));
    user->username = strdup(info[0]);
    user->email = strdup(info[1]);
    user->first_name = strdup(info[2]);
    user->last_name = strdup(info[3]);
    user->age = GiveAge(info[4]);
    user->country = strdup(info[5]);
    user->sub_type = strdup(info[6]);
    if (info[7] != NULL) user->liked_musics_id = strdup(info[7]);
    else user->liked_musics_id = NULL;
    user->views_genre = NULL;
    user->user_history = arrayd_create(sizeof(char*),20);
    return user;

}

void user_free (USER user) {
    free(user->username);
    free(user->email);
    free(user->first_name);
    free(user->last_name);
    free(user->country );
    free(user->sub_type);
    if (user->liked_musics_id != NULL) free(user->liked_musics_id);
    if (user->views_genre != NULL) free(user->views_genre);
    arrayd_free(user->user_history,free,0);
    free(user);
}

int user_check_age (USER user,int max_age,int min_age) {
    int age = user->age;
    if (age >=min_age && age <= max_age) return 1;
    else return 0;
}

char *user_get_username(USER user) {
    char *s=strdup(user->username);
    return s;
}

char *user_get_email(USER user) {
    char *s=strdup(user->email);
    return s;
}

char *user_get_firstname(USER user){
    char *s=strdup(user->first_name);
    return s;
}

char *user_get_lastname(USER user){
    char *s=strdup(user->last_name);
    return s;
}

int user_get_age(USER user){
    return user->age;
}

char *user_get_country(USER user){
    char *s=strdup(user->country);
    return s;
}

char *user_get_liked_id_musics(USER user) {
    char*s=strdup(user->liked_musics_id);
    return s;
}

void user_create_views_genre(USER user, int ln) {
    if (user->views_genre == NULL) user->views_genre = calloc(ln,sizeof(int));
}

void user_add_views_genre(USER user,int index) {
    user->views_genre[index]++;
}

const int * user_get_views_genre(USER user) {
    return user->views_genre;
}

void user_add_history(USER user,char* history_id){
    arrayd_add(strdup(history_id),user->user_history);
}

char **user_get_user_history(USER user,int *ln) {
    (*ln) = arrayd_get_length(user->user_history);
    char **copia= calloc(*ln,sizeof(char*));
    for(int i =0;i<*ln;i++){
        copia[i] = strdup((char*)arrayd_index(user->user_history,i));
    }
    return copia;
}