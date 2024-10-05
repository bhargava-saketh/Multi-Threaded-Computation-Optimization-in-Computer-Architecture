/*
Code 1 - Single-Threaded Matrix Multiplication
This program reads data from files data1 and data2 and forms two 1000x1000 matrices mat1 and mat2.
The function "matmul" multiplies the two matrices and stores the result in the 1000x1000 matrix mat3.
*/

#include <stdio.h>
#include <stdlib.h>

double mat1[1000][1000], mat2[1000][1000], mat3[1000][1000];
int m = 1000, n = 1000, p = 1000;

void matmul(void);

int main(void)
{
    FILE *f;

    f = fopen("data1", "rb");
    fread(mat1, sizeof(double), sizeof(mat1) / sizeof(double), f);
    fclose(f);

    f = fopen("data2", "rb");
    fread(mat2, sizeof(double), sizeof(mat2) / sizeof(double), f);
    fclose(f);

    matmul();

    printf("%lf %lf %lf %lf\n", mat3[6][0], mat3[5][3], mat3[5][4], mat3[901][7]);

    return 0;
}

void matmul(void) 
{ 
    int i, j, k; 
    double sum = 0;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            for (k = 0; k < n; k++) {
                sum = sum + mat1[i][k] * mat2[k][j];
            }
 
            mat3[i][j] = sum;
            sum = 0;
        }
    }
}
