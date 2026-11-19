//
// Created by timmy on 11/19/26.
//

#include <stdio.h>
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
