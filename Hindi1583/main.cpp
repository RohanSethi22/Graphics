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

void one(int xc, int yc, float theta)
{
    int cx=5, cy=-22, lx=12, ly=20;
    theta*=M_PI/180;
    float xx=(float)(cx*cos(theta)-cy*sin(theta));
    float yy=(float)(cx*sin(theta)+cy*cos(theta));
    cx=round(xx)+xc;
    cy=round(yy)+yc;
    circle(cx,cy,5);
    xx=(float)(lx*cos(theta)-ly*sin(theta));
    yy=(float)(lx*sin(theta)+ly*cos(theta));
    lx=round(xx)+xc;
    ly=round(yy)+yc;
    line(xc,yc,lx,ly);
    int x[]={10,6,3,1};
    int y[]={-22,-15,-9,0};
    for(int i=0; i<4; i++)
    {
        float xx=(float)(x[i]*cos(theta)-y[i]*sin(theta));
        float yy=(float)(x[i]*sin(theta)+y[i]*cos(theta));
        x[i]=round(xx)+xc;
        y[i]=round(yy)+yc;
    }
    for(float t=0 ; t<=1; t+=0.01)
    {
        float px=(-pow(t,3)+3*pow(t,2)-3*t+1)*x[0]+(3*pow(t,3)-6*pow(t,2)+3*t)*x[1]+(-3*pow(t,3)+3*pow(t,2))*x[2]+(pow(t,3))*x[3];
        int pix=round(px);
        float py=(-pow(t,3)+3*pow(t,2)-3*t+1)*y[0]+(3*pow(t,3)-6*pow(t,2)+3*t)*y[1]+(-3*pow(t,3)+3*pow(t,2))*y[2]+(pow(t,3))*y[3];
        int piy=round(py);
        putpixel(pix,piy,WHITE);
    }
}

void five(int xc, int yc, float theta)
{
    int cx=5, cy=-22, lx1=0, ly1=-22, lx2=0, ly2=20;
    theta*=M_PI/180;
    float xx=(float)(cx*cos(theta)-cy*sin(theta));
    float yy=(float)(cx*sin(theta)+cy*cos(theta));
    cx=round(xx)+xc;
    cy=round(yy)+yc;
    //circle(cx,cy,5);
    xx=(float)(lx1*cos(theta)-ly1*sin(theta));
    yy=(float)(lx1*sin(theta)+ly1*cos(theta));
    lx1=round(xx)+xc;
    ly1=round(yy)+yc;
    xx=(float)(lx2*cos(theta)-ly2*sin(theta));
    yy=(float)(lx2*sin(theta)+ly2*cos(theta));
    lx2=round(xx)+xc;
    ly2=round(yy)+yc;
    line(lx1,ly1,lx2,ly2);
    int x[]={-10,-10,-8,-2};
    int y[]={-22,-2,0,0};
    for(int i=0; i<4; i++)
    {
        float xx=(float)(x[i]*cos(theta)-y[i]*sin(theta));
        float yy=(float)(x[i]*sin(theta)+y[i]*cos(theta));
        x[i]=round(xx)+xc;
        y[i]=round(yy)+yc;
    }
    for(float t=0 ; t<=1; t+=0.01)
    {
        float px=(-pow(t,3)+3*pow(t,2)-3*t+1)*x[0]+(3*pow(t,3)-6*pow(t,2)+3*t)*x[1]+(-3*pow(t,3)+3*pow(t,2))*x[2]+(pow(t,3))*x[3];
        int pix=round(px);
        float py=(-pow(t,3)+3*pow(t,2)-3*t+1)*y[0]+(3*pow(t,3)-6*pow(t,2)+3*t)*y[1]+(-3*pow(t,3)+3*pow(t,2))*y[2]+(pow(t,3))*y[3];
        int piy=round(py);
        putpixel(pix,piy,WHITE);
    }
}

void eight(int xc, int yc, float theta)
{
    int lx=-12, ly=0;
    theta*=M_PI/180;
    float xx=(float)(lx*cos(theta)-ly*sin(theta));
    float yy=(float)(lx*sin(theta)+ly*cos(theta));
    lx=round(xx)+xc;
    ly=round(yy)+yc;
    line(xc,yc,lx,ly);
    int x[]={0,-6,10,20};
    int y[]={0,10,20,5};
    for(int i=0; i<4; i++)
    {
        float xx=(float)(x[i]*cos(theta)-y[i]*sin(theta));
        float yy=(float)(x[i]*sin(theta)+y[i]*cos(theta));
        x[i]=round(xx)+xc;
        y[i]=round(yy)+yc;
    }
    for(float t=0 ; t<=1; t+=0.01)
    {
        float px=(-pow(t,3)+3*pow(t,2)-3*t+1)*x[0]+(3*pow(t,3)-6*pow(t,2)+3*t)*x[1]+(-3*pow(t,3)+3*pow(t,2))*x[2]+(pow(t,3))*x[3];
        int pix=round(px);
        float py=(-pow(t,3)+3*pow(t,2)-3*t+1)*y[0]+(3*pow(t,3)-6*pow(t,2)+3*t)*y[1]+(-3*pow(t,3)+3*pow(t,2))*y[2]+(pow(t,3))*y[3];
        int piy=round(py);
        putpixel(pix,piy,WHITE);
    }
}

void three(int xc, int yc, float theta)
{
    int cx=0, cy=16, lx=0, ly=25;
    theta*=M_PI/180;
    float xx=(float)(cx*cos(theta)-cy*sin(theta));
    float yy=(float)(cx*sin(theta)+cy*cos(theta));
    cx=round(xx)+xc;
    cy=round(yy)+yc;
    circle(cx,cy,4);
    xx=(float)(lx*cos(theta)-ly*sin(theta));
    yy=(float)(lx*sin(theta)+ly*cos(theta));
    lx=round(xx)+xc;
    ly=round(yy)+yc;
    int x[]={0,20,20,0,20,20,0};
    int y[]={-22,-15,-6,0,6,15,20};
    for(int i=0; i<7; i++)
    {
        float xx=(float)(x[i]*cos(theta)-y[i]*sin(theta));
        float yy=(float)(x[i]*sin(theta)+y[i]*cos(theta));
        x[i]=round(xx)+xc;
        y[i]=round(yy)+yc;
    }
    for(float t=0 ; t<=1; t+=0.01)
    {
        float px=(-pow(t,3)+3*pow(t,2)-3*t+1)*x[0]+(3*pow(t,3)-6*pow(t,2)+3*t)*x[1]+(-3*pow(t,3)+3*pow(t,2))*x[2]+(pow(t,3))*x[3];
        int pix=round(px);
        float py=(-pow(t,3)+3*pow(t,2)-3*t+1)*y[0]+(3*pow(t,3)-6*pow(t,2)+3*t)*y[1]+(-3*pow(t,3)+3*pow(t,2))*y[2]+(pow(t,3))*y[3];
        int piy=round(py);
        putpixel(pix,piy,WHITE);
    }
    for(float t=0 ; t<=1; t+=0.01)
    {
        float px=(-pow(t,3)+3*pow(t,2)-3*t+1)*x[3]+(3*pow(t,3)-6*pow(t,2)+3*t)*x[4]+(-3*pow(t,3)+3*pow(t,2))*x[5]+(pow(t,3))*x[6];
        int pix=round(px);
        float py=(-pow(t,3)+3*pow(t,2)-3*t+1)*y[3]+(3*pow(t,3)-6*pow(t,2)+3*t)*y[4]+(-3*pow(t,3)+3*pow(t,2))*y[5]+(pow(t,3))*y[6];
        int piy=round(py);
        putpixel(pix,piy,WHITE);
    }
}

int main()
{
    int gd=DETECT,gm; char zz[]="";
    initgraph(&gd,&gm,zz);

    int cx=120, cy=220, cx3=cx+100, cx8=cx+70, cx5=cx+40, cy5=cy-13, cy3=cy-33, cy8=cy-23, rot=-30, rot5=-30, rot8=-30, rot3=-30;
    for(int k=0; k<400; k++)
    {
        cleardevice();
        if(cx+100==420)
        {
            rot3=90;
            cx3+=30;
            cy3=150;
        }
        if(cx+70==420)
        {
            rot8=90;
            cx8+=30;
            cy8=145;
        }
        if(cx+40==420)
        {
            rot5=90;
            cx5+=30;
            cy5=140;
        }
        if(cx==420)
        {
            rot=90;
            cx+=30;
            cy=1350;
        }
        if(cx+100>420)
        {
            cy3++;
            cx3--;
        }
        if(cx>420)
        {
            cy++;
            cx--;
        }
        if(cx+70>420)
        {
            cy8++;
            cx8--;
        }
        if(cx+40>420)
        {
            cy5++;
            cx5--;
        }
        one(cx,cy,rot);
        five(cx5,cy5,rot5);
        eight(cx8,cy8,rot8);
        three(cx3,cy3,rot3);
        line(120,240,420,240);
        line(420,240,420,140);
        line(420,140,120,240);
        delay(50);
        cx++;
        cx3++;
        cx5++;
        cx8++;
        if(k%3==0)
        {
            cy--;
            cy3--;
            cy8--;
            cy5--;
        }
    }
    getch();
    return 0;
}
//
