#include "script.h"
#include <string>
#include <vector>
#include <chrono>
#include <thread>

void PRINT_MESSAGE(const char* message) {
	UILOG::_UILOG_SET_CACHED_OBJECTIVE(message);
	UILOG::_UILOG_PRINT_CACHED_OBJECTIVE();
	UILOG::_UILOG_CLEAR_HAS_DISPLAYED_CACHED_OBJECTIVE();
	UILOG::_UILOG_CLEAR_CACHED_OBJECTIVE();
}

void update() {
	PRINT_MESSAGE("Can you see this?");
}

void main()
{		
	while (true)
	{
		update();
		WAIT(0);
	}
}

void ScriptMain()
{	
	srand(GetTickCount());
	main();
}
