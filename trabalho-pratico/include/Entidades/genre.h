#ifndef GENRE_H
#define GENRE_H

typedef struct Genre *GENRE;

/// @brief  Cria uma estrutura do tipo GENRE
/// @param  genreS O nome do género que se pretende criar
/// @return Um género
GENRE genre_create(char *genreS);

/// @brief "Dá" 'free' a uma estrutura do tipo GENRE
/// @param genre O género a que se pretende "dar" 'free'
void genre_free (GENRE genre);

/// @brief Getter do nome de um género
/// @param genre A estrutura de que se pretende o género
/// @return O género da estrutura do tipo GENRE
char *genre_get_name_genre(GENRE genre);

/// @brief Getter da soma total de likes de um género
/// @param genre A estrutura de que se pretende a soma total de likes
/// @return A soma total de likes de um determinado género
int genre_get_soma_likes(GENRE genre);

/// @brief Adiciona um like a um género, tendo em conta a idade do user que deu like
/// @param genre O género a que se pretende adicionar um like
/// @param age A idade do user, necessária para se saber "onde adicionar o like"
void genre_add_likes(GENRE genre, int age);

/// @brief Incrementa o número de likes de um género numa determinada idade
/// @param genre O género a que se pretende incrementar o valor da soma de likes
/// @param min A idade mínima a considerar para esta função
/// @param max A idade máxima a considerar para esta função
void set_soma_likes(GENRE genre, int min, int max);

/// @brief Altera o valor da soma de likes para zero
/// @param genre O género do qual se pretende zerar o valor da soma total de likes
void set_soma_likes_to_0(GENRE genre) ;

/// @brief Determina, entre dois géneros, qual tem a menor soma total de likes
/// @param genre1 Um dos géneros usado na comparação
/// @param genre2 Um dos géneros usado na comparação
/// @return Um int que serve apenas para identificar qual dos dois géneros, genre1 ou genre2, tem um menor número de likes
int menor_soma_likes (const void * genre1,const void * genre2);

#endif 