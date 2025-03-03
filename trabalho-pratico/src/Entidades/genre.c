#include <stdio.h>
#include <glib.h>
#include <string.h>
#include "../../include/Utility/utility.h"
#include "../../include/Estruturas/listasLigadas.h"

typedef struct Likes {
    int age;
    int n_likes;
}*LIKES;

typedef struct Genre {
    char *name_genre;
    LIST likes_per_age;
    int soma_likes;
}*GENRE;

GENRE genre_create(char *genreS){
    GENRE genre =malloc(sizeof(struct Genre));
    genre->name_genre = strdup(genreS);
    genre->likes_per_age = NULL;
    genre->soma_likes =0;
    return genre;
}



LIKES likes_create (int age) {
    LIKES likes = malloc(sizeof(struct Likes));
    likes->age = age;
    likes->n_likes = 1;
    return likes;
}


int likes_compare(LIKES likes1,LIKES likes2) {
    return (likes1->age)-(likes2->age);
}

void genre_free (GENRE genre) {
    list_free(genre->likes_per_age,free);
    free(genre->name_genre);
    free(genre);
}

char *genre_get_name_genre(GENRE genre) {
    char*s = strdup(genre->name_genre);
    return s;
}

int genre_get_soma_likes(GENRE genre) {
    return genre->soma_likes;
}

LIKES genre_likes_lookup(LIST list,int age) {
    LIKES likes;
    for(;list && (likes=((LIKES) list_get_info(list)))->age != age;list=list_next(list));
    if (list == NULL) return NULL;
    return likes;
}

void genre_add_likes(GENRE genre,int age) {
    LIKES likes = genre_likes_lookup(genre->likes_per_age,age);
    if (likes != NULL) likes->n_likes++;
    else {
        genre->likes_per_age = list_add_sorted(likes_create(age),genre->likes_per_age,likes_compare);
    }
}

void set_soma_likes(GENRE genre,int min,int max) {
    LIST aux = genre->likes_per_age;
    LIKES likes = ((LIKES)(list_get_info(aux)));
    for(;aux && likes->age <= max;aux=list_next(aux),likes = ((LIKES)(list_get_info(aux)))) {
        if (likes->age>=min) genre->soma_likes += likes->n_likes;
    }
}

int menor_soma_likes (const void * genre1_,const void * genre2_) {
    GENRE genre1 = *(GENRE*) genre1_;
    GENRE genre2 = *(GENRE*) genre2_;
    if (genre1->soma_likes < genre2->soma_likes || (genre1->soma_likes == genre2->soma_likes && strcmp(genre1->name_genre,genre2->name_genre) > 0)) 
        return 1;
    else return -1;
}

void set_soma_likes_to_0(GENRE genre) {
    genre->soma_likes =0;
}