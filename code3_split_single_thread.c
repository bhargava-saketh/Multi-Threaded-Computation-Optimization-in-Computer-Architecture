/*
Code 3 - Single-Threaded Matrix Splitting and Multiplication
This program reads data from files data1 and data2 and forms two 1000x1000 matrices mat1 and mat2.
Then it creates a single thread to perform both matrix splitting and multiplication, storing the result in the 1000x1000 matrix mat3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double mat1[1000][1000], mat2[1000][1000], mat3[1000][1000];
int m = 1000, n = 1000, p = 1000;

void* matmul(void * arg);
void split_mat1(double mat1a[500][1000], double mat1b[500][1000]);

int main(void)
{
    FILE *f;

    f = fopen("data1", "rb");
    fread(mat1, sizeof(double), sizeof(mat1) / sizeof(double), f);
    fclose(f);

    f = fopen("data2", "rb");
    fread(mat2, sizeof(double), sizeof(mat2) / sizeof(double), f);
    fclose(f);

    // Split mat1 into two parts
    double mat1a[500][1000];
    double mat1b[500][1000];
    split_mat1(mat1a, mat1b);

    pthread_t tid1;

    pthread_create(&tid1, NULL, matmul, NULL);
    pthread_join(tid1, NULL);

    printf("%lf %lf %lf %lf\n", mat3[6][0], mat3[5][3], mat3[5][4], mat3[901][7]);

    return 0;
}

void split_mat1(double mat1a[500][1000], double mat1b[500][1000])
{
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 1000; j++) {
            mat1a[i][j] = mat1[i][j];
            mat1b[i][j] = mat1[i + 500][j];
        }
    }
}

void* matmul(void * arg)
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

    pthread_exit(NULL);
}
