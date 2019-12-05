#include<stdio.h>
#include<conio.h>
#include<graphics.h>


void matrix_multi(int matA[3][3],int matB[3][3],int resultant_mat[3][3]);
void draw_triangle(int mat[3][3]);
void set_scaling_matrix(int scaling_matrix[3][3], int sx, int sy);

void set_scaling_matrix(int scaling_matrix[3][3], int sx, int sy){
scaling_matrix[0][0] = sx;
scaling_matrix[1][0] = 0;
scaling_matrix[2][0] = 0;

scaling_matrix[0][1] = 0;
scaling_matrix[1][1] = sy;
scaling_matrix[2][1] = 0;

scaling_matrix[0][2] = 0;
scaling_matrix[1][2] = 0;
scaling_matrix[2][2] = 1;

}
void draw_triangle(int mat[3][3]){
	line(mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
	line(mat[1][0], mat[1][1], mat[2][0], mat[2][1]);
	line(mat[2][0], mat[2][1], mat[0][0], mat[0][1]);
}

void matrix_multi(int matA[3][3], int matB[3][3], int resultant_mat[3][3]){

int i,j, k, sum;

for(i=0; i<3; i++){
	for(j=0; j<3; j++){
		sum = 0;
		for(k=0;k<3;k++){
			sum += matA[i][k] * matB[k][j];
		}
		resultant_mat[i][j] = sum;
	}
}

}
int main(){


int gd=DETECT, gm;
int orig_tri[3][3], scaling_matrix[3][3], scaled_tri[3][3], sx, sy;

int i, j, k;
clrscr();
initgraph(&gd, &gm, " ");

printf("\n Input the triangle matrix : ");
for(i=0; i<3; i++) for(j=0; j<3; j++) scanf("%d", &orig_tri[i][j]);

printf("\n Enter the scaling factor : ");
scanf("%d%d", &sx, &sy);

set_scaling_matrix(scaling_matrix, sx, sy);

matrix_multi(orig_tri, scaling_matrix, scaled_tri);
draw_triangle(orig_tri);
draw_triangle(scaled_tri);

getch();
closegraph();

return 0;
}