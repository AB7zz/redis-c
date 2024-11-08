#include <stdlib.h>
#include <string.h>
#include "kv_store.h"

typedef struct {
    char *key;
    char *value;
} StringEntry;

#define TABLE_SIZE 1024
static StringEntry *table[TABLE_SIZE];

unsigned int hash(const char *key){
    unsigned int hash = 0;
    while(*key){
        hash = (hash << 5) + *key++;
    }
    return hash % TABLE_SIZE;
}

void init_table(){
    memset(table, 0, sizeof(table));
}

void set(const char *key, const char *value ){
    unsigned int index = hash(key);
    StringEntry *entry = table[index];

    if(entry){
        free(entry->value);
        entry->value = strdup(value);
    }else {
        entry = malloc(sizeof(StringEntry));
        entry->key = strdup(key);
        entry->value = strdup(value);
        table[index] = entry;
    }
}

char *get(const char *key){
    unsigned int index = hash(key);
    StringEntry *entry = table[index];

    if(entry && strcmp(entry->key, key) == 0){
        return entry->value;
    }
    
    return NULL;
}