#include "../../include/appManager.h"

#ifndef VALIDACAOLOGUSERS_H
#define VALIDACAOLOGUSERS_H

/// @brief  Verifica se um user é logicamente válido
/// @param  user O user que se pretende verificar se é válido 
/// @param  master_manager O gestor de gestores. É usado para se poder aceder a outros gestores
/// @return Um int que serve apenas como valor booleano
int validaLog_user(char** user, MASTER_MANAGER master_manager);

#endif