#pragma once

#include "ClientState.h"

class CoreStateEngine
{
public:
	CoreStateEngine() = default;
	~CoreStateEngine() = default;
	bool transitionToState(ClientState targetState);

private:
	ClientState currentState = ClientState::CONNECTED;
};