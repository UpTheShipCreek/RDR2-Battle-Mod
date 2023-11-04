#include "script.h"

#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <Windows.h>

#define ARTIFICIAL_TICK_MARGIN 200

bool promptKeyActivated = false;

void print_message(const char* message) {
	UILOG::_UILOG_SET_CACHED_OBJECTIVE(message);
	UILOG::_UILOG_PRINT_CACHED_OBJECTIVE();
	UILOG::_UILOG_CLEAR_HAS_DISPLAYED_CACHED_OBJECTIVE();
	UILOG::_UILOG_CLEAR_CACHED_OBJECTIVE();
}

bool key_pressed(int key){
	return GetAsyncKeyState(key) & 0x8000;
}

void update(){



	if (key_pressed(VK_F9)){

		if(!promptKeyActivated){

			print_message("Can you see this?");
		}
		else {

			print_message("Second");
		}
		promptKeyActivated = !promptKeyActivated;
	}
}

void main()
{		
	while (true)
	{
		update();
		WAIT(ARTIFICIAL_TICK_MARGIN);
	}
}

void ScriptMain()
{	
	srand(GetTickCount());
	main();
}
