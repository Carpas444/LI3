#include "../../include/Entidades/artist.h"


#ifndef ARTISTMANAGER_H
#define ARTISTMANAGER_H

typedef struct ArtistManager *ARTIST_MANAGER;

/// @brief  Cria uma estrutura do tipo ARTIST_MANAGER
/// @return Uma estrutura do tipo ARTIST_MANAGER criada pela função
ARTIST_MANAGER artist_manager_create(); 

/// @brief Usando três outras funções, cria e adiciona um artista à HashTable de artistas
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param info O array de strings com a informação necessária para criar um artista 
void artist_manager_add (ARTIST_MANAGER artist_manager, char** info);

/// @brief "Dá" 'free' a uma estrutura do tipo ARTIST_MANAGER
/// @param  artist_manager A estrutura a que se pretende "dar" 'free'
void artist_manager_free (ARTIST_MANAGER artist_manager);

/// @brief Usando duas outras funções, procura um artista e adiciona um certo valor à sua discografia
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param id O id do artista a que se pretende adicionar uma certa duração à sua discografia
/// @param duration O valor da duração de uma música que se pretende adicionar ao artista
void artist_manager_add_discography (ARTIST_MANAGER artist_manager, char* id, int duration);

/// @brief Usando duas outras funções, procura um artista e incrementa o número de álbuns individuais
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param id O id de artista
void artist_manager_add_num_individuals_albuns (ARTIST_MANAGER artist_manager, char* id);

/// @brief  Cria um array de strings com os id's de todos os artistas
/// @param  artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param  ln O comprimento do array
/// @return Um array de strings, em que cada uma é um id de artista
char** getArtistsArray(ARTIST_MANAGER artist_manager, unsigned int* ln);

/// @brief  Calcula, entre dois artistas, qual deles tem o maior valor de discografia
/// @param  id1 O id de um dos artistas usado na comparação
/// @param  id2 O id de um dos artistas usado na comparação
/// @param  artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @return Um int que serve como valor booleano, para identifcar o artista com maior valor de discograifa
int maiorDisco(const void* id1_, const void* id2_, void *artist_manager);

/// @brief Ordena um array de id's de artistas pelo valor da discografia
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
void artist_manager_sort_array_id_by_disco(ARTIST_MANAGER artist_manager);

/// @brief  Verifica se um artista existe na HashTable de artistas
/// @param  artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param  id O id do artista que se pretende verificar se está na HashTable de artistas
/// @return Um int que serve apenas como valor booleano
int artist_manager_test_exist(ARTIST_MANAGER artist_manager,char * id);

/// @brief Função auxiliar à artist_add_recipe
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param artists_id Uma string com o(s) id('s) do(s) artista(s)
/// @param participacao O valor que deve ser adicionado à receita do artista, caso ele faça parte de uma banda
void artist_manager_add_recipe(ARTIST_MANAGER artist_manager,char *artists_id,double participacao);

/// @brief Função auxiliar à artist_add_repro_time
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param id O id do artista
/// @param duration A duração de uma música que é o valor a adicionar ao repro_time do artista
/// @return Um int que serve apenas como valor booleano
int artist_manager_add_repro_time(ARTIST_MANAGER artist_manager,char * id,int duration);

/// @brief  Compara dois artistas pelo valor de reprodução de cada um
/// @param  id1_ O id de um dos artistas a ser usado na comparação
/// @param  id2_ O id de um dos artistas a ser usado na comparação
/// @param  arg Argumento extra que será usado para uma melhor comparação
/// @return Um valor apenas para identificar qual dos dois artistas tem um menor valor de tempo de reprodução
int artist_manager_compare(const void *id1_, const void *id2_,void * arg);

/// @brief Função auxiliar à artist_add_top10
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param id O id do artista a que deve ser adicionado o número da semana
/// @param week O número da semana a adicionar ao artista
void artist_manager_add_top10(ARTIST_MANAGER artist_manager,char *id,int week);

/// @brief Função auxiliar à setter do tempo de reprodução de um artista
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param id O id do artista de que se pretende alterar o valor de tempo de reprodução
/// @param setter O valor para o qual o tempo de reprodução do artista deve ser alterado
void artist_manager_set_repro_time(ARTIST_MANAGER artist_manager,char *id,int setter);

/// @brief Função auxiliar à artist_see_top10
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param max O maior número de vezes que o artista que esteve mais vezes no top10, no momento em que a função é chamada, esteve no top10
/// @param id O id do artista que se pretende calcular quantas vezes esteve no top10 entre duas semanas
/// @param max_id O id do artista que mais vezes esteve no top10 entre aquelas duas semanas (no momento em que a função é chamada)
/// @param week_first A primeira semana a contar para o cálculo de top10
/// @param week_last A última semana a contar para o cálculo de top10
/// @return O número de vezes que o artista esteve no top10 entre aquelas duas semanas
int artist_manager_see_top10(ARTIST_MANAGER artist_manager,int max ,char *id,char*max_id,int week_first,int week_last);

/// @brief  Função auxiliar à getter do país de um artista
/// @param  artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param  id O id do artista de que se pretende o país
/// @return O país do artista
char* artist_manager_get_id(ARTIST_MANAGER artist_manager,char *id);

/// @brief Função auxiliar à getter do país de um artista
/// @param char* É o id do artista de que se pretende o país
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @return O país do artista
char *artist_manager_get_country(char* id, ARTIST_MANAGER artist_manager);

/// @brief Função auxiliar à getter do nome de um artista
/// @param id O id do artista de que se pretende o nome
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @return O nome do artista
char *artist_manager_get_name(char* id, ARTIST_MANAGER artist_manager);

/// @brief Função auxiliar à getter do tipo (individual ou group) de um artista
/// @param id O id do artista de que se pretende o tipo
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @return O tipo do artista
char *artist_manager_get_type(char* id, ARTIST_MANAGER artist_manager);

/// @brief Função auxiliar à getter do valor da discografia de um artista
/// @param id O id do artista de que se pretende o valor da discografia
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @return O valor da discografia do artista
int artist_manager_get_discography(char* id, ARTIST_MANAGER artist_manager);

/// @brief Função auxiliar à getter do número de aĺbuns individuais de um artista
/// @param id O id do artista de que se pretende o número de álbuns individuais
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @return O número de álbuns individuais do artista
int artist_manager_get_num_albuns_individual(char* id, ARTIST_MANAGER artist_manager);

/// @brief Função auxiliar à getter da receita total de um artista
/// @param id O id do artista de que se pretende a receita total
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @return O valor da receita total do artista
double artist_manager_get_total_recipe(char* id, ARTIST_MANAGER artist_manager);

/// @brief  Usando duas outras funções, procura um artista e depois é usada uma função de comparação para se comparar os valores de audição de cada um dos artistas
/// @param  id1_ Um dos id's de artista usado na comparação
/// @param  id2_ Um dos id's de artista usado na comparação
/// @param  arg Argumento extra que será usado para uma melhor comparação
/// @return Um int para se saber qual dos dois artistas tem um maior valor de tempo de audição
int artist_manager_compare_listening_time(const void *id1_, const void *id2_,void * arg);

/// @brief Função auxiliar à artist_add_listening_time
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param id O id do artista ao qual se pretende adicionar um valor ao valor de audição
/// @param time O valor que se pretende adicionar ao valor de audição do artista
/// @return Um int que serve apenas como valor booleano
int artist_manager_add_listening_time(ARTIST_MANAGER artist_manager,char *id, int time);

/// @brief  Função auxiliar à getter do valor de audição do artista
/// @param  artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param  id O id do artista de que se pretende o valor de audição
/// @return O valor de audição do artista
int artist_manager_get_listening_time(ARTIST_MANAGER artist_manager,char* id);

/// @brief Função auxiliar à setter do valor de audição do artista
/// @param artist_manager O gestor de artistas. É necessário para se aceder à HashTable de artistas
/// @param id O id do artista de que se pretende alterar o valor de audição
/// @param set O valor para o qual se pretende alterar o valor de audição do artista
void artist_manager_set_listening_time (ARTIST_MANAGER artist_manager,char *id, int set);

/// @brief Calcula o comprimento do array dinâmico de id's de artistas
/// @param artist_manager O gestor de artistas. É necessário para se aceder ao array dinâmico de id's de artistas
/// @return O comprimento desse mesmo array
int artist_manager_array_get_ln(ARTIST_MANAGER artist_manager);

/// @brief Calcula o id de artista que está num determinado índice do array dinâmico de artistas
/// @param artist_manager O gestor de artistas. É necessário para se aceder ao array dinâmico de id's de artistas 
/// @param index O índice a que se pretende aceder no array dinâmico de artistas
/// @return O id de artista no índice especificado na array dinâmico de artistas
char * artist_manager_array_get_id (ARTIST_MANAGER artist_manager,int index);
#endif
