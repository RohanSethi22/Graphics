#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<conio.h>
int main()
{
    int i=250,j=250,x=0,y=-1,ch;
    int gd=DETECT,gm; char zz[]="";
    initgraph(&gd,&gm,zz);
            while(1)                                                               //infinite loop
            {
                   circle(i,j,30);
                    //   outtextxy(400,400,”Press Esc to Exit…..”);
                   if(kbhit())                                            //check if a key is pressed
                           {
                                    ch=getch();
                                    if(ch==57)                           //move upward
                                     {
                                           x=0;
                                            y=-1;
                                     }

                                    if(ch==61)                           //move left
                                       {
                                                 x=-1;
                                                 y=0;
                                       }

                                    if(ch==63)                           //move right
                                       {
                                                 x=1;
                                                 y=0;
                                       }

                                    if(ch==62)                           //move downward
                                        {
                                                  x=0;
                                                  y=1;
                                        }
                                   if(ch==27)                           //exit when esc pressed
                                           exit(0);
                           }
                           i=i+x;
                           j=j+y;

                           delay(2000);
                           cleardevice();
                }
    return 0;
}
