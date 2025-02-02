/* 
 * COMP15
 * Spring 2018
 * For Lab 4
 *
 * Queue class with linked structure
 * Defined as a template class!
 *
 */

#include <exception>
#include <string>
using namespace std;

#ifndef QUEUE_H_
#define QUEUE_H_


// Custom exceptions
class FullQueue : public exception{
public:
    const char * what() const throw() {return "Full Queue!\n";}; 
};

class EmptyQueue : public exception{
public:
    const char * what() const throw() {return "Empty and sad queue\n";}
};

// The Queue's NodeType as a template
template<class E>
struct NodeType
{
    E value;
    NodeType *next;
};


template<class E> class Queue
{
private:
    NodeType<E> *front;
    NodeType<E> *rear;

public:
    Queue();
    
    // Big Three!
    ~Queue();
    Queue(const Queue &);
    Queue &operator = (const Queue &);

    // Basic Queue functions
    void enqueue(E);
    bool is_full() const;
    E dequeue();
    bool is_empty() const;
    void make_empty();
    int get_length() const;
};


#endif
