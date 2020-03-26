#include <iostream>
#include<conio.h>
#include <graphics.h>
#include<math.h>

using namespace std;

int main()
{
    int gd=DETECT,gm; char x[]="";
    initgraph(&gd,&gm,x);
    int cx=getmaxx()/2, cy=getmaxy()/2;

    int r=200, i=0;
    double theta=0;
    while(!kbhit())
    {
        cleardevice();
        setcolor(WHITE);
        circle(cx,cy,r);
        floodfill(cx,cy,WHITE);
        setcolor(BLACK);
        arc(cx-r*sin(theta)/2,cy-r*cos(theta)/2,270+i,90+i,r/2);
        pieslice(cx-r*sin(theta)/2,cy-r*cos(theta)/2,0,360,r/5);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(cx-r*sin(theta)/2,cy+2-r*cos(theta)/2,BLACK);
        setfillstyle(SOLID_FILL,WHITE);
        arc(cx+r*sin(theta)/2,cy+r*cos(theta)/2,90+i,270+i,r/2);
        pieslice(cx+r*sin(theta)/2,cy+r*cos(theta)/2,0,360,r/5);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(cx+r*sin(theta)/2,cy+2+r*cos(theta)/2,BLACK);
        setfillstyle(SOLID_FILL,WHITE);
        putpixel(cx,cy,BLACK);
        delay(200);
        theta+=M_PI/180;
        i++;
    }
    getch();
    closegraph();
    return 0;
}
