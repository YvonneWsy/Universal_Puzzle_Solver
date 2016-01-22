//ArrayQueue.hpp
#ifndef _ARRAYQUEUE_HPP
#define _ARRAYQUEUE_HPP

#include "BagOfPuzzleStates.hpp"

// 221 STUDENTS:
//
// This skeleton file (along with the .cpp file) is here to help get you
// started, but you are free to change function signatures, etc. as
// long as ArrayQueue is derived from (i.e., a subclass of) BagOfPuzzleStates.
class ArrayQueue: public BagOfPuzzleStates
{
 public:
  ArrayQueue(); // constructor
  
  void put_in(PuzzleState *elem);
  PuzzleState *take_out();
  bool is_empty();

  ~ArrayQueue(); // destructor

  static const int INIT_SIZE = 1;

 private:
  // A helper function that consumes a number and ensures the queue
  // has enough space for that many elements.
  void ensure_capacity(int n);

  // A pointer to the underlying array with elements of type
  // (PuzzleState *).  Use an explicit pointer,
  // NOT "PuzzleState *array[..]" so you can resize.
  PuzzleState **array;
  int front;
  int back;
  int capacity;
  int counter;
  // List additional private member variables here.
};

#endif

