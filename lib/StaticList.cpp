/*

StaticList.cpp - library for using static lists with Arduino

this implements an static list that lives or dies like a block, it doesn't use
memory management for allocating/deallocatin the pointers to the list elements

this implementation contains some wrappers
    to use it as LIFO list: LIFOlist
    to use it as FIFO list: FIFOlist

Coded by Juan M. Rodriguez.

2013-05-26: initial version

*/

#include "Arduino.h"

#include "list.h"

/**** class: StaticList ***********************************************
*/

StaticList::StaticList(void) {
  _size = 0;
}

void* StaticList::n_element(int n) {
  if ( n < 0 || n >= _size ) return NULL;
  return list[n];
}

void* StaticList::first(void) {
  return list[0];
}

void* StaticList::last(void) {
  return list[_size - 1];
}

void StaticList::add_first(void* data) {
  if (_size == STATIC_LIST_MAX_ELEMENTS) // if array cannot grow anymore...
    extract_last(); // quietly forget about the last element
		    // (NOTE: data loss, updates size)
  if ( _size > 0 )
    // make some space at the 0 position
    for (int i = _size; i > 0; i--)
      list[i] = list[i - 1];

  list[0] = data;
  _size += 1;
}


void StaticList::add_last(void* data) {
  if ( _size == STATIC_LIST_MAX_ELEMENTS ) // if array cannot grow anymore...
    extract_first(); // quietly forget about the first element 
		     // (note: data loss, updates size)
  list[_size] = data;
  _size += 1;
}


void* StaticList::extract_first(void) {
  if ( _size < 1 ) return NULL;
  void *first_data = list[0];
  for (int i = 1; i < _size; i++)
    list[i - 1] = list[i];
  _size -= 1;
  list[_size] = NULL; // to allow an eventual garbage collection
  return first_data;
}


void* StaticList::extract_last(void) {
  if ( _size < 1 ) return NULL;
  _size -= 1;
  void* last_data = list[_size];
  list[_size] = NULL; // to allow an eventual garbage collection
  return last_data;
}


void* StaticList::extract_n(int n) {
  if ( _size < 1 or _size < n+1 or n < 0) return NULL;
  void* data = list[n];
  for (int i = n; i < _size - 1; i++) {
    // move all array elements from n+1 to size-1 to fill the space at n
    list[i] = list[i+1];
  }
  _size -= 1;
  list[_size] = NULL; // to allow an eventual garbage collection
  return data;
}


void* StaticList::extract(void* data) {
  if ( _size < 1 ) return NULL;

  for (int i = 0; i < _size; i++)
    if ( list[i] == data ) // found !!
      return extract_n(i);
  // not found !!
  return NULL;
}


/****** class wrappers: StaticLIFO, StaticFIFO ***************************
*/

void LIFO::push(void* data)	{ list.add_last(data); }
void* LIFO::pop(void)		{ list.extract_last(); }
unsigned LIFO::size(void) 	{ list.size(); }
void FIFO::put(void* data) 	{ list.add_last(data); }
void* FIFO::get(void)		{ list.extract_first(); }
unsigned FIFO::size(void)	{ list.size(); }

