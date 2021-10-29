#pragma once

#include "array.h"

#include <iostream>
#include <stdexcept>


namespace clrs {
	struct Queue {
		Array* array;
		size_t head = 0;
    size_t tail = 0;
    bool is_empty = true;

		Queue(Array* array) {
			this->array = array;
		}

		// non-copyable
		Queue(const Queue&) = delete;
		Queue& operator=(const Queue&) = delete;

		void log() {
			this->array->log();
		}

    void isFull() {
      return (!this->is_empty) && (this->head != this->tail);
    }

    void enqueue(int value) {
      if (this->isFull()) {
        throw std::runtime_error("queue is full");
      }

      this->array[this->tail] = value;
      this->tail += 1;

      if (this->tail == this->array.size) {
        this->tail = 0;
      }

      if (this->is_empty) {
        this->is_empty = false;
      }
    }

    int dequeue() {
      if (this->is_empty) {
        throw std::runtime_error("queue is empty");
      }

      int result = this->array[this->head];
      this->head += 1;

      if (this->head == this->array.size) {
        this->head = 0;
      }

      if (this->head == this->tail) {
        this->is_empty = true;
      }

      return result;
    }
	};
}
