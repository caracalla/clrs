#pragma once

#include "random.h"

#include <iostream>


namespace clrs {
	struct Array {
		static constexpr int element_lower_bound = 1;
		static constexpr int element_upper_bound = 99;

		int* data;
		size_t size;

		// randomly generate an array
		Array(size_t size) {
			this->size = size;
			data = (int*)malloc(size * sizeof(int));
			
			for (size_t i = 0; i < size; i++) {
				data[i] = random::randomInt(element_lower_bound, element_upper_bound);
			}
		}

		// non-copyable
		Array(const Array&) =delete;
  	Array& operator=(const Array&) =delete;

		~Array() {
			free(this->data);
		}

		void log() {
			std::cout << "[";

			for (size_t i = 0; i < this->size - 1; i++) {
				std::cout << this->data[i] << ", ";
			}

			std::cout << this->data[this->size - 1] << "]\n";
		}

		int& operator[](size_t index) {
			return this->data[index];
		}
	};
}