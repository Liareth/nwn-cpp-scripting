#include "Windows.h"
#include "Game/Example.hpp"
#include <stdio.h>

BOOL WINAPI DllMain(HINSTANCE, DWORD fdwReason, LPVOID)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			//AllocConsole();
			//freopen("CONOUT$", "w", stdout);
			//freopen("CONOUT$", "w", stderr);

            example::init();

			break;
		}

		case DLL_PROCESS_DETACH:
		{
			//FreeConsole();
			break;
		}
	}

	return true;
}
