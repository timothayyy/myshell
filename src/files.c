//
// Created by timmy on 11/19/26.
//

#include <stdio.h>
#include <dirent.h>
#include <errno.h>

int file_ls() {
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    if (errno != 0) {
        perror("readdir");
    }

    closedir(dir);
    return 0;
}