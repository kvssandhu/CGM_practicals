// Aim : To draw a horizontal line

#include<stdio.h>
#include<graphics.h>

int main(){

int gd = DETECT, gm, k;
initgraph(&gd, &gm, NULL);

for(k=0; k<400; k++){
    putpixel(k,200, YELLOW);
}

getch();
closegraph();

return 0;
}
