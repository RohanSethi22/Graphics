#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void circlesymmetry(int x , int y)
 {
      putpixel(320+x,240-y , WHITE);
      putpixel(320-x,240-y , WHITE);
      putpixel(320+x,240+y , WHITE);
      putpixel(320-x,240+y , WHITE);
      putpixel(320+y,240-x , WHITE);
      putpixel(320-y,240+x , WHITE);
      putpixel(320-y,240-x , WHITE);
      putpixel(320+y,240+x , WHITE);
 }

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    int r=100;
    initgraph(&gdriver, &gmode, "");
    cout << "Enter the radius of circle :";
    cin >> r;
    cleardevice();
    float x, y , d,de,dse;
    de=3;
    dse=-2*r+5;
    x= 0 ; y= r;
    putpixel(320+x,240-y,WHITE);
    d =  1 - r;
    while(x <=y)
    {
        if(d<=0)
        {
            d+=de;
            de+=2;
            dse+=2;
        }
        else
        {
            d += dse;
            de+=2;
            dse+=4;
            y-- ;
        }
        x++;
        circlesymmetry(x,y);
    }
    getch();
    closegraph();
    return 0;
}
