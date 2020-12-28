#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<dos.h>
int main()
{

	int i, j = 0, gd = 0, gm, jj =0 ,kk =0;
	initgraph(&gd, &gm, "");

	//for the road
	setcolor(WHITE);
	setlinestyle(0,0,3);
	line(0,348,640,348);

    setlinestyle(0,0,1); //thickness and line typr
	for (i = 0; i <= 420; i = i + 6)
        {

        setcolor(DARKGRAY);
        //FOR UPPER BODY
		line(0 + i, 300, 210 + i, 300);
		line(50 + i, 300, 75 + i, 270);
		line(75 + i, 270, 150 + i, 270);
		line(150 + i, 270, 165 + i, 300);
		line(0 + i, 300, 0 + i, 330);
		line(210 + i, 300, 210 + i, 330);


         setcolor(DARKGRAY);
		// For left wheel of car
		circle(65 + i, 330, 15);                  //LW = LEFT WHEEL
        line(75+ i,320,55+ i,340);            //LW right horizon
        line(55+ i,320,75+ i,340);            //LW left horizon
        line(50 + i , 330 , 80 + i , 330);    //LW horizontal
        line(65 + i,315,65 + i ,345);         //LW veritical
        if(jj == 0)
         {
             setcolor(BLACK);
             line(75+ i,320,55+ i,340);            //LW right horizon
             line(55+ i,320,75+ i,340);            //LW left horizon
             jj = 1;
         }
         else
         {
              setcolor(BLACK);
              line(50 + i , 330 , 80 + i , 330);    //LW horizontal
              line(65 + i,315,65 + i ,345);         //LW veritical
              jj = 0;
         }

         setcolor(DARKGRAY);
		// For right wheel of car
		 circle(145 + i, 330, 15);                      //RW = RIGHT WHEEL
		 line(130 + i , 330 , 160 + i , 330);    //RW horizontal
         line( 145 + i , 315 , 145 + i , 345);   //RW vertical
         line(155 + i,320,135+ i,340);           //RW right horizon
         line(135+ i,320,155+ i,340);           //RW left horizon

         if(kk == 0)
         {
             setcolor(BLACK);
             line(155 + i,320,135+ i,340);           //RW right horizon
             line(135+ i,320,155+ i,340);           //RW left horizon
             kk = 1;
         }
         else
         {
             setcolor(BLACK);
             line(130 + i , 330 , 160 + i , 330);    //RW horizontal
             line( 145 + i , 315 , 145 + i , 345);   //RW vertical
             kk = 0 ;
         }


         setcolor(DARKGRAY);
		// Line left of left wheel
		line(0 + i, 330, 50 + i, 330);

		// Line middle of both wheel
		line(80 + i, 330, 130 + i, 330);

		// Line right of right wheel
		line(210 + i, 330, 160 + i, 330);

		delay(100);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// To erase previous drawn car, draw
		// the whole car at same possition
		// but color using black

		setcolor(BLACK);

		// Lines for bonnet and body of car
		line(0 + i, 300, 210 + i, 300);
		line(50 + i, 300, 75 + i, 270);
		line(75 + i, 270, 150 + i, 270);
		line(150 + i, 270, 165 + i, 300);
		line(0 + i, 300, 0 + i, 330);
		line(210 + i, 300, 210 + i, 330);

		// Line left of left wheel
		line(0 + i, 330, 50 + i, 330);

		// Line middle of both wheel
		line(80 + i, 330, 130 + i, 330);

		// Line right of right wheel
		line(210 + i, 330, 160 + i, 330);


		circle(65 + i, 330, 15);                   //LW = left wheel
		circle(145 + i, 330, 15);                 //RW = right wheel

        line(50 + i , 330 , 80 + i , 330);    //LW horizontal
        line(65 + i,315,65 + i ,345);         //LW vertical

        line(75+ i,320,55+ i,340);            //LW right horiz
        line(55+ i,320,75+ i,340);            //LW left horizN

        line(130 + i , 330 , 160 + i , 330);          //RW horizontal
        line( 145 + i , 315 , 145 + i , 345);         // RW vertical

        line(155 + i,320,135+ i,340);                 // RW right horiz
        line(135+ i,320,155+ i,340);                  // RW left horiz

	}

	getch();
	closegraph();
	return 0;
}

