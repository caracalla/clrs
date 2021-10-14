#pragma once

#include "random.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>


constexpr int default_lower_bound = 1;
constexpr int default_upper_bound = 99;


namespace clrs {
	struct Array {
		int lower_bound = std::numeric_limits<int>::min();
		int upper_bound = std::numeric_limits<int>::max();

		int* data;
		size_t size;

		// randomly generate an array
		static Array createRandomized(
				size_t size,
				int lower_bound = default_lower_bound,
				int upper_bound = default_upper_bound) {
			Array array;
			array.size = size;
			array.lower_bound = lower_bound;
			array.upper_bound = upper_bound;
			array.data = (int*)malloc(size * sizeof(int));
			
			for (size_t i = 0; i < size; i++) {
				array.data[i] = random::randomInt(lower_bound, upper_bound);
			}

			return array;
		}

		static Array createZeroed(size_t size) {
			Array array;
			array.size = size;
			array.data = (int*)malloc(size * sizeof(int));

			memset((void*)array.data, 0, size * sizeof(int));

			return array;
		}

		// copy from a vector (for pre-existing test data)
		static Array createCopy(std::vector<int>& predefined_values) {
			Array array;
			array.size = predefined_values.size();
			array.data = (int*)malloc(predefined_values.size() * sizeof(int));

			for (size_t i = 0; i < predefined_values.size(); i++) {
				array.data[i] = predefined_values[i];
			}

			return array;
		}

		// non-copyable
		Array(const Array&) = delete;
		Array& operator=(const Array&) = delete;

		// moveable
		Array(Array&&) = default;
		Array& operator=(Array&&) = default;

		Array() = default;

		~Array() {
			free(this->data);
		}

		void log() {
			std::cout << "[";

			for (size_t i = 0; i < this->size - 1; i++) {
				std::cout << std::setw(3) << this->data[i] << ", ";
			}

			std::cout << std::setw(3) << this->data[this->size - 1] << "]\n";
		}

		int& operator[](size_t index) {
			return this->data[index];
		}
	};
}
