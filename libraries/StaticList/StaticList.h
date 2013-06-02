/*

StaticList - library for using static lists with Arduino

Copyright 2013 Juanma Rodriguez

You can redistribute and/or modify this software under the terms of
the GNU Lesser General Public License (LGPL v3 or above).


Description
-----------
this implements an static list that lives or dies like a block, it doesn't
use memory management for allocating/deallocating the list elements

WARNING: this is intended to use only for fairly known short lists, if you
try to use more elements than STATIC_LIST_MAX_ELEMENTS then it forgets about
the "older" one that not fit originating data loss.


this implementation contains also some wrappers
    to use it as LIFO list: LIFOlist
    to use it as FIFO list: FIFOlist

Changelog
---------
2013-05-26: initial version, still not tested

*/

#ifndef LIBDUINO_STATICLIST_H_
#define LIBDUINO_STATICLIST_H_

#define STATIC_LIST_MAX_ELEMENTS 20

StaticList {
  public:
    StaticList(void);
    void add_first(void* data);
    void add_last(void* data);
    void* extract_first(void);
    void* extract_last(void);
    void* extract_n(int n);
    void* extract(void* data);
    void* n_element(int n); // 0..size-1
    void* first(void);
    void* last(void);
    unsigned size(void);
  private:
    void* list[STATIC_LIST_MAX_ELEMENTS];
    unsigned _size;
};


// wrapper to StaticList 
class StaticLIFOlist {
  public:
    void push(void* data);
    void* pop(void);
    unsigned size(void);
  private:
    StaticList list;
};


// wrapper to StaticList 
class StaticFIFOlist {
  public:
    void queue(void* data);
    void* next(void);
    unsigned size(void);
  private:
    StaticList list;
};


#endif
