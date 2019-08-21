#include<stdio.h>
#include<graphics.h>
#define ROUND(a) ((int) (a + 0.5))

int main(){

int xa, ya, xb, yb;
int gd=DETECT, gm;


printf("\n Enter the coordinates of initial point : \t");
scanf("%d%d", &xa, &ya);


printf("\n Enter the coordinates of final point : \t");
scanf("%d%d", &xb, &yb);
initgraph(&gd, &gm,"");
DDA(xa, ya, xb, yb);

return 0;
}

int DDA(int xa, int ya, int xb, int yb){

int dx = xb - xa, dy = yb-ya, steps, k;
float xinc, yinc, x = xa, y=ya;

if ( abs(dx) > abs(dy) ) steps = abs(dx);
else steps = abs(dy);

xinc = dx / (float) steps;
yinc = dy / (float) steps;

putpixel( ROUND(x), ROUND(y), WHITE);

for(k=0; k<steps; k++){

    x = x + xinc;
    y = y + yinc;
    putpixel( ROUND(x), ROUND(y), WHITE);
}
getch();

return 0;
}
