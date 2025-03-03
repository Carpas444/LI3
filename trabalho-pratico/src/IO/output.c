#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


FILE *create_result_file(int command_number) {
    int j =1;
    for(int i=10; command_number >= i;i=i*10,j++);
    char cmd_number[18+j];
    sprintf(cmd_number,"command%d_output.txt",command_number);
    char *str = malloc(sizeof("resultados/")+sizeof(cmd_number));
    strcpy(str,"resultados/");
    strcat(str,cmd_number);
    FILE *output = fopen(str,"w");
    free(str);
    return output;
}

void write_in_result_int (FILE *output,int info,int lastline,int tem_S) {
    char sep = ';';
    if (tem_S) sep = '=';
    if (lastline ==1 ) fprintf(output,"%d\n",info);
    else fprintf(output,"%d%c",info,sep);
}

void write_in_result_str (FILE *output,char *info,int lastline,int tem_S) {
    char sep = ';';
    if (tem_S) sep = '=';
    if (lastline ==1 ) fprintf(output,"%s\n",info);
    else fprintf(output,"%s%c",info,sep);
}

void write_in_result_double(FILE *output,double info,int lastline,int tem_S) {
    char sep = ';';
    if (tem_S) sep = '=';
    double rounded = info;
    if (lastline ==1 ) fprintf(output,"%.2f\n",rounded);
    else fprintf(output,"%.2f%c",rounded,sep);
}