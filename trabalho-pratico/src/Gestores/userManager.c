#include "../../include/Gestores/userManager.h"
#include "../../include/Entidades/user.h"
#include <glib.h>


typedef struct UserManager{
    GHashTable *Users;
}*USER_MANAGER;


USER_MANAGER user_manager_create() {

    // pointer da struct e criaçao da ghashtable
    USER_MANAGER user_manager = malloc(sizeof(GHashTable*));
    user_manager->Users = g_hash_table_new_full(g_str_hash,g_str_equal,free,(void *)(user_free));
    return user_manager;
}

void user_manager_add (USER_MANAGER user_manager,char **info) {
    USER user= user_create(info);
    g_hash_table_insert(user_manager->Users,user_get_username(user),user);
}
USER user_manager_lookup (USER_MANAGER user_manager,char *username) {
    USER user = g_hash_table_lookup(user_manager->Users,username);
    return user;
}

void user_manager_free (USER_MANAGER user_manager) {
    g_hash_table_destroy(user_manager->Users);
    free(user_manager);
}

int user_manager_test_exist(USER_MANAGER user_manager,char * id) {
    if(user_manager_lookup (user_manager,id) == NULL) return 1;
    else return 0;
}

char * user_manager_get_email(USER_MANAGER user_manager,char *id) {
    return user_get_email(user_manager_lookup(user_manager,id));
}
char * user_manager_get_firstname(USER_MANAGER user_manager,char *id) {
    return user_get_firstname(user_manager_lookup(user_manager,id));
}
char * user_manager_get_lastname(USER_MANAGER user_manager,char *id) {
    return user_get_lastname(user_manager_lookup(user_manager,id));
}
char * user_manager_get_country(USER_MANAGER user_manager,char *id) {
    return user_get_country(user_manager_lookup(user_manager,id));
}
int user_manager_get_age(USER_MANAGER user_manager,char *id) {
    return user_get_age(user_manager_lookup(user_manager,id));
}

void user_manager_create_views_genre(USER_MANAGER user_manager,int length,char *id){
    USER user = user_manager_lookup(user_manager,id);
    user_create_views_genre(user,length);
}

void user_manager_add_views_to_genre(USER_MANAGER user_manager,int index,char *id){
    USER user = user_manager_lookup(user_manager,id);
    user_add_views_genre(user,index);
}

const int *user_manager_get_views_genre(USER_MANAGER user_manager,char *id) {
    return user_get_views_genre(user_manager_lookup(user_manager,id));
}

char** user_manager_get_key_as_array(USER_MANAGER user_manager, unsigned int * len){
    return((char**) g_hash_table_get_keys_as_array(user_manager->Users, len));
}

void user_manager_add_history(USER_MANAGER user_manager,char *user_id,char *history_id){
    user_add_history(user_manager_lookup(user_manager,user_id),history_id);
}

char**user_manager_get_user_history(USER_MANAGER user_manager,char* id,int*ln) {
   return user_get_user_history(user_manager_lookup(user_manager,id),ln);
}