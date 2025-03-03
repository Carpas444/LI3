#include "Gestores/musicManager.h"
#include "Gestores/userManager.h"
#include "Gestores/artistManager.h"
#include "Gestores/albumManager.h"
#include "Gestores/historyManager.h"
#include "Validações/validacaoLogUsers.h"
#include "Validações/validacaoLogMusics.h"
#include "Validações/validacaoSintUsers.h"
#include "Validações/validacaoSintMusics.h"
#include "Validações/validacaoLogSintArtists.h"
#include "Validações/validacaoSintHistorys.h"
#include "Queries/query1.h"
#include "Queries/query2.h"
#include "Queries/query3.h"
#include "Queries/query4.h"
#include "Queries/query5.h"
#include "Queries/query6.h"
#include "IO/parser.h"
#include "IO/funcoesIO.h"
#include "IO/output.h"
#include "IO/inputComandos.h"
#include "Estruturas/arrayDinamico.h"
#include "Utility/utility.h"


typedef struct MasterManager {
    ARTIST_MANAGER artist_manager;
    MUSIC_MANAGER music_manager;
    USER_MANAGER user_manager;
    GENREMANAGER genre_manager;
    ALBUM_MANAGER album_manager;
    HISTORY_MANAGER history_manager;
}*MASTER_MANAGER;

void feed_managers (MASTER_MANAGER master_manager,void * manager,char * path, char * src , char * errors,int (*validaSint)(char**),int (*validaLog)(char**,MASTER_MANAGER),void (*insere)(void *,char**)) {
    // abrir o ficheiro de dataset e criação do ficheiro para erros
    char file[100];
    strcpy(file,path);  
    strcat(file,src);

    FICHEIRO ficheiro = open_file(file,"r");
    FICHEIRO ficheiro_errors= open_file(errors,"w");
    //chamada do parser para ou preencher a hash table com informação do dataset ou enviar informaçao invalida para o ficheiro de erros
    char *info[8];
    char *line;
    int valido;
    int bool_existe_log =0;
    if (validaLog == NULL) bool_existe_log = 1;
    passar_primeira_linha(ficheiro,ficheiro_errors);
    while ((valido = parser(ficheiro,info,&line,validaSint)) != -1) { 
        if (valido == 1 && (bool_existe_log || validaLog(info,master_manager))) {
            insere(manager,info);
        }
        else {
            escreve_errors(ficheiro_errors,line);
        }
        free(info[0]);
        free(line);
    }
    close_file(ficheiro);    
    close_file(ficheiro_errors);
}

void process_album_manager(MASTER_MANAGER master_manager) {
    unsigned int ln_array_key;
    char ** array_key = album_manager_get_key_as_array(master_manager->album_manager,&ln_array_key);
    for(int i =0;i<ln_array_key;i++) {
        char *artists_id = album_manager_get_artists_id(master_manager->album_manager,array_key[i]);
        char *copia = artists_id;
        char *aux;
        while((aux=strsep(&artists_id,",")) != NULL) {
            artist_manager_add_num_individuals_albuns(master_manager->artist_manager,aux);
        }
        free(copia);
    }
    free(array_key);
}

void find_top10(ARTIST_MANAGER artist_manager,ARRAYD artists_in_use,int n_artists,int week) {
    arrayd_sort_r(artists_in_use,artist_manager_compare,artist_manager);
    int teste = arrayd_get_length(artists_in_use);
    int i;
    char *id;
    for (i=0;i<n_artists && (id = (char *) arrayd_index(artists_in_use,i)) != NULL;i++) {
        if(i<10) {
            artist_manager_add_top10(artist_manager,id,week);
        }
        artist_manager_set_repro_time(artist_manager,id,0);
    }
}

void process_historys (MASTER_MANAGER master_manager) {
    char *day = strdup("2024/09/08");
    ARRAYD artists_in_use=arrayd_create(sizeof(char*),100);
    int n_artits=0;
    int week =0;
    int ln = history_manager_get_ln(master_manager->history_manager);
    history_manager_sort_by_date(master_manager->history_manager);
    for (int i =0;i<ln;i++) {
        char *timestamp = history_manager_get_timestamp(master_manager->history_manager,i);
        int duration = history_manager_get_duration(master_manager->history_manager,i);
        char *music_id = history_manager_get_music_id(master_manager->history_manager,i);
        char *artists_id = music_manager_get_artists_id(master_manager->music_manager,music_id);
        while (strcmp(timestamp,day) < 0) {
            find_top10(master_manager->artist_manager,artists_in_use,n_artits,week);
            week++;
            char *new_day = Sub7Days(day);
            free(day);
            day = new_day;
            arrayd_free(artists_in_use,free,0);
            artists_in_use = arrayd_create(sizeof(char*),100); 
            n_artits =0;
        }
        char *copia = artists_id;
        char *id;
        
        while(( id= strsep((&artists_id),",")) != NULL) {
            artist_manager_add_recipe(master_manager->artist_manager,id,0);
            int teste,teste1;
            teste1=0;
            if (strcmp(id,"A0003542")==0) teste1=1;
            if((teste =(artist_manager_add_repro_time(master_manager->artist_manager,id,duration))) == 0) {
                arrayd_add(strdup(id),artists_in_use);
                n_artits++;
            }

        }
        char*history_id = history_manager_get_history_id(master_manager->history_manager,i);
        char*user_id = history_manager_get_user_id(master_manager->history_manager,i);
        char*genre = music_manager_get_genre(master_manager->music_manager,music_id);
        int index = genre_manager_get_index_genre_static(master_manager->genre_manager,genre);
        user_manager_create_views_genre(master_manager->user_manager,genre_manager_get_ln(master_manager->genre_manager),user_id);
        user_manager_add_views_to_genre(master_manager->user_manager,index,user_id);
        user_manager_add_history(master_manager->user_manager,user_id,history_id);
        free(history_id);
        free(copia);
        free(music_id);
        free(timestamp);
        free(genre);
        free(user_id);
    }
    find_top10(master_manager->artist_manager,artists_in_use,n_artits,week);
    free(day);
    arrayd_free(artists_in_use,free,0);
}


MASTER_MANAGER master_manager_create (){
    MASTER_MANAGER master_manager = malloc(sizeof(struct MasterManager));
    master_manager->artist_manager = artist_manager_create();
    master_manager->music_manager = music_manager_create();
    master_manager->genre_manager = genre_manager_create();
    master_manager->user_manager = user_manager_create();
    master_manager->album_manager = album_manager_create();
    master_manager->history_manager = history_manager_create();
    return master_manager;
}

void master_manager_load_and_process (char *dataset,MASTER_MANAGER master_manager) {
    feed_managers(master_manager,master_manager->artist_manager,dataset,"/artists.csv","resultados/artists_errors.csv",validaLogSintArtists,NULL,artist_manager_add);
    feed_managers(master_manager,master_manager->album_manager,dataset,"/albums.csv","resultados/albuns_errors.csv",NULL,NULL,album_manager_add);
    feed_managers(master_manager,master_manager->music_manager,dataset,"/musics.csv","resultados/musics_errors.csv",validaSint_music,validaLog_music,music_manager_add);
    feed_managers(master_manager,master_manager->user_manager,dataset,"/users.csv","resultados/users_errors.csv",validaSint_user,validaLog_user,user_manager_add);
    feed_managers(master_manager,master_manager->history_manager,dataset,"/history.csv","resultados/history_errors.csv",validaSint_historys,NULL,history_manager_add);
    process_album_manager(master_manager);
    process_historys(master_manager);
    artist_manager_sort_array_id_by_disco(master_manager->artist_manager);
}

void master_manager_free(MASTER_MANAGER master_manager) {
    user_manager_free(master_manager->user_manager);
    music_manager_free(master_manager->music_manager);
    artist_manager_free(master_manager->artist_manager);
    genre_manager_free(master_manager->genre_manager);
    album_manager_free(master_manager->album_manager);
    history_manager_free(master_manager->history_manager);
    free(master_manager);
}

USER_MANAGER get_user_manager(MASTER_MANAGER master_manager) {
    return master_manager ->user_manager;
}

MUSIC_MANAGER get_music_manager(MASTER_MANAGER master_manager) {
    return master_manager ->music_manager;
}

ARTIST_MANAGER get_artist_manager(MASTER_MANAGER master_manager) {
    return master_manager ->artist_manager;
}

ALBUM_MANAGER get_album_manager(MASTER_MANAGER master_manager) {
    return master_manager ->album_manager;
}

HISTORY_MANAGER get_history_manager(MASTER_MANAGER master_manager) {
    return master_manager ->history_manager;
}

GENREMANAGER get_genre_manager(MASTER_MANAGER master_manager) {
    return master_manager ->genre_manager;
}

int queries (MASTER_MANAGER master_manager,char **info,FILE*output) {

  //char **users_array_keys;
  //int length_users_array_keys=user_manager_key_array(user_manager,&users_array_keys);

    int tem_S=0;
    if(strlen(info[0]) == 2) tem_S=1;
    void *query;
    switch (info[0][0])
    {
    case '1':
        if(info[1] == NULL) return 1;
        query = query1_create(info);
        query1(master_manager->user_manager,master_manager->artist_manager,(QUERY1)query,tem_S,output);
        break;
    case '2':
        if(info[1] == NULL) return 1;
        query = query2_create(info);
        query2(master_manager->artist_manager,(QUERY2)query,tem_S,output);
        break;
    case '3':
        if (info[1] == NULL || info[2] == NULL) return 1;
        query = query3_create(info);
        query3(master_manager->genre_manager,(QUERY3)query,tem_S,output);
        break;
    case '4':
        if (info[1] != NULL && info[2] == NULL) return 1;
        query = query4_create(info);
        query4(master_manager->artist_manager,(QUERY4)query,tem_S,output);
        break;
    case '5':
        if (info[1] == NULL || info[2] == NULL) return 1;
        query = query5_create(info);
        query5(master_manager->user_manager,master_manager->music_manager,master_manager->genre_manager,(QUERY5)query,tem_S,output);
        break;
    case '6':
        if (info[1] == NULL || info[2] == NULL) return 1;
        query = query6_create(info);
        query6(master_manager->history_manager,master_manager->music_manager,master_manager->artist_manager,master_manager->user_manager,(QUERY6)query,tem_S,output);
        break;
    default:
        break;
    }
    return 0;
}

void app_principal(char **args){

    MASTER_MANAGER master_manager= master_manager_create();
    master_manager_load_and_process(args[1],master_manager);
    FILE *comandos = fopen(args[2],"r");
    char **info; char *line;
    for(int i=1;(info =parser_comandos(comandos,&line)) != NULL;i++) {
        FILE *output = create_result_file(i);
        queries(master_manager,info,output);
        free(info);
        free(line);
    }
    master_manager_free(master_manager);
    fclose(comandos);
}

double *app_testes(char **args,int *total_queries,int**n_queries){
    int n_diff_queries = 6;
    int *n_querys=calloc(n_diff_queries,sizeof(int));
    double *elapsed_times = calloc(n_diff_queries,sizeof(double));
    struct timespec start, end;
    int i;


    MASTER_MANAGER master_manager= master_manager_create();
    master_manager_load_and_process(args[1],master_manager);
    FILE *comandos = fopen(args[2],"r");
    char **info; char *line;
    for(i=1;(info =parser_comandos(comandos,&line)) != NULL;i++) {
        FILE *output = create_result_file(i);
        clock_gettime(CLOCK_REALTIME, &start);
        queries(master_manager,info,output);
        clock_gettime(CLOCK_REALTIME, &end);
        elapsed_times[info[0][0]-'0'-1] += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        n_querys[info[0][0]-'0'-1]++;
        free(line);
        free(info);
    }
    (*n_queries) = n_querys;
    *total_queries = i-1;   



    master_manager_free(master_manager);
    fclose(comandos);
    return elapsed_times;
}

int app_interativo(){
    int restart=1;
    MASTER_MANAGER master_manager= master_manager_create();
    char* input;
    size_t ln=0;
    printf("Introduza o caminho dos ficheiros de dados:\n");
    getline(&input,&ln,stdin);
    input[strlen(input)-1] = '\0';
    master_manager_load_and_process(input,master_manager);
    printf("Dataset carregado... \n");
    free(input);
    while(restart) {
        input =NULL; ln=0;
        printf("Que query deseja executar e quais os seus argumentos:\n");
        getline(&input,&ln,stdin);
        char**info=process_line(input);
        if(info[0][0] <'1' || info[0][0] > '6' || strlen(info[0]) > 2 || (strlen(info[0]) == 2 && info[0][1] != 'S') ) {printf("Query Nao Valida\n");}
        else {
            printf("Output:\n");
            if(queries(master_manager,info,stdout)) printf("Argumentos Invalidos\n");
        }
        free(input); ln =0; free(info);
        printf("Deseja Continuar?:(S ou N)\n");
        getline(&input,&ln,stdin);
        if(strlen(input) != 2 || (input[0] != 'N' && input[0] != 'S')){
            printf("Resposta Invalida! Parando o programa\n");
            restart=0;
        }
        else if(input[0] == 'N') restart=0;
    }
    master_manager_free(master_manager);
    return 0;
}