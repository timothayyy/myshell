#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main(void) {

    char input[256];
    int running = 1;

    while (running) {
        printf("> ");

        if (fgets(input, sizeof(input), stdin) == NULL) break;


        input[strcspn(input, "\n")] = '\0';

       if (strcmp(input, "pwd") == 0) {
           char cwd[PATH_MAX];
           if (getcwd(cwd, sizeof(cwd)) != NULL) {
               printf("%s\n", cwd);
           } else {
               perror("getcwd");
           }
       }
        else if (strcmp(input, "quit") == 0) {
            running = 0;
        }
        else if (strcmp(input, "help") == 0) {
            printf("help\n");
        } else {
            printf("Unknown command\n");
        }

    }
    return 0;
}
