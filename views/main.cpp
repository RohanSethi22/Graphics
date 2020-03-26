#include <iostream>
#include <graphics.h>
#include<math.h>

using namespace std;

int round(float f)
{
    if(f>0) return (int)(f+0.5);
    else return (int)(f-0.5);
}

void fv(int *x, int *y, bool **E, int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(E[i][j])
                line(x[i]+getmaxx()/6,y[i]+getmaxy()/4,x[j]+getmaxx()/6,y[j]+getmaxy()/4);
}

void sv(int *y, int *z, bool **E, int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(E[i][j])
                line(-z[i]+getmaxx()/2,y[i]+getmaxy()/4,-z[j]+getmaxx()/2,y[j]+getmaxy()/4);
}

void tv(int *x, int *z, bool **E, int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(E[i][j])
                line(x[i]+5*getmaxx()/6,-z[i]+getmaxy()/4,x[j]+5*getmaxx()/6,-z[j]+getmaxy()/4);
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
                line(xx[i]+getmaxx()/6,yy[i]+3*getmaxy()/4,xx[j]+getmaxx()/6,yy[j]+3*getmaxy()/4);
}

void dv(int *x, int* y, int *z, bool **E, int n, float k)
{
    float coss=sqrt(2)*k/sqrt(2+pow(k,2));
    float sinn=sqrt(1-pow(coss,2));
    int *xx=new int[n];
    int *yy=new int[n];
    int *zz=new int[n];
    for(int j=0; j<n; j++)
    {
        float xt=(float)((x[j]-z[j])/sqrt(2));
        float zt=(float)((x[j]+z[j])/sqrt(2));
        xx[j]=round(xt);
        zz[j]=round(zt);
        float yt=(float)(y[j]*coss-zz[j]*sinn);
        yy[j]=round(yt);
    }
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(E[i][j])
                line(xx[i]+getmaxx()/2,yy[i]+3*getmaxy()/4,xx[j]+getmaxx()/2,yy[j]+3*getmaxy()/4);
}

void pv(int *x, int* y, int* z, bool **E, int n, int pz, int d)     //projectionplane at z=pz, center of projection at z=d
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
                line(xx[i]+5*getmaxx()/6,yy[i]+3*getmaxy()/4,xx[j]+5*getmaxx()/6,yy[j]+3*getmaxy()/4);
}

int main()
{
    int n=0, e=0;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the vertices: " << endl;
    int *x=new int[n];
    int *y=new int[n];
    int *z=new int[n];
    bool **E=new bool*[n];
    for(int i=0; i<n; i++)
    {
        E[i]=new bool[n];
        for(int j=0; j<n; j++)
            E[i][j]=false;
    }

    for(int i=0; i<n; i++)
    {
        cout<< "Enter coordinates for vertex " << i+1 << ": ";
        cin >> x[i] >> y[i] >> z[i];
    }

    cout << "Enter the number of edges: ";
    cin >> e;

    for(int i=0; i<e; i++)
    {
        int u, v;
        cout<< "Enter the number of starting and ending vertices for edge " << i+1 << ": ";
        cin >> u >> v;
        E[u-1][v-1]=E[v-1][u-1]=true;
    }

    float k=1; int pz=50, d=100;
    cout << "Enter value of k (ie ratio along vertical axis) for dimetric view: ";
    cin >> k;

    cout << "Enter value of projection plane (z=?) for perspective view: ";
    cin >> pz;

    cout << "Enter value center of projection for perspective view: ";
    cin >> d;

    cout << "\nPress x, y, z to rotate about the respective coordinate axes, and escape to exit.";

    int gd=DETECT,gm; char zz[]="";
    initgraph(&gd,&gm,zz);

    char ch='s';
    while(ch!=27)
    {

        int cx=getmaxx()/2, cy=getmaxy()/2;
        line(getmaxx()/3,0,getmaxx()/3,getmaxy());
        line(2*getmaxx()/3,0,2*getmaxx()/3,getmaxy());
        line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

        ch=getch();
        cleardevice();

        if(ch=='z')
            for(int j=0; j<n; j++)
            {
                float xx=(float)(x[j]*cos(45*M_PI/180)-y[j]*sin(45*M_PI/180));
                float yy=(float)(x[j]*sin(45*M_PI/180)+y[j]*cos(45*M_PI/180));
                x[j]=round(xx);
                y[j]=round(yy);
            }
        else if(ch=='x')
            for(int j=0; j<n; j++)
            {
                float zz=(float)(y[j]*sin(45*M_PI/180)+z[j]*cos(45*M_PI/180));
                float yy=(float)(y[j]*cos(45*M_PI/180)-z[j]*sin(45*M_PI/180));
                z[j]=round(zz);
                y[j]=round(yy);
            }
        else if(ch=='y')
            for(int j=0; j<n; j++)
            {
                float xx=(float)(x[j]*cos(45*M_PI/180)+z[j]*sin(45*M_PI/180));
                float zz=(float)(-x[j]*sin(45*M_PI/180)+z[j]*cos(45*M_PI/180));
                x[j]=round(xx);
                z[j]=round(zz);
            }
        else ;

        fv(x,y,E,n);
        sv(y,z,E,n);
        tv(x,z,E,n);
        iv(x,y,z,E,n);
        dv(x,y,z,E,n,k);
        pv(x,y,z,E,n,pz,d);
    }
    closegraph();
    return 0;
}

// 5 -20 20 0 20 20 0 20 -20 0 -20 -20 0 0 0 60 8 1 2 2 3 3 4 4 1 1 5 2 5 3 5 4 5 0.5
// 8 -25 -25 -25 25 -25 -25 25 25 -25 -25 25 -25 -25 -25 25 25 -25 25 25 25 25 -25 25 25 12 1 2 2 3 3 4 4 1 5 6 6 7 7 8 8 5 1 5 2 6 3 7 4 8 0.5
