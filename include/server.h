#ifndef SERVER_H
#define SERVER_H

void start_server(void);
void handle_client(int client_fd);
char *process_command(char *command);

#endif
