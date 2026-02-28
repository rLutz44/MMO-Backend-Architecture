#include "CoreStateEngine.h"

bool CoreStateEngine::transitionToState(ClientState targetState)
{
    switch (targetState) {
        case ClientState::AUTHENTICATED:
            if (currentState == ClientState::CONNECTED) {
                currentState = targetState;
                return true;
            }
            break; 

        case ClientState::IN_GAME:
            if (currentState == ClientState::AUTHENTICATED) {
                currentState = targetState;
                return true;
            }
            break;
    }

    return false;
}
