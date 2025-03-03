#ifndef ARTIST_H
#define ARTIST_H

typedef struct artist *ARTIST;

/// @brief  Cria uma estrutura do tipo ARTIST
/// @param  info Um array de strings com toda a informação necessaŕia para criar um artista
/// @return Um artista
ARTIST artist_create(char** info);

/// @brief "Dá" 'free' a uma estrutura do tipo ARTIST
/// @param artist O artista a que se pretende "dar" 'free'
void artist_free (ARTIST artist);

/// @brief  Getter do país de um artista
/// @param  artist O artista de que se pretende o país
/// @return O país do artista
char* artist_get_countryARTIST(ARTIST artist);

/// @brief  Getter do nome de um artista
/// @param  artist O artista de que se pretende o nome
/// @return O nome do artista
char* artist_get_name(ARTIST artist);

/// @brief  Getter do id de um artista
/// @param  artist O artista de que se pretende io id
/// @return O id do artista
char* artist_get_id_artist(ARTIST artist);

/// @brief Adiciona o valor da duração de uma música a um artista
/// @param artist O artista ao qual se pretende incrementar o valor da discografia
/// @param duration O valor da duração de uma música
void artist_add_discography(ARTIST, int duration);

/// @brief  Getter do valor da discografia de um artista
/// @param  artist O artista de que se pretende o valor da discografia
/// @return O valor da discografia do artista
int artist_get_discography(ARTIST artist);

/// @brief  Getter dos id's dos constituintes de um artista (do tipo grupo)
/// @param  artist O grupo de que se pretende os id's dos constituintes
/// @return Uma string com os id's dos constintuintes (separados por ',')
char* artist_get_id_constituent(ARTIST artist);

/// @brief  Getter do número de constintuintes de um artista (do tipo grupo)
/// @param  artist O grupo de que se pretende o número de constintuintes
/// @return O número de constintuintes do grupo
int artist_get_n_id_constituent (ARTIST artist);

/// @brief  Getter do tipo (individual ou group) de um artista
/// @param  artist O artista de que se pretende o tipo
/// @return O tipo do artista
char* artist_get_type(ARTIST artist);

/// @brief Incrementa o número de álbuns individuais de um artista
/// @param artist O artista cujo número de álbuns individuais é incrementado
void artist_add_num_individual_albuns(ARTIST artist);

/// @brief Adiciona um determinado valor de receita a um (ou mais) artistas
/// @param artist O artista a que deve ser incrementado o valor de receita
/// @param participacao O valor que deve ser adicionado à receita do artista, caso ele faça parte de uma banda 
void artist_add_recipe(ARTIST artist,double participacao);

/// @brief  Getter do número de álbuns individuais de um artista
/// @param  artist O artista de que se pretende o número de álbuns individuais
/// @return O número de álbuns individuais do artista
int artist_get_num_albuns_individual(ARTIST artist);

/// @brief  Getter da receita total de um artista
/// @param  artist O artista de que se pretende a receita total
/// @return O valor da receita total do artista
double artist_get_total_recipe(ARTIST artist);

/// @brief Adiciona um valor de duração de uma música ao tempo de reprodução de um artista
/// @param artist O artista a que deve ser incrementado o tempo de reprodução
/// @param duration A duração de uma música que é o valor a adicionar ao repro_time de um artista
/// @return O tempo de reprodução do artista
int artist_add_repro_time(ARTIST artist,int duration);

/// @brief Compara o valor de tempo de reprodução de dois artistas
/// @param artist1 Um dos artistas a ser usado na comparação
/// @param artist2 Um dos artistas a ser usado na comparação
/// @return Valor apenas para identificar qual dos dois artistas tem um menor valor de tempo de reprodução 
int artist_compare_repro_time(ARTIST artist1,ARTIST artist2);

/// @brief  Compara o tempo que dois artistas foram ouvidos
/// @param  artist1 Um dos artistas a ser usado na comparação
/// @param  artist2 Um dos artistas a ser usado na comparação
/// @return Um int que serve apenas como valor booleano
int artist_compare_listening_time(ARTIST artist1,ARTIST artist2);

/// @brief Adiciona uma semana (não UMA semana, mas sim o número da semana) à lista ligada de semanas de um artista
/// @param artist O artista a que se pretende adicionar a semana
/// @param week O número da semana (a semana) que se pretende adicionar ao artista
void artist_add_top10(ARTIST artist, int week);

/// @brief Setter do valor de tempo de reprodução de um artista
/// @param artist O artista a que se pretende alterar o valor de tempo de reprodução
/// @param setter O valor para o qual o tempo de reprodução do artista deve ser alterado
void artist_set_repro_time(ARTIST artist,int setter);

/// @brief Calcula quantas vezes um artista esteve no top10 de artistas entre duas determinadas semanas
/// @param artist O artista de que se pretende calcular o valor
/// @param week_first A primeira semana a contar para o cálculo de top10
/// @param week_last A última semana a contar para o cálculo de top10 
/// @return O número de vezes que o artista esteve no top10 entre aquelas duas semanas
int artist_see_top10(ARTIST artist,int week_first,int week_last);

/// @brief  Getter do id de um artisa
/// @param  artist O artista de que se pretende o id 
/// @return O id do artista
char * artist_get_id(ARTIST artist);

/// @brief  Getter da rate_recipe de um artista
/// @param  artist O artista de que se pretende a rate_recipe
/// @return A rate_recipe de um artista
double artist_get_rate_recipe(ARTIST artist);

/// @brief Adiciona um certo valor ao tempo de audilção de um artista
/// @param artist O artista a que se pretende incrementar o valor de audição
/// @param time A duração a adicionar ao tempo de audição de um artista
/// @return Um int que serve apenas como valor booleano
int artist_add_listening_time(ARTIST artist, int time);

/// @brief  Getter do tempo que um artista foi ouvido
/// @param  artist O artista de que se pretende o tempo que foi ouvido
/// @return O tempo que um artista foi ouvido
int artist_get_listening_time(ARTIST artist);

/// @brief Altera o valor do tempo que um artista foi ouvido
/// @param artist O artista do qual se pretende alterar o valor de tempo que foi ouvido
/// @param set O valor para o qual se pretende alterar o valor de tempo que o artista foi ouvido
void artist_set_listening_time(ARTIST artist,int set); 
#endif 