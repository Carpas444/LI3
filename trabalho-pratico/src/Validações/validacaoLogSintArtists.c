#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/Validações/validacaoLogSintArtists.h"
#include "../../include/Validações/validacaoFuncoesGen.h"

int validaLogSintArtists(char** artist){                       //verifica se o artista é logicamente válido, de acordo com os requisitos do enunciado
    int valid = 1;
    int len = strlen(artist[4]);
    if (strcmp(artist[6],"individual") == 0 && len != 2) {valid = 0; return valid;}   //len != 2 pois a string para quando o artista é individual, é "[]" que tem len == 2.
    
    char* id_constituent = artist[4];
    if(!validaParenteses(id_constituent)) {valid = 0; return valid;}

    return valid;  
}