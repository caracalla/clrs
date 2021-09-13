#include "array.h"
#include "random.h"
#include "searching.h"
#include "sorting.h"


void checkLinearSearch(clrs::Array& arr, int desired) {
	std::optional<size_t> result = clrs::searching::linear(arr, desired);

	if (result.has_value()) {
		std::cout << "got index " << result.value() << std::endl;
	} else {
		std::cout << "element was not found" << std::endl;
	}
}


int main() {
	clrs::Array arr1(15);

	std::cout << "insertion sort:\n";
	arr1.log();
	clrs::sorting::insertion(arr1);
	arr1.log();

	std::cout << "\nlinear search:\n";
	clrs::Array arr2(20);
	arr2.log();
	size_t index = clrs::random::randomInt(0, 19);
	std::cout << "looking for element " << arr2[index] << " at index " << index << std::endl;
	checkLinearSearch(arr2, arr2[index]);
	int nonexistent = 102;
	std::cout << "looking for nonexistent element " << nonexistent << std::endl;
	checkLinearSearch(arr2, nonexistent);

	return 0;
}