#ifndef _ARRAYQUEUE_CPP
#define _ARRAYQUEUE_CPP

//ArrayQueue.cpp

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp file) is here to help get you
// started, but you are free to change function signatures, etc. as
// long as ArrayQueue is derived from BagOfPuzzleStates.
ArrayQueue::ArrayQueue()
{
  // Constructor: initialize member variables
  //              and do any other initialization
  //              needed (if any)
  // TODO: implement constructor
	array = new PuzzleState*[INIT_SIZE];
	capacity = INIT_SIZE;
	front = back = 0;
	counter = 0;
}

void ArrayQueue::put_in(PuzzleState *elem)
{
  // TODO: implement put_in method
	ensure_capacity(capacity + 1);
	array[back] = elem;
	back = (back + 1) % capacity;
	counter += 1;
}

PuzzleState *ArrayQueue::take_out()
{
  // TODO: implement take_out method
	assert(!is_empty());
	PuzzleState *retValue = array[front];
	front = (front + 1) % capacity;
	counter -= 1;
	return retValue;
}

bool ArrayQueue::is_empty()
{
  // TODO: implement is_empty method
	if (counter == 0) {
		return true;
	}
	else {
		return false;
	}
}

// TODO: implement ensure_capacity (but leave this to last.. just
// start with lots of capacity!)
void ArrayQueue::ensure_capacity(int n)
{
	if (!is_empty()) {
		if (front == back) {
			int target_capacity = (n > 2 * capacity + 1) ? n : (2 * capacity + 1);

			PuzzleState** old_array = array;
			array = new PuzzleState*[target_capacity];

			for (int i = 0; i < capacity; i++) {
				array[i] = old_array[back];
				back = (back + 1) % capacity;
			}
			front = 0;
			back = capacity;
			capacity = target_capacity;
			delete[] old_array;
		}
	}
}


ArrayQueue::~ArrayQueue()
{
  // TODO: implement the destructor

  // do any cleanup like deallocating
  // any dynamically allocated memory
	delete [] array;
}

#endif

