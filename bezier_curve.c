/*

Aim : To create a curve Using Bezier Curve Algorithm
Test Case :

*/


#include<stdio.h>
#include<graphics.h>
#include<math.h>


int main(){

int gd=DETECT, gm;
int x[4], y[4], xu, yu, i=0;
float u;

printf("\n Enter 4 control points for bezier curve : \t");
for(i=0; i<4; i++) scanf("%d%d", &x[i], &y[i]);

printf("\n \n Curve is : \n ");
initgraph(&gm, &gd, " ");

for(u=0.00; u<1.0; u+=0.005){

    xu = x[0]*pow(1-u,3) + x[1]*3*u*pow(1-u,2) + x[2]*3*(1-u)*pow(u,2) + x[3];
    yu = y[0]*pow(1-u,3) + y[1]*3*u*pow(1-u,2) + y[2]*3*(1-u)*pow(u,2) * y[3];

    putpixel(xu, yu, WHITE);

}

getchar();
closegraph();

return 0;
}
