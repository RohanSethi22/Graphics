#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include <iostream>

using namespace std;

int round(float f)
{
    if(f>0) return (int)(f+0.5);
    else return (int)(f-0.5);
}

void curv(int* x, int* y)
{
    for(float t=0 ; t<=1; t+=0.01)
    {
        float px=(-pow(t,3)+3*pow(t,2)-3*t+1)*x[0]+(3*pow(t,3)-6*pow(t,2)+3*t)*x[1]+(-3*pow(t,3)+3*pow(t,2))*x[2]+(pow(t,3))*x[3];
        int pix=round(px);
        float py=(-pow(t,3)+3*pow(t,2)-3*t+1)*y[0]+(3*pow(t,3)-6*pow(t,2)+3*t)*y[1]+(-3*pow(t,3)+3*pow(t,2))*y[2]+(pow(t,3))*y[3];
        int piy=round(py);
        putpixel(pix,piy,WHITE);
    }
}

int main()
{
    int gd=DETECT,gm; char zz[]="";
    initgraph(&gd,&gm,zz);

    int n=0;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the vertices: " << endl;
    int *x=new int[n];
    int *y=new int[n];
    for(int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    for(int i=0;i+3<n;i+=3)
    {
        int xx[4]={x[i],x[i+1],x[i+2],x[i+3]};
        int yy[4]={y[i],y[i+1],y[i+2],y[i+3]};
        curv(xx,yy);
        delay(400);
    }
    int xx[4]={x[n-4],x[n-3],x[n-2],x[n-1]};
    int yy[4]={y[n-4],y[n-3],y[n-2],y[n-1]};
    curv(xx,yy);
    getch();
    return 0;
}
// 25 140 150 145 160 150 220 140 300 135 220 130 170 140 150 155 140 170 135 180 150 190 170 170 200 150 220 165 250 180 280 195 310 200 200 190 120 160 110 115 130 120 220 140 320 160 340 180 346 220 300
// 240 250 250 140 235 120 230 150 220 260 230 320
