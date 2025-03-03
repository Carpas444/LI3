#include "Gestores/musicManager.h"
#include "Gestores/genreManager.h"
#include "Gestores/artistManager.h"
#include "Gestores/userManager.h"
#include "Gestores/albumManager.h"
#include "Gestores/historyManager.h"
#include <stdio.h>

#ifndef APPMANAGER_H
#define APPMANAGER_H

typedef struct MasterManager *MASTER_MANAGER;

/// @brief Preenche as coleções de dados dos diferentes gestores
/// @param master_manager O gestor de gestores. É necessário para se aceder a outros gestores
/// @param manager O gestor cuja coleção de dados se pretende preencher
/// @param path O caminho para os ficheiros das diferentes coleções de dados
/// @param file O ficheiro das coleções de dados
/// @param errors O ficheiro de erros onde devem ser escritos os dados de cada coleção que não são válidos
/// @param validaSint Função de validação sintática (para cada determinada coleção de dados)
/// @param validaLog Função de validação lógica (para cada determinada coleção de dados)
/// @param insere Função que adiciona, caso seja válido, uma entidade à sua estrutura de dados correspondente
void feed_managers (MASTER_MANAGER master_manager,void * manager,char * path, char * file , char * errors,int (*validaSint)(char**),int (*validaLog)(char**,MASTER_MANAGER),void (*insere)(void *,char**));

/// @brief Cria uma estrutura do tipo MASTER_MANAGER
/// @return Uma estrutura do tipo MASTER_MANAGER criada pela função
MASTER_MANAGER master_manager_create ();

/// @brief  Getter do gestor de users
/// @param  master_manager O gestor de gestores. É usado para se poder aceder a outros gestores
/// @return O gestor de users
USER_MANAGER get_user_manager(MASTER_MANAGER master_manager);

/// @brief  Getter do gestor de músicas
/// @param  master_manager O gestor de gestores. É usado para se poder aceder a outros gestores
/// @return O gestor de músicas
MUSIC_MANAGER get_music_manager(MASTER_MANAGER master_manager);

/// @brief  Getter do gestor de artistas
/// @param  master_manager O gestor de gestores. É usado para se poder aceder a outros gestores
/// @return O gestor de artistas
ARTIST_MANAGER get_artist_manager(MASTER_MANAGER master_manager);

/// @brief  Getter do gestor de álbuns
/// @param  master_manager O gestor de gestores. É usado para se poder aceder a outros gestores
/// @return O gestor de álbuns
ALBUM_MANAGER get_album_manager(MASTER_MANAGER master_manager);

/// @brief  Getter do gestor de históricos
/// @param  master_manager O gestor de gestores. É usado para se poder aceder a outros gestores
/// @return O gestor de históricos
HISTORY_MANAGER get_history_manager(MASTER_MANAGER master_manager);

/// @brief  Getter do gestor de géneros
/// @param  master_manager O gestor de gestores. É usado para se poder aceder a outros gestores
/// @return O gestor de géneros
GENREMANAGER get_genre_manager(MASTER_MANAGER master_manager);

/// @brief Carrega os ficheiros das diferentes coleções de dados e depois, recorrendo a outras funções, processa os dados de cada coleção
/// @param dataset Caminho para os ficheiros das diferentes coleções de dados
/// @param master_manager O gestor de gestores. É necessário para se aceder a outros gestores
void master_manager_load_and_process(char* dataset,MASTER_MANAGER master_manager);

/// @brief "Dá" 'free' a uma estrutura do tipo MATSTER_MANAGER
/// @param master_manager A estrutura a que se pretende "dar" 'free'
void master_manager_free(MASTER_MANAGER master_manager);

/// @brief  Função de queries - a partir desta função calculam-se os resultados das outras queries
/// @param  master_manager O gestor de gestores. É usado para se poder aceder a outros gestores
/// @param  info Informaçao retirada de um comando
/// @param  output ficheiro aonde sera escrito o output da query;
/// @return Um int que serve apenas para verificar se a função executou na totalidade
int queries (MASTER_MANAGER master_manager,char **info,FILE *output);

/// @brief Corre o programa-principal
/// @param args Os caminhos para os ficheiros das coleções de dados e para o ficheiro de input de comandos
void app_principal(char **args);

/// @brief Corre o programa-testes
/// @param args Os caminhos para os ficheiros das coleções de dados, para o ficheiro de input de comandos e para o ficheiro de ouputs esperados
/// @param total_queries O número total de queries executadas (valor por referência - int)
/// @param n_queries Um array que nos informa quantas queries foram corridas de cada tipo (valor por referência - int*)
/// @return Um array com os tempos que cada query demorou a ser executada
double *app_testes(char **args,int *total_queries,int**n_queries);

/// @brief Corre o programa-interativo
/// @return Valor apenas para poder acabar a execução do programa
int app_interativo();

#endif