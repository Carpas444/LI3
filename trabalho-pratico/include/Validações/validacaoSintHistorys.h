#ifndef VALIDACAOSINTHISTORYS_H
#define VALIDACAOSINTHISTORYS_H

/// @brief  Verifica se um histórico é sintaticamente válido
/// @param  history O histórico que se pretende verificar se é válido
/// @return Um int que serve apenas como valor booleano
int validaSint_historys(char** history);

/// @brief  Verifica se um timestamp é válido
/// @param  timestamp O timestamp que se pretende verificar se é válido
/// @return Um int que serve apenas como valor booleano
int valida_timestamp(char* timestamp);

/// @brief  Verifica se uma plataforma é válida
/// @param  platform A plataforma que se pretende verificar se é válida
/// @return Um int que serve apenas como valor booleano
int valida_plataforma(char* platform);

#endif