#include <iostream>
#include<conio.h>
#include <graphics.h>
#include<math.h>

using namespace std;

int flag(int cx,int cy,int r=50)
{
    int thetabase=0;
    while(!kbhit())
    {
        cleardevice();
        setcolor(RED);
        setfillstyle(SOLID_FILL,RED);
        rectangle(cx-250,cy-150,cx+250,cy-50);
        floodfill(cx,cy-100,RED);
        setcolor(WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        rectangle(cx-250,cy-50,cx+250,cy+50);
        floodfill(cx,cy,WHITE);
        setcolor(GREEN);
        setfillstyle(SOLID_FILL,GREEN);
        rectangle(cx-250,cy+50,cx+250,cy+150);
        floodfill(cx,cy+100,GREEN);
        setcolor(BLUE);
        circle(cx,cy,r);
        double theta=M_PI*thetabase/180;
        for(int i=0;i<180;i+=15, theta+=M_PI/12)
        {
            line(cx+r*cos(theta),cy+r*sin(theta),cx-r*cos(theta),cy-r*sin(theta));
        }
        thetabase++;
        thetabase%=15;
        delay(200);
    }
    return 0;
}

