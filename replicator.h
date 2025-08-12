//
// Created by ferdinand on 8/12/25.
//

#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <dirent.h>

#include "neutral.h"

void getHiddenFiles (const std::string& dir, std::vector<std::string> &files);
void replicate(char* source);