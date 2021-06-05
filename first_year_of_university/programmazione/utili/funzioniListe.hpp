#ifndef FUNZIONILISTE_HPP
#define FUNZIONILISTE_HPP

#include <iostream>

using namespace std;

#define limit 10

/**
 * FL0: Takes list's length from user and asks elements value. (head-insertion (new element are inserted on the list's top)).
 * FL0.1: Takes list's length from user and generate random elements's value. (head-insertion oe (new element are inserted on the list's top)).
 * FL1: Prints all elements from the inserted pointer onwards (dal puntatre inserito in poi).
 * FL2: create a new element
 * FL3: headInserto of an element
 * FL3.1: bottomInser of an element
 * FL4: Remove an element
 * FL4.1: Bottom remove
 * FL5: Returns the average ole
 * FL6: Returns a reversed list
 * FL7: Returns the union of two lists
 *
 *
*/

#define limit 10

struct List {
	int val;
	List* next;
};
typedef List *p_list;

// FL0: Takes list's length from user and asks elements value. (head-insertion (new element are inserted on the list's top)).
p_list user_headGen_list (int n);

// FL0.1: Takes list's length from user and generate random elements's value. (head-insertion oe (new element are inserted on the list's top)).
p_list radom_headGen_list (int n);

// FL1: Prints all elements from the inserted pointer onwards (dal puntatre inserito in poi).
void print_ole (p_list p);

// FL2: create a new element
p_list newElement (int n);

// FL3: headInserto of an element
p_list headInsert (p_list in_list, int n);

// FL3.1: bottomInser of an element
p_list bottomInsert (p_list in_list, int n);

// FL4: Remove an element
p_list remove (p_list in_list, int n);

// FL4.1: Bottom remove
p_list bottom_remove (p_list in_list, int n);

// FL5: Return the average ole
double average_ole (p_list p);

// FL6: Return a reversed list.
p_list reverse_list (p_list in_list);

// FL7: Returns the union of two lists
p_list listUnion (p_list in_list_1, p_list in_list_2);


#endif
