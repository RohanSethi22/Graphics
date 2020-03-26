#include<graphics.h>
#include<conio.h>
#include<math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void linedraw(int x1, int y1, int x2, int y2)
{
    float x=x1, y=y1, dx=x2-x1, dy=y2-y1, d=0;
    //putpixel(320+x,240-y,WHITE);
    if(abs(dy)<abs(dx))
    {
        d=(2*dy)-dx;
        cout << "Here";
        while(x<x2)
        {
            if(d<=0)
                d+=2*dy;
            else
            {
                d+=2*(dy-dx);
                y++;
            }
            x++;
            cout << x << " " << y << endl;
            putpixel(320+x,240-y,YELLOW);
        }
    }
    else
    {
        d=(dy)-(2*dx);
        while(y<=y2)
        {
            if(d<=0)
            {
                d-=2*(dx);
            }
            else
            {
                d+=2*(dy-dx);
                x++;
            }
            y++;
            putpixel(320+x,240-y,YELLOW);
        }
    }
}


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x0,y0,x1,y1,temp;
    cout << "Enter starting coordinates: ";
    cin >> x0 >> y0;
    cout << "Enter ending coordinates: ";
    cin >> x1 >> y1;
    line(320,0,320,480);
    line(0,240,640,240);
    if(x0>x1)
    {
        temp=x1;
        x1=x0; x0=temp;
        temp=y1;
        y1=y0;
        y0=temp;
    }
    linedraw(x0,y0,x1,y1);
    getch();
    closegraph();
    return 0;
}
