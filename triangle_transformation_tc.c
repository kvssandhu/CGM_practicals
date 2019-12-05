#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void matrix_multi(int matA[3][3], int matB[3][3], int resultant_mat[3][3]){

int i,j, k, sum;

for(i=0; i<3; i++){
	for(j=0; j<3; j++){
		sum = 0;
		for(k=0; k<3; k++){

		sum += matA[i][k] * matB[k][j];

		}
		resultant_mat[i][j] = sum;
	}
}
}

void set_shearing_factor(int mat[3][3], int shx, int shy){

	mat[0][0] = 1;
	mat[0][1] = shy;
	mat[0][2] = 0;

	mat[1][0] = shx;
	mat[1][1] = 1;
	mat[1][2] = 0;

	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 1;

}

void set_translation(int mat[3][3], int tx, int ty){

	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[0][2] = 0;

	mat[1][0] = 0;
	mat[1][1] = 1;
	mat[1][2] = 0;

	mat[2][0] = tx;
	mat[2][1] = ty;
	mat[2][2] = 1;


}

void set_rotation(int mat[3][3], int q){

	mat[0][0] = cos(q);
	mat[0][1] = sin(q);
	mat[0][2] = 0;

	mat[1][0] = -sin(q);
	mat[1][1] = cos(q);
	mat[1][2] = 0;

	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 1;

}

void draw_triangle(int mat[3][3]){
	line(mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
	line(mat[1][0], mat[1][1], mat[2][0], mat[2][1]);
	line(mat[2][0], mat[2][1], mat[0][0], mat[0][1]);
}

void set_reflection(int mat[3][3]){

	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[0][2] = 0;

	mat[1][0] = 0;
	mat[1][1] = -1;
	mat[1][2] = 0;

	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 1;

}
int main(){
   int gd=DETECT, gm;
   float angle;

   int orig_tri[3][3], shearing_mat[3][3], sheared_tri[3][3];
   int translation_mat_1[3][3], translation_mat_2[3][3], rotation_mat[3][3];
   int rotated_tri[3][3], reflected_tri[3][3], reflection_mat[3][3];
   int xmax, ymax;
   int i,j;
   int shx, shy;

   initgraph(&gd, &gm, " ");

   printf("\n Enter triangle matrix : ");
   for(i=0; i<3; i++) for(j=0; j<3; j++) scanf("%d", &orig_tri[i][j]);

   /* for reflection :
   xmax = getmaxx();
   ymax = getmaxy();

   line(xmax/2, 0, xmax/2, ymax);
   line(0, ymax/2, xmax, ymax/2);

   set_translation(translation_mat_1, -xmax/2, -ymax/2);
   set_reflection(reflection_mat);
   set_translation(translation_mat_2, xmax/2, ymax/2 );

   matrix_multi(orig_tri, translation_mat_1, reflected_tri);
   matrix_multi(reflected_tri, reflection_mat, reflected_tri);
   matrix_multi(reflected_tri, translation_mat_2, reflected_tri);


   draw_triangle(orig_tri);
   draw_triangle(reflected_tri);
   */

   /* for rotation :
   printf("\n Enter the Rotation angle : ");
   scanf("%d", &angle);

   angle = (angle * 3.14) / 10;

   set_translation(translation_mat_1, -orig_tri[0][0], -orig_tri[0][1]);
   set_rotation(rotation_mat, angle);
   set_translation(translation_mat_2, orig_tri[0][0], orig_tri[0][1]);

   matrix_multi(orig_tri, translation_mat_1, rotated_tri);
   matrix_multi(rotated_tri, rotation_mat, rotated_tri);
   matrix_multi(rotated_tri, translation_mat_2, rotated_tri);

   draw_triangle(orig_tri);
   draw_triangle(rotated_tri);
   */

   /*
   for shearing :

   printf("\n Enter the shearing factor : ");
   scanf("%d%d", &shx, &shy);


   set_shearing_factor(shearing_mat, shx, shy);
   matrix_multi(orig_tri, shearing_mat, sheared_tri);
   draw_triangle(orig_tri);
   draw_triangle(sheared_tri);
   */
   getch();
   closegraph();

return 0;
}