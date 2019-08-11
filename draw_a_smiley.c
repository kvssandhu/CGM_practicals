// Aim : To draw a smiley using CG

#include<stdio.h>
#include<graphics.h>

int main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm," ");

 setcolor(YELLOW);
 //Face
 circle(300,100,40);
 setlinestyle(SOLID_LINE,0,1);
 floodfill(300,100,YELLOW);

 setcolor(BLACK);
 setlinestyle(SOLID_LINE,0,1);
 //Eyes
 fillellipse(313,90,6,6);
 fillellipse(287,90,6,6);
 //Smile
 arc(300,125,200,340,15);
 arc(300,125,200,340,16);

 getch();
 closegraph();
 return 0;
}
