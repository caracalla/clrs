#pragma once

#include "array.h"
#include "heap.h"


namespace clrs {
	namespace maxSubarray {
		struct Result {
			int start;
			int end;
			int sum;
		};

		// Maximum-subarray problem: Chapter 4, page 68
		Result findCrossing(
				Array& array,
				int low,
				int mid,
				int high) {
			Result result;
			int sum = 0;
			int left_sum = std::numeric_limits<int>::min();

			for (int i = mid; i >= low; i--) {
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

		Result find(Array& array, int low, int high) {
			if (low == high) {
				return Result{low, high, array[low]};
			}

			int mid = (low + high) / 2;

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
