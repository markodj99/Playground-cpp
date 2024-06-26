#include "windows.h"
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

#include "MyTesting.hpp"

int main()
{
	_CrtMemState sOld;
	_CrtMemState sNew;
	_CrtMemState sDiff;
	_CrtMemCheckpoint(&sOld);

	Test();

	_CrtMemCheckpoint(&sNew);
	if (_CrtMemDifference(&sDiff, &sOld, &sNew))
	{
		OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
		_CrtMemDumpStatistics(&sDiff);
		OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
		_CrtMemDumpAllObjectsSince(&sOld);
		OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
		_CrtDumpMemoryLeaks();
	}

	return 0;
}