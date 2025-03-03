#include "../../include/appManager.h"


#ifndef VALIDACAOLOGMUSICS_H
#define VALIDACAOLOGMUSICS_H

/// @brief  Verifica se uma música é logicamente válida
/// @param  music A música que se pretende verificar se é logicamente válida
/// @param  master_manager O gestor de gestores. É usado para se poder aceder a outros gestores
/// @return Um int que serve aenas como valor booleano
int validaLog_music(char** music, MASTER_MANAGER master_manager);

#endif