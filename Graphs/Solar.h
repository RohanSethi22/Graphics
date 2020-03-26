#include <iostream>
#include<conio.h>
#include <graphics.h>
#include<math.h>

using namespace std;

int solar(int cx, int cy, int a=250, int b=150, int sr=70, int re=30, int md=50)
{
    double theta=0, mtheta=0;
    for(int i=0; !kbhit(); i++, theta+=M_PI/180)
    {
        mtheta=0;
        for(int j=0; mtheta<2*M_PI; j++, mtheta+=M_PI/180)
        {
            cleardevice();
            setcolor(LIGHTGRAY);
            setlinestyle(DASHED_LINE, 1, 1);
            ellipse(cx,cy,0,360,a,b);
            setlinestyle(SOLID_LINE, 1, 1);
            setcolor(YELLOW);
            setfillstyle(SOLID_FILL,YELLOW);
            pieslice(cx,cy,0,360,sr);

            setcolor(BLUE);
            setfillstyle(SOLID_FILL,BLUE);
            circle(cx+a*cos(theta),cy+b*sin(theta),re);
            floodfill(cx+a*cos(theta),cy+b*sin(theta),BLUE);
            setcolor(GREEN);
            setfillstyle(SOLID_FILL,GREEN);
            arc(cx+a*cos(theta),cy+b*sin(theta),270,90,re);
            arc(cx+a*cos(theta),cy+b*sin(theta)+re/2,270,90,re/2);
            pieslice(cx+a*cos(theta),cy+b*sin(theta)-re/2,0,360,15);
            floodfill(cx+a*cos(theta)+re/2,cy+b*sin(theta),GREEN);

            setcolor(LIGHTGRAY);
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            pieslice(cx+a*cos(theta)+md*cos(mtheta),cy+b*sin(theta)+md*sin(mtheta),0,360,10);
            delay(10);
        }
    }
    return 0;
}
