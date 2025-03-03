#include "../../include/Entidades/genre.h"
#include "../../include/Estruturas/arrayDinamico.h"
#include <stdio.h>
#include <glib.h>
#include <string.h>

typedef struct GenreManager {
    ARRAYD genres;
    ARRAYD genres_static;
}*GENREMANAGER;


GENREMANAGER genre_manager_create() {
    GENREMANAGER genre_manager=malloc(sizeof(struct GenreManager));
    genre_manager->genres=arrayd_create(sizeof(GENRE),10);
    genre_manager->genres_static=arrayd_create(sizeof(GENRE),10);
    return genre_manager;
}

void genre_manager_add(GENREMANAGER genre_manager,GENRE genre) {
    arrayd_add(genre,genre_manager->genres);
    arrayd_add(genre,genre_manager->genres_static);
}

GENRE genre_manager_lookup(ARRAYD genres,char *genreS) {
    for(int i=0;i<arrayd_get_length(genres);i++) {
        char *genre = genre_get_name_genre(arrayd_index(genres,i)); 
        if (strcmp(genre,genreS)==0) {free(genre);return arrayd_index(genres,i);}
        free(genre);
    }
    return NULL;
}

void genre_manager_likes(GENREMANAGER genre_manager,char*genreS,int age) {
    GENRE genre;
    if ((genre = genre_manager_lookup(genre_manager->genres,genreS) )==NULL) {
        genre = genre_create(genreS);
        genre_manager_add(genre_manager,genre);
    }
    genre_add_likes(genre,age);

}

void genre_manager_soma_likes(GENREMANAGER genre_manager,int min , int max) {
    for(int i=0;i<arrayd_get_length(genre_manager->genres);i++) {
        set_soma_likes(arrayd_index(genre_manager->genres,i),min,max);
    }
}


void sort_genre_manager(GENREMANAGER genre_manager) {
    arrayd_sort(genre_manager->genres,menor_soma_likes);
}

void genre_manager_free(GENREMANAGER genre_manager) {
    arrayd_free(genre_manager->genres,genre_free,0);
    arrayd_free(genre_manager->genres_static,genre_free,1);
    free(genre_manager);
}

char *genre_manager_get_name_genre(GENREMANAGER genre_manager,int index){
    return genre_get_name_genre(arrayd_index(genre_manager->genres,index));
}

char *genre_manager_get_name_genre_static(GENREMANAGER genre_manager,int index){
    return genre_get_name_genre(arrayd_index(genre_manager->genres_static,index));
}

int genre_manager_get_soma_likes(GENREMANAGER genre_manager,int index){
    return genre_get_soma_likes(arrayd_index(genre_manager->genres,index));
}

void genre_manager_set_soma_likes_to_0(GENREMANAGER genre_manager,int index){
    set_soma_likes_to_0(arrayd_index(genre_manager->genres,index));
}

int genre_manager_get_index_genre_static(GENREMANAGER genre_manager,char *genreS) {
        for(int i=0;i<arrayd_get_length(genre_manager->genres_static);i++) {
        char *genre = genre_get_name_genre(arrayd_index(genre_manager->genres_static,i)); 
        if (strcmp(genre,genreS)==0) {free(genre);return i;}
        free(genre);
    }
    return -1;
}

int genre_manager_get_ln(GENREMANAGER genre_manager) {
    return arrayd_get_length(genre_manager->genres);
}
