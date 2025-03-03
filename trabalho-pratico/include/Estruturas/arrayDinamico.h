#include <stdlib.h>

#ifndef ARRAY_DINAMICO_H
#define ARRAY_DINAMICO_H

typedef struct ArrayD *ARRAYD;

/// @brief  Função que cria uma struct ArrayD ou seja que cria um Array Dinamico
/// @param  menber_size numero de bytes de tamanho de um membro do array
/// @param  n_member numero de membros de um array
/// @return Um pointer para a struct ArrayD
ARRAYD arrayd_create (size_t member_size,size_t n_member);


/// @brief  Função que realoca a memoria do array para aumentar a sua capacidade
/// @param array_d array que se pretende aumentar a capacidade
void arrayd_realloc(ARRAYD array_d);

/// @brief  Função que adiciona informaçao ao array
/// @param info informaçao que vai ser adicionada ao array
/// @param array_d array aonde se pretende adicionar a informaçao
void arrayd_add (void *info, ARRAYD array_d);


/// @brief Funçao que liberta a memoria utilizada pelo o array dinamico
/// @param array_d array que se pretende libertar
/// @param free funçao que liberta a memoria utilizada pelo os membros do array
/// @param bool_vazio valor boleano que diz se os membros do array ja foram liberados ou n
void arrayd_free(ARRAYD array_d,void (*free)(void*),int bool_vazio);

/// @brief Funçao que devolve a informaçao guardada no array numa certa posiçao
/// @param array_d array que se pretende ir buscar informaçao
/// @param index posicao da informaçao que queremos
/// @return Informaçao que estava na posicao index do array_d(este valor não é copia.necessario cuidado a utiliza-lo)
void *arrayd_index(ARRAYD array_d,int index);

/// @brief Funcao que devolve o tamanho/numero de membros do array
/// @param arrayd array que se pretende saber qual o seu tamanho
/// @return Tamanho do arrayd
int arrayd_get_length(ARRAYD arrayd);


/// @brief Funcao que ordena o array
/// @param arrayd array que se pretende ordenar
/// @param comp funçao de comparaçao utilizada nos membros do array para poder ordena-lo
void arrayd_sort (ARRAYD arrayd,int (*comp)(const void *,const void *));


/// @brief Funçao que ordena o array mas recebe um argumento extra para melhores comparaçoes
/// @param arrayd array que se pretende ordenar
/// @param comp funçao de comparaçao utilizada nos membros do array para poder ordena-lo com argumento extra para comparaçoes mais complexas
/// @param arg Argumento extra (Pode ser um manager,por exemplo, para se poder organizar ids utilizando valores dentro das suas estruturas)
void arrayd_sort_r(ARRAYD arrayd,int (*comp)(const void *,const void *,void*), void * arg);

#endif