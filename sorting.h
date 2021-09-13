#pragma once

#include "array.h"


namespace clrs {
  namespace sorting {
    // invariant: At the start of each iteration of the for loop, the subarray
    // array[0 .. i - 1] consists of elements originally in array[0 .. i - 1]
    // but in sorted order
    void insertion(Array& array) {
      for (size_t i = 1; i < array.size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
          array[j + 1] = array[j];
          j -= 1;
        }

        array[j + 1] = key;
      }
    }
  }
}
