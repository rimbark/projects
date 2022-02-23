#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void set_columns(int* b, int row);
void sorting(int* b, int **a, int row);

int main() {
		int** a;
		int* b;
		int row_of_arr, randomiser, num, i, j;
		srand(time(NULL));
		  printf("Insert num: ");
		  scanf("%d", &row_of_arr);
		a = (int**)malloc(row_of_arr * sizeof(int*));
		b = (int *)malloc(row_of_arr * sizeof(int));
		set_columns(b, row_of_arr);
		for (i = 0; i < row_of_arr; i++) {
				a[i] = (int*)malloc(b[i] * sizeof(int));
				for (j = 0; j < b[i]; j++) {
						randomiser = rand();
						num = 1 + randomiser % 99;
						a[i][j] = num;
				}
		}
		sorting(b, a, row_of_arr);
		for (i = 0; i < row_of_arr; i++) {
				for (j = 0; j < b[i]; j++) {
						printf("%5d", a[i][j]);
				}
				printf("\n");
		}
		for (i = 0; i < row_of_arr; i++)
				free(a[i]);
		free(a);
		free(b);
		return 0;
}

void set_columns(int* b, int row) {
		int randomiser, col, j;
		for (int i = 0; i < row; i++) {
				randomiser = rand();
				col = 1 + randomiser % 20;
				b[i] = col;
				if (i > 0) {
						j = 0;
						while (j < i) {
								if (b[i] == b[j]) {
										j = 0;
										randomiser = rand();
										col = 1 + randomiser % 20;
										b[i] = col;
								} else {
										j++;
								}
						}
				}
		}
}
void sorting(int* b, int **a, int row) {
		int i, j, s, tmp;
		for (i = 0; i < row; i++) {
				if (i % 2 == 0) {
						for (s = 0; s < b[i]; s++) {
								for (j = b[i] - 1; j > s; j--) {
										if (a[i][j] < a[i][j - 1]) {
												tmp = a[i][j];
												a[i][j] = a[i][j - 1];
												a[i][j - 1] = tmp;
										}
								}
						}
				} else {
						for (s = 0; s < b[i]; s++) {
								for (j = b[i] - 1; j > s; j--) {
										if (a[i][j] > a[i][j - 1]) {
												tmp = a[i][j - 1];
												a[i][j - 1] = a[i][j];
												a[i][j] = tmp;
										}
								}
						}
				}
		}
}