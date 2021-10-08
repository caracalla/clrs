#pragma once

#include "array.h"
#include "heap.h"


namespace clrs {
	namespace sorting {
		// Insertion sort: Chapter 2, page 16
		void insertion(Array& array) {
			// invariant: At the start of each iteration of the for loop, the
			// subarray array[0 .. i - 1] consists of elements originally in
			// array[0 .. i - 1] but in sorted order
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
		void selection(Array& array) {
			// invariant: the subarray array[0 .. i - 1] is sorted, and all values
			// within that subarray are smaller than all values outside that subarray
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
		void mergeSort(Array& array) {
			// gotta specify the type in full, or the compiler complains since this
			// is called recursively
			using msi = std::function<void(size_t, size_t)>;
			// AND we need to do full capture
			msi mergeSortImpl = [&](size_t start, size_t end) {
				// merge subroutine
				auto merge = [&array](size_t start, size_t middle, size_t end) {
					size_t subarray_L_size = middle - start + 1;
					size_t subarray_R_size = end - middle;

					// increase size of each subarray by 1 to hold sentinel value
					Array subarray_L(subarray_L_size + 1);
					Array subarray_R(subarray_R_size + 1);

					for (size_t i = 0; i < subarray_L_size; i++) {
						subarray_L[i] = array[start + i];
					}

					for (size_t i = 0; i < subarray_R_size; i++) {
						subarray_R[i] = array[middle + i + 1];
					}

					subarray_L[subarray_L_size] = Array::upper_bound + 1;
					subarray_R[subarray_R_size] = Array::upper_bound + 1;

					int sL_idx = 0;
					int sR_idx = 0;

					// invariant: subarray array[p..k - 1] contains the k-p smallest
					// elements of both L and R, in sorted order.  L[sL_idx] and
					// R[sR_idx] are the smallest elements of each that have not been
					// copied back into array
					for (size_t i = start; i <= end; i++) {
						if (subarray_L[sL_idx] <= subarray_R[sR_idx]) {
							array[i] = subarray_L[sL_idx];
							sL_idx += 1;
						} else {

							array[i] = subarray_R[sR_idx];
							sR_idx += 1;
						}
					}
				};

				if (start < end) {
					size_t middle = (start + end) / 2;

					mergeSortImpl(start, middle);
					mergeSortImpl(middle + 1, end);
					merge(start, middle, end);
				}
			};

			mergeSortImpl(0, array.size - 1);
		}

		// Heap sort: Chapter 6, page 151
		void heapsort(Array& array) {
			Heap heap(&array);
			heap.buildMaxHeap();

			for (size_t i = heap.size - 1; i >= 1; i--) {
				heap.swap(0, i);
				heap.heap_size -= 1;
				heap.maxHeapify(0);
			}
		}
	}
}
