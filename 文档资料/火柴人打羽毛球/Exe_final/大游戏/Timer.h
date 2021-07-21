#pragma once
#include <windows.h>

class Timer // 改进的延时
{
private:
	LARGE_INTEGER clock;	
	LONGLONG lastClock;		
	int frequency;				

public:
	Timer() 
	{
		QueryPerformanceFrequency(&clock);
		frequency = (int)clock.QuadPart / 1000;
		lastClock = 0;
	}

	void Sleep(int ms) 
	{
		unsigned int c = ms * frequency;
		if (lastClock == 0)
		{
			QueryPerformanceCounter(&clock);
			lastClock = clock.QuadPart;		
		}
		lastClock += c;
		QueryPerformanceCounter(&clock);
		if (clock.QuadPart > lastClock)
			lastClock = clock.QuadPart;
		else
		{
			do
			{
				::Sleep(1);
				QueryPerformanceCounter(&clock);	
			}
			while(clock.QuadPart < lastClock);
		}
	}	
};