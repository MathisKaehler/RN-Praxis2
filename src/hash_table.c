#include "hash_table.h"
//function that sets the value of a key in the hash table
void htable_set(htable **ht, const unsigned char *key, size_t key_len,
                const unsigned char *value, size_t value_len) {
    /* TODO IMPLEMENT */
        htable *s;
        HASH_FIND(hh, *ht, key, key_len, s); //find the key
        if (s == NULL) {
            s = (htable *)malloc(sizeof(htable)); //if it doesn't exist, create it
            s->key = (unsigned char *)malloc(key_len);
            memcpy(s->key, key, key_len);
            s->key_len = key_len;
            HASH_ADD_KEYPTR(hh, *ht, s->key, s->key_len, s); //add it to the hash table
        }
        s->value = (unsigned char *)malloc(value_len); //set the value
        memcpy(s->value, value, value_len);
        s->value_len = value_len;

    
}

htable *htable_get(htable **ht, const unsigned char *key, size_t key_len) {
    /* TODO IMPLEMENT */
    htable *s;
    HASH_FIND(hh, *ht, key, key_len, s);
    return s;
}

int htable_delete(htable **ht, const unsigned char *key, size_t key_len) {
    /* TODO IMPLEMENT */
    htable *s;
    HASH_FIND(hh, *ht, key, key_len, s);
    if (s) {
        HASH_DEL(*ht, s);
        free(s->key);
        free(s->value);
        free(s);
        return 0;
    }
    return -1;
}
