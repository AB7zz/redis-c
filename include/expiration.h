#ifndef EXPIRATION_H
#define EXPIRATION_H

// Function declarations
void init_expiry_table(void);
void set_expiry(const char *key, int seconds);
int is_expired(const char *key);
void remove_expiry(const char *key);

#endif
