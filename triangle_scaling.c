
// Triangle Scaling

#include<stdio.h>
#include<graphics.h>



int main(){
    int x1, y1, x2, y2, x3, y3;
    int sx, sy;

    int gd=DETECT, gm;


    printf("\n Enter the coordinates of triangle : \t");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("\n Enter the Scaling factor : \t");
    scanf("%d%d", &sx, &sy);

    initgraph(&gd, &gm, "");
    draw_triangle(x1, y1, x2, y2, x3, y3);
    scale(sx, sy, x1, y1, x2, y2, x3, y3);
    getch();
    closegraph();

    return 0;


}

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3){

    line(x1,y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

}


int scale(int sx,int sy, int x1, int y1, int x2, int y2, int x3, int y3){
    int x, y, a1, a2, a3, b1, b2, b3;
    int mx, my;

    mx = (x1+x2+x3)/3;
    my = (y1+y2+y3)/3;

    a1 = mx + (x1 - mx)*sx;
    a2 = mx + (x2 - mx)*sx;
    a3 = mx + (x3 - mx)*sx;

    b1 = mx + (y1 - mx)*sy;
    b2 = mx + (y2 - mx)*sy;
    b3 = mx + (y3 - mx)*sy;

    draw_triangle(a1, b1, a2, b2, a3, b3);

    return 0;
}
