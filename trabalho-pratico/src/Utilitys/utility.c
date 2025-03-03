#include "../../include/Utility/utility.h"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void rmSimbolo(char *str,char simb1,char simb2){    // string acaba em '/0'
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != simb1 && *dst != simb2) dst++;
    }
    *dst = '\0';
}

char **ArrayToArray2D (char *info, int size_inital, char *simbs) {
    int tamanho = size_inital;
    char **savedinfo = calloc(tamanho,sizeof(char*));
    for(int i = 0; (savedinfo[i]=strsep(&info,simbs))!= NULL;i++){
        if (i==tamanho-1) {
            savedinfo=realloc(savedinfo,(sizeof(char*)*tamanho+sizeof(char*)*size_inital));
            tamanho = tamanho+size_inital;
        } 
    }
    return savedinfo; 
}

int GiveSeconds(char *time) {
    char **tempo = ArrayToArray2D(time,4,":");
    int sec = atoi(tempo[0])*3600+atoi(tempo[1])*60+atoi(tempo[2]);
    free(tempo);
    return sec;
}

int GiveAge (char *date){
    char*aux[3];
    for(int i=0;i<3;i++) aux[i]=strsep(&date,"/");
    int age = atoi(aux[0]);
    int month = atoi(aux[1]);
    int day = atoi(aux[2]);
    if (month > 9 || (month == 9 && day > 9)) return 2024-age-1;
    else return 2024-age;
}

char* GiveDisco(int discography){
    int resto_h = discography % 3600;
    int h = (discography - resto_h) / 3600;
    int resto_m = resto_h % 60;
    int m = (resto_h - resto_m) / 60;
    int s = resto_m;
    char disco[9];
    sprintf(disco,"%02d:%02d:%02d", h, m ,s);
    char* aux = strdup(disco);
    return aux;
}
int DateCompare (char *date1,char* date2) {
    return strcmp(date1,date2);
}

char *Sub7Days(char *date) {
    char*aux[3];
    for(int i=0;i<3;i++) aux[i]=strsep(&date,"/");
    struct tm *new_date = malloc(sizeof(struct tm));
    int year= atoi(aux[0]);
    int month= atoi(aux[1]);
    int day= atoi(aux[2]);
    new_date->tm_mday = day-7;
    new_date->tm_mon = month-1;
    new_date->tm_year = year-1900;
    new_date->tm_hour = 0;
    new_date ->tm_min =0;
    new_date ->tm_sec = 0;
    new_date->tm_isdst= 0;
    mktime(new_date);
    char*newdate = calloc(100,sizeof(char));
    sprintf(newdate,"%d/%02d/%02d\0",new_date->tm_year+1900,new_date->tm_mon+1,new_date->tm_mday);
    free(new_date);
    return newdate;
}

double GiveWeek(char * date) {
    char*aux[3];
    for(int i=0;i<3;i++) aux[i]=strsep(&date,"/");
    struct tm *input_date = malloc(sizeof(struct tm));
    input_date->tm_mday = atoi(aux[2]);
    input_date->tm_mon = atoi(aux[1])-1;
    input_date->tm_year = atoi(aux[0])-1900;
    input_date->tm_hour = 0;
    input_date ->tm_min =0;
    input_date ->tm_sec = 0;
    input_date->tm_isdst= 0;


    struct tm *original_date = malloc(sizeof(struct tm));
    original_date->tm_mday = 8;
    original_date->tm_mon = 8;
    original_date->tm_year = 2024-1900;
    original_date->tm_hour = 0;
    original_date ->tm_min =0;
    original_date ->tm_sec = 0;
    original_date->tm_isdst= 0;

    double seconds = difftime(mktime(original_date),mktime(input_date));
    free(input_date);
    free(original_date);
    return ceil(seconds / 604800);
}


void swap(void* a, void* b, size_t size) {
    char* p1 = (char*)a;
    char* p2 = (char*)b;
    for (size_t i = 0; i < size; i++) {
        char temp = p1[i];
        p1[i] = p2[i];
        p2[i] = temp;
    }
}
int partition(void* base, int low, int high, size_t size, int (*cmp)(const void*, const void*,void*),void *arg) {
    char* array = (char*)base;
    void* pivot = array + high * size;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (cmp(array + j * size, pivot,arg) <= 0) {
            i++;
            swap(array + i * size, array + j * size, size);
        }
    }
    swap(array + (i + 1) * size, array + high * size, size);
    return i + 1;
}

void qsort_r(void* base, int low, int high, size_t size, int (*cmp)(const void*, const void*,void*),void *arg) {
    if (low < high) {
        int pi = partition(base, low, high, size, cmp,arg);

        qsort_r(base, low, pi - 1, size, cmp,arg);
        qsort_r(base, pi + 1, high, size, cmp,arg);
    }
}

void sepString (char* src, char** dest, char* simb, int numpos){
    int i;
    
    for(i = 0; i < numpos; i++){
        dest[i] = strsep(&src, simb);
    }
}



void swap2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortIndexes(int arr[], int indexes[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[indexes[i]] < arr[indexes[j]]) {
                swap2(&indexes[i], &indexes[j]);
            }
        }
    }
}
