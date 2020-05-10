//
//  main.cpp
//  black_playground
//
//  Created by Artsiom Kaliaha on 4/21/20.
//  Copyright © 2020 Artsiom Kaliaha. All rights reserved.
//

#include <stdio.h>

#define NO_STATE -1

void onUserWin() {
    printf("user won\n");
}

void onAIWin() {
    printf("ai won\n");
}

void onStartNewGame() {
    printf("new game started\n");
}

enum { STATE_PLAYING = 0, STATE_GAME_OVER = 1, STAME_MAX = 2 };

enum { EVENT_USER_WIN = 0, EVENT_AI_WIN = 1, EVENT_START_NEW_GAME = 2, EVENT_MAX = 3 };

typedef struct {
    void (*action)();
    int nextState;
} Transition;

static Transition stateTable[EVENT_MAX][STAME_MAX] = {
                              /*STATE_PLAYING*/              /*STATE_GAME_OVER*/
    /*EVENT_USER_WIN*/      { { onUserWin, STATE_GAME_OVER }, { NULL,           NO_STATE      } },
    /*EVENT_AI_WIN*/        { { onAIWin,   STATE_GAME_OVER }, { NULL,           NO_STATE      } },
    /*EVENT_START_NEW_GAME*/{ { NULL,      NO_STATE        }, { onStartNewGame, STATE_PLAYING } }
};

int handleEvent(int currentState, int event) {
    Transition transition = stateTable[event][currentState];
    
    if (event < EVENT_MAX && currentState < STAME_MAX) {
        if (transition.nextState != NO_STATE && transition.action != NULL) {
            transition.action();
            return transition.nextState;
        }
    }
    
    return NO_STATE;
}

int main(int argc, const char * argv[]) {
    int state = STATE_GAME_OVER;
    
    int newState = handleEvent(STATE_GAME_OVER, EVENT_START_NEW_GAME);
    if (newState != NO_STATE) {
        state = newState;
    }
    
    return 0;
}
