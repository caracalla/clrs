#pragma once

#include "array.h"
#include "heap.h"


namespace clrs {
  namespace sorting {
    // Insertion sort: Chapter 2, page 16
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

    // Selection sort: Chapter 2, page 29
    // invariant: the subarray array[0 .. i - 1] is sorted, and all values
    // within that subarray are smaller than all values outside that subarray
    void selection(Array& array) {
      for (size_t i = 0; i < array.size - 1; i++) {
        int current = array[i];
        int min_index = i;

        for (size_t j = i + 1; j < array.size; j++) {
          if (array[j] < array[min_index]) {
            min_index = j;
          }
        }

        array[i] = array[min_index];
        array[min_index] = current;
      }
    }

    // Merge sort: Chapter 2, page 30
    // Array mergeSort(Array& array) {

    // }

    // Heap sort: Chapter 6, page 151
    void heapsort(Array& array) {
      Heap heap(&array);
      heap.buildMaxHeap();

      for (int i = heap.size - 1; i >= 1; i--) {
        heap.swap(0, i);
        heap.heap_size -= 1;
        heap.maxHeapify(0);
      }
    }
  }
}
