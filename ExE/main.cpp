#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include<dos.h>
#include<windows.h>
#include<math.h>
#include<fstream>
using namespace std;
int main()
{
    int hr1,hr2,xmax,ymax,i,scale,crit1,crit2,y,t,pixc1,pixc2,ytemp,dec,cont=0,per,h,t1,last,angle=0,t2=0,counter3=0,counter2=0,k2=0,k3=0,t3;
    char temp[10],f;
    initwindow(1024,700);

    xmax=1000;
    ymax=500;
loc:
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    line(40,40,40,ymax);
    line(40,ymax,xmax,ymax);


    //Scaling the Graph
    scale=0;
    for(i=ymax; i>=40; i=i-20)                                           //Scale Y-Axis
    {
        itoa(scale,temp,10);
        outtextxy(10,i,temp);
        scale=scale+10;
    }
    scale=0;
    for(i=40; i<=xmax; i=i+30)                                          //Scale X-Axis
    {
        itoa(scale,temp,10);
        outtextxy(i,ymax+8,temp);
        scale=scale+10;
    }


    //Executing Graph
    cout<<endl<<"Executing Graph...";
    srand(time(0));
    h=rand()%20+80;
    t1=0;
    last=400;
    for(i=40; i<=xmax; i++)
    {
        delay(10);
        y = 50*sin(angle*3.141/180);         // Drawing the graph
        if(t1>=h || t1==0)
        {
            t=rand()%4+1;
            t3=rand()%2+1;
            while(t==t2)
            {
                t=rand()%4+1;
            }
            if(t1!=0)
            {
                h=h+h;
            }
            if(t==1 || t==2) // Values 1 and 2 used represent heart rate is normal
            {
                setcolor(WHITE);
                settextstyle(BOLD_FONT,HORIZ_DIR,8);
                outtextxy(40,600,"Walking");
            }
            else
            {
                setcolor(WHITE);
                settextstyle(BOLD_FONT,HORIZ_DIR,8);
                switch(t3)
                {
                case 2:                // Value 2 used in case label represents acceleration less than 1.66 m/s^2
                    outtextxy(40,600,"Walking");
                    break;
                case 1:                // Value 1 used in case label represents acceleration greater than 1.66 m/s^2
                    outtextxy(40,600,"Running");
                    break;
                }
            }
            t1++;
        }
        else
        {
            t1++;
        }
        if(t==1 || t==2)
        {
            setcolor(GREEN);
            per=rand()%3+3;
            line(i,last,i+1,ymax-y-100);
            angle=angle+per;
        }
        else if(t==3)                  // Value 3 represents heart rate is high
        {
            setcolor(YELLOW);
            per=rand()%3+8;
            line(i,last,i+1,ymax-y-100);
            angle=angle+per;
            if(t2==3 || t2==4)
            {
            	if(t3==2)
            	{          // counter2 is used for finding the duration of the persistence of heart rate in yellow zone
            		counter2++;
				}
            }
            else
            {
                counter2=0;
            }
        }
        else
        {
            setcolor(RED);
            per=rand()%3+14;
            line(i,last,i+1,ymax-y-100);
            angle=angle+per;
            if(t2==4)
            {
                if(t3==2)
                {          // counter2 is used for finding the duration of the persistence of heart rate in red zone
                	counter3++;
				}
            }
            else
            {
                counter3=0;
            }
        }
        last=ymax-y-100;
        t2=t;
        if(counter2==150 && t3==2) // Condition when minor discrepancy or minor seizure occurs
        {
            system("message_relative.bat");
            delay(6000);
            k2++;
        }
        if(counter3==150 && t3==2) // Condition when major discrepancy or major seizure occurs
        {
            system("message_ambulance.bat");
            delay(6000);
            k3++;
        }
    }
    setcolor(WHITE);
    cleardevice();
    goto loc;

    while(!kbhit()) delay(1);
    return 0;
}
