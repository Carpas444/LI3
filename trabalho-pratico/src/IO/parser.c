#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/Utility/utility.h" 
#include "../../include/Validações/validacaoSintUsers.h" 
#include "../../include/Validações/validacaoSintMusics.h"
#include "../../include/Validações/validacaoLogSintArtists.h" 
#include "../../include/IO/parser.h"
#include "../../include/IO/funcoesIO.h"

void escreve_errors (FICHEIRO errors,char*line) {
    fprintf(get_file(errors),"%s",line);
}

void passar_primeira_linha(FICHEIRO ficheiro,FICHEIRO errors) {
    char *line=calloc(3000,sizeof(char));
    fgets(line,3000,get_file(ficheiro));
    escreve_errors(errors,line);
    free(line);
}


int parser (FICHEIRO ficheiro, char ** info,char **l , int (*validaSint)(char**)) {
    int r =-1;
    FILE *file = get_file(ficheiro);
    char *line =NULL;
    size_t ln=0;
    if (getline(&line,&ln,file) != -1) {
        r = 0;
        char* aux = strdup(line);
        aux[strlen(aux)-1] = '\0';
        int length;
        for ( length=0 ; (info[length] = strsep(&aux,";") ) !=NULL; length++) {
           rmSimbolo(info[length],'"','"');
        }
        if (validaSint != NULL )r = (validaSint(info));
        else r = 1;
        for(int i=0;i<length && r==1;i++) {
            if (info[i][0] == '[' && info [i][strlen(info[i])-1] == ']') {
                if (strlen(info[i]) ==2) info[i]=NULL;
                else {
                    rmSimbolo(info[i],'[',']');
                    rmSimbolo(info[i],' ',' ');
                    rmSimbolo(info[i],'\'','\'');
                } 
            }
        }
        free(aux);
        (*l)=line;
        return r;
    }
    free(line);
    return r;
}