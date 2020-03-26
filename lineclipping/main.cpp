#include <iostream>
#include<conio.h>
#include <graphics.h>
#include<math.h>

using namespace std;

struct ans{

float v;
bool ent=false, ex=false;
};

void sortmy(ans* a, int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(a[j].v<a[i].v)
            {
                ans temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
}

int main()
{
    int n=0;
    int gd=DETECT, gm;
    char z[]="";
    initgraph(&gd,&gm,z);
    cleardevice();
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the vertices in ANTI-CLOCKWISE order around the circumference." << endl;
    int *x=new int[n];
    int *y=new int[n];
    int et[n][4];
    ans *t=new ans[n];
    bool start=false, ends=false; // starts/ends with p1/p2
    for(int i=0; i<n; i++)
    {
        cout<< "Enter coordinates for vertex " << i+1 << ": ";
        cin >> x[i] >> y[i];
    }

    for(int i=0; i<n-1; i++)
        line(x[i],y[i],x[i+1],y[i+1]);
    line(x[0],y[0],x[n-1],y[n-1]);

    cout << "Enter the end points of the line to be clipped :" << endl;
    int x1, x2, y1, y2;
    cout<< "Enter coordinates for first end point " << ": ";
    cin >> x1 >> y1;
    cout<< "Enter coordinates for second end point " << ": ";
    cin >> x2 >> y2;

    setcolor(BLUE);
    line(x1,y1,x2,y2);

    cout << "Creating edge table.\n";
    for(int i=0; i<n-1; i++)
    {
        et[i][0]=x[i+1]-x[i];          // edge vector i
        et[i][1]=y[i+1]-y[i];          // edge vector j
        et[i][2]=-et[i][1];        // normal vector i
        et[i][3]=et[i][0];          // normal vector j
    }
    et[n-1][0]=x[0]-x[n-1];          // edge vector i
    et[n-1][1]=y[0]-y[n-1];          // edge vector j
    et[n-1][2]=-et[n-1][1];        // normal vector i
    et[n-1][3]=et[n-1][0];          // normal vector j

    for (int i=0; i<n; i++)
    {
        float num= (x[i]-x1)*et[i][2] + (y[i]-y1)*et[i][3];
        float den= (x2-x1)*et[i][2] + (y2-y1)*et[i][3];
        if(den>0)
        {
            t[i].ent=true;
            t[i].ex=false;
        }
        else if(den<0)
        {
            t[i].ex=true;
            t[i].ent=false;
        }
        t[i].v=(float) (num/den);
    }

    sortmy(t,n);

    setcolor(YELLOW);

    int starting=0, ending=0;
    for(int i=0; i<n; i++)
    if(t[i].v>=0 && t[i].v<=1)
    {
        starting=i;
        if(t[i].ex)
        {
            start=true;
            int x=(int) (t[i].v*(x2-x1)+0.5),y=(int) (t[i].v*(y2-y1)+0.5);
            line(x1,y1,x1+x,y1+y);
        }
        break;
    }

    for(int i=starting; i<n; i++)
    if(t[i].v>=0 && t[i].v<=1 && t[i].ent)
    {
        for(int j=i+1; j<n; j++)
        {
            if(t[i].v>=0 && t[i].v<=1 && t[j].ex)
            {
                int x=(int) (t[i].v*(x2-x1)+0.5),y=(int) (t[i].v*(y2-y1)+0.5);
                int xx=(int) (t[j].v*(x2-x1)+0.5),yy=(int) (t[j].v*(y2-y1)+0.5);
                line(x1+x,y1+y,x1+xx,y1+yy);
                break;
            }
        }
    }

    for(int i=n-1; i>=0; i--)
    if(t[i].v>=0 && t[i].v<=1)
    {
        ending=i;
        if(t[i].ent)
        {
            ends=true;
            int x=(int) (t[i].v*(x2-x1)+0.5),y=(int) (t[i].v*(y2-y1)+0.5);
            line(x1+x,y1+y,x2,y2);
        }
        break;
    }

    cout << "The intersection points are - \n";

    for(int i=0; i<n; i++)
    {
        if(t[i].v>=0 && t[i].v<=1)
        {
            int x=(int) (t[i].v*(x2-x1)+0.5),y=(int) (t[i].v*(y2-y1)+0.5);
            putpixel(x1+x,y1+y,GREEN);
            setcolor(GREEN);
            circle(x1+x,y1+y,2);
            setcolor(YELLOW);
            circle(x1+x,y1+y,5);
            cout << "\t" << x1+x << "\t" << y1+y << endl;
        }
    }

    getch();
    closegraph();
    return 0;
}
