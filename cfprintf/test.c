#include "cfprintf.h"
#include "../StateMachines/TrafficLightState.h"
#include "../functions/outputTrafficLightColor.h"

int main(int argc, char **argv) {
    outTrC(Red);
    outTrC(RedYellow);
    outTrC(Yellow);
    outTrC(Green);
    outTrC(BlinkingGreen);
    outTrC(BlinkingYellow);
    outTrC(Off);
    return 0;
}
