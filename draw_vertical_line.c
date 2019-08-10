// Aim : To draw a vertical line

#include<stdio.h>
#include<graphics.h>

int main(){

int gd = DETECT, gm, k;
initgraph(&gd, &gm, NULL);

for(k=0; k<400; k++){
    putpixel(200,k, YELLOW);
}

getch();
closegraph();

return 0;
}
