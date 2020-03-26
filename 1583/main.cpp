#include <iostream>
#include <graphics.h>
#include<math.h>

using namespace std;

int round(float f)
{
    if(f>0) return (int)(f+0.5);
    else return (int)(f-0.5);
}

void iv(int *x, int* y, int *z, bool **E, int n)
{
    int *xx=new int[n];
    int *yy=new int[n];
    int *zz=new int[n];
    for(int j=0; j<n; j++)
    {
        float xt=(float)((x[j]-z[j])/sqrt(2));
        float zt=(float)((x[j]+z[j])/sqrt(2));
        xx[j]=round(xt);
        zz[j]=round(zt);
        float yt=(float)((y[j]*sqrt(2)-zz[j])/sqrt(3));
        yy[j]=round(yt);
    }
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(E[i][j])
                line(xx[i]-60+getmaxx()/2,-yy[i]+getmaxy()/2,xx[j]-60+getmaxx()/2,-yy[j]+getmaxy()/2);
}

void pv(int *x, int* y, int* z, bool **E, int n, int pz, int d)
{
    int *xx=new int[n];
    int *yy=new int[n];
    for(int j=0; j<n; j++)
    {
        float xt=(float)((x[j]*(d+pz))/(d+z[j]));
        float yt=(float)((y[j]*(d+pz))/(d+z[j]));
        xx[j]=round(xt);
        yy[j]=round(yt);
    }
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(E[i][j])
                line(xx[i]-60+getmaxx()/2,-yy[i]+getmaxy()/2,xx[j]-60+getmaxx()/2,-yy[j]+getmaxy()/2);
}

void cuboid(int* x, int* y, int* z, bool **E, int px, int py, int pz, int i)
{
    x[i+0]=x[i+1]=x[i+2]=x[i+3]=px-20;
    x[i+4]=x[i+5]=x[i+6]=x[i+7]=px+20;
    y[i+0]=y[i+7]=y[i+4]=y[i+3]=py-8;
    y[i+1]=y[i+5]=y[i+6]=y[i+2]=py+8;
    z[i+6]=z[i+7]=z[i+2]=z[i+3]=pz-8;
    z[i+4]=z[i+5]=z[i+0]=z[i+1]=pz+8;
    E[i+0][i+1]=E[i+1][i+0]=E[i+2][i+1]=E[i+1][i+2]=E[i+2][i+3]=E[i+3][i+2]=E[i+0][i+3]=E[i+3][i+0]=true;
    E[i+4][i+5]=E[i+5][i+4]=E[i+5][i+6]=E[i+6][i+5]=E[i+6][i+7]=E[i+7][i+6]=E[i+7][i+4]=E[i+4][i+7]=true;
    E[i+0][i+4]=E[i+4][i+0]=E[i+2][i+6]=E[i+6][i+2]=E[i+7][i+3]=E[i+3][i+7]=E[i+1][i+5]=E[i+5][i+1]=true;
}

void vcuboid(int* x, int* y, int* z, bool **E, int px, int py, int pz, int i)
{
    x[i+0]=x[i+1]=x[i+2]=x[i+3]=px-8;
    x[i+4]=x[i+5]=x[i+6]=x[i+7]=px+8;
    y[i+0]=y[i+7]=y[i+4]=y[i+3]=py-20;
    y[i+1]=y[i+5]=y[i+6]=y[i+2]=py+20;
    z[i+6]=z[i+7]=z[i+2]=z[i+3]=pz-8;
    z[i+4]=z[i+5]=z[i+0]=z[i+1]=pz+8;
    E[i+0][i+1]=E[i+1][i+0]=E[i+2][i+1]=E[i+1][i+2]=E[i+2][i+3]=E[i+3][i+2]=E[i+0][i+3]=E[i+3][i+0]=true;
    E[i+4][i+5]=E[i+5][i+4]=E[i+5][i+6]=E[i+6][i+5]=E[i+6][i+7]=E[i+7][i+6]=E[i+7][i+4]=E[i+4][i+7]=true;
    E[i+0][i+4]=E[i+4][i+0]=E[i+2][i+6]=E[i+6][i+2]=E[i+7][i+3]=E[i+3][i+7]=E[i+1][i+5]=E[i+5][i+1]=true;
}

int main()
{
    int *x=new int[152];
    int *y=new int[152];
    int *z=new int[152];
    bool **E=new bool*[152];
    for(int i=0; i<152; i++)
    {
        E[i]=new bool[152];
        for(int j=0; j<152; j++)
            E[i][j]=false;
    }

    int gd=DETECT,gm; char zz[]="";
    initgraph(&gd,&gm,zz);

        int b=0;
        vcuboid(x,y,z,E,-75,30,0,b);
        b+=8;
        vcuboid(x,y,z,E,-75,-30,0,b);
        b+=8;

        cuboid(x,y,z,E,-10,0,0,b);
        b+=8;
        vcuboid(x,y,z,E,-35,30,0,b);
        b+=8;
        cuboid(x,y,z,E,-10,60,0,b);
        b+=8;
        vcuboid(x,y,z,E,15,-30,0,b);
        b+=8;
        cuboid(x,y,z,E,-10,-60,0,b);
        b+=8;

        cuboid(x,y,z,E,70,0,0,b);
        b+=8;
        vcuboid(x,y,z,E,45,30,0,b);
        b+=8;
        vcuboid(x,y,z,E,95,30,0,b);
        b+=8;
        cuboid(x,y,z,E,70,60,0,b);
        b+=8;
        vcuboid(x,y,z,E,45,-30,0,b);
        b+=8;
        vcuboid(x,y,z,E,95,-30,0,b);
        b+=8;
        cuboid(x,y,z,E,70,-60,0,b);
        b+=8;

        cuboid(x,y,z,E,150,0,0,b);
        b+=8;
        vcuboid(x,y,z,E,175,30,0,b);
        b+=8;
        cuboid(x,y,z,E,150,60,0,b);
        b+=8;
        vcuboid(x,y,z,E,175,-30,0,b);
        b+=8;
        cuboid(x,y,z,E,150,-60,0,b);
        b+=8;

    for(double theta=0; !kbhit(); theta=30*M_PI/180)
    {
        cleardevice();
        pv(x,y,z,E,152,200,300);
        for(int j=0; j<152; j++)
        {
         //   float xx=(float)(x[j]*cos(theta)-y[j]*sin(theta));
         //   float yy=(float)(x[j]*sin(theta)+y[j]*cos(theta));
         //   x[j]=round(xx);
         //   y[j]=round(yy);

            float xx=(float)(x[j]*cos(theta)+z[j]*sin(theta));
            float zz=(float)(-x[j]*sin(theta)+z[j]*cos(theta));
            x[j]=round(xx);
            z[j]=round(zz);
        }
        delay(400);
    }
    getch();
    closegraph();
    return 0;
}
