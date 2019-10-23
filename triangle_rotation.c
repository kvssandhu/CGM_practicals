// Rotation of a triangle

/*
Test Cases :

Sample Triangle : 100 100 1 150 200 1 200 100 1

*/

#include<stdio.h>
#include<graphics.h>
#include<math.h>


int main(){
    int orig_tri[3][3], translation_to_origin_matrix[3][3], translation_from_origin_matrix[3][3], resultant_tri[3][3];
    int i, j, k;
    int angle=0, x1, y1;
    int rotation_matrix[3][3];
    double q;
    int gd=DETECT, gm;

    // Input the triangle matrix
    printf("\n Input the triangle matrix (row by row): \t");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d",&orig_tri[i][j]);
        };
    };
    //Enter the Rotation Parameters
    printf("\n Enter the angle of rotation (Anticlockwise) ( in degrees ) : \t");
    scanf("%d", &angle);
    q = (angle* M_PI )/180;

    printf("\n Rotating Triangle by %.2f Radians \n", q);

    printf("\n Enter the coordinates of point about which rotation is to be done : \t");
    scanf("%d%d", &x1, &y1);

    //Print Original Triangle Matrix

   printf("\n Original Matrix : \n");
   print_a_matrix(orig_tri);

    printf("\n Cos(90 degree) : %.2f \n", cos(q));
    printf("\n sin(90 degree) : %.2f \n", sin(q));
    //input_a_matrix(translation_to_origin_matrix, 1,0,0,0,1,0,-x1,-y1, 1);
    // Input Translation to Origin Matrix
    translation_to_origin_matrix[0][0] = 1;
    translation_to_origin_matrix[0][1] = 0;
    translation_to_origin_matrix[0][2] = 0;

    translation_to_origin_matrix[1][0] = 0;
    translation_to_origin_matrix[1][1] = 1;
    translation_to_origin_matrix[1][2] = 0;

    translation_to_origin_matrix[2][0] = -x1;
    translation_to_origin_matrix[2][1] = -y1;
    translation_to_origin_matrix[2][2] = 1;

    // Input Rotation Matrix

    rotation_matrix[0][0] = cos(q);
    rotation_matrix[0][1] = sin(q);
    rotation_matrix[0][2] = 0;

    rotation_matrix[1][0] = -sin(q);
    rotation_matrix[1][1] = cos(q);
    rotation_matrix[1][2] = 0;

    rotation_matrix[2][0] = 0;
    rotation_matrix[2][1] = 0;
    rotation_matrix[2][2] = 1;

      // Input Translation From Origin Matrix
    translation_from_origin_matrix[0][0] = 1;
    translation_from_origin_matrix[0][1] = 0;
    translation_from_origin_matrix[0][2] = 0;

    translation_from_origin_matrix[1][0] = 0;
    translation_from_origin_matrix[1][1] = 1;
    translation_from_origin_matrix[1][2] = 0;

    translation_from_origin_matrix[2][0] = x1;
    translation_from_origin_matrix[2][1] = y1;
    translation_from_origin_matrix[2][2] = 1;


   // input_a_matrix(rotation_matrix,0,1,0,-1,0,0,0,0,1 );
   // input_a_matrix(translation_from_origin_matrix, 1,0,0,0,1,0,x1,y1,1);

   printf("\n Translation to origin Matrix : \n");
   print_a_matrix(translation_to_origin_matrix);

   printf("\n Rotation Matrix : \n");
   print_a_matrix(rotation_matrix);

   printf("\n Translation from Origin Matrix : \n");
   print_a_matrix(translation_from_origin_matrix);


    matrix_multiplication(orig_tri, translation_to_origin_matrix, resultant_tri);
    printf("\n Printing Triangle x Translation to origin : \n");
    print_a_matrix(resultant_tri);

    matrix_multiplication(resultant_tri, rotation_matrix, resultant_tri);
    printf("\n Printing Triangle x Translation to Origin x Rotation : \n");
    print_a_matrix(resultant_tri);

    matrix_multiplication(resultant_tri, translation_from_origin_matrix, resultant_tri);


    printf("\n Printing Triangle x Translation to Origin x Rotation x Translation from Origin : \n");
    print_a_matrix(resultant_tri);

   //initgraph(&gd, &gm, "");

    // create the original triangle
    //draw_triangle(orig_tri);

    // create the scaled triangle
    //draw_triangle(resultant_tri);

    getchar();
    //closegraph();

    return 0;


}

void draw_triangle(int triangle[3][3]){
    int x1, x2, x3, y1, y2, y3;

    x1 = triangle[0][0];
    x2 = triangle[1][0];
    x3 = triangle[2][0];

    y1 = triangle[0][1];
    y2 = triangle[1][1];
    y3 = triangle[2][1];


    line(x1,y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

}
int matrix_multiplication(int matrix_1[3][3], int matrix_2[3][3], int resultant_matrix[3][3]){
    int i, j, k;

    for(i=0; i < 3; i++){
        for(j=0; j<3; j++){
            resultant_matrix[i][j] = 0;
            for (k=0; k<3; k++) {
                resultant_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }

    return 0;
}

int print_a_matrix(int A[3][3]){

    int i, j;

    for(i=0; i<3; i++) {
        printf("\n");
        for(j=0;j<3;j++){ printf("\t %d", A[i][j]);
        }
        };

    return 0;
}
//
//int input_a_matrix(double matrix[3][3], double a00, double a01, double a02, double a10, double a11, double a12, double a20, double a21, double a22){
//
//    matrix[0][0] = a00;
//    matrix[0][1] = a01;
//    matrix[0][2] = a02;
//
//    matrix[1][0] = a10;
//    matrix[1][1] = a11;
//    matrix[1][2] = a12;
//
//    matrix[2][0] = a20;
//    matrix[2][1] = a21;
//    matrix[2][2] = a22;
//
//return 0;
//}
