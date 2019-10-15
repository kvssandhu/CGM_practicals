// Cohen Sutherland Algo


#include<stdio.h>
#include<graphics.h>

int main(){

    int xmin, ymin, xmax, ymax;
    int x1, y1, x2, y2;
    int gd=DETECT, gm;


    printf("\n Enter the values of x-min, x-max, y-min, y-max : \t ");
    scanf("%d%d%d%d", &xmin, &xmax, &ymin, &ymax);


    printf("\n Enter the initial coordinates of line : \t");
    scanf("%d%d", &x1, &y1);

    printf("\n Enter the final coordinate of line : \t");
    scanf("%d%d", &x2, &y2);


    initgraph(&gd, &gm, "");

    draw_rectangle(xmin, xmax, ymin, ymax);
    check_line(x1, y1, x2, y2, xmin, xmax, ymin, ymax);
    line(x1,y1,x2,y2);
    getch();
    closegraph();

    return 0;
}


int draw_rectangle(int xmin, int xmax, int ymin, int ymax){

    int i;

    for (i=xmin; i < xmax; i++){
    putpixel(i, ymin, WHITE);
    putpixel(i, ymax, WHITE);
    };


    for (i=ymin; i < ymax; i++){
    putpixel(xmin, i, WHITE);
    putpixel(xmax, i, WHITE);
    };



    return 0;
}

int check_line(int x1, int y1, int x2, int y2, int xmin,int xmax,int ymin,int ymax){

    int a0, a1, a2, a3;
    int b0, b1, b2, b3;

    // Calculating bits for initial point of the line
    a0 = sign(y1 - ymax);
    a1 = sign(ymin - y1);
    a2 = sign(x1 - xmax);
    a3 = sign(xmin - x1);

    // Calculating bits for final point of the line
    b0 = sign(y2 - ymax);
    b1 = sign(ymin - y2);
    b2 = sign(x2 - xmax);
    b3 = sign(xmin - x2);


    // Checking if line is visible, not visible, or clipping candidate
    printf("\n Bits for initial coordinate : %d %d %d %d \n", a0, a1, a2, a3);
    printf("\n Bits for final coordinate : %d %d %d %d \n", b0, b1, b2, b3);

    if ( a0==0 && a1==0 && a2==0 && a3==0 && b0==0 && b1==0 && b2==0 && b3==0 ) printf("\n Line will be completely visible");
    else if ( ( a0&b0 || a1&b1 || a2&b2 || a3&b3 ) == 0 ) printf("\n Line will be a clipping candidate");
    else printf("\n Line will be not Visible");

    return 0;
}

int sign(int value){
    return (value < 0) ? 0 : 1;
}
