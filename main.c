#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void set_columns(int* b, int row);
void initialization(int** a, int* b, int row);
void sorting(int* b, int** a, int row);
void output(int** a, int* b, int row);
void mem_free(int** a, int* b, int row);

int main() {
  int** a;
  int* b;
  int size_of_arr;
  srand(time(NULL));
  printf("Insert num (from 1 to 20): ");
  scanf("%d", &size_of_arr);
  a = (int**)malloc(size_of_arr * sizeof(int*));
  b = (int*)malloc(size_of_arr * sizeof(int));
  set_columns(b, size_of_arr);
  initialization(a, b, size_of_arr);
  sorting(b, a, size_of_arr);
  output(a, b, size_of_arr);
  mem_free(a, b, size_of_arr);
  return 0;
}

void set_columns(int* b, int row) {
  int randomiser, col, j;
  for (int i = 0; i < row; i++) {
    randomiser = rand();
    col = 1 + randomiser % 21;
    b[i] = col;
    if (i > 0) {
      j = 0;
      while (j < i) {
        if (b[i] == b[j]) {
          j = 0;
          randomiser = rand();
          col = 1 + randomiser % 21;
          b[i] = col;
        } else {
          j++;
        }
      }
    }
  }
}

void initialization(int** a, int* b, int row) {
  int randomiser, num;
  for (int i = 0; i < row; i++) {
    a[i] = (int*)malloc(b[i] * sizeof(int));
    for (int j = 0; j < b[i]; j++) {
      randomiser = rand();
      num = 1 + randomiser % 99;
      a[i][j] = num;
    }
  }
}

void sorting(int* b, int** a, int row) {
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

void output(int** a, int* b, int row) {
  for (int i = 0; i < row; i++) {
    printf("Arr size is - [%d]\n", b[i]);
    for (int j = 0; j < b[i]; j++) {
      printf("%5d", a[i][j]);
    }
    printf("\n");
  }
}

void mem_free(int** a, int* b, int row) {
  for (int i = 0; i < row; i++) free(a[i]);
  free(a);
  free(b);
}
