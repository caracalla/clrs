#include "array.h"
#include "heap.h"
#include "random.h"
#include "searching.h"
#include "sorting.h"

namespace clrs {
	void demoInsertionSort() {
		std::cout << "\n****************************************************************************************\n";
		std::cout << "insertion sort:\n";
		std::cout << "****************************************************************************************\n";
		Array arr = Array::createRandomized(15);
		arr.log();

		sorting::insertion(arr);
		arr.log();
	}


	void demoSelectionSort() {
		std::cout << "\n****************************************************************************************\n";
		std::cout << "selection sort:\n";
		std::cout << "****************************************************************************************\n";
		Array arr = Array::createRandomized(15);
		arr.log();

		sorting::selection(arr);
		arr.log();
	}


	void demoLinearSearch() {
		std::cout << "\n****************************************************************************************\n";
		std::cout << "linear search:\n";
		std::cout << "****************************************************************************************\n";
		Array arr = Array::createRandomized(20);
		arr.log();

		size_t index = random::randomInt(0, 19);
		std::cout << "looking for element " << arr[index] << " at index " << index << std::endl;
		searching::checkSearch(searching::linear, arr, arr[index]);

		int nonexistent = 102;
		std::cout << "looking for nonexistent element " << nonexistent << std::endl;
		searching::checkSearch(searching::linear, arr, nonexistent);
	}


	void demoMergeSort() {
		std::cout << "\n****************************************************************************************\n";
		std::cout << "merge sort:\n";
		std::cout << "****************************************************************************************\n";
		Array arr = Array::createRandomized(15);
		arr.log();

		sorting::mergeSort(arr);
		arr.log();
	}


	void demoHeapSort() {
		std::cout << "\n****************************************************************************************\n";
		std::cout << "heapsort:\n";
		std::cout << "****************************************************************************************\n";
		Array arr = Array::createRandomized(15);
		arr.log();

		sorting::heapsort(arr);
		arr.log();
	}
}


int main() {
	// clrs::demoInsertionSort();
	// clrs::demoSelectionSort();
	// clrs::demoHeapSort();
	// clrs::demoLinearSearch();

	clrs::demoMergeSort();

	return 0;
}