#ifndef KV_STORE_H
#define KV_STORE_H

// Function declarations
void init_table(void);
void set(const char *key, const char *value);
char *get(const char *key);
unsigned int hash(const char *key);

#endif
