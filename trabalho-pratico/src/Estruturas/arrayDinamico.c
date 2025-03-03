#include <stdlib.h>
#include "../../include/Utility/utility.h"

typedef struct ArrayD {
    void **array;
    size_t max_ln;
    size_t ln;
    size_t size_total;
    unsigned long member_size;
}*ARRAYD;

ARRAYD arrayd_create (size_t member_size,size_t n_member) {
    ARRAYD arrayd = malloc(sizeof(struct ArrayD));
    arrayd->array = calloc(n_member,member_size);
    arrayd->max_ln = n_member;
    arrayd->member_size = member_size;
    arrayd->ln = 0;
    arrayd->size_total=n_member*member_size;
    return arrayd;
}

void arrayd_realloc(ARRAYD array_d) {
    array_d->array = realloc(array_d->array,array_d->size_total*2);
    array_d->max_ln *= 2;  
    array_d->size_total*=2;
}

void arrayd_add (void *info, ARRAYD array_d) {
    if (array_d->ln == array_d->max_ln){
        arrayd_realloc(array_d);
    }
    array_d->array[array_d->ln]=info;
    array_d->ln++;
}

void arrayd_free(ARRAYD array_d,void (*free_info)(void*),int bool_vazio) {
    for (int i=0;bool_vazio != 1 && i<array_d->ln;i++){
        free_info(array_d->array[i]);
    }
    free(array_d->array);
    free(array_d);
}

void *arrayd_index(ARRAYD array_d,int index){
    if (index >= array_d->ln) return NULL;
    return array_d->array[index];
}

int arrayd_get_length(ARRAYD arrayd) {
    return arrayd->ln;
}

void arrayd_sort (ARRAYD arrayd,int (*comp)(const void *,const void *)) {
    qsort(arrayd->array,arrayd->ln,sizeof(arrayd->array[0]),comp);
}

void arrayd_sort_r(ARRAYD arrayd,int (*comp)(const void *,const void *,void*), void * arg) {
    qsort_r(arrayd->array,0,arrayd->ln-1,sizeof(arrayd->array[0]),comp,arg);
}