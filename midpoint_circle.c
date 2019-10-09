// To draw a circle using Midpoint Circle Algorithm

#include<stdio.h>
#include<graphics.h>

int main(){

    int xc, yc, r;
    int gd=DETECT, gm;

    printf("\n Enter the coordinates of the center of the circle : \t ");
    scanf("%d%d", &xc, &yc);

    printf("\n Enter the radius of the circle : \t");
    scanf("%d", &r);

    initgraph(&gd, &gm, " ");
    midpoint_circle(xc,yc, r);
    getch();
    closegraph();
    return 0;
}

int midpoint_circle(int xc, int yc, int r){

    int x=0, y =r;
    int p = 1 - r;

    while(x<=y){

        draw_circle(xc,yc,x,y); //Put a point and also implement 8 way symmetry of the circle

        x++;
        if(p>0) {
                y--;
                p = p + 2*(x+1) +1 -2*(y-1);
        }
        else p = p + 2*x + 3;

    }

    return 0;
}

void draw_circle(int xc, int yc, int x, int y){

    putpixel(xc + x, yc + y,RED);
    putpixel(xc + x, yc - y,RED);
    putpixel(xc - x, yc + y,RED);
    putpixel(xc - x, yc - y,RED);
    putpixel(xc + y, yc + x,RED);
    putpixel(xc + y, yc - x,RED);
    putpixel(xc - y, yc + x,RED);
    putpixel(xc - y, yc - x,RED);

}

