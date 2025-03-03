#include "../../include/Entidades/history.h"
#ifndef HISTORY_MANAGER_H

#define HISTORY_MANAGER_H

typedef struct HistoryManager *HISTORY_MANAGER;

/// @brief  Cria uma estrutura do tipo ARTIST_MANAGER
/// @return Uma estrutura do tipo HISTORY_MANAGER criada pela função
HISTORY_MANAGER history_manager_create();

/// @brief Usando três outras funções, cria e adiciona um histórico à HashTable de históricos
/// @param HISTORY_MANAGER O gestor de históricos. É necessário para se aceder à HashTable de históricos
/// @param char** O array de strings com a informação necessária para criar um histórico
void history_manager_add(HISTORY_MANAGER, char**);

/// @brief "Dá" 'free' a uma estrutura do tipo HISTORY_MANAGER
/// @param history_manager A estrutura a que se pretende "dar" 'free'
void history_manager_free (HISTORY_MANAGER history_manager);

/// @brief  Função auxiliar à getter do id de música de um histórico
/// @param  history_manager O gestor de históricos. É usado para se aceder ao array dinâmico de históricos
/// @param  index O índice a que se pretende aceder no array
/// @return 
char *history_manager_get_music_id(HISTORY_MANAGER history_manager,int index);

/// @brief  Função auxiliar à getter do timestamp de um histórico
/// @param  history_manager O gestor de históricos. É usado para se aceder ao array dinâmico de históricos
/// @param  index O índice a que se pretende aceder no array
/// @return O timestamp do histórico
char *history_manager_get_timestamp(HISTORY_MANAGER history_manager, int index);

/// @brief  Função auxiliar à getter do id de user de um histórico
/// @param  history_manager O gestor de históricos. É usado para se aceder ao array dinâmico de históricos
/// @param  index O índice a que se pretende aceder no array
/// @return O id de user do histórico
char *history_manager_get_user_id(HISTORY_MANAGER history_manager, int index);

/// @brief  Função auxiliar à getter da duração de um histórico
/// @param  history_manager O gestor de históricos. É usado para se aceder ao array dinâmico de históricos
/// @param  index O índice a que se pretende aceder no array
/// @return A duração do histórico
int history_manager_get_duration(HISTORY_MANAGER history_manager, int index);

/// @brief  Função auxiliar à getter do comprimento de um array dinâmico
/// @param  history_manager O gestor de históricos. É usado para se aceder ao array dinâmico de históricos
/// @return O comprimento do array dinâmico
int history_manager_get_ln(HISTORY_MANAGER history_manager);

/// @brief Ordena um array de id's de músicas, pelo seu id
/// @param array O array que se pretende ordenar
/// @param len O comprimento do array
/// @param history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
void sortArrayHistByMusic(char** array, int len, HISTORY_MANAGER history_manager);

/// @brief  Determina qual id é menor
/// @param  id1 Um dos id's usado na comparação 
/// @param  id2 Um dos id's usado na comparação
/// @return Um valor inteiro apenas indicativo de qual dos dois id's é menor
int menorID(char* id1, char* id2);

/// @brief  Procura um histórico na HashTable de históricos
/// @param  history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
/// @param  id O id do histórico que se pretende procurar
/// @return O histórico (caso exista, senão devolve NULL)
HISTORY history_manager_lookup_HT (HISTORY_MANAGER history_manager,char *id);

/// @brief  Função auxiliar à getter do timestamp de um histórico
/// @param  history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
/// @param  hist_id O id do histórico de que se pretende o timestamp
/// @return O timestamp do histórico
char* history_manager_get_timestamp_HT(HISTORY_MANAGER history_manager, char* hist_id);

/// @brief  Verifica se dois anos (o ano de input da query6 e o ano de um histórico) são iguais
/// @param  history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
/// @param  history_id O id do histórico cujo ano se pretende usar na comparação
/// @param  yearInput O ano de input da query
/// @return Um int que serve apenas como valor booleano
int isYearTrue(HISTORY_MANAGER history_manager,char* history_id, int yearInput);

/// @brief  Calcula o número de músicas diferentes num array de músicas
/// @param  array Um array de músicas, ordenado pelo id das mesmas
/// @param  len O comprimento do array
/// @param  history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
/// @return O número de músicas diferentes
int get_number_listened_songs(char** array, int len, HISTORY_MANAGER history_manager);

/// @brief  Função auxiliar à getter da duração de um histórico
/// @param  history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
/// @param  hist_id O id do histórico de que se pretende a duração
/// @return A duração do histórico
int history_manager_get_duration_HT(HISTORY_MANAGER history_manager, char* hist_id);

/// @brief  Calcula o tempo total de audição de um array de históricos
/// @param  array O array de históricos do qual se pretende calcular o tempo total de audição
/// @param  lenArray O comprimento do array
/// @param  history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
/// @return O tempo total de audição
int get_total_listening_time(char** array, int lenArray, HISTORY_MANAGER history_manager);

/// @brief  Função auxiliar à getter da hora de audição de um histórico
/// @param  history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
/// @param  id O id do histórico de que se pretende a hora de audição
/// @return A hora de audição do histórico
int history_manager_get_hour_HT(HISTORY_MANAGER history_manager, char* id);

/// @brief  Calcula a hora mais ouvida num array de históricos
/// @param  arrayHists O array de históricos
/// @param  len O comprimento do array
/// @param  history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
/// @return A hora mais ouvida
int get_most_listened_hour(char** arrayHists, int len, HISTORY_MANAGER history_manager);

/// @brief  Função auxiliar à getter da data de um histórico
/// @param  history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
/// @param  hist_id O id do histórico de que se pretende a data
/// @return A data do histórico
char* history_manager_get_date_HT(HISTORY_MANAGER history_manager, char* hist_id);

/// @brief  Função auxiliar à getter do id de música de um histórico
/// @param  history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
/// @param  id O id do histórico de que se pretende o id de música
/// @return O id de música do histórico
char *history_manager_get_music_id_HT(HISTORY_MANAGER history_manager,char *id);

/// @brief  Calcula o dia em que foi ouvida mais música, num array de históricos
/// @param  arrayHists O array de históricos
/// @param  len O comprimento do array
/// @param  history_manager O gestor de históricos. É usado para se aceder à HashTable de históricos
/// @return O dia em que foi ouvida mais música
char* get_most_listened_day(char** arrayHists, int len, HISTORY_MANAGER history_manager);

/// @brief Ordena um array dinãmico de históricos, pela data dos mesmos
/// @param history_manager O gestor de históricos. É usado para se aceder ao array dinâmico de históricos
void history_manager_sort_by_date(HISTORY_MANAGER history_manager);

/// @brief  Função auxiliar à getter do id de histórico
/// @param  history_manager O gestor de históricos. É usado para se aceder ao array dinâmico de históricos
/// @param  index O índice a que se pretende aceder no array 
/// @return O id do histórico
char* history_manager_get_history_id(HISTORY_MANAGER history_manager, int index);

#endif