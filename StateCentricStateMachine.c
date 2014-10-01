#include <stdio.h>
#include <stdlib.h>
//#include colors.h

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif


typedef enum _TrafficLightState { Red, RedYellow, Yellow, Green, BlinkingGreen, BlinkingYellow} TrafficLightState;
typedef enum _Command { Standby,Wait,Idle,Reset,Go,Stop,PrepareToStop,Error} Command;
#define SLEEP_TIME 1000

void trafficLight(TrafficLightState* state, Command *command) {
    switch(*state) {
        case Red:
            if(*command==Wait){
                puts("Red: Wait");
                _flushall();
                Sleep(SLEEP_TIME);
                *state=RedYellow;
                *command=Standby;
            }
            if(*command==Reset){
                puts("Red: Reset");
                _flushall();
                Sleep(SLEEP_TIME);
                *state=RedYellow;
                *command=Standby;
            }
            break;
        case Green:
            if(*command==Go){
                puts("Green: Go");
                _flushall();
                Sleep(SLEEP_TIME);
                *state=BlinkingGreen;
                *command=PrepareToStop;
            }
            break;
        case RedYellow:
            if(*command==Standby){
                puts("RedYellow: Standby");
                _flushall();
                Sleep(SLEEP_TIME);
                *state=Green;
                *command=Go;
            }
            break;
        case Yellow:
            if(*command==Stop){
                puts("Yellow: Stop");
                _flushall();
                Sleep(SLEEP_TIME);
                *state=Red;
                *command=Wait;
            }
            break;
        case BlinkingGreen:
            if(*command==PrepareToStop){
                puts("BlinkingGreen: PrepareToStop");
                _flushall();
                Sleep(SLEEP_TIME);
                *state=Yellow;
                *command=Stop;
            }
            break;
        case BlinkingYellow:
            if(*command==Idle){
                puts("BlinkingYellow: Idle");
                _flushall();
                Sleep(SLEEP_TIME);
                *state=Red;
                *command=Reset;
            }
            if(*command==Error){
                puts("BlinkingYellow: Error");
                _flushall();
                Sleep(SLEEP_TIME);
                *state=Red;
                *command=Reset;
            }
            break;
        default:
            puts("Invalid state error!");
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