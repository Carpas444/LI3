#include <stdlib.h>
typedef struct List {
    void *info;
    struct List *prox;
}*LIST;

LIST list_create(void *info){
    LIST list =malloc(sizeof(struct List));
    list->info= info;
    list->prox = NULL;
    return list;
}

LIST list_add_sorted (void *info, LIST list,int (*comparar)(void*,void*)) {
    LIST copia = list;
    LIST new = list_create(info);
    if(list == NULL) return new;
    LIST anterior = NULL;
    for(;copia && comparar(new->info,copia->info) > 0;anterior = copia,copia=copia->prox);
    new->prox=copia;
    if(anterior== NULL) return new;
    anterior->prox=new;
    return list;
}   

LIST list_next(LIST list) {
    return (list->prox);
}

void *list_get_info(LIST list) {
    if (list == NULL) return NULL;
    return list->info;
}

void list_free(LIST list,void (*free_info)(void*)) {
    LIST prox=list->prox;
    while(prox){
        free_info(list->info);
        free(list);
        list=prox;
        prox=prox->prox;
    }
    free_info(list->info);
    free(list);
}