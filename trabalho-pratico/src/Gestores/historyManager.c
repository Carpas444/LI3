#include "../../include/Entidades/history.h"
#include "../../include/Estruturas/arrayDinamico.h"
#include <glib.h>


typedef struct HistoryManager{
    ARRAYD Historys;
    GHashTable *Historys_HT;
}*HISTORY_MANAGER;


HISTORY_MANAGER history_manager_create() {

    // pointer da struct e criaçao da ghashtable
    HISTORY_MANAGER history_manager = malloc(sizeof(struct HistoryManager));
    history_manager->Historys = arrayd_create(sizeof(HISTORY),500000);
    history_manager->Historys_HT = g_hash_table_new_full(g_str_hash,g_str_equal,free,(void *)history_free);
    return history_manager;
}

void history_manager_add (HISTORY_MANAGER history_manager,char ** info) {
    HISTORY history= history_create(info);
    arrayd_add(history, history_manager->Historys);
    g_hash_table_insert(history_manager->Historys_HT,strdup(info[0]),history);
}


void history_manager_free (HISTORY_MANAGER history_manager) {
    g_hash_table_destroy(history_manager->Historys_HT);
    arrayd_free(history_manager->Historys,history_free,1);
    free(history_manager);
}

char *history_manager_get_music_id(HISTORY_MANAGER history_manager, int index) {
    HISTORY history = (HISTORY) arrayd_index(history_manager->Historys,index);
    return history_get_music_id(history);
}

char *history_manager_get_timestamp(HISTORY_MANAGER history_manager, int index) {
    HISTORY history = (HISTORY) arrayd_index(history_manager->Historys,index);
    return history_get_timestamp(history);
}

char *history_manager_get_user_id(HISTORY_MANAGER history_manager, int index) {
    HISTORY history = (HISTORY) arrayd_index(history_manager->Historys,index);
    return history_get_user_id(history);
}

int history_manager_get_duration(HISTORY_MANAGER history_manager, int index) {
    HISTORY history = (HISTORY) arrayd_index(history_manager->Historys,index);
    return history_get_duration(history);
}

char* history_manager_get_history_id(HISTORY_MANAGER history_manager, int index) {
    HISTORY history = (HISTORY) arrayd_index(history_manager->Historys,index);
    return history_get_history_id(history);
}

int history_manager_get_ln(HISTORY_MANAGER history_manager) {
    return arrayd_get_length(history_manager->Historys);
}

void history_manager_sort_by_date(HISTORY_MANAGER history_manager) {
    arrayd_sort(history_manager->Historys,history_compare);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


HISTORY history_manager_lookup_HT (HISTORY_MANAGER history_manager,char *id) {
    HISTORY history = g_hash_table_lookup(history_manager->Historys_HT,id);
    return history;
}

char *history_manager_get_music_id_HT(HISTORY_MANAGER history_manager,char *id) {
    return history_get_music_id(history_manager_lookup_HT(history_manager,id));
}

char* history_manager_get_timestamp_HT(HISTORY_MANAGER history_manager, char* hist_id){
    return history_get_timestamp(history_manager_lookup_HT(history_manager, hist_id));
}

char* history_manager_get_date_HT(HISTORY_MANAGER history_manager, char* hist_id){
    return history_get_date(history_manager_lookup_HT(history_manager, hist_id));
}

int history_manager_get_duration_HT(HISTORY_MANAGER history_manager, char* hist_id){
    return history_get_duration(history_manager_lookup_HT(history_manager, hist_id));
}

int history_manager_get_hour_HT(HISTORY_MANAGER history_manager, char* id){
    return history_get_hour(history_manager_lookup_HT(history_manager, id));
}

int menorID(char* id1, char* id2){
    int r = 0;
    char* aux1 = strdup(id1); char* aux2 = strdup(id2);
    aux1[0] = '0'; aux2[0] = '0';
    
    if(atoi(aux1) <= atoi(aux2)) r = 1;
    free(aux1); free(aux2);

    return r;
}

void sortArrayHistByMusic(char** array, int len, HISTORY_MANAGER history_manager){
    for(int i = 1; i < len; ++i){
        char* key = array[i];
        int j = i - 1;
        
        char* music1 = history_manager_get_music_id_HT(history_manager, array[j]);
        char* music2 = history_manager_get_music_id_HT(history_manager, key);
        while(j >= 0 && (menorID(music1, music2))){
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = key;
        free(music1); free(music2);
    }
}

int isYearTrue(HISTORY_MANAGER history_manager,char* id, int yearInput){
    char* timestamp = history_manager_get_timestamp_HT(history_manager, id);
    char year[4]; for(int i = 0; i < 4; i++) year[i] = timestamp[i];
    int ano = atoi(year);
    if (ano == yearInput) {free(timestamp); return 1;} 
    else {free(timestamp); return 0;}
}

int get_number_listened_songs(char** array, int len, HISTORY_MANAGER history_manager){
    int total = 0;
    if(len == 1) return 1;
    for(int i = 1; i < len; i++){
        char* music1 = history_manager_get_music_id_HT(history_manager, array[i]);
        char* music2 = history_manager_get_music_id_HT(history_manager, array[i-1]);
        if (strcmp(music1, music2) == 0) {free(music1); free(music2); continue;}
        else {total++; free(music1); free(music2);}
    }
    return total + 1;
}

int get_total_listening_time(char** array, int len, HISTORY_MANAGER history_manager){
    int total = 0;
    for(int i = 0; i < len; i++){
        int duration = history_manager_get_duration_HT(history_manager, array[i]);
        total += duration;
    }
    return total;
}

int get_most_listened_hour(char** arrayHists, int len, HISTORY_MANAGER history_manager){
    if(len == 1) return (history_manager_get_hour_HT(history_manager, arrayHists[0]));

    int arrayHoras[24] = {0};

    for(int i = 0; i < len; i++) {
        arrayHoras[history_manager_get_hour_HT(history_manager, arrayHists[i])]+=history_manager_get_duration_HT(history_manager,arrayHists[i]);
    }

    int maxIndex = 0;
    for(int k = 0; k < 24; k++){
        if(arrayHoras[k] > arrayHoras[maxIndex]) maxIndex = k;
        else if(arrayHoras[k] == arrayHoras[maxIndex] && k < maxIndex) maxIndex = k;
    }

    return maxIndex;
}

char* get_most_listened_day(char** arrayHists, int len, HISTORY_MANAGER history_manager){
    if(len == 1) return (history_manager_get_date_HT(history_manager, arrayHists[0]));

    int arrayDias[len]; for(int a  = 0; a < len; a++) arrayDias[a] = 0;

    for(int i = 0; i < len; i++){
        char* date1 = history_manager_get_date_HT(history_manager, arrayHists[i]);
        for(int j = i; j < len; j++){
            if(j == i) {(arrayDias[i])++;continue;}
            char* date2 = history_manager_get_date_HT(history_manager, arrayHists[j]);
            if(strcmp(date1, date2) == 0) (arrayDias[i])++;
            free(date2);
        }
        free(date1); 
    }  

    int maxIndex = 0;
    for(int k = 0; k < len; k++){
        if(arrayDias[k] > arrayDias[maxIndex]) maxIndex = k;
        else if(arrayDias[k] == arrayDias[maxIndex]){
            char* data1 = history_manager_get_date_HT(history_manager, arrayHists[k]);
            char* data2 = history_manager_get_date_HT(history_manager, arrayHists[maxIndex]);
            if(strcmp(data1, data2) > 0) maxIndex = k;
            free(data1); free(data2);
        }
    }

    return (history_manager_get_date_HT(history_manager, arrayHists[maxIndex]));
}