#include "../../include/IO/funcoesIO.h"
#include <stdio.h>

#ifndef PARSER_H
#define PARSER_H

/// @brief  Parser para uma linha de informação
/// @param  file O ficheiro onde se pretende usar o parser
/// @param  info A linha de informação que se pretende "parsear"
/// @param  l A linha que acabou de ser "parseada" - mantém-se um pointer para a informação desta linha para que, caso não seja válida, possa ser escrita no ficheiro de erros
/// @param  validaSint A função de validação sintática que será usada para validar a informação
/// @return Um int que serve apenas como valor booleano
int parser (FICHEIRO file, char ** info, char** l, int (*validaSint)(char**));

#endif

