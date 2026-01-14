#include <stdio.h>

/* -------- Exercise 02 Functions -------- */
int add(int a, int b) {
    return a + b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

float average(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return (float)sum / n;
}

/* -------- Exercise 01 Function -------- */
void transposeMatrix(int mat[10][10], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

/* -------- Main Program -------- */
int main() {

    /* ===== Exercise 01 ===== */
    int mat[10][10];
    int n;

    printf("Enter matrix size n: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    transposeMatrix(mat, n);

    printf("Matrix a
