#include<graphics.h>
#include<conio.h>
#include<math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void draw(int x1,int y1,int x2,int y2)
{
    float x=x1, y=y1, dx=x2-x1, dy=y2-y1, m=dy/dx;
    int i,s=0;
    if(abs(dx)>=abs(dy))
       while(x<=x2)
        {
            putpixel(x,y,WHITE);
            x=x+1;
            y+=m;
        }
    else
        while(y<=y2)
        {
            putpixel(x,y,WHITE);
            x+=(1/m);
            y++;
        }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x0,y0,x1,y1;
    cout << "Enter starting coordinates: ";
    cin >> x0 >> y0;
    cout << "Enter ending coordinates: ";
    cin >> x1 >> y1;
    draw(x0,y0,x1,y1);
    getch();
    closegraph();
    return 0;
}
