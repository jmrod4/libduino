/*

StaticList.cpp - library for using static lists with Arduino

this implements an static list that lives or dies like a block, it doesn't use 
memory management for allocating/deallocatin the list elements

this implementation contains some wrappers
    to use it as LIFO list: LIFOlist
    to use it as FIFO list: FIFOlist

Coded by Juan M. Rodriguez.

2013-05-26: initial version

*/

#ifndef _list_h_
#define _list_h_

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
    void put(void* data);
    void* get(void);
    unsigned size(void);
  private:
    StaticList list;
};


#endif
