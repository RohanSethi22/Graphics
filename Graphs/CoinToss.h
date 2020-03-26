#include <iostream>
#include<conio.h>
#include <graphics.h>
#include<math.h>

using namespace std;

int cointoss(int cx,int cy, int r=100)
{
	int i=0;
	bool increase=true;
	while(!kbhit())
	{
		cleardevice();
		ellipse(cx,cy,0,360,r,i);
		if (increase) i++;
		else i--;
		if (i==r && increase) increase=false;
		else if (i==r && !increase) increase=true;
	}
	return 0;
}
