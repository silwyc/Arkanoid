#include <Gamefunctions.hpp>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main()
{
	if (setupcheck)
		gamerunning();

	return 0;
}