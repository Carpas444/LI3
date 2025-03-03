#include <stdio.h>

#ifndef INPUTCOMANDOS_H
#define INPUTCOMANDOS_H

typedef struct Query *QUERY;

/// @brief  Processa uma linha, criando um array 2D resultante com toda a informação da linha separada por campos
/// @param  line A linha a processar 
/// @return O array resultante de separar a linha por campos
char **process_line(char *line);

/// @brief  Parser de um ficheiro de input de comandos
/// @param  file O ficheiro de input de comandos
/// @param  l A linha que acabou de ser "parseada" - fica-se com um pointer desta linha para depois se poder "dar" 'free'
/// @return O array resultante de separar a linha por campos
char **parser_comandos(FILE *file,char **l);

#endif