#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/Validações/validacaoSintMusics.h"
#include "../../include/Validações/validacaoFuncoesGen.h"

int validaSint_music(char** music){               //verifica se uma música é sintaticamente válida, de acordo com os requisitos do enunciado
    return (validaParenteses(music[2]) && valida_ano(music[6]) && valida_duracao(music[4]));
}

//-------------------------------------YEAR------------------------------------------//

int valida_ano(char* musicYear){                  //verifica se o ano de uma música é sintaticamente válido, de acordo com os requisitos do enunciado
    int ano = atoi(musicYear);
    if(ano > 2024) return 0;
    return 1;
}