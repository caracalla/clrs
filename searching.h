#pragma once

#include "array.h"

#include <optional>


namespace clrs {
  namespace searching {
    using SearchFunction = std::function<std::optional<size_t>(Array&, int)>;

    void checkSearch(SearchFunction search, Array& arr, int desired) {
      std::optional<size_t> result = search(arr, desired);

      if (result.has_value()) {
        std::cout << "  got index " << result.value() << std::endl;
      } else {
        std::cout << "  element was not found" << std::endl;
      }
    }

    // Linear search: Chapter 2, page 22
    // invariant: All values at indices less than i are not equal to the
    // desired value
    std::optional<size_t> linear(Array& array, int desired) {
      for (size_t i = 0; i < array.size; i++) {
        if (array[i] == desired) {
          return i;
        }
      }

      return {};
    }
  }
}
