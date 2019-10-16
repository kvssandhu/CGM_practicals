
// Triangle Scaling

#include<stdio.h>
#include<graphics.h>


int main(){
    int orig_tri[3][3], scaling_matrix[3][3], sx, sy, scaled_tri[3][3];
    int i, j, k;
    int gd=DETECT, gm;

    // Input the triangle matrix
    printf("\n Input the triangle matrix (row by row): \t");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d",&orig_tri[i][j]);
        };
    };
    //Enter the scaling factors
    printf("\n Enter the scaling factor : \t");
    scanf("%d%d", &sx, &sy);

    //Print Original Triangle Matrix

   // printf("\n Original Matrix : \n");
   // print_a_matrix(orig_tri);

    //Scaling Matrix
    scaling_matrix[0][0] = sx;
    scaling_matrix[1][0] = 0;
    scaling_matrix[2][0] = 0;
    scaling_matrix[0][1] = 0;
    scaling_matrix[1][1] = sy;
    scaling_matrix[2][1] = 0;
    scaling_matrix[0][2] = 0;
    scaling_matrix[1][2] = 0;
    scaling_matrix[2][2] = 1;

    //Print Scaling Matrix
   // printf("\n Scaling Matrix : \n");
    //print_a_matrix(scaling_matrix);


    // Multiplying Original Triangle matrix with scaling matrix

    for(i=0; i < 3; i++){
        for(j=0; j<3; j++){
            scaled_tri[i][j] = 0;
            for (k=0; k<3; k++) {
                scaled_tri[i][j] += orig_tri[i][k] * scaling_matrix[k][j];
            };
        };
    };

    //printf("\n Scaled Triangle : \n");
    //print_a_matrix(scaled_tri);

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

int matrix_multiplication(int A[3][3], int B[3][3]){
    int C[3][3], i, j, k;

    for(i=0; i < 3; i++){
        for(j=0; j<3; j++){
            C[i][j] = 0;
            for (k=0; k<3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
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
