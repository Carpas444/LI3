#include "../../include/Gestores/artistManager.h"
#include "../../include/Entidades/artist.h"
#include "../../include/Estruturas/arrayDinamico.h"
#include <glib.h>
#include <string.h>

typedef struct ArtistManager{
    GHashTable *Artists;
    ARRAYD Artists_Array_ID;
}*ARTIST_MANAGER;



ARTIST_MANAGER artist_manager_create() {
    ARTIST_MANAGER artist_manager = malloc(sizeof(struct ArtistManager));                            // pointer da struct e criaçao da ghashtable
    artist_manager->Artists = g_hash_table_new_full(g_str_hash,g_str_equal,free,(void *)artist_free);
    artist_manager->Artists_Array_ID = arrayd_create(sizeof(char*),12000);
    return artist_manager;
}

void artist_manager_add (ARTIST_MANAGER artist_manager,char **info) {
    ARTIST artist= artist_create(info);
    char * id = artist_get_id_artist(artist);
    arrayd_add(strdup(id),artist_manager->Artists_Array_ID);
    g_hash_table_insert(artist_manager->Artists,id,artist);
}
ARTIST artist_manager_lookup (ARTIST_MANAGER artist_manager,char *id) {
    ARTIST artist = g_hash_table_lookup(artist_manager->Artists,id);
    return artist;
}

void artist_manager_add_discography (ARTIST_MANAGER artist_manager,char *id , int duration) {
    ARTIST artist = artist_manager_lookup(artist_manager,id);
    artist_add_discography(artist,duration);
}

void artist_manager_free (ARTIST_MANAGER artist_manager) {
    g_hash_table_destroy(artist_manager->Artists);
    arrayd_free(artist_manager->Artists_Array_ID,free,0);
    free(artist_manager);
}

void  artist_manager_add_num_individuals_albuns (ARTIST_MANAGER artist_manager,char* id) {
    ARTIST artist = artist_manager_lookup(artist_manager,id);
    artist_add_num_individual_albuns(artist);
}

int maiorDisco(const void* id1_, const void* id2_, void * artist_manager){
    int r = 0;
    char *id1 = *(char**) id1_;
    char *id2 = *(char**) id2_;
    int disco1 = artist_get_discography(artist_manager_lookup((ARTIST_MANAGER)artist_manager, id1));
    int disco2 = artist_get_discography(artist_manager_lookup((ARTIST_MANAGER)artist_manager, id2));
    if(disco1 == disco2){
        char* aux1 = strdup(id1); char* aux2 = strdup(id2);
        aux1[0] = '0'; aux2[0] = '0';
        r = atoi(aux1)-atoi(aux2);
        free(aux1); free(aux2);
    }
    else r= disco2-disco1;
    return r;
}

int artist_manager_test_exist(ARTIST_MANAGER artist_manager,char * id) {
    if(artist_manager_lookup (artist_manager,id) == NULL) return 1;
    else return 0;
}

void artist_manager_sort_array_id_by_disco(ARTIST_MANAGER artist_manager) {
    arrayd_sort_r(artist_manager->Artists_Array_ID,maiorDisco,artist_manager);
}


void artist_manager_add_recipe(ARTIST_MANAGER artist_manager,char *id,double participacao) { 
        ARTIST artist = artist_manager_lookup(artist_manager,id);
        artist_add_recipe(artist,participacao);
        char *type = artist_get_type(artist);
        if (strcmp(type,"group") ==0) {
            char *id_const;
            char *artists_id_constituent = artist_get_id_constituent(artist);
            char * copia = artists_id_constituent;
            while((id_const = strsep(&artists_id_constituent,",")) != NULL) {
                artist_manager_add_recipe(artist_manager,id_const,(artist_get_rate_recipe(artist)/artist_get_n_id_constituent(artist)));
            }
            free(copia);
        }
        free(type);
}

int artist_manager_add_repro_time(ARTIST_MANAGER artist_manager,char * id, int duration) {
    ARTIST artist = artist_manager_lookup(artist_manager,id);
    int repro_time=artist_add_repro_time(artist,duration);
    return repro_time-duration;
}

char *artist_manager_get_country(char *id, ARTIST_MANAGER artist_manager) {
    return artist_get_countryARTIST(artist_manager_lookup(artist_manager,id));
}

char *artist_manager_get_name(char *id, ARTIST_MANAGER artist_manager) {
    return artist_get_name(artist_manager_lookup(artist_manager,id));
}

char *artist_manager_get_type(char *id, ARTIST_MANAGER artist_manager) {
    return artist_get_type(artist_manager_lookup(artist_manager,id));
}

int artist_manager_get_discography(char *id, ARTIST_MANAGER artist_manager) {
    return artist_get_discography(artist_manager_lookup(artist_manager,id));
}

int artist_manager_get_num_albuns_individual(char *id, ARTIST_MANAGER artist_manager) {
    return artist_get_num_albuns_individual(artist_manager_lookup(artist_manager,id));
}

double artist_manager_get_total_recipe(char *id, ARTIST_MANAGER artist_manager) {
    return artist_get_total_recipe(artist_manager_lookup(artist_manager,id));
}

int artist_manager_compare(const void *id1_, const void *id2_,void * arg) {
    char *id1 = *(char **) id1_;
    char *id2 = *(char **) id2_;
    ARTIST_MANAGER artist_manager = (ARTIST_MANAGER) arg;
    return artist_compare_repro_time(artist_manager_lookup(artist_manager,id1),artist_manager_lookup(artist_manager,id2));
}

int artist_manager_compare_listening_time(const void *id1_, const void *id2_,void * arg) {
    char *id1 = *(char **) id1_;
    char *id2 = *(char **) id2_;
    ARTIST_MANAGER artist_manager = (ARTIST_MANAGER) arg;
    return artist_compare_listening_time(artist_manager_lookup(artist_manager,id1),artist_manager_lookup(artist_manager,id2));
}

void artist_manager_add_top10(ARTIST_MANAGER artist_manager,char *id,int week) {
    ARTIST artist = artist_manager_lookup(artist_manager,id);
    artist_add_top10 (artist,week);
} 

void artist_manager_set_repro_time(ARTIST_MANAGER artist_manager,char *id,int setter) {
    ARTIST artist = artist_manager_lookup(artist_manager,id);
    artist_set_repro_time(artist,setter);
}

int artist_manager_see_top10(ARTIST_MANAGER artist_manager,int max ,char *id,char*max_id,int week_first,int week_last) {
    ARTIST artist = artist_manager_lookup(artist_manager,id);
    int n_top10 = artist_see_top10(artist,week_first,week_last);
    if (max < n_top10 || (max == n_top10 && max_id != NULL && strcmp(max_id,id) > 0 )) return n_top10;
    else return 0;
}

char * artist_manager_get_id(ARTIST_MANAGER artist_manager,char *id) {
    return artist_get_id(artist_manager_lookup(artist_manager,id));
}

int artist_manager_add_listening_time(ARTIST_MANAGER artist_manager,char *id, int time) {
    return artist_add_listening_time(artist_manager_lookup(artist_manager,id),time);
}

int artist_manager_get_listening_time(ARTIST_MANAGER artist_manager,char* id) {
    return artist_get_listening_time(artist_manager_lookup(artist_manager,id));
}

void artist_manager_set_listening_time (ARTIST_MANAGER artist_manager,char *id, int set) {
    artist_set_listening_time(artist_manager_lookup(artist_manager,id),set);
}

int artist_manager_array_get_ln(ARTIST_MANAGER artist_manager){
    return arrayd_get_length(artist_manager->Artists_Array_ID);
}

char * artist_manager_array_get_id (ARTIST_MANAGER artist_manager,int index) {
    return (strdup((char *)arrayd_index(artist_manager->Artists_Array_ID,index)));
}