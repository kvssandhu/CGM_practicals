// Triangle Shearing

#include<stdio.h>
#include<graphics.h>


int main(){
    int orig_tri[3][3], shearing_matrix[3][3], shx, shy, scaled_tri[3][3];
    int i, j, k;
    int gd=DETECT, gm;

    // Input the triangle matrix
    printf("\n Input the triangle matrix (row by row): \t");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d",&orig_tri[i][j]);
        };
    };
    //Enter the Shearing factors
    printf("\n Enter the Shearing factor : \t");
    scanf("%d%d", &shx, &shy);

    //Print Original Triangle Matrix

   printf("\n Original Matrix : \n");
   print_a_matrix(orig_tri);

    //Scaling Matrix
    shearing_matrix[0][0] = 1;
    shearing_matrix[1][0] = shx;
    shearing_matrix[2][0] = 0;
    shearing_matrix[0][1] = shy;
    shearing_matrix[1][1] = 1;
    shearing_matrix[2][1] = 0;
    shearing_matrix[0][2] = 0;
    shearing_matrix[1][2] = 0;
    shearing_matrix[2][2] = 1;

    //Print Scaling Matrix
    printf("\n Scaling Matrix : \n");
    print_a_matrix(shearing_matrix);

    matrix_multiplication(orig_tri, shearing_matrix, scaled_tri);


    printf("\n Scaled Triangle : \n");
    print_a_matrix(scaled_tri);

    initgraph(&gd, &gm, "");

    // create the original triangle
   draw_triangle(orig_tri);

    // create the scaled triangle
   draw_triangle(scaled_tri);

    //
  //  draw_triangle(x1, y1, x2, y2, x3, y3);
//    scale(sx, sy, x1, y1, x2, y2, x3, y3);
    getchar();
   closegraph();

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
