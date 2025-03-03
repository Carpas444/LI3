#include <stdio.h>
#include <glib.h>
#include <string.h>
#include "../../include/IO/output.h"
#include "../../include/Gestores/historyManager.h"
#include "../../include/Gestores/musicManager.h"
#include "../../include/Gestores/artistManager.h"
#include "../../include/Gestores/userManager.h"
#include "../../include/Utility/utility.h"
#include "../../include/Estruturas/arrayDinamico.h"

typedef struct Query6{
    char* user_id;
    int year;
    int N;
}*QUERY6;

void free_query6(QUERY6 query){
    free(query->user_id);
    free(query);
}

QUERY6 query6_create (char** info){
    QUERY6 query6 = malloc(sizeof(struct Query6));
    query6->user_id = strdup(info[1]);
    query6->year = atoi(info[2]);
    if(info [3] == NULL) query6 -> N = -1;
    else query6->N = atoi(info[3]);
    return query6;
}

ARRAYD get_artists_by_order(char** arrayMusicas, int* arrayMusicasHistDuracao, int len, MUSIC_MANAGER music_manager, ARTIST_MANAGER artist_manager){
    ARRAYD arrayDurArt = arrayd_create(sizeof(char*),len);
        
    for(int i = 0; i < len; i++){
        char* artists_id = music_manager_get_artists_id(music_manager, arrayMusicas[i]);
        char *copia = artists_id;
        char *artist_id;
        while((artist_id=strsep(&artists_id,",")) != NULL) {
            if (artist_manager_add_listening_time(artist_manager,artist_id,arrayMusicasHistDuracao[i]) == 0) arrayd_add(strdup(artist_id),arrayDurArt);
        }
        free(copia);

    }
    arrayd_sort_r(arrayDurArt,artist_manager_compare_listening_time,artist_manager);
    return arrayDurArt;
}

int query6(HISTORY_MANAGER history_manager, MUSIC_MANAGER music_manager, ARTIST_MANAGER artist_manager,USER_MANAGER user_manager, QUERY6 query6, int tem_S,FILE *output){
    
    int ln_user_hist=0;
    int numHist = 0;   
    char **user_hist;
    int bool_criou=0;
    if (user_manager_test_exist(user_manager,query6->user_id)==0) {user_hist = user_manager_get_user_history(user_manager,query6->user_id,&ln_user_hist);bool_criou=1;}
    char** arrayHistsTruncado = calloc(ln_user_hist,sizeof(char*));
    for(int i=0;i < ln_user_hist;i++) {
        if (isYearTrue(history_manager,user_hist[i],query6->year)) {
            arrayHistsTruncado[numHist] = user_hist[i];
            numHist++;
        }
    }
    
    if(numHist == 0) {
        for(int i = 0; i < ln_user_hist;i++) free(user_hist[i]);
        if (bool_criou) free(user_hist);
        free(arrayHistsTruncado); 
        write_in_result_str(output, "", 1, tem_S); 
        if (output != stdout )fclose(output); free_query6(query6); return 0;
    }

    sortArrayHistByMusic(arrayHistsTruncado, numHist, history_manager);

    char* arrayMusicsID[numHist];   
    for(int i = 0; i < numHist; i++){
        arrayMusicsID[i] = malloc(strlen(arrayHistsTruncado[i]) + 1);
        char* music_id = history_manager_get_music_id_HT(history_manager, arrayHistsTruncado[i]);
        strcpy(arrayMusicsID[i], music_id);
        free(music_id);
    }

    int arrayMusicsHistDuration[numHist];
    for(int i = 0; i < numHist; i++) arrayMusicsHistDuration[i] = history_manager_get_duration_HT(history_manager, arrayHistsTruncado[i]);
    
    ARRAYD artists_by_order= get_artists_by_order(arrayMusicsID, arrayMusicsHistDuration, numHist, music_manager,artist_manager);

    int tempoTotalAud          = get_total_listening_time(arrayHistsTruncado, numHist, history_manager); char* totalListeningTime = GiveDisco(tempoTotalAud);
    int numberSongsListened    = get_number_listened_songs(arrayHistsTruncado, numHist, history_manager);
    char* most_listened_day    = get_most_listened_day(arrayHistsTruncado, numHist, history_manager);
    char* most_listened_genre  = get_most_listened_genre(arrayMusicsID, arrayMusicsHistDuration, numHist, music_manager);
    char* favorite_album       = get_favorite_album(arrayMusicsID, arrayMusicsHistDuration, numHist, music_manager);
    int most_listened_hour_int = get_most_listened_hour(arrayHistsTruncado, numHist, history_manager); char most_listened_hour_char[2]; sprintf(most_listened_hour_char, "%02d", most_listened_hour_int);
    
    write_in_result_str(output, totalListeningTime,      0, tem_S);
    write_in_result_int(output, numberSongsListened,     0, tem_S);
    write_in_result_str(output, arrayd_index(artists_by_order,0),0, tem_S);
    write_in_result_str(output, most_listened_day,       0, tem_S);
    write_in_result_str(output, most_listened_genre,     0, tem_S);
    write_in_result_str(output, favorite_album,          0, tem_S);
    write_in_result_str(output, most_listened_hour_char, 1, tem_S);

    if(query6->N != -1 && query6->N != 0){
        if(numHist == 1){
            write_in_result_str(output, arrayd_index(artists_by_order,0),0, tem_S);
            write_in_result_int(output, 1,                    0, tem_S);
            write_in_result_str(output, totalListeningTime,   1, tem_S);
        }
        else{

            for(int i = 0;  i < numHist && i < query6->N; i++){
                write_in_result_str(output, arrayd_index(artists_by_order,i), 0, tem_S);
                write_in_result_int(output, get_total_artist_number(arrayd_index(artists_by_order,i), arrayMusicsID, numHist, music_manager), 0, tem_S);
                char* artist_listening_time = GiveDisco(artist_manager_get_listening_time(artist_manager,arrayd_index(artists_by_order,i)));
                write_in_result_str(output, artist_listening_time, 1, tem_S);
                free(artist_listening_time); //GiveDisco faz um strdup
            }

        }
    }
    for(int i = 0; i < arrayd_get_length(artists_by_order); i++) artist_manager_set_listening_time(artist_manager,arrayd_index(artists_by_order,i),0);
    arrayd_free(artists_by_order,free,0);


    //FREE DE TODOS OS ARRAY AUXILIARES E VARIÁVEIS CRIADAS A PARTIR DE STRDUP
    for(int i = 0; i < ln_user_hist; i++) free(user_hist[i]);
    for(int i = 0; i < numHist; i++) free(arrayMusicsID[i]);
    free(most_listened_genre); free(favorite_album); free(totalListeningTime); free(most_listened_day); free(arrayHistsTruncado);free(user_hist);
    if (output != stdout )fclose(output);
    free_query6(query6);
    
    return 1;
}
