
#include <iostream>
#include<conio.h>
#include <graphics.h>
#include<math.h>

using namespace std;

void sort_edge(float E[][4], int e)
{
    for(int i=0; i<e-1; i++)
        for(int j=i+1; j<e; j++)
        if(E[j][0]<E[i][0])
        {
            float t0=E[i][0], t1=E[i][1], t2=E[i][2], t3=E[i][3];
            E[i][0]=E[j][0]; E[i][1]=E[j][1]; E[i][2]=E[j][2]; E[i][3]=E[j][3];
            E[j][0]=t0; E[j][1]=t1; E[j][2]=t2; E[j][3]=t3 ;
        }
    for(int i=0; i<e-1; i++)
        for(int j=i+1; j<e; j++)
        if( (E[j][0]==E[i][0]) && (E[j][1]<E[i][1]) )
        {
            float t0=E[i][0], t1=E[i][1], t2=E[i][2], t3=E[i][3];
            E[i][0]=E[j][0]; E[i][1]=E[j][1]; E[i][2]=E[j][2]; E[i][3]=E[j][3];
            E[j][0]=t0; E[j][1]=t1; E[j][2]=t2; E[j][3]=t3 ;
        }
     for(int i=0; i<e-1; i++)
        for(int j=i+1; j<e; j++)
        if( (E[j][0]==E[i][0]) && (E[j][1]==E[i][1]) && (E[j][2]<E[i][2]) )
        {
            float t0=E[i][0], t1=E[i][1], t2=E[i][2], t3=E[i][3];
            E[i][0]=E[j][0]; E[i][1]=E[j][1]; E[i][2]=E[j][2]; E[i][3]=E[j][3];
            E[j][0]=t0; E[j][1]=t1; E[j][2]=t2; E[j][3]=t3 ;
        }
}

int main()
{
    cleardevice();
    int n=0;
    int gd=DETECT,gm; char z[]="";
    initgraph(&gd,&gm,z);
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the vertices in their order around the circumference." << endl;
    int *x=new int[n];
    int *y=new int[n];
    float et[n][4];
    int e=0;

    for(int i=0; i<n; i++)
    {
        cout<< "Enter coordinates for vertex " << i+1 << ": ";
        cin >> x[i] >> y[i];
    }

    for(int i=0; i<n-1; i++)
        line(x[i],y[i],x[i+1],y[i+1]);

    line(x[0],y[0],x[n-1],y[n-1]);
    cout << "Creating edge table.\n";
    for(int i=0; i<n-1; i++)
    {
        if(y[i]==y[i+1])
        {
            continue;
        }
        int l=y[i]>y[i+1]?i+1:i;
        int h= 2*i+1-l;
        et[e][0]=y[l];          // current y=ymin
        et[e][1]=x[l];          // x of ymin
        et[e][2]=(float)(x[h]-x[l])/(y[h]-y[l]);        //change in x
        et[e++][3]=y[h];          // ymax
    }
    int l=0, h=0;
    if(y[0]>y[n-1])
    {
        l=n-1;
        h=0;
    }
    else{
        h=n-1;
        l=0;
    }
    et[e][0]=y[l];
    et[e][1]=x[l];
    et[e][2]=(float)(x[h]-x[l])/(y[h]-y[l]);
    et[e++][3]=y[h];

    sort_edge(et,e);
    delay(2000);

    for(int i=et[0][0]; i<et[e-1][3]; i++)
    {
        for(int j=0; j<e; j++)
        {
            if(i>=et[j][3]) //Newloop
            {
                et[j][0]=et[j][3]=-1;
            }
        }
        sort_edge(et,e);

        float *left;
        float *right;
        bool edge[e];
        for(int x=0; x<e; x++)
            edge[x]=false;
        for(int j=0; j<e; j++)
        {
            if(i>=et[j][0] && i<et[j][3] && !edge[j])
            {
                left=et[j];
                edge[j]=true;
                for(int k=j+1; k<e; k++)
                {
                    if(i>=et[k][0] && i<et[k][3] && !edge[k])
                    {
                        right=et[k];
                        edge[k]=true;
                        int l=(int) left[1]+0.5;
                        int r=(int) right[1]+0.5;
                        line(l,i,r,i);
                        left[1]+=left[2];
                        right[1]+=right[2];
                        left[0]++;
                        right[0]++;
                        break;
                    }
                }
            }
        }
    }
    getch();
    closegraph();
    return 0;
}
// 6 100 100 250 100 250 300 200 200 150 200 100 300
// 6 100 100 100 300 200 200 300 300 300 100 200 200
