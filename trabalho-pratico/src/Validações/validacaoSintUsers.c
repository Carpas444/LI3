#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/Validações/validacaoSintUsers.h"
#include "../../include/Validações/validacaoFuncoesGen.h"
#include "../../include/Utility/utility.h"


int validaSint_user(char** user){                //verifica se o user é sintaticamente válido, de acordo com os requisitos do enunciado
    return (validaParenteses(user[7]) && valida_data(user[4]) && valida_email(user[1]) && valida_subType(user[6]));
}

//-------------------------------------EMAIL------------------------------------------//

int valida_email(char* email){                   //verifica se o endereço de email é sintaticamente válido, de acordo com os requisitos do enunciado
    int valid = 1;
    int lenEmail = strlen(email);

    if (validaArrobaEponto(email) == 0) {valid = 0; return 0;}     //se o email não tiver pelo menos um arroba e um ponto, dá logo return 0, pois o formato de email está errado
    
    char* emailSep[2];
    char emailAux[lenEmail];
    strcpy(emailAux, email);
    sepString(emailAux, emailSep, "@", 2);
    
    int lenDomain = strlen(emailSep[1]);
    char* domainSep[2];
    char domainAux[lenDomain];
    strcpy(domainAux, emailSep[1]);
    sepString(domainAux, domainSep, ".", 2);
    
    if((checkUsername(emailSep[0]) == 0) || (checkLString(domainSep[0]) == 0) || (checkRString(domainSep[1]) == 0)) {valid = 0; return valid;}

    return valid;
}

int validaArrobaEponto(char* email){             //verifica se o email tem pelo menos um ponto e um @; se não tiver, o endereço email está mal e é logo descartado
    if (strchr(email,'.') != NULL && strchr(email,'@') != NULL) return 1;
    else return 0;
}

int checkUsername(char* username){               //verifica se username é válido, de acordo com os requisitos do enunicado
    int valid = 1;
    int len = strlen(username);

    if(len <= 0) {valid = 0; return valid;}

    for(int i = 0; i < len; i++){
        if((username[i] >= 'a' && username[i] <= 'z') || (username[i] >= '0' && username[i] <= '9' )) valid = 1;     //verifica se username só tem caracteres pertencentes a [a,z] e [0,9]-
        else {valid = 0; return valid;}
    }

    return valid;
}

int checkLString(char* lstring){                 //verifica se a LString é válida, de acordo com os requisitos do enunciado
    int valid = 1;
    
    int len = strlen(lstring);
    if(len == 0) {valid = 0; return valid;}     //verifica se LString tem pelo menos um caracter 
    
    for(int i = 0; i < len; i++){
        if(lstring[i] >= 'a' && lstring[i] <= 'z') valid = 1;     //verifica se LString só tem caracteres pertencentes a [a,z]
        else {valid = 0; return valid;}
    }

    return valid;
}

int checkRString(char* rstring){                 //verifica se a RString é válida, de acordo com os requisitos do enunciado
    int valid = 1;
    
    int len = strlen(rstring);
    if(len < 2 || len > 3) {valid = 0; return valid;}     //verifica se RString tem 2 ou 3 caracteres de comprimento

    for(int i = 0; i < len; i++){
        if(rstring[i] >= 'a' && rstring[i] <= 'z') valid = 1;     //verifica se RString só tem caracteres pertencentes a [a,z]
        else {valid = 0; return valid;}
    }

    return valid;
}

//------------------------------SUBSCRIPTION_TYPE------------------------------------//

int valida_subType(char* subType){               //verifica se o tipo de subscrição do user é válido, de acordo com os requisitos do enunciado
    if(strcmp(subType,"normal") != 0 && strcmp(subType,"premium") != 0) return 0;
    return 1;
}