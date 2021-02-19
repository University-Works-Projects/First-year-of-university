#include <iostream>

using namespace std;

#define limit 10

struct list{
	int val;
	list* next;
};
typedef list *p_list;

// FL0: Takes list's length from user and asks elements value. (head-insertion (new element are inserted on the list's top)).
p_list user_headGen_list(int n){
	p_list new_list, el;
	new_list = NULL;
	for (int i = 0; i < n; i++) {
		el = new list;
		cout << "Enter element value: "; cin >> el -> val;
		el -> next = new_list;
		new_list = el;
	}
	return (new_list);
}

// FL0.1: Takes list's length from user and generate random elements's value. (head-insertion oe (new element are inserted on the list's top)).
p_list radom_headGen_list(int n){
	p_list new_list, el;
	new_list = NULL;
	for (int i = 0; i < n; i++) {
		el = new list;
		el -> val = (rand() % limit); // srand(time(0))
		el -> next = new_list;
		new_list = el;
	}
	return (new_list); ;
}

// FL1: Prints all elements from the inserted pointer onwards (dal puntatre inserito in poi).
void print_ole(p_list p){
	while (p != NULL){
		cout << "Element: " << p -> val;
		cout << "  ;  Next: " << p -> next << endl;
		p = p -> next;
	}
}

// FL2: create a new element
p_list newElement(int n){
  p_list newList = new list;
  newList -> val = n;
  newList -> next = NULL;
  return newList;
}

// FL3: headInserto of an element
p_list headInsert(p_list in_list, int n){
  p_list newEl = newElement(n);
  if (in_list == NULL) return newEl;
  newEl -> next = in_list;
  return newEl; // Ritorna tutta la lista col nuovo elemento in testa

}

// FL3.1: bottomInser of an element
p_list bottomInsert(p_list in_list, int n){
  p_list head = in_list, new_el = newElement(n);
  while (in_list -> next != NULL){
    in_list = in_list -> next;
  }
  in_list -> next = new_el;
  return head;

}

// FL4: Remove an element
p_list remove(p_list in_list, int n){
    if (in_list == NULL) return in_list;
    p_list head = in_list, pre_el = in_list, post_el = NULL;
    // Non serve controllare il primo elemento in quanto se in_list == NULL salta il ciclo e ritorna direttamente in_list
    while (in_list != NULL){
    	if (in_list -> val == n){
			if (in_list == head){ 			    // Controllo qualora il primo elemento fosse in cima
				head = in_list -> next; 	    // head punta al secondo elemento della lista
				delete in_list;  				// Il primo elemento della lista
				in_list = head; 				// lista ed head sono di nuovo uguali
			} else {							// Se non è al primo elemento
				post_el = in_list -> next;	    // post_el punta all'elemento successivo
				delete in_list;					// Cancella l'elemento corrente
				pre_el -> next = post_el;
			}
		}
		pre_el = in_list; // Si aggiorna pre_el in modo tale da farlo puntare sempre ll'elemento corrente, e NON ALLA TESTA, altrimenti sarebbe inutile.
		in_list = in_list -> next;
	}
	return head;

}

// FL4.1: Bottom remove
p_list bottom_remove(p_list in_list, int n){
  p_list head = in_list, new_el = newElement(n);

  if (in_list == NULL) return in_list;
	else if (in_list -> next == NULL){
		delete in_list;
		in_list = NULL;
	} else {
		while (in_list -> next -> next != NULL) in_list = in_list -> next;
		delete in_list -> next;
		in_list -> next = NULL;
	}

}

// FL5: Return the average ole
double average_ole(p_list p){
	double average = 0; int counter = 0;
	while (p != NULL){
		average += p -> val;
		counter++;
		p = p -> next;
	}
	return(average / counter);
}

// FL6: Return a reversed list.
p_list reverse_list(p_list in_list){
  p_list new_reversed_list = NULL, new_el = NULL;
  while (in_list != NULL) {
    new_el = new list;
    new_el -> val = in_list -> val;
    new_el -> next = new_reversed_list;
    new_reversed_list = new_el;
    in_list = in_list -> next;
  }
  return new_reversed_list;
}

int main() {



	return(0) ;
}
