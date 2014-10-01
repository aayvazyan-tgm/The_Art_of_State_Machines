#include "cfprintf.h"

int main(int argc, char **argv) {
    cfprintf(stderr,
            "yellowblue{Yellow on Blue}\n"
                    "redgreen{Red on Green}\n"
                    "blueyellow{Blue on Yellow}\n"
                    "bluewhite{Blue on White}\n"
                    "blackwhite{Black on White}\n"
                    "yellowred{Yellow on Red}\n"
                    "redteal{Red on Teal}\n");
    return 0;
}
