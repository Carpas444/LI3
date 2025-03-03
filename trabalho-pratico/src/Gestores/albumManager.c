#include "../../include/Entidades/album.h"
#include <glib.h>


typedef struct AlbumManager{
    GHashTable *Albums;
}*ALBUM_MANAGER;


ALBUM_MANAGER album_manager_create() {

    // pointer da struct e criaçao da ghashtable
    ALBUM_MANAGER album_manager = malloc(sizeof(GHashTable*));
    album_manager->Albums = g_hash_table_new_full(g_str_hash,g_str_equal,free,(void *)album_free);
    return album_manager;
}

void album_manager_add (ALBUM_MANAGER album_manager,char ** info) {
    ALBUM album= album_create(info);
    char * id = album_get_id_album(album);
    g_hash_table_insert(album_manager->Albums,id,album);
}

ALBUM album_manager_lookup (ALBUM_MANAGER album_manager,char *id) {
    ALBUM album = g_hash_table_lookup(album_manager->Albums,id);
    return album;
}

void album_manager_free (ALBUM_MANAGER album_manager) {
    g_hash_table_destroy(album_manager->Albums);
    free(album_manager);
}

char ** album_manager_get_key_as_array(ALBUM_MANAGER album_manager,unsigned int *ln) {
    char **keys = (char **) g_hash_table_get_keys_as_array(album_manager->Albums,ln);
    return keys;
}

char * album_manager_get_artists_id (ALBUM_MANAGER album_manager,char * id) {
    ALBUM album = album_manager_lookup(album_manager,id);
    return album_get_artists_id(album);
}