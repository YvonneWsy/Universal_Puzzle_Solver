//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}

void HeapPriorityQueue::put_in(PuzzleState *elem) {
  // TODO:  Put your code here!
	heap.push_back(elem);
	for (unsigned int i = heap.size() - 1; i > 0;) {
		if (heap[i]->getBadness() < heap[parent(i)]->getBadness()) {
			swap(heap[i], heap[parent(i)]);
			i = parent(i);
		}
		else {
			break;
		}
	}
}

PuzzleState * HeapPriorityQueue::take_out() {
  assert(!is_empty());
  
  // TODO:  Put your code here! 
  backup.clear();
  backup.push_back(heap[0]);
  heap[0] = heap[heap.size() - 1];
  heap.pop_back();
  int leftChild;
  int rightChild;
  for (unsigned int i = 0; i < heap.size();) {
	  leftChild = first_child(i);
	  rightChild = leftChild + 1;
	  int s = i;
	  if (leftChild < heap.size() && heap[leftChild]->getBadness() < heap[s]->getBadness()) {
		  s = leftChild;
	  }
	  if (rightChild < heap.size() && heap[rightChild]->getBadness() < heap[s]->getBadness()) {
		  s = rightChild;
	  }
	  if (i != s) {
		  swap(heap[i], heap[s]);
		  i = s;
	  }
	  else {
		  break;
	  }
  }
  return backup[0];
}


bool HeapPriorityQueue::is_empty() {
  return (heap.size() == 0);
}

int HeapPriorityQueue::parent(int index) {
  return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
  return 2 * index + 1;
}

bool HeapPriorityQueue::is_root(int index) {
  return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
  return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
  int fchild = first_child(index);
  return max(0, min(2, (int)heap.size() - fchild));
}

#endif
