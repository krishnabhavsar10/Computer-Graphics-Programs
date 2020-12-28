//THE SNAKE GAME
#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

int endfunc(int e , int a);

int main()
{
    int gd ,gm ,rx=200 ,ry=200 ,d = 1 ;
    int speed =  5;
    int colour = 1 ;
    int  x[200] = {0} , y[200] = {0};
    x[0]=200,y[0]=200;                                                   //initial coordinate
    int f =1;                                                                      //f = food
    int chk = 700;                                                            //check
    int dir = 1;                                                                  //Initial direction in right
    detectgraph(&gd,&gm);                                           //DETECTING THE GRAPHICS DRIVE AVALIABLE
    initgraph(&gd,&gm,"");                                            //FORMING THE GRAPHICS CONSOLE
    srand(time(0));                                                          //To randomize the coordinate of the food.
    int length = 1;                                                           //Initial length of snake

   settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
   outtextxy(100,220,"Press any key to start the game.");
   outtext("Welcome to the Snake game.");
   moveto(0, 20);
   outtext("Don't touch the Wall and Don't try to eat yourself.");
   moveto(0, 40);
   outtext("ENJOY");
   getch();
   setviewport(0,0,640,480,1);

    for(;;)
    {
        setfillstyle(1,0);                                                     //for creating the background black
        bar(0,0,640,480);

        setfillstyle(1,7);                                                     //creating the boundaries
        bar(0,0,640,10);
        bar(0,0,10,480);
        bar(0,480,640,470);
        bar(630,10,640,480);

        // food taken
        if(x[0]==rx && y[0]==ry )
        {
            length++;
            colour++;                                       //changing the colours of the food.

            f=f+1;                                             // incrementing the food value
            setfillstyle(1,0);                            //BLACK FILLSTYLE ..hence we are putting a black box over it to make it disappear.
            bar(rx,ry,rx+10,ry+10);                //it will be a block of (10 x 10) but its position is going to change

            do //creating random location
            {
                rx = (10+rand()%620);
                ry = (10+rand()%460);
            }while(getpixel(rx,ry)!=0 && rx > 10&& ry > 10);  //As the food cannot appear on the boundary/wall.
            //making it multiple of 10 as its a block of 10 x 10 else it will change its shape.
            //also this will divide the screen into the blocks of 10.
            rx=rx/10;
            rx=rx*10;
            ry=ry/10;
            ry=ry*10;
        }
        if(15 <= colour)
            colour = 1;
        setfillstyle(1,colour);
        bar(rx,ry,rx+10,ry+10);

        setfillstyle(1,5);
        //for detecting the key presses.
        if(dir == 1)
        {
            //initially in this state snake is moving right so left key is stroke is disabled
            if(GetAsyncKeyState(VK_RIGHT)){d=1;}
            else if(GetAsyncKeyState(VK_UP)){ d=3;}
            else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
            else{d=0;}

        }else if(dir == 2)
          {
               // In this state snake is moving in left so right key is stroke is disabled
                if(GetAsyncKeyState(VK_LEFT)){ d=2;}
                else if(GetAsyncKeyState(VK_UP)){ d=3;}
                else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
                else{d=0;}

        } else if(dir == 3)
            {
                    //In this state snake is moving up so down key stroke is disabled
                    if(GetAsyncKeyState(VK_RIGHT)){d=1;}
                    else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
                    else if(GetAsyncKeyState(VK_UP)){ d=3;}
                    else{d=0;}

            }else if(dir == 4)
                {
                        //In this state snake is moving down so up key stroke is disabled
                        if(GetAsyncKeyState(VK_RIGHT)){d=1;}
                        else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
                        else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
                        else{d=0;}

                }

        switch(d)
        {
                case 0:         //default case when no key is pressed.
                    if(dir==1){x[0]=x[0]+(10 );}
                    else if(dir==2){x[0]=x[0]-(10);}
                    else if(dir==3){ y[0]=y[0]-(10);}
                    else if(dir==4) {y[0]=y[0]+(10);}
                    break;
                case 1:        //when Right arrow key is pressed the logic for it
                    x[0]=x[0]+10;
                    dir=1;
                    break;
                case 2:        //when left arrow key is pressed the logic for it
                    x[0]= x[0]-10;
                    dir=2;
                    break;
                case 3:        //when up arrow key is pressed the logic for it
                    y[0]=y[0]-10;
                    dir=3;
                    break;
                case 4:       //when down key is pressed the logic for it
                    y[0]= y[0]+10;
                    dir=4;
                    break;
        }

        for(int i = 0; i < length;i++)   //for printing/displaying the snake.
            {
                bar(x[i],y[i],x[i]+10,y[i]+10);
            }

        for(int i= 199; i >0;i--)
            {
                x[i] = x[i-1];
                y[i] = y[i-1];
            }

        delay(100);
        if(x[0] >= 630 || x[0]<=10|| y[0]<=10 || y[0]>=470)
        {
            endfunc(f,0);
            break;
        }
       //if snake try's  to eat itself.
        for(int i = 2; i < length;i++)
        {
            if(x[0] == x[i] && y[0] == y[i])
            {
                chk = i;
                break;
            }
        }
        if(x[0] == x[chk] && y[0] == y[chk])
        {
            endfunc(f,1);
            break;
        }
    }
}

//when you touch the wall ans your own body
int endfunc(int e,int a)
{
    setfillstyle(1,5);
    e=e-2;
    bar(0,0,640,470);
    system("cls");
    if(a == 0){
        printf("You died outside the boundary!!!\n");
    }
    else if(a== 1){
        printf("You bite yourself gg !!!\n");
    }
    printf("Your score is : %d\n", e);
    getch();
    return 0;
}
