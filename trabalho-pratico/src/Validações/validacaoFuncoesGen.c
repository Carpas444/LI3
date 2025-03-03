#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/Validações/validacaoFuncoesGen.h"
#include "../../include/Utility/utility.h"


int validaParenteses(char* str){
    int len = strlen(str);
    if(str[0] != '[' || str[len-1] != ']') return 0;
    return 1;
}

int valida_data(char* date){               //verifica se a data de nascimento do utilizador é sintaticamente válida, de acordo com os requisitos do enunciado
    int valid = 1;
    int lenDate = strlen(date);
    
    if (checkDateInvalidConditions(date) == 0) {valid = 0; return valid;}

    char* birthDateSep[3];
    char   birthDateAux[lenDate];
    strcpy(birthDateAux, date);
    sepString(birthDateAux, birthDateSep, "/", 3);
    
    if ((checkMonthDayValidaty(birthDateSep) == 0) || (isDateBeforeNorm(birthDateSep) == 0)) {valid = 0; return valid;}

    return valid;
}

int checkDateInvalidConditions(char* date){      //verifica se a data de nascimento do utilizador tem alguma condição inválida, de acordo com os requisitos do enunciado (outras condições são testadas noutras funções!)
    int valid = 1;                               //começa a True, se depois alguma condição der mal, é alterado para 0 e dá return valid
    int len = strlen(date);

    if ((len != 10) || ((date[4] != '/') || (date[7] != '/')) ) {valid = 0; return valid;}  //se a data não tiver 10 caracteres ou não tiver as barras bem colocadas, dá automaticamente mal
    
    for(int j = 0; j < 10; j++){                //'for' que testa se todos os números estão entre 0 e 9 - if not, return 0
        if (j == 4 || j == 7) continue;         //passa as barras à frente (já se sabe que elas estão lá, por causa da verificação na linha de código anterior)
        else if (date[j] < '0' || date[j] > '9') {valid = 0; return valid;}
    }

    return valid;
}

int checkMonthDayValidaty(char** ydm){           //verifica se os dias e os meses na data de nascimento do utilizador são válidos, de acordo com os requisitos do enunciado
    int valid = 1;
    int mes = atoi(ydm[1]);
    int dia = atoi(ydm[2]);

    if(dia < 1 || dia > 31) {valid = 0; return valid;}

    if(mes < 1 || mes > 12) {valid = 0; return valid;}

    return valid;
}

int isDateBeforeNorm(char** ydm){                //verifica se a data de nascimento do utilizador é válida, de acordo com os requisitos do enunciado
    int valid = 1;                               //return 0 se a data for depois de 2024/09/09
    int ano = atoi(ydm[0]);                      //ydm = yearDayMonth -- enganei-me e pus ydm em vez de ymd - não me apteceu mudar o nome da variável tho
    int mes = atoi(ydm[1]);
    int dia = atoi(ydm[2]);
    
    if((ano > 2024) || (ano == 2024 && mes > 9) || (ano == 2024 && mes == 9 && dia > 9)) {valid = 0; return valid;}
    
    return valid;
}

int valida_duracao(char* duracao){                //verifica se a duração de uma música é sintaticamente válida, de acordo com os requisitos do enunciado
    int valid = 1;
    int len = strlen(duracao);

    if ((len != 8) || ((duracao[2] != ':') || (duracao[5] != ':'))) {valid = 0; return 0;}

    for(int i = 0; i < 8; i++){                //'for' que testa se todos os números estão entre 0 e 9 - if not, return 0
        if (i == 2 || i == 5) continue;         //passa os dois pontos à frente (já se sabe que elas estão lá, por causa da verificação na linha de código anterior)
        else if (duracao[i] < '0' || duracao[i] > '9') {valid = 0; return valid;}
    }
    
    char* duracaoSep[3];
    char duracaoAux[len];
    strcpy(duracaoAux, duracao);
    sepString(duracaoAux, duracaoSep, ":", 3);

    if ((checkTimeNums(duracaoSep[0], 'h') == 0) || (checkTimeNums(duracaoSep[1], 'm') == 0) || (checkTimeNums(duracaoSep[2], 's') == 0)) {valid = 0; return valid;}
    
    return valid;
}

int checkTimeNums(char* time, char type){
    int valid = 1;
    int hms = atoi(time);

    if(type == 'h'){
        if(hms < 0 || hms > 99) {valid = 0; return valid;}
        return valid;
    }
    else if(type == 'm' || type == 's'){
        if(hms < 0 || hms > 59) {valid = 0; return valid;}
        return valid;
    }
    return 0;
}

int valida_hora(char* hora){
    int valid = 1;
    int lenHora = strlen(hora);

    char* horaSep[3];
    char horaAux[lenHora];
    strcpy(horaAux, hora);
    sepString(horaAux, horaSep, ":", 3);
    
    int h = atoi(horaSep[0]);
    int m = atoi(horaSep[1]);
    int s = atoi(horaSep[2]);

    if(h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {valid = 0; return valid;}

    return valid;
}