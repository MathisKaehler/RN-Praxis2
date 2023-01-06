#include "hash_table.h"
//function that sets the value of a key in the hash table
void htable_set(htable **ht, const unsigned char *key, size_t key_len,
                const unsigned char *value, size_t value_len) {
    /* TODO IMPLEMENT */
    int hash = hash_function(key, key_len);
    htable *curr = ht[hash];
    if (curr == NULL) {
        curr = htable_new();
        curr->key = key;
        curr->key_len = key_len;
        curr->value = value;
        curr->value_len = value_len;
    } else {
        htable *prev = NULL;
        while (curr != NULL) {
            if (curr->key == key) {
                curr->value = value;
                curr->value_len = value_len;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = htable_new();
        prev->next->key = key;
        prev->next->key_len = key_len;
        prev->next->value = value;
        prev->next->value_len = value_len;
    }
    
}

htable *htable_get(htable **ht, const unsigned char *key, size_t key_len) {
    /* TODO IMPLEMENT */
int hash = hash_function(key, key_len);
    htable *curr = ht[hash];
    if (curr == NULL) {
        return NULL;
    } else {
        while (curr != NULL) {
            if (curr->key == key) {
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }
}

int htable_delete(htable **ht, const unsigned char *key, size_t key_len) {
    /* TODO IMPLEMENT */
    int hash = hash_function(key, key_len);
    htable *curr = ht[hash];
    htable *prev = NULL;
    if (curr == NULL) {
        return 0;
    } else {
        while (curr != NULL)
}
