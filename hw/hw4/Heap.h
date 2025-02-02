/* COMP15
 * Shaikat Islam
 * HW 4
 * 14-03-18
 * Heap.h
 *
 * COMP15
 * Spring 2018
 * Lab 4
 *
 * Interface for Heap abstract class
 *
 * This week's data structures pun:
 * https://i.stack.imgur.com/4Fe9y.png
 */

#include <exception>
#include "Patient.h"
using namespace std;

#ifndef HEAP_H_
#define HEAP_H_

const int MAX_CAPACITY = 3000;

// Custom classes for full/empty exceptions
class FullHeap : public exception
{
public:
    const char *what () const throw() { return "SO FULL NO MORE PLS\n"; }
};

class EmptyHeap : public exception
{
public:
    const char * what() const throw() { return "DISASSEMBLE HEAP FIIVE!!!\n"; }
};

// Template class for abstract Heap type
template <class E> class Heap
{
public:
    Heap();
    virtual ~Heap();

    // Basic Heap functions (inherited, not overridden)
    bool is_full() const;
    bool is_empty() const;
    void insert_item(E);
    E extract();

    // Helper functions for heapify
    // (and useful for testing!)
    int get_parent_index(int) const;
    void get_children_indices(int, int &, int &) const;

    // for testing purposes
    E get_value_at(int) const;
    void print() const;

protected:
    // Purely virtual functions make the class abstract
    virtual void heapify_up(int) = 0;
    virtual void heapify_down(int) = 0;

    E heap[MAX_CAPACITY];
    int length;
};

#endif
