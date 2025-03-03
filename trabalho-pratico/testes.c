#include "include/appManager.h"
#include <sys/resource.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

 struct Errors {
    int query;
    int line;
    int comando;
};



int main (int argc , char ** argv) {
    if (argc != 4) {
        printf("Wrong Ammount of Arguments\n");
        return 1;
    }
    struct timespec start, end;
    double elapsed;
    int total_queries;
    int *n_queries;
    clock_gettime(CLOCK_REALTIME, &start);
    double* elapsed_times = app_testes(argv,&total_queries,&n_queries);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    FILE * inputs = fopen(argv[2],"r");

    struct Errors errors[total_queries];
    for(int i=0;i<total_queries;i++){
        char *line_input = NULL;
        size_t n_input =0;
        getline(&line_input,&n_input,inputs);
        errors[i].line =0;
        errors[i].query = line_input[0]-'0';
        errors[i].comando = i+1;
        int j =1;
        for(int u=10; i+1 >= u;u=u*10,j++);
        char cmd_number[20+j];
        sprintf(cmd_number,"/command%d_output.txt",i+1);
        
        char *comando = malloc(sizeof("resultados")+sizeof(cmd_number));
        char* comando_esperado =malloc(sizeof(argv[3])+sizeof(cmd_number));
        strcpy(comando,"/resultados");
        strcpy(comando_esperado,argv[3]);
        strcat(comando,cmd_number);
        strcat(comando_esperado,cmd_number);
        FILE* comando_file = fopen(comando,"r");
        FILE* comando_esperado_file = fopen(comando_esperado,"r");
        char* line1 = NULL;
        char* line2 = NULL;
        size_t ln1=0;
        size_t ln2=0;
        ssize_t n1=0;
        ssize_t n2=0;
        int line_counter =1;
        while ( n1 != -1 && n2 != -1 ) {
            if(comando_file == NULL) break;
            n1 =getline(&line1,&ln1,comando_file);
            n2 =getline(&line2,&ln2,comando_esperado_file);
            if (n1 == -1 || n2 == -1) continue;

            if (strcmp(line1,line2) ==0) {
                line_counter++;
            }
            else {
                errors[i].line = line_counter;
                break;
            }
        }
        if (n1 == -1 && n2 != -1) {
            errors[i].line = line_counter;
        }
        if (n1 != -1 && n2 ==-1 ) {
            errors[i].line = line_counter;
        }
        line_counter = 1;
        free(line1);
        free(line2);
        free(line_input);
        if (comando_file != NULL) fclose(comando_file);
        fclose(comando_esperado_file);
        free(comando);
        free(comando_esperado);


    }
    int queries_acertadas[6]={0};
    for (int i =0;i< total_queries;i++) {
        if (errors[i].line ==0) queries_acertadas[(errors[i].query)-1]++;
    }
    for (int i =0 ;i< 6;i++) {
        int ln=0;
        printf("Q%d : %d de %d testes ok\n",i+1,queries_acertadas[i],n_queries[i]);
        for (int j=0;j<n_queries[i];){
            if(errors[ln].query==i+1){
                j++;
                if (errors[ln].line != 0) printf("    Descrepância na query %d: linha %d de ”resultados/command%d_output.txt”\n",ln+1,errors[i].line,ln+1);
            }
            ln++;
        }
    }

    //       printf("    Descrepância na query %d: linha %d de ”resultados/command%d_output.txt”\n",i+1,errors[i],i);
    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);
    printf("Tempos de execução:\n");
    for (int i=0;i<6;i++) {
        printf("    Q%d: %.6f seconds\n",i+1,elapsed_times[i]);
    }
    printf("Tempo Tolal do programa: %.6f seconds\n",elapsed);
    free(elapsed_times);
    fclose(inputs);
    free(n_queries);
    return 0;
}