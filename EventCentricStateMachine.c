#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

typedef enum _TrafficLightState { Red, RedYellow, Yellow, Green, BlinkingGreen, BlinkingYellow} TrafficLightState;
typedef enum _Command { Standby,Wait,Idle,Reset,Go,Stop,PrepareToStop,Error} Command;
#define SLEEP_TIME 1000
#define NEXTSTATE nextState(state, command)

void nextState(TrafficLightState* state, Command *command);

void trafficLight(TrafficLightState* state, Command* command, char* currentTrafficLightColor) {
    switch(*command) {
        case Standby:
            if(*state==RedYellow){
                strcpy(currentTrafficLightColor, "Red");
                NEXTSTATE;
            }
        case Wait:
            if(*state==){
                strcpy(currentTrafficLightColor, "");
                NEXTSTATE;
            }
        case Idle:
            if(*state==){
                strcpy(currentTrafficLightColor, "Off");
                NEXTSTATE;
            }
        case Reset:
            if(*state==Red){
                strcpy(currentTrafficLightColor, "Off");
                NEXTSTATE;
            }
        case Go:
            if(*state==Green){
                strcpy(currentTrafficLightColor, "Off");
                NEXTSTATE;
            }
        case Stop:
            if(*state==Yellow){
                strcpy(currentTrafficLightColor, "Off");
                NEXTSTATE;
            }
        case PrepareToStop:
            if(*state==BlinkingGreen){
                strcpy(currentTrafficLightColor, "Off");
                NEXTSTATE;
            }
        case Error:
            if(*state==BlinkingYellow){
                strcpy(currentTrafficLightColor, "Off");
                NEXTSTATE;
            }
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

