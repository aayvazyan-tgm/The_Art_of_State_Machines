#include "../cfprintf/cfprintf.h"
#include "../StateMachines/TrafficLightState.h"
#include "outputTrafficLightColor.h"

void outTrC(TrafficLightState tf) {
    switch (tf){
        case Red:
            cfprintf(stdout, "blackred{Red}|" "|blackwhite{Yellow}|" "|blackwhite{Green}\n");
            break;
        case RedYellow:
            cfprintf(stdout, "blackred{Red}|" "|blackyellow{Yellow}|" "|blackwhite{Green}\n");
            break;
        case Yellow:
            cfprintf(stdout, "blackwhite{Red}|" "|blackyellow{Yellow}|" "|blackwhite{Green}\n");
            break;
        case Green:
            cfprintf(stdout, "blackwhite{Red}|" "|blackwhite{Yellow}|" "|blackgreen{Green}\n");
            break;
        case BlinkingGreen:
            cfprintf(stdout, "blackwhite{Red}|" "|blackwhite{Yellow}|" "|blackgreen{Gr}blackwhite{ee}blackgreen{n}\n");
            break;
        case BlinkingYellow:
            cfprintf(stdout, "blackwhite{Red}|" "|blackyellow{Ye}" "blackwhite{ll}" "blackyellow{ow}|" "|blackwhite{Green}\n");
            break;
        case Off:
        default:
            cfprintf(stdout, "blackwhite{Red}|" "|blackwhite{Yellow}|" "|blackwhite{Green}\n");
            break;
    }
}