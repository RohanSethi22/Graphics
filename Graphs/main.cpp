
#include <iostream>
#include<conio.h>
#include <graphics.h>
#include<math.h>
#include"Solar.h"
#include"Flag.h"
#include"YinYang.h"
#include"CoinToss.h"

using namespace std;

int main()
{
    int gd=DETECT,gm; char x[]="";
    initgraph(&gd,&gm,x);
    //bar(10,10,600,700);
    int cx=getmaxx()/2, cy=getmaxy()/2;
    //cointoss(cx,cy);
    //flag(cx,cy,r);
    //solar(cx,cy);
    rotus(cx,cy);
    getch();
    closegraph();
    return 0;
}
