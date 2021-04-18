#include <iostream>

using namespace std;

struct Variable {
    char var;
    Variable* next;
};
typedef Variable *p_var;

p_var newVar (char in_var) {
    p_var tmpNewVar = new Variable;
    tmpNewVar -> var = in_var;
    tmpNewVar -> next = NULL;
    return tmpNewVar;
}

p_var headInsert (p_var in_list, char in_var) {
    p_var tmpNewVar = newVar (in_var);
    if (in_list == NULL) return tmpNewVar;
    tmpNewVar -> next = in_list;
    return tmpNewVar;
}

p_var create_headInsert (p_var in_list, char in_var) {  // Per creale solo l'elemento: create_headInsert (in_var, NULL)
    p_var tmpNewVar = new Variable;
    tmpNewVar -> var = in_var;
    tmpNewVar -> next = in_list;
    return tmpNewVar;
}




