#ifndef LISTOPERATIONS_HPP
#define LISTOPERATIONS_HPP

#include <iostream>

using namespace std;

struct Variable {
    char var;
    int val;
    Variable* next;
};
typedef Variable *p_var;

p_var newVar (char in_var, int in_val);

p_var headInsert (p_var in_list, char in_var, int in_val) ;

p_var create_headInsert (p_var in_list, char in_var, int in_val);  // Per creale solo l'elemento: create_headInsert (in_var, NULL)



#endif