#include <windows.h> 
#include <iostream> 
#include <stdio.h>
#include <clocale>
#include <memory>

class Point
{
private:
	int x;
	int y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}

	Point(int xx, int yy)
	{
		x = xx;
		y = yy;
	}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}
};