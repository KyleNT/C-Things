#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

int main()
{    

   int gd = DETECT, gm;
   initgraph(&gd, &gm, "X:\\TC\\BGI");
 
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
   outtextxy(275,0,"HATATE HIMEKAIDOU GRAPH");
 
   setlinestyle(SOLID_LINE,0,2);
   /* Draw X and Y Axis */
   line(90,410,90,50);
   line(90,410,590,410);
   line(85,60,90,50);
   line(95,60,90,50);
   line(585,405,590,410);
   line(585,415,590,410);
 
   outtextxy(65,60,"Y");
   outtextxy(570,420,"X");
   outtextxy(70,415,"O");
   /* Draw bars on screen */
   setfillstyle(XHATCH_FILL, RED);
   bar(150,165,200,410);
   bar(225,175,275,410);
   bar(300,185,350,410);
   bar(375,195,425,410);
   bar(450,205,500,410);
 
   getch();
   closegraph();
   return 0;

}
