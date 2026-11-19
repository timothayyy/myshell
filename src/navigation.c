//
// Created by timmy on 11/19/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void cmd_pwd(void) {
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd");
    }
}

void cmd_cd(const char *path) {

    if (path == NULL) {
        path = getenv("HOME");
    }

    if (path == NULL) {
        fprintf(stderr, "cd HOME not set\n");
    }

    if (chdir(path) != 0) {
        perror("cd");
    }

}
