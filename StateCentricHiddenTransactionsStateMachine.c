#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <winbase.h>
#define Sleep(x) usleep((x)*1000)
#endif

typedef enum _TrafficLightState { Red, RedYellow, Yellow, Green, BlinkingGreen, BlinkingYellow} TrafficLightState;
typedef enum _Command { Standby,Wait,Idle,Reset,Go,Stop,PrepareToStop,Error} Command;
#define SLEEP_TIME 1000
#define NEXTSTATE nextState(state, command)

void nextState(TrafficLightState* state, Command *command);

void trafficLight(TrafficLightState* state, Command* command, char* currentTrafficLightColor) {
    switch(*state) {
        case Red:
            if(strcmp(currentTrafficLightColor,"Red")!=0)
                strcpy(currentTrafficLightColor, "Red");
            if(*command==Wait){

                puts("Red: Wait");
                _flushall();
                Sleep(SLEEP_TIME);

                NEXTSTATE;
            }
            if(*command==Reset){

                puts("Red: Reset");
                _flushall();
                Sleep(SLEEP_TIME);

                NEXTSTATE;
            }
            break;
        case Green:
            if(strcmp(currentTrafficLightColor,"Green")!=0)
                strcpy(currentTrafficLightColor, "Green");
            if(*command==Go){

                puts("Green: Go");
                _flushall();
                Sleep(SLEEP_TIME);

                NEXTSTATE;
            }
            break;
        case RedYellow:
            if(strcmp(currentTrafficLightColor,"RedYellow")!=0)
                strcpy(currentTrafficLightColor, "RedYellow");
            if(*command==Standby){

                puts("RedYellow: Standby");
                _flushall();
                Sleep(SLEEP_TIME);

                NEXTSTATE;
            }
            break;
        case Yellow:
            if(strcmp(currentTrafficLightColor,"Yellow")!=0)
                strcpy(currentTrafficLightColor, "Yellow");
            if(*command==Stop){

                puts("Yellow: Stop");
                _flushall();
                Sleep(SLEEP_TIME);

                NEXTSTATE;
            }
            break;
        case BlinkingGreen:
            if(strcmp(currentTrafficLightColor,"BlinkingGreen")!=0)
                strcpy(currentTrafficLightColor, "BlinkingGreen");
            if(*command==PrepareToStop){

                puts("BlinkingGreen: PrepareToStop");
                _flushall();
                Sleep(SLEEP_TIME);

                NEXTSTATE;
            }
            break;
        case BlinkingYellow:
            if(strcmp(currentTrafficLightColor,"BlinkingYellow")!=0) {
                strcpy(currentTrafficLightColor, "BlinkingYellow");
            }
            if(*command==Idle){
                
                puts("BlinkingYellow: Idle");
                _flushall();
                Sleep(SLEEP_TIME);

                NEXTSTATE;
            }
            break;
        default:
            if(strcmp(currentTrafficLightColor,"BlinkingYellow")!=0){
                strcpy(currentTrafficLightColor, "BlinkingYellow");
            }
            puts("Invalid state error!");
            _flushall();

            *state=BlinkingYellow;
            *command=Error;
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

