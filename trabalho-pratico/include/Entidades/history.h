#ifndef HISTORY_H
#define HISTORY_h

typedef struct History *HISTORY;

/// @brief  Cria uma estrutura do tipo HISTORY
/// @param  info Um array de strings com toda a informação necessária para criar um histórico
/// @return Uma estrutura do tipo histórico criada a partir do único argumento da função
HISTORY history_create(char** info);

/// @brief "Dá" 'free' a uma estrutura do tipo HISTORY
/// @param history O histórico a que se pretende "dar" 'free'
void history_free(HISTORY history);

/// @brief  Getter do id de um histórico
/// @param  history O histórico de que se pretende o id
/// @return O id do histórico
char* history_get_id_history(HISTORY history);

/// @brief  Getter do id da música de um histórico
/// @param  history O histórico de que se pretende o id da música
/// @return O id da música do histórico
char* history_get_music_id(HISTORY history);

/// @brief  Getter do id de um histórico
/// @param  history O histórico de que se pretende o próprio id 
/// @return O id do histórico
char* history_get_history_id(HISTORY history);

/// @brief  Getter do timestamp de um histórico
/// @param  history O histórico de que se pretende o timestamp
/// @return O timestamp do histórico
char* history_get_timestamp(HISTORY history);

/// @brief  Getter do id de user de um histórico
/// @param  history O histórico de que se pretende o id de user
/// @return O id de user do histórico
char* history_get_user_id(HISTORY history);

/// @brief  Compara, recorrendo ao timestamp de cada um, dois históricos
/// @param  history1 Um dois históricos a ser usado na comparação
/// @param  history2 Um dois históricos a ser usado na comparação
/// @return Um int para indicar qual dos históricos ocorre antes do outro
int history_compare(const void * history1,const void *history2);

/// @brief  Getter da duração de um histórico
/// @param  history O histórico de que se pretende a duração 
/// @return A duração do histórico
int history_get_duration(HISTORY history);

/// @brief  Getter da data de um histórico
/// @param  history O histórico de que se pretende a data
/// @return A data do histórico
char* history_get_date(HISTORY history);

/// @brief  Getter da hora de um histórico
/// @param  history O histórico de que se pretende a hora
/// @return A hora do histórico
int history_get_hour(HISTORY history);

#endif