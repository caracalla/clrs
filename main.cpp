#include "array.h"
#include "heap.h"
#include "misc.h"
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

		sorting::merge(arr);
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


	void demoStockPrice() {
		std::cout << "\n****************************************************************************************\n";
		std::cout << "stock price (maximum subarray):\n";
		std::cout << "****************************************************************************************\n";
		// book example values
		// std::vector<int> vals = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
		// Array arr = Array::createCopy(vals);
		
		// random values
		Array arr = Array::createRandomized(20, 60, 120);

		Array diffs = Array::createZeroed(arr.size - 1);

		// set up the list of differences in price
		for (size_t i = 0; i < diffs.size; i++) {
			diffs[i] = arr[i + 1] - arr[i];
		}

		Array days = Array::createZeroed(arr.size);
		
		for (size_t i = 0; i < days.size; i++) {
			days[i] = i;
		}

		std::cout << "day:          ";
		days.log();
		std::cout << "stock prices: ";
		arr.log();
		std::cout << "price diffs:       ";
		diffs.log();

		maxSubarray::Result result = maxSubarray::find(diffs, 0, diffs.size - 1);

		// result.start, indicates when to buy, but result.end indicates the day to sell AFTER (so add 1 to end)
		// why?
		std::cout << "buy on " << result.start << ", sell on " << result.end + 1 << " for a profit of " << result.sum << std::endl;
	}


	void demoQuickSort() {
		std::cout << "\n****************************************************************************************\n";
		std::cout << "quicksort:\n";
		std::cout << "****************************************************************************************\n";
		Array arr = Array::createRandomized(15);
		arr.log();

		sorting::quick(arr);
		arr.log();
	}
}


int main() {
	// clrs::demoInsertionSort();
	// clrs::demoSelectionSort();
	// clrs::demoHeapSort();
	// clrs::demoLinearSearch();
	// clrs::demoMergeSort();
	// clrs::demoStockPrice();

	clrs::demoQuickSort();

	return 0;
}
