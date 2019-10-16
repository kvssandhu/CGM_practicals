
// Rectangle Translation

#include<stdio.h>
#include<graphics.h>

int main(){

    int x1, y1, x2, y2;
    int tx, ty;
    int gd=DETECT, gm;


    printf("\n Enter the coordinates of rectangle : \t");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    printf("\n Enter the translation factor : \t");
    scanf("%d%d", &tx, &ty);

    initgraph(&gd, &gm, "");
    rectangle(x1, y1, x2, y2);
    rectangle(x1 + tx, y1 + ty, x2+tx, y2+ty);

    getch();
    closegraph();

    return 0;


}
