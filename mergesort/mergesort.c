#include "mergesort.h"
#include <stdlib.h>

void mergesort(int size, int* values) {
  mergesortRange(values, 0, size);
  return;
}

void mergesortRange(int* values, int startIndex, int endIndex) {
  int rangeSize = endIndex - startIndex;
  if needsSorting(rangeSize)) {
    int midpoint = (startIndex + endIndex) / 2;
    mergesortRange(values, startIndex, midpoint);
    mergesortRange(values, midpoint, endIndex);
    mergeRanges(values, startIndex, midpoint, endIndex);
  }
}

bool needsSorting(int rangeSize) {
  return rangeSize >= 2;
}

void mergeRange(int* values, int startIndex, int midpoint, int endIndex) {
  /* Assume the two ranges are sorted: and then merge them together */
  int rangeSize = endIndex - startIndex;
  int* destination = calloc(rangeSize, sizeof(int));
  int firstIndex = startIndex;
  int secondIndex = midpoint;
  int copyIndex = 0;
  while (firstIndex < midpoint && secondIndex < endIndex) {
    if(values[firstIndex] < values[secondIndex]) {
     destination[copyIndex] = values[firstIndex];
     ++firstIndex;
    }
    else {
      destination[copyIndex] = values[secondIndex];
      ++secondIndex;
    }
    ++copyIndex;
  }
  while(firstIndex < midpoint) {
    destination[copyIndex] = values[firstIndex];
    ++copyIndex;
    ++firstIndex;
  }
  while(secondIndex < endIndex) {
    destination[copyIndex] = values[secondIndex];
    ++copyIndex;
  }
  int i;
  for(i = 0; i < rangeSize; ++i) {
   values[i + startIndex] = destination[i]; 
  }
  free(destination);
}
