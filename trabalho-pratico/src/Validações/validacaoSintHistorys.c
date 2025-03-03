#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/Validações/validacaoSintHistorys.h"
#include "../../include/Validações/validacaoFuncoesGen.h"
#include "../../include/Utility/utility.h"

int validaSint_historys(char** history){
    return(valida_timestamp(history[3]) && valida_duracao(history[4]) && valida_plataforma(history[5]));
}

int valida_timestamp(char* timestamp){
    int lenTimeStamp = strlen(timestamp);

    char* timeStampSep[2];
    char timeStampAux[lenTimeStamp];
    strcpy(timeStampAux, timestamp);
    sepString(timeStampAux, timeStampSep, " ", 2);

    return(valida_data(timeStampSep[0]) && valida_hora(timeStampSep[1]));
}

int valida_plataforma(char* plataforma){
    if((strcmp(plataforma, "mobile") != 0) && (strcmp(plataforma, "desktop") != 0)) return 0;
    return 1;
}
