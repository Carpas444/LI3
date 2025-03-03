#ifndef VALIDACAOSINTUSERS_H
#define VALIDACAOSINTUSERS_H

/// @brief  Verifica se um user é sintaticamente válido
/// @param  user O user que se pretende verificar se é válido
/// @return Um int que serve apenas como valor booleano
int validaSint_user(char** user);

/// @brief  Verifica se um email é válido
/// @param  email O email que se pretende validar
/// @return Um int que serve apenas como valor booleano
int valida_email(char* email);

/// @brief  Verifica se um enderenço de email tem um arroba e um ponto
/// @param  email O email que se pretende verificar
/// @return Um int que serve apenas como valor booleano
int validaArrobaEponto(char* email);

/// @brief  Verifica se um username de um email é válido
/// @param  username O username que se pretende verificar se é válido
/// @return Um int que serve apenas como valor booleano
int checkUsername(char* username);

/// @brief  Verifica se a LString de um domínio de email é válida
/// @param  lstr A LString que se pretende verificar se é válida
/// @return Um int que serve apenas como valor booleano
int checkLString(char* lstr);

/// @brief  Verifica se a RString de um domínio de email é válida
/// @param  rstr A RString que se pretende verificar se é válida 
/// @return Um int que serve apenas como valor booleano
int checkRString(char* rstr);

/// @brief  Verifica se o tipo de subscrição de um user é válido
/// @param  subtype O tipo de subscrição que se pretende verificar se é válido 
/// @return Um int que serve apenas como valor booleano
int valida_subType(char* subtype);

#endif