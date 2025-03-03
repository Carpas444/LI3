#include <stdio.h>
#include <glib.h>
#include <string.h>
#include <Utility/utility.h>

typedef struct History {
    char *id;
    char *user_id;
    char *music_id;
    char *timestamp;
    int  duration; //em segundos
}*HISTORY;

HISTORY history_create(char **info) {
    HISTORY history = malloc(sizeof(struct History));
    history->id = strdup(info[0]);
    history->user_id= strdup(info[1]);
    history->music_id = strdup(info[2]);
    history->timestamp = strdup(info[3]);
    history->duration= GiveSeconds(info[4]);
    return history;
}

void history_free(HISTORY history) {
    free(history->id);
    free(history->user_id);
    free(history->music_id);
    free(history->timestamp);
    free(history);
}

char * history_get_id_history(HISTORY history) {
    char* id = strdup(history->id);
    return id;
}

char* history_get_music_id(HISTORY history) {
    return strdup(history->music_id);
}

char* history_get_timestamp(HISTORY history) {
    return strdup(history->timestamp);
}

char* history_get_user_id(HISTORY history) {
    return strdup(history->user_id);
}

char* history_get_history_id(HISTORY history) {
    return strdup(history->id);
}

int history_get_duration(HISTORY history) {
    return history->duration;
}

int history_compare(const void * history1_,const void *history2_) {
    HISTORY history1 = *(HISTORY*) history1_;
    HISTORY history2 = *(HISTORY*) history2_;
    if (strcmp(history1->timestamp,history2->timestamp) > 0) return -1;
    else return 1;
}

char* history_get_date(HISTORY history){
    char date[10];
    for(int i = 0; i < 10; i++){
        date[i] = (history->timestamp)[i];
    }
    char* aux = strdup(date);
    return aux;
}

int history_get_hour(HISTORY history){
    char hora[2];
    hora[0] = (history->timestamp)[11];
    hora[1] = (history->timestamp)[12];
    return (atoi(hora)); 
}