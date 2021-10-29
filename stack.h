#pragma once

#include "array.h"

#include <iostream>
#include <stdexcept>


namespace clrs {
	struct Stack {
		Array* array;
		size_t top = 0;

		Stack(Array* array) {
			this->array = array;
		}

		// non-copyable
		Stack(const Stack&) = delete;
		Stack& operator=(const Stack&) = delete;

		void log() {
			this->array->log();
		}

    bool isEmpty() {
      return this->top == 0;
    }

    bool isFull() {
      return this->top == this->array.size;
    }

    void push(int value) {
      if (this->isFull()) {
        throw std::runtime_error("stack is full");
      }

      this->array[this->top] = value;
      this->top += 1;
    }

    int pop() {
      if (this->isEmpty()) {
        throw std::runtime_error("stack is empty");
      }

      this->top -= 1;
      return this->array[this->top];
    }
	};
}
