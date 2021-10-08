#pragma once

#include "array.h"

#include <iostream>


namespace clrs {
	struct Heap {
		Array* array;
		size_t size;
		size_t heap_size;

		Heap(Array* array) {
			this->array = array;
			this->size = array->size;
			this->heap_size = 0;
		}

		// non-copyable
		Heap(const Heap&) =delete;
		Heap& operator=(const Heap&) =delete;

		void log() {
			this->array->log();
		}

		static size_t parent(size_t index) {
			return index / 2 - 1;
		}

		static size_t left(size_t index) {
			return index * 2 + 1;
		}

		static size_t right(size_t index) {
			return index * 2 + 2;
		}

		void swap(size_t index1, size_t index2) {
			int temp = (*this->array)[index1];
			(*this->array)[index1] = (*this->array)[index2];
			(*this->array)[index2] = temp;
		}

		void maxHeapify(size_t index) {
			size_t l = left(index);
			size_t r = right(index);

			size_t largest = index;

			if (l < this->heap_size && (*this->array)[l] > (*this->array)[largest]) {
				largest = l;
			}

			if (r < this->heap_size && (*this->array)[r] > (*this->array)[largest]) {
				largest = r;
			}

			if (largest != index) {
				this->swap(largest, index);

				this->maxHeapify(largest);
			}
		}

		void buildMaxHeap() {
			this->heap_size = this->size;

			for (int i = this->size / 2 - 1; i >= 0; i--) {
				this->maxHeapify(i);
			}
		}
	};
}
