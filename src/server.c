#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"

#define PORT 6379
#define BUFFER_SIZE 1024

void start_server(){
    int server_fd, client_fd;
    struct sockaddr_in address;

    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))){
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, 3) < 0){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while(1) {
        if((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0){
            perror("Accept failed");
            continue;
        }

        read(client_fd, buffer, BUFFER_SIZE);
        printf("Received: %s\n", buffer);

        char *response = process_command(buffer);
        send(client_fd, response, strlen(response), 0);
        close(client_fd);
    }
}

char *process_command(char *command){
    char *token = strtok(command, " ");
    if (token == NULL){
        return "ERROR: Invalid command\n";
    }

    if (strcasecmp(token, "SET") == 0){
        char *key = strtok(NULL, " ");
        char *value = strtok(NULL, " ");
        if (key && value){
            set(key, value);
            return "OK\n";
        }
    }else if(strcasecmp(token, "GET") == 0){
        char *key = strtok(NULL, " ");
        if (key){
            char *value = get(key);
            return value ? value : "NULL\n";
        }
    }

    return "ERROR: Unkown command\n";
}