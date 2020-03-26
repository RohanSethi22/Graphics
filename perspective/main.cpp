
#include <iostream>
#include<conio.h>
#include <graphics.h>
#include<math.h>

using namespace std;

int round(float f)
{
    if(f>0) return (int)(f+0.5);
    else return (int)(f-0.5);
}

int main()
{
    //cleardevice();
    //int gd=DETECT,gm; char zz[]="";
    //initgraph(&gd,&gm,zz);

    int a, b, c, d, vx, vy, vz, n=0;
    cout << "Enter the coefficients of i, j, k and the constant of view plane ( ax+by+cx = d): ";
    cin >> a >> b >> c >> d;
    cout << "Enter the coordinates of the view point : ";
    cin >> vx >> vy >> vz;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the vertices in their order around the circumference." << endl;
    int *x=new int[n];
    int *y=new int[n];
    int *z=new int[n];

    for(int i=0; i<n; i++)
    {
        cout<< "Enter coordinates for vertex " << i+1 << ": ";
        cin >> x[i] >> y[i] >> z[i];
    }

    //for(int i=0; i<n-1; i++)
     //   line(x[i],y[i],x[i+1],y[i+1]);
    //line(x[0],y[0],x[n-1],y[n-1]);

    float *t=new float[n];
    int *px=new int[n];
    int *py=new int[n];
    int *pz=new int[n];

    float num=(d-a*vx-b*vy-c*vz);
    for(int i=0; i<n; i++)
    {
        float den=(a*(vx-x[i])+b*(vy-y[i])+c*(vz-z[i]));
        t[i]=(float) (num/den);
        px[i]=round(t[i]*(vx-x[i])+vx);
        py[i]=round(t[i]*(vy-y[i])+vy);
        pz[i]=round(t[i]*(vz-z[i])+vz);
    }

    cout << endl;
    for(int i=0; i<n; i++)
    {
        cout << "Point " << i+1 << ": ( " << x[i] << ", " << y[i] << ", " << z[i] << ") \t" << t[i] << "\t ( " << px[i] << ", " << py[i] << ", " << pz[i] << ")\n";
    }

    //delay(2000);

    //getch();
    //closegraph();
    return 0;
}
// 0 0 1 0 0 0 -10 4 10 10 10 10 10 100 10 -10 10 10 -10 100
