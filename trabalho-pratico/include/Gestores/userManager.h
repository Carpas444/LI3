#include <glib.h>
#include "../../include/Entidades/user.h"
#ifndef USERMANAGER_H

#define USERMANAGER_H

typedef struct UserManager *USER_MANAGER;

/// @brief  Cria uma estrutura do tipo USER_MANAGER
/// @return Uma estrutura do tipo USER_MANAGER criada pela função
USER_MANAGER user_manager_create();

/// @brief Usando três outras funções, cria e adiciona um user à HashTable de users
/// @param user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param info O array de strings com toda a informação necessária para criar um user
void user_manager_add (USER_MANAGER user_manager, char ** info);

/// @brief "Dá" 'free' a uma estrutura do tipo USER_MANAGER
/// @param user_manager A estrutura a que se pretende "dar" 'free'
void user_manager_free (USER_MANAGER user_manager);

/// @brief  Verifica se um user existe na HashTable de users
/// @param  user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param  id O id do user que se pretende verificar se existe
/// @return Um int que serve apenas como valor booleano

int user_manager_test_exist(USER_MANAGER user_manager,char * id);

/// @brief Função auxiliar à user_create_views_genre
/// @param user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param length O comprimento do array que se pretende cirar, que é o número de géneros
/// @param id O id do user onde se pretende criar o array
void user_manager_create_views_genre(USER_MANAGER user_manager,int length,char *id);

/// @brief Função auxiliar à user_add_views_to_genre
/// @param user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param index O índice a que se pretende aceder no array de géneros
/// @param id O id do user a que se pretende adicionar uma visualização de género
void user_manager_add_views_to_genre(USER_MANAGER user_manager,int index,char *id);

/// @brief Função auxiliar à getter do número de visualizações de géneros para cada género
/// @param user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param id O id do user do qual se pretende obter o array (criado na user_get_views_genre)
/// @return Um array de int's em que cada posição é o número de visualizações em cada género
const int *user_manager_get_views_genre(USER_MANAGER user_manager,char *id);

/// @brief Cria um array com os id's de todos os users de uma HashTable de users
/// @param user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param len O comprimento do array
/// @return O array com os id's de todos os users de uma HashTable de users
char** user_manager_get_key_as_array(USER_MANAGER user_manager, unsigned int * len);

/// @brief  Função auxiliar à getter do email de um user
/// @param  user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param  id O id do user que se pretende determinar o email
/// @return O email do user
char * user_manager_get_email(USER_MANAGER user_manager, char* id);

/// @brief  Função auxiliar à getter do primeiro nome de um user
/// @param  user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param  id O id do user que se pretende determinar o primeiro nome
/// @return O primeiro nome do user
char * user_manager_get_firstname(USER_MANAGER user_manager, char* id);

/// @brief  Função auxiliar à getter do último nome de um user
/// @param  user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param  id O id do user que se pretende determinar o último nome
/// @return O último nome do user
char * user_manager_get_lastname(USER_MANAGER user_manager, char* id);

/// @brief  Função auxiliar à getter do país de um user
/// @param  user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param  id O id do user que se pretende determinar o país
/// @return O país do user
char * user_manager_get_country(USER_MANAGER user_manager, char* id);

/// @brief  Função auxiliar à getter da idade de um user
/// @param  user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param  id O id do user que se pretende determinar a idade
/// @return A idade do user
int user_manager_get_age(USER_MANAGER user_manager, char* id);

/// @brief Função auxiliar à user_add_history
/// @param user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param user_id O id do user a que se pretende adicionar um histórico
/// @param history_id O id de histórico que se pretende adicionar ao user
void user_manager_add_history(USER_MANAGER user_manager,char *user_id,char *history_id);

/// @brief Função auxiliar à user_get_user_history
/// @param user_manager O gestor de users. É necessário para se aceder à HashTable de users
/// @param id O id do user de que se pretende o array id('s) de histórico(s)
/// @param ln O comprimento do array
/// @return Um array com o(s) id('s) do(s) histórico(s) do user
char**user_manager_get_user_history(USER_MANAGER user_manager,char* id,int *ln);
#endif