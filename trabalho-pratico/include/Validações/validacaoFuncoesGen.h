#ifndef VALIDACAOFUNCOESGEN_H
#define VALIDACAOFUNCOESGEN_H

/// @brief  Verifica se uma string(lista) tem os parenteses retos bem colocados
/// @param  str A string cujos parenteses se pretendem validar
/// @return Um int que serve apenas como valor booleano
int validaParenteses(char* str);

/// @brief  Verifica se uma data é sintaticamente válida
/// @param  date A data que se pretende verificar se é válida
/// @return Um int que serve apenas como valor booleano
int valida_data(char* date);

/// @brief  Verifica se a data está inválida (verifica algumas das condições de uma data inválida)
/// @param  date A data que se pretende verificar se é válida (pelo menos estas condições)
/// @return Um int que serve apenas como valor booleano
int checkDateInvalidConditions(char* date);

/// @brief  Verifica se o dia e o mês de uma data são válidos 
/// @param  date A data de que se pretende validar o dia e o mês
/// @return Um int que serve apenas como valor booleano
int checkMonthDayValidaty(char** date);

/// @brief  Verifica se uma data é antes da data norma do enunciado (09/09/2024)
/// @param  date A data que se pretende verificar se é antes da data norma ou a data norma
/// @return Um int que serve apenas como valor booleano
int isDateBeforeNorm(char** date);

/// @brief  Verifica se uma determinada durção é válida
/// @param  duration A duração que se pretende verificar se é válida
/// @return Um int que serve apenas como valor booleano
int valida_duracao(char* duration);

/// @brief  Verifica se um determinado número de horas, minutos ou segundos é válido
/// @param  time O número que se pretende verificar se é válido
/// @param  type Apenas um char para indicar o tipo de número a verificar (horas, minutos ou segundos)
/// @return Um int que serve apenas como valor booleano
int checkTimeNums (char* time, char type);

/// @brief  Verifica se um tripo horas, miutos e segundos é válido
/// @param  hora A hora que se pretende verificar se é válida
/// @return Um int que serve apenas como valor booleano
int valida_hora(char* hora);
#endif