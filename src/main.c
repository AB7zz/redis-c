#include "server.h"
#include "kv_store.h"
#include "expiration.h"

int main() {
    // Initialize tables
    init_table();
    init_expiry_table();
    
    // Start server
    start_server();
    
    return 0;
}
