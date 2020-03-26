
#include <iostream>
#include<conio.h>
#include <graphics.h>
#include<math.h>

using namespace std;

int mx, my, hx, hy;

int gencode(int x, int y)
{
    int code=0;
    int left=8, right=4, bottom=2, top=1;
    if(x<mx) code=code|left;
    if(x>hx) code=code|right;
    if(y<my) code=code|bottom;
    if(y>hy) code=code|top;
    return code;
}

void func(int x1, int y1, int x2, int y2)
{
    int p1code=gencode(x1,y1), p2code=gencode(x2,y2);
    cout << "P1 code = " << p1code << endl << "P2 code = " << p2code << endl;

    if(p1code==0 && p2code==0)
    {
        line(x1,y1,x2,y2);
        cout << "Line is completely visible.\n";
    }

    else if((p1code&p2code)!=0) cout << "Line is completely invisible.\n";

    //Consider case when midpoint lies on rectangle.

    else
    {
        int midx=(x1+x2)/2, midy=(y1+y2)/2;
        func(x1,y1,midx,midy);
        func(midx,midy,x2,y2);
    }
}

int main()
{
    int gd=DETECT,gm; char x[]="";
    initgraph(&gd,&gm,x);
    cout<< "Enter coordinates of first corner of rectangle: ";
    cin >> mx >> my;
    cout<< "Enter coordinates of opposite corner of rectangle: ";
    cin >> hx >> hy;

    int px1, px2, py1, py2;
    cout<< "Enter coordinates of point 1 of line: ";
    cin >> px1 >> py1;
    cout<< "Enter coordinates of point 2 of line: ";
    cin >> px2 >> py2;

    func(px1, py1, px2, py2);

    for(int i=mx; i<hx; i++)
    {
        putpixel(i,my,WHITE);
        putpixel(i,hy,WHITE);
    }
    for(int i=my; i<hy; i++)
    {
        putpixel(mx,i,WHITE);
        putpixel(hx,i,WHITE);
    }


    getch();
    closegraph();
    return 0;
}
