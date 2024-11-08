#include <stdlib.h>
#include <time.h>
#include "expiration.h"

typedef struct {
    char *key;
    time_t expiry;
} ExpiryEntry;

#define EXPIRY_TABLE_SIZE 1024
static ExpiryEntry *expiry_table[EXPIRY_TABLE_SIZE];

void init_expiry_table(){
    memset(expiry_table, 0, sizeof(expiry_table));
}

void set_expiry(const char *key, int seconds){
    unsigned int index = hash(key);
    ExpiryEntry *entry = expiry_table[index];

    time_t expiry = time(NULL) + seconds;

    if (entry){
        entry->expiry = expiry;
    } else {
        entry = malloc(sizeof(ExpiryEntry));
        entry->key = strdup(key);
        entry->expiry = expiry;
        expiry_table[index] = entry;
    }
}

int is_expired(const char *key){
    unsigned int index = hash(key);
    ExpiryEntry *entry = expiry_table[index];

    if (!entry) return 0;

    return time(NULL) > entry->expiry;
}

void remove_expiry(const char *key){
    unsigned int index = hash(key);
    ExpiryEntry *entry = expiry_table[index];

    if (entry){
        free(entry->key);
        free(entry);
        expiry_table[index] = NULL;
    }
}