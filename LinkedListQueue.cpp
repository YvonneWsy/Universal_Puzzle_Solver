//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
LinkedListQueue::LinkedListQueue()
{
  // TODO
	head = NULL;
	tail = NULL;
}

void LinkedListQueue::put_in(PuzzleState *elem)
{
  // TODO
	if (is_empty()) {
		head = tail = new node;
		head->data = tail->data = elem;
		head->next = tail->next = NULL;
	}
	else {
		tail->next = new node;
		tail = tail->next;
		tail->data = elem;
		tail->next = NULL;
	}
}

PuzzleState *LinkedListQueue::take_out()
{
  // TODO
	assert(!is_empty());
	PuzzleState* retData = head->data;
	node* temp = head;
	head = head->next;
	delete temp;
	return retData;
}

bool LinkedListQueue::is_empty()
{
  // TODO
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

LinkedListQueue::~LinkedListQueue()
{
  // TODO
	while (!is_empty()) {
		take_out();
	}
}

#endif


