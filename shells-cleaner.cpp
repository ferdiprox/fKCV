//
// Created by ferdinand on 8/12/25.
//

#include "shells-cleaner.h"

#include <dirent.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <csignal>
#include <string>

void cleanShells() {
    DIR *dir = opendir("/proc");
    if (dir == nullptr) {
        return;
    }

    dirent *entry;
    std::string path;
    std::string exePathBuffer(256, 0);

    while ((entry = readdir(dir))) {
        pid_t pid = atoi(entry->d_name);
        if (entry->d_type != DT_DIR || pid == 0)
            continue;

        path = std::string("/proc/") + entry->d_name + "/exe";
        ssize_t len = readlink(path.c_str(), exePathBuffer.data(), exePathBuffer.size() - 1);
        if (len == -1) continue;

        exePathBuffer[len] = '\0';

        if (exePathBuffer.find("/bash") == std::string::npos) continue;

        kill(pid, SIGKILL);
    }
    closedir(dir);
}
