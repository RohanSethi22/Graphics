#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void ellipsesymmetry(int x , int y)
{
    putpixel(320+x,240-y , WHITE);
    putpixel(320-x,240-y , WHITE);
    putpixel(320+x,240+y , WHITE);
    putpixel(320-x,240+y , WHITE);
}

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    int a, b;
    initgraph(&gdriver, &gmode, "");
    cout << "Enter the values of a and b in ellipse equation : ";
    cin >> a >> b;
    cleardevice();
    float x=a, y=0 , d=(a*a-b*a*b+b*b*(.25));
    putpixel(320+x,240-y,WHITE);
    while(b*b*abs(x)>a*a*abs(y))
    {
        if(d<=0)
        d += a*a*(2*y +3);
        else
        {
            d+= a*a*(2*y +3)+2*b*b*(1-x);
            x-- ;
        }
        y++;
        ellipsesymmetry(x,y);
    }
    while(x>0)
    {
        if(d>0)
            d+= (3-2*x)*b*b;
        else
        {
            d+=a*a*2*(1+y)+(3-2*x)*b*b;
            y++ ;
        }
        x--;
        ellipsesymmetry(x,y);
    }
    getch();
    closegraph();
    return 0;
}
