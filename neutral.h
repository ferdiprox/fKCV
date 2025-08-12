//
// Created by ferdinand on 8/12/25.
//

#pragma once

#include <string>
#include <unistd.h>
#include <pwd.h>

#define CAREANDBARE(action) try action catch(...){}

inline std::string homePath;
inline std::vector<std::string> replicatedEntries;
inline std::string noninjectKey = "---";

inline void getHomePath() {
    passwd *pw = getpwuid(getuid());
    if (pw != nullptr) {
        homePath = std::string(pw->pw_dir) + '/';
        return;
    }
    // fallback using environment variable
    const char* homeEnv = getenv("HOME");
    if (homeEnv != nullptr) {
        homePath = std::string(homeEnv) + '/';
        return;
    }
    std::exit(0);
}
