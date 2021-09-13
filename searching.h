#pragma once

#include "array.h"

#include <optional>


namespace clrs {
  namespace searching {
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
