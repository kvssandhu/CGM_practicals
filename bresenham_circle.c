// To draw a circle using Bresenham's Circle Algorithm

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
    circle_bresenham(xc,yc, r);
    getch();
    closegraph();
    return 0;
}

int circle_bresenham(int xc, int yc, int r){

    int x=0, y =r;
    int d= 3 - 2*r;

    while(x<=y){

        draw_circle(xc,yc,x,y); //Put a point and also implement 8 way symmetry of the circle

        x++;
        if(d>0) {
                y--;
                d = d + 4*(x-y)+10;
        }
        else d = d + 4*x + 6;

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
