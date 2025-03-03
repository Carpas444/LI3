#ifndef USER_H
#define USER_H

typedef struct user *USER;

/// @brief  Cria uma estrutura do tipo USER
/// @param  info Um array de strings com toda a informação necessária para criar um user
/// @return Um artista
USER user_create(char** info);

/// @brief "Dá" 'free' a uma estrutura do tipo USER
/// @param user O user a que pretendemos "dar" 'free'
void user_free (USER user);

/// @brief  Getter do username de um user
/// @param  user O user de que se pretende o username
/// @return O username de um user
char *user_get_username(USER user);

/// @brief  Getter do email de um user
/// @param  user O user de que se pretende o email
/// @return O email de um user
char *user_get_email(USER user);

/// @brief  Getter do primeiro nome de um user
/// @param  user O user de que se pretende o primeiro nome
/// @return O primeiro nome de um user
char *user_get_firstname(USER);

/// @brief  Getter do último nome de um user
/// @param  user O user de que se pretende o último nome
/// @return O último nome de um user
char *user_get_lastname(USER user);

/// @brief  Getter da idade de um user
/// @param  user O user de que se pretende a idade
/// @return A idade de um user
int user_get_age(USER user);

/// @brief  Getter do país de um user
/// @param  user O user de que se pretende o país
/// @return O país de um user
char *user_get_country(USER user);

/// @brief  Verifica se um user está dentro de um certo intervalo de idades
/// @param  user O user do qual pretendemos verificar a idade
/// @param  max_age A idade mínima do intervalo pretendido
/// @param  min_age A idade máxima do intervalo pretendido
/// @return Um int que serve apenas como valor booleano
int user_check_age (USER user, int max_age, int min_age);

/// @brief  Getter dos id('s) da(s) música(s) a que um user deu like
/// @param  user O user de que se pretende o(s) id('s) da(s) música(s) a que deu like
/// @return O(s) id('s) da(s) músicas(s) a que o user deu like
char *user_get_liked_id_musics(USER user);

/// @brief Cria, na estrutura do user, um array de visualizações de géneros
/// @param user O user onde se pretende criar o array
/// @param ln O comprimento do array, que é o número de géneros
void user_create_views_genre(USER user, int ln);

/// @brief Adiciona uma visualização a um determinado género no array de visualizações de géneros de um user
/// @param user O user a que se pretende adicionar uma visualização de género
/// @param index O índice a que se pretende aceder no array de géneros
void user_add_views_genre(USER user,int index);

/// @brief Getter do número de visualizações de géneros para cada género
/// @param user O user do qual se pretende obter esta informação
/// @return Um array de int's em que cada posição é o número de visualizações em cada género
const int * user_get_views_genre(USER user);

/// @brief Adiciona um id de histórico ao array dinâmico de históricos de um user
/// @param user O user a que se pretende adicionar o id de hisórico
/// @param history_id O id de histórico que se pretende adicionar
void user_add_history(USER user,char* history_id);

/// @brief Cria um array de id's de históricos de um user
/// @param user O user de que se pretende o array de id('s) de histórico(s)
/// @param ln O comprimento do array de id('s) histórico(s) do user
/// @return O array de id('s) de histórico(s) do user
char **user_get_user_history(USER user,int *ln);
#endif 