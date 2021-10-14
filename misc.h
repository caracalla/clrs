#pragma once

#include "array.h"
#include "heap.h"


namespace clrs {
	namespace maxSubarray {
		struct Result {
			size_t start;
			size_t end;
			int sum;
		};

		// Maximum-subarray problem: Chapter 4, page 68
		Result findCrossing(
				Array& array,
				size_t low,
				size_t mid,
				size_t high) {
			Result result;
			int sum = 0;
			int left_sum = std::numeric_limits<int>::min();

			// for some reason, if mid and high are both 0, problems happen unless
			// that i >= 0 conditional is there
			// why?
			for (int i = mid; i >= low && i >= 0; i--) {
				sum += array[i];

				if (sum > left_sum) {
					left_sum = sum;
					result.start = i;
				}
			}

			sum = 0;
			int right_sum = std::numeric_limits<int>::min();

			for (int i = mid + 1; i <= high; i++) {
				sum += array[i];

				if (sum > right_sum) {
					right_sum = sum;
					result.end = i;
				}
			}

			result.sum = left_sum + right_sum;

			return result;
		}

		Result find(Array& array, size_t low, size_t high) {
			if (low == high) {
				return Result{low, high, array[low]};
			}

			size_t mid = (low + high) / 2;

			Result left = find(array, low, mid);
			Result right = find(array, mid + 1, high);
			Result cross = findCrossing(array, low, mid, high);

			if (left.sum > right.sum && left.sum > cross.sum) {
				return left;
			} else if (right.sum > left.sum && right.sum > cross.sum) {
				return right;
			} else {
				return cross;
			}
		}
	}
}
