#include <iostream>
#include<conio.h>
#include <graphics.h>
#include<math.h>

using namespace std;

int rotus(int cx, int cy, int r=200)
{
    double theta=0;
    int i=0;
    while(!kbhit())
    {
        cleardevice();
        setcolor(WHITE);
        //setfillstyle(SOLID_FILL,GREEN);
        circle(cx,cy,r);
        floodfill(cx,cy,WHITE);
        setcolor(BLACK);
        //setfillstyle(SOLID_FILL,BLUE);
        //arc(cx,cy,270+i,90+i,r);
        arc(cx-r*sin(theta)/2,cy-r*cos(theta)/2,270+i,90+i,r/2);
        arc(cx+r*sin(theta)/2,cy+r*cos(theta)/2,90+i,270+i,r/2);
        putpixel(cx,cy,BLACK);
        //setfillstyle(SOLID_FILL,BLACK);
        //floodfill(cx+r*sin(theta)/2,cy+r*cos(theta)/2,BLACK);
        delay(200);
        theta+=M_PI/180;
        i++;
    }
    return 0;
}
