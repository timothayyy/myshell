
#include <stdio.h>
#include <string.h>
#include "include/commands.h"

int main(void) {

    char input[256];
    int running = 1;

    while (running) {

        // Display shell prompt
        printf("myshell> ");
        fflush(stdout);

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Remove trailing newline
        input[strcspn(input, "\n")] = '\0';

        // Identify and execute commands
        if (strcmp(input, "pwd") == 0) {
            cmd_pwd();
        }
        else if (strcmp(input, "help") == 0) {
            cmd_help();
        }
        else if (strcmp(input, "quit") == 0) {
            running = 0;
        }
        else if (input[0] == '\0') {
            continue;
        }
        else {
            printf("Unknown command: %s\n", input);
        }
    }

    return 0;
}
