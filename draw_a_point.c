// Aim : To draw a point

#include<stdio.h>
#include<graphics.h>

int main(){

int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);
putpixel(200,200, YELLOW);
getch();
closegraph();
return 0;
}
