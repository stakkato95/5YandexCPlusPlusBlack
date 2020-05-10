//
//  1_embedded_state_machine_2.c
//  black_playground
//
//  Created by Artsiom Kaliaha on 5/10/20.
//  Copyright © 2020 Artsiom Kaliaha. All rights reserved.
//

#include <stdio.h>

#define NO_STATE -1

void onStart() {
    printf("started -> now runnable\n");
}

void onYield() {
    printf("yielded -> still running\n");
}

void onPause() {
    printf("paused -> now not runnable\n");
}

void onResume() {
    printf("paused -> now not runnable\n");
}

void onStop() {
    printf("stopped -> now dead\n");
}

enum { STATE_NEW = 0, STATE_RUNNABLE = 1, STATE_NOT_RUNNABLE = 2, STATE_DEAD = 3, STATE_MAX = 4 };
enum { EVENT_START = 0, EVENT_YIELD = 1, EVENT_PAUSE = 2, EVENT_RESUME = 3, EVENT_STOP = 4, EVENT_MAX = 5 };

typedef struct {
    void (*action)();
    int nextState;
} Transition;

//static Transition statetable[EVENT_MAX][STATE_MAX] = {
//                     /*STATE_NEW*/                /*STATE_RUNNABLE*/                /*STATE_NOT_RUNNABLE*/        /*STATE_DEAD*/
//    /*EVENT_START*/ { { STATE_RUNNABLE, onStart }, { NO_STATE,              NULL }, { NO_STATE,           NULL }, { NO_STATE, NULL } },
//    /*EVENT_YIELD*/ { { NO_STATE,          NULL }, { STATE_RUNNABLE,     onYield }, { NO_STATE,           NULL }, { NO_STATE, NULL } },
//    /*EVENT_PAUSE*/ { { NO_STATE,          NULL }, { STATE_NOT_RUNNABLE, onPause }, { NO_STATE,           NULL }, { NO_STATE, NULL } },
//    /*EVENT_RESUME*/{ { NO_STATE,          NULL }, { STATE_NOT_RUNNABLE, onPause }, { STATE_RUNNABLE, onResume }, { NO_STATE, NULL } },
//    /*EVENT_STOP*/  { { STATE_DEAD,      onStop }, { STATE_DEAD,          onStop }, { STATE_DEAD,       onStop }, { NO_STATE, NULL } }
//};

int main(int argc, const char * argv[]) {
    
    return 0;
}
