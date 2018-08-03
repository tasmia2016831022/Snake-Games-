#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;

                        // Prototype of Functions:

void check();
void finish();
void win();

                        //Declaration of GLOBAL VARIABLES.

int m[500],n[500],size_ = 5,score = 0,tim,high;
clock_t start,stop;



int  main()
{
    freopen("GameData.dat","r",stdin);
    cin >> high;
    int gd=DETECT,gm,maxx,maxy,x=13,y=14,p,q,spd=90;
    char ch;
    initgraph(&gd,&gm,"c:\\TC\\BGI");

    //This is the HOMWE page design:

    setcolor(GREEN);
    settextstyle(3,0,6);
    outtextxy(150,2,"SNAKE GAME ");
    setcolor(3);
    settextstyle(3,0,1);
    outtextxy(20,80," Use Arrow Keys To Direct The Snake ");
    outtextxy(20,140," Avoid The Head Of Snake Not To Hit Any Part Of Snake");
    outtextxy(20,170," Pick The Beats Untill You Win The Game ");
    outtextxy(20,220," Press 'Esc' Anytime To Exit ");
    outtextxy(20,250," Press Any Key To Continue ");
    outtextxy(20,280," Collect 100 to WIN the Game ");

    // Press any key without ESC to start the game:

    ch=getch();
    if(ch==27)
        exit(0);
    cleardevice();

    // Starting of Game Logic:

    maxx=getmaxx();
    maxy=getmaxy();
    p=rand() % maxx;
    int temp=p%13;
    p=p-temp;
    q=rand() % maxy;
    temp=q%14;
    q=q-temp;


    start=clock();
    int a=4,i=0,j,t;
    bool isbonus = false;
    int bonus = 500;
    while(1)
    {

    /*setcolor(WHITE);
    setfillstyle(SOLID_FILL,con+5);
    circle(p,q,5);
    floodfill(p,q,WHITE);*/
    if(score>0 &&   score%5==4)
    {
        isbonus = true;
    }
    else{
        bonus = 500;
        isbonus = false;
 }

 if(isbonus==false || bonus == 0){
 setcolor(BLACK);
 outtextxy(250,10,"Hurry!!");

 setcolor(WHITE);
 setfillstyle(SOLID_FILL,WHITE);
 circle(p,q,5); //x position,y position,size
 floodfill(p,q,WHITE);
 }
 else
 {
 setcolor(RED);
 setfillstyle(SOLID_FILL,RED);
 circle(p,q,5);
 floodfill(p,q,RED);

 char spp[1000];
 setcolor(BLACK);
 sprintf(spp,"Hurry!! %d",bonus);
 outtextxy(250,10,"Hurry!!");
 setcolor(MAGENTA);
 outtextxy(250,10,spp);
// clears
 }
                        //Structure of Game Page:
        setcolor(RED);
        setfillstyle(SOLID_LINE,RED);
        rectangle(0,0,645,475);
        setcolor(GREEN);
        circle(p,q,5);
        floodfill(p,q,GREEN);
        setcolor(YELLOW);
        char arr[1000];
        sprintf(arr,"Your Score: %d ",score);
        settextstyle(3,0,1);
        outtextxy(500,10,arr);

        if(score>high)
            high = score;
        char arre[1000];
        sprintf(arre,"High Score: %d ",high);
        outtextxy(500,30,arre);
                        //Control KEY:

        if( kbhit() )
        {
            ch=getch();
            if(ch==0)
                ch=getch();
            if(ch==72&& a!=2)
                a=1;
            if(ch==80&& a!=1)
                a=2;
            if(ch==75&& a!=4)
                a=3;
            if(ch==77&& a!=3)
                a=4;
        }
        else
        {
            if(ch==27)
                break;
        }

        if(i<20)
        {
 		   m[i]=x-260;
 		   n[i]=y-280;
 		   i++;
        }

        if(i>=20)
        {
            for(j=size_-2;j>=0;j--)
            {
                m[1+j]=m[j];
                n[1+j]=n[j];
            }
		    m[0]=x;
		    n[0]=y;
		   /*setcolor(YELLOW);
		   setfillstyle(SOLID_LINE,RED);
		   rectangle(0,0,650,480);
           circle(m[0],n[0],8);
		   floodfill(m[0],n[0],WHITE);*/


                      // Game Interface Structure:
            setcolor(RED);  //HEAD OF SNAKE
            setfillstyle(SOLID_FILL,GREEN);
            circle(m[0],n[0],8);
            floodfill(m[0],n[0],RED);
            setcolor(GREEN);
		    for(j=1;j<size_;j++)
            {
                setfillstyle(SOLID_FILL,BLACK);
                circle(m[j],n[j],5);
                floodfill(m[j],n[j],GREEN);
            }
            delay(spd);
            //clearviewport();
            setcolor(BLACK);
            setfillstyle(SOLID_FILL,BLACK);
            //clearviewport();
            circle(m[0],n[0],8);
            floodfill(m[0],n[0],BLACK);
		   setcolor(BLACK);
		   setfillstyle(SOLID_FILL,BLACK);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],BLACK);
		   clearviewport();

        }
        stop=clock();
        t=(stop-start)/CLK_TCK;
        tim=t;
        //printf(" TIME %d sec   ",t);
        //score = 0;
        //printf("SCORE %d",con-5);
        check();

        if(x==p&&y==q)
        {
            //con=con+1;
            size_++;
            score++;
                if(score%5==0 && score>0)score+=bonus;
            if(spd>=13)
                spd=spd-3;
            else
                spd=10;
            if(score>1000)
                win();
            p=rand() % maxx;
            temp=p%13;
            p=p-temp;
            q=rand() % maxy;
            temp=q%14;
            q=q-temp;
        }
        if(a==1)
            y =  y-14;
            if(y<0)
            {
                temp=maxy%14;
                y=maxy-temp;
            }
        if(a==2)
            y =  y+14;
        if(y>maxy)
            y=0;
        if(a==3)
            x =  x-13;
        if(x<0)
        {
            temp=maxx%13;
            x=maxx-temp;
        }
        if(a==4)
            x =  x+13;
        if(x>maxx)
            x=0;
        if(a==0)
        {
            y = y+14 ;
            x=x+13;
        }
        if(isbonus){
    if(bonus>0)
    bonus-=10;
        }
    }

 }

                      //CHECK FUNCTION:

void check()
{
    int a;
    for(a=1;a<size_;a++)

    if(m[0]==m[a] && n[0]==n[a])
        finish();
    else
        continue;
   }

                      //GAME END FUNCTION:

void finish()

{

    freopen("GameData.dat","w",stdout);
    int j,i;
    setcolor(WHITE);
    for(i=0;i<5;i++)
    {
        delay(500);
        cleardevice();
        delay(500);
        for(j=0;j<=size_;j++)
        {
            setfillstyle(SOLID_FILL,RED);
            circle(m[j],n[j],5);
            floodfill(m[j],n[j],WHITE);
        }

    }
    clearviewport();
    setcolor(YELLOW);
    settextstyle(3,0,4);
    outtextxy(150,150,"     GAME OVER ");
    char arr[1000];
    sprintf(arr,"  YOUR SCORE: %d ",score);
    outtextxy(150,200,arr);
    char arre[1000];
    sprintf(arre,"  High: %d",high);
    outtextxy(150,250,arre);
    if(high < score)
    cout << score << endl;
    else cout << high << endl;
    setcolor(RED);

    settextstyle(3,0,1);
    outtextxy(400,420,"Press Any KEY to EXIT");
    getch();
    exit(0);
}

                        //WIN FUNCTION:

void win()
{
    int j,i;
    setcolor(WHITE);
    for(i=0;i<5;i++)
    {
        for(j=0;j<=size_;j++)
        {
            setfillstyle(SOLID_FILL,WHITE);
            circle(m[j],n[j],5);
            floodfill(m[j],n[j],WHITE);
        }
        delay(500);
        cleardevice();
        delay(500);
    }
    setcolor(RED);
    settextstyle(6,0,3);
    outtextxy(140,120," CONGRATULATION ");
    outtextxy(210,220," YOU WIN ");
    settextstyle(3,0,1);
    outtextxy(400,420,"Press Any KEY to EXIT");
    delay(500);
    getch();
    exit(0);
}
