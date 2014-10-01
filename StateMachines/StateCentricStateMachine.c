#include <stdio.h>
#include <stdlib.h>
#include "TrafficLightState.h"
#include "Commands.h"
#include "../functions/outputTrafficLightColor.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif


#define SLEEP_TIME 1000

void trafficLight(TrafficLightState* state, Command *command) {
    switch(*state) {
        case Red:
            if(*command==Wait){
                puts("Red: Wait");
                outTrC(Red);
                _flushall();
                Sleep(SLEEP_TIME);
                *state=RedYellow;
                *command=Standby;
            }
            if(*command==Reset){
                puts("Red: Reset");
                outTrC(Red);
                _flushall();
                Sleep(SLEEP_TIME);
                *state=RedYellow;
                *command=Standby;
            }
            break;
        case Green:
            if(*command==Go){
                puts("Green: Go");
                outTrC(Green);
                _flushall();
                Sleep(SLEEP_TIME);
                *state=BlinkingGreen;
                *command=PrepareToStop;
            }
            break;
        case RedYellow:
            if(*command==Standby){
                puts("RedYellow: Standby");
                outTrC(RedYellow);
                _flushall();
                Sleep(SLEEP_TIME);
                *state=Green;
                *command=Go;
            }
            break;
        case Yellow:
            if(*command==Stop){
                puts("Yellow: Stop");
                outTrC(Yellow);
                _flushall();
                Sleep(SLEEP_TIME);
                *state=Red;
                *command=Wait;
            }
            break;
        case BlinkingGreen:
            if(*command==PrepareToStop){
                puts("BlinkingGreen: PrepareToStop");
                outTrC(BlinkingGreen);
                _flushall();
                Sleep(SLEEP_TIME);
                *state=Yellow;
                *command=Stop;
            }
            break;
        case BlinkingYellow:
            if(*command==Idle){
                puts("BlinkingYellow: Idle");
                outTrC(BlinkingYellow);
                _flushall();
                Sleep(SLEEP_TIME);
                *state=Red;
                *command=Reset;
            }
            if(*command==Error){
                puts("BlinkingYellow: Error");
                outTrC(BlinkingYellow);
                _flushall();
                Sleep(SLEEP_TIME);
                *state=Red;
                *command=Reset;
            }
            break;
        default:
            puts("Invalid state error!");
            outTrC(Off);
            _flushall();
            *state=BlinkingYellow;
            *command=Error;
    }
}

int main(void) {
	int x=0;
    TrafficLightState tls=BlinkingYellow;
    Command com=Idle;

    while(x<20){
        trafficLight(&tls, &com);
        x++;
	}
    return EXIT_SUCCESS;
}