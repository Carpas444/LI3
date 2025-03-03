
#include <stdio.h>
#include <glib.h>
#include <string.h>
#include "../../include/Entidades/artist.h"
#include "../../include/Utility/utility.h"
#include "../../include/Estruturas/listasLigadas.h"

typedef struct artist{
    char *id;
    char *name;

    double rate_recipe;
    double total_recipe;
    char *id_constituent; //pode vir a ser um Array 2D
    int n_id_constituent;
    char *country;
    int discography;
    char *type;
    int n_individual_albuns;
    int repro_time;
    int listening_time;
    LIST top10_weeks;
    

}*ARTIST;

typedef struct week{
    int number;
}*WEEK;

int give_n_artists(char *artists_id) {
    if (artists_id == NULL ) return 0;
    int n_artists = 1;
    for(int i =0;artists_id[i] != '\0';i++) {
        if(artists_id[i] == ',') n_artists++;
    }
    return n_artists;
}


ARTIST artist_create(char **info) {
    int debug =0;
    if (strcmp(info[1],"Lil Richard") == 0) debug=1;
    ARTIST artist = malloc(sizeof(struct artist));
    artist->id = strdup(info[0]);
    artist->name = strdup(info[1]);
    artist->rate_recipe = atof(info[3]);
    artist->country = strdup(info[5]);
    artist->type = strdup(info[6]);
    artist->discography= 0;
    if (info[4] == NULL) artist->id_constituent = NULL;
    else artist->id_constituent = strdup(info[4]);
    if(info[4] == NULL) artist->n_id_constituent = 0;
    else artist->n_id_constituent = give_n_artists(info[4]);
    artist->n_individual_albuns = 0;
    artist->total_recipe=0; 
    artist->top10_weeks = NULL;
    artist->repro_time=0;
    artist->listening_time =0;
    return artist;


}

void artist_free (ARTIST artist) {
    free(artist->id);
    free(artist->name);
    free(artist->country);
    free(artist->type);
    if (artist->top10_weeks!= NULL) list_free(artist->top10_weeks,free);
    if (artist->id_constituent != NULL) free(artist->id_constituent);
    free(artist);
}

char * artist_get_countryARTIST(ARTIST artist) {
    char* country = strdup(artist->country);
    return country;
}

char * artist_get_name(ARTIST artist) {
    char* name = strdup(artist->name);
    return name;
}

char * artist_get_id_artist(ARTIST artist) {
    char* id = strdup(artist->id);
    return id;
}

void artist_add_discography(ARTIST artist, int duration){
    artist->discography += duration;
}

int artist_get_discography(ARTIST artist) {
    int discography = artist -> discography;
    return discography;
}

char* artist_get_type(ARTIST artist) {
    char* type = strdup(artist -> type);
    return type;
}

char* artist_get_id_constituent(ARTIST artist) {
    return strdup(artist -> id_constituent);
}

int artist_get_num_albuns_individual(ARTIST artist) {
    return artist->n_individual_albuns;
}

int artist_get_n_id_constituent (ARTIST artist) {
    return artist->n_id_constituent;
}


double artist_get_total_recipe(ARTIST artist) {
    return artist->total_recipe;
}

void artist_add_num_individual_albuns(ARTIST artist) {
    artist->n_individual_albuns++;
}

void artist_add_recipe(ARTIST artist,double participacao) {
    if (participacao != 0) artist->total_recipe += participacao;
    else artist->total_recipe +=artist->rate_recipe;
}

int artist_add_repro_time(ARTIST artist,int duration) {
    (artist->repro_time)+=duration;
    return (artist->repro_time);
}

int artist_compare_repro_time(ARTIST artist1,ARTIST artist2) {
    if (artist1->repro_time-artist2->repro_time == 0) {
        return strcmp(artist1->id,artist2->id);
    }
    else return artist2->repro_time-artist1->repro_time;
}

int artist_compare_listening_time(ARTIST artist1,ARTIST artist2) {
    if (artist1->listening_time-artist2->listening_time == 0) {
        return strcmp(artist1->id,artist2->id);
    }
    else return artist2->listening_time-artist1->listening_time;
}

int artist_compare_week(WEEK week1,WEEK week2) {
    return (week1->number)-(week2->number);
}

void artist_add_top10(ARTIST artist, int week) {
    WEEK semana = malloc(sizeof(struct week));
    semana->number = week;
    artist->top10_weeks = list_add_sorted(semana,artist->top10_weeks,artist_compare_week);
}

void artist_set_repro_time(ARTIST artist,int setter) {
    artist->repro_time = setter;
}

int artist_see_top10(ARTIST artist,int week_first,int week_last) {
    int debug =0;
    int n_top10=0;
    if(strcmp(artist->id,"A0006666")==0) debug =1;
    LIST aux = artist->top10_weeks;
    for(;aux && ( week_first  == -1 || ((WEEK)list_get_info(aux))->number<=week_first);aux=list_next(aux)){
        if (week_last == -1 || ((WEEK) list_get_info(aux))->number>= week_last ) n_top10++;
    }
    return n_top10;
}

char * artist_get_id(ARTIST artist) {
    return strdup(artist->id);
}

double artist_get_rate_recipe(ARTIST artist) {
    return artist->rate_recipe;
}

int artist_add_listening_time(ARTIST artist, int time) {
    artist->listening_time+=time;
    return artist->listening_time-time;
}

int artist_get_listening_time(ARTIST artist) {
    return artist->listening_time;
}

void artist_set_listening_time(ARTIST artist,int set) {
    artist->listening_time=set;
}