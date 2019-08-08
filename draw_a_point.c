#include<stdio.h>
#include<graphics.h>

int main(){

int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);
for(int i=0; i<=400; i++){
    // Code for point
    putpixel(100,200, RED);
}
getch();
closegraph();
return 0;
}
