#include <iostream>
#include<graphics.h>

using namespace std;

int main()
{
    int gd=DETECT,gm; char zz[]="";
    initgraph(&gd,&gm,zz);

    int n=0, e=0;
    int px=0, py=0, pz=100;     // view point = (0,0,100)
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

    for(int i=0; i<n; i++)
    {
        int v1i=x[(i+1)%n]-x[i], v1j=y[(i+1)%n]-y[i], v1k=z[(i+1)%n]-z[i];      //AB
        int v2i=x[(i+2)%n]-x[i], v2j=y[(i+2)%n]-y[i], v2k=z[(i+2)%n]-z[i];      //AC
        int ni=v1j*v2k-v1k*v2j, nj=v1k*v2i-v1i*v2k, nk=v1i*v2j-v1j*v2i;     //Normal ABxAC
        int mx=(x[i]+x[(i+1)%n]+x[(i+2)%n])/3, my=(y[i]+y[(i+1)%n]+y[(i+2)%n])/3, mz=(z[i]+z[(i+1)%n]+z[(i+2)%n])/3;
        int mpx=mx-x[(i+3)%n], mpy=my-y[(i+3)%n], mpz=mz-z[(i+3)%n];      //EM
        if((ni*mpx+nj*mpy+nk*mpz)<0)
        {
            ni=-ni;
            nj=-nj;
            nk=-nk;
        }
        mx-=px;
        my-=py;
        mz-=pz;     //PM
        if((mx*ni+my*nj+mz*nk)>0)
            setlinestyle(DASHED_LINE, 1, 1);
        else
            setlinestyle(SOLID_LINE,1,1);
        if(E[i][(i+1)%n])
        {
            line(x[i]+getmaxx()/2,y[i]+getmaxy()/2,x[(i+1)%n]+getmaxx()/2,y[(i+1)%n]+getmaxy()/2);
            E[i][(i+1)%n]=E[(i+1)%n][i]=false;
        }
        if(E[(i+1)%n][(i+2)%n])
        {
            line(x[(i+1)%n]+getmaxx()/2,y[(i+1)%n]+getmaxy()/2,x[(i+2)%n]+getmaxx()/2,y[(i+2)%n]+getmaxy()/2);
            E[(i+1)%n][(i+2)%n]=E[(i+2)%n][(i+1)%n]=false;
        }
        if(E[(i+2)%n][i])
        {
            line(x[(i+2)%n]+getmaxx()/2,y[(i+2)%n]+getmaxy()/2,x[i]+getmaxx()/2,y[i]+getmaxy()/2);
            E[(i+2)%n][i]=E[i][(i+2)%n]=false;
        }
    }
    getch();
    return 0;
}
// 4 -100 -100 0 100 -100 0 0 200 0 0 0 -100 6 1 2 2 3 3 1 1 4 2 4 3 4
