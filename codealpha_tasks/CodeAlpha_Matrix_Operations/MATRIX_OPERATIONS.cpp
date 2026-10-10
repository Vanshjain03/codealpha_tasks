/* 
 * Author: Vansh Jain
 * Task 2: Medium - Matrix Operations 
 */
#include <stdio.h>
#define MAX 10
void inputMatrix(int mat[MAX][MAX], int r, int c) {
    printf("Enter elements:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}
void displayMatrix(int mat[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
void addMatrix(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void multiplyMatrix(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void transposeMatrix(int mat[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            res[j][i] = mat[i][j];
        }
    }
}
int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], res[MAX][MAX];
    int r = 2, c = 2; // Default size for demonstration
    printf("Matrix 1 (2x2):\n");
    inputMatrix(mat1, r, c);
    printf("Matrix 2 (2x2):\n");
    inputMatrix(mat2, r, c);
    printf("\nAddition:\n");
    addMatrix(mat1, mat2, res, r, c);
    displayMatrix(res, r, c);
    printf("\nMultiplication:\n");
    multiplyMatrix(mat1, mat2, res, r, c, c);
    displayMatrix(res, r, c);
    printf("\nTranspose of Matrix 1:\n");
    transposeMatrix(mat1, res, r, c);
    displayMatrix(res, c, r);
    return 0;
}
