#include <iostream>
#include "listOperations.hpp"

using namespace std;

p_var newVar (char in_var, int in_val) {
    p_var tmpNewVar = new Variable;
    tmpNewVar -> var = in_var;
    tmpNewVar -> val = in_val;
    tmpNewVar -> next = NULL;
    return tmpNewVar;
}

p_var headInsert (p_var in_list, char in_var, int in_val) {
    p_var tmpNewVar = newVar (in_var, in_val);
    if (in_list == NULL) return tmpNewVar;
    tmpNewVar -> next = in_list;
    return tmpNewVar;
}

p_var create_headInsert (p_var in_list, char in_var, int in_val) {  // Per creale solo l'elemento: create_headInsert (in_var, NULL)
    p_var tmpNewVar = new Variable;
    tmpNewVar -> var = in_var;
    tmpNewVar -> val = in_val;
    tmpNewVar -> next = in_list;
    return tmpNewVar;
}




