#include "array_merge.h"
#include <stdlib.h>
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values);
int getMax(int num_arrays, int* sizes);
int* getTempArray(int num_arrays, int* sizes, int** values);


int* array_merge(int num_arrays, int* sizes, int** values) {
  // This is obviously broken. It has the right type, though, eh?
  int* tempArr = getTempArray(num_arrays, sizes, values);
  int i;
  int uniques = 0;
  int offset = 0; 
  for(i = 1; i < tempArr[0]; i++) {
    if(i == 1 || tempArr[i] != tempArr[i-1]) {
      uniques ++;
    }
  }
  int* finalArray = (int*)calloc(uniques + 1, sizeof(int));
  for(i = 1; i < tempArr[0]; i++) {
    if(i == 1 || tempArr[i] != tempArr[i-1]) {
      offset ++;
      finalArray[offset] = tempArr[i];
    }
  }
  free(tempArr);
  finalArray[0] = offset;
  return finalArray;
}

int getMax(int num_arrays, int* sizes) {
  int i;
  int maxSize = 0;
  for(i = 0; i < num_arrays; i++) {
    maxSize += sizes[i];
  }
  return maxSize;
}

int* getTempArray(int num_arrays, int* sizes, int** values) {
  int i;
  int j;
  int offset = 0;
  int max = getMax(num_arrays, sizes);
  int* tempArr = (int*)calloc(max + 1, sizeof(int));
  for(i = 0; i < num_arrays; i++) {
    for(j = 0; j < sizes[i]; j++) {
      offset ++;
      tempArr[offset] = values[i][j];
    }
  }
  tempArr[0] = offset;
  mergesort(offset, &(tempArr[1]));
  return tempArr;
}
