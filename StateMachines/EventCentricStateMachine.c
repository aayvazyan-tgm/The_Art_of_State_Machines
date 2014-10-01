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
#define NEXTSTATE nextState(state, command)

void nextState(TrafficLightState* state, Command *command);

void trafficLight(TrafficLightState* state, Command* command, char* currentTrafficLightColor) {
    switch(*command) {
        case Standby:
            if(*state==RedYellow){
                strcpy(currentTrafficLightColor, "RedYellow");
                outTrC(RedYellow);
                Sleep(SLEEP_TIME);
                NEXTSTATE;
            }
            break;
        case Wait:
            if(*state==Red){
                strcpy(currentTrafficLightColor, "Red");
                outTrC(Red);
                Sleep(SLEEP_TIME);
                NEXTSTATE;
            }
            break;
        case Idle:
            if(*state==BlinkingYellow){
                strcpy(currentTrafficLightColor, "BlinkingYellow");
                outTrC(BlinkingYellow);
                Sleep(SLEEP_TIME);
                NEXTSTATE;
            }
            break;
        case Reset:
            if(*state==Red){
                strcpy(currentTrafficLightColor, "Red");
                outTrC(Red);
                Sleep(SLEEP_TIME);
                NEXTSTATE;
            }
            break;
        case Go:
            if(*state==Green){
                strcpy(currentTrafficLightColor, "Green");
                outTrC(Green);
                Sleep(SLEEP_TIME);
                NEXTSTATE;
            }
            break;
        case Stop:
            if(*state==Yellow){
                strcpy(currentTrafficLightColor, "Yellow");
                outTrC(Yellow);
                Sleep(SLEEP_TIME);
                NEXTSTATE;
            }
            break;
        case PrepareToStop:
            if(*state==BlinkingGreen){
                strcpy(currentTrafficLightColor, "BlinkingGreen");
                outTrC(BlinkingGreen);
                Sleep(SLEEP_TIME);
                NEXTSTATE;
            }
            break;
        case Error:
            if(*state==BlinkingYellow){
                strcpy(currentTrafficLightColor, "BlinkingYellow");
                outTrC(BlinkingYellow);
                Sleep(SLEEP_TIME);
                NEXTSTATE;
            }
            break;
        default:
            break;
    }
}

void nextState(TrafficLightState* state, Command *command) {
    switch(*state) {
        case Red:
            if(*command==Wait){
                *state=RedYellow;
                *command=Standby;
            }
            if(*command==Reset){
                *state=RedYellow;
                *command=Standby;
            }
            break;
        case Green:
            if(*command==Go){
                *state=BlinkingGreen;
                *command=PrepareToStop;
            }
            break;
        case RedYellow:
            if(*command==Standby){
                *state=Green;
                *command=Go;
            }
            break;
        case Yellow:
            if(*command==Stop){
                *state=Red;
                *command=Wait;
            }
            break;
        case BlinkingGreen:
            if(*command==PrepareToStop){
                *state=Yellow;
                *command=Stop;
            }
            break;
        case BlinkingYellow:
            if(*command==Idle){
                *state=Red;
                *command=Reset;
            }
            break;
        default:
            *state=BlinkingYellow;
            *command=Error;
    }
}

int main(void) {
    int x=0;
    TrafficLightState tls=BlinkingYellow;
    Command com=Idle;
    char *currentColor=(char *) malloc(100);
    strcpy(currentColor,"Off");
    while(x<15){
        char *displayColor=(char *) malloc(100);

        strcpy(displayColor,"The traffic light shows: ");
        strcat(displayColor,currentColor);
        puts(displayColor); _flushall();

        free(displayColor);

        trafficLight(&tls, &com, currentColor);
        x++;
    }
    return EXIT_SUCCESS;
}

