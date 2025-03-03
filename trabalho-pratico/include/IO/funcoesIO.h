#include <stdio.h>

#ifndef FUNCOESIO_H
#define FUNCOESIO_H

typedef struct File *FICHEIRO;

/// @brief  Abre um ficheiro
/// @param  path O caminho para o ficheiro
/// @param  type Uma string apenas para especificar o modo de abrir o ficheiro (fopen_r, fopen_w, etc.)
/// @return O ficheiro que se abriu através da função
FICHEIRO open_file (char* path, char* type);

/// @brief Fecha um ficheiro
/// @param file O ficheiro que se pretende fechar
void close_file (FICHEIRO file);

/// @brief Busca e devolve um ficheiro
/// @param f A estrutura onde se vai buscar o ficheiro
/// @return Um ficheiro
FILE *get_file(FICHEIRO f);

/// @brief Passa à frente a primeira linha de um ficheiro de uma coleção, escrevendo-o diretamente num ficheiro de erros
/// @param file O ficheiro do qual pretendemos passar, para o ficheiro de erros, a primeira linha
/// @param errors O ficheiro de erros onde é escrita a primeira linha passada à frente
void passar_primeira_linha(FICHEIRO file, FICHEIRO errors); 

/// @brief Escreve, num ficheiro de erros, as linhas inválidas
/// @param errors O ficheiro de erros onde se escrevem as linhas inválidas
/// @param line A linha (que contém informação inválida) que se escreve no ficheiro de erros
void escreve_errors (FICHEIRO errors, char* line);

#endif