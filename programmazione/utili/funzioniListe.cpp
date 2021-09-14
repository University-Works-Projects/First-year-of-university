#include "funzioniListe.hpp"

using namespace std;

// FL0
p_list user_headGen_list (int n) {
	p_list new_list, el;
	new_list = NULL;
	for (int i = 0; i < n; i++) {
		el = new List;
		cout << "Enter element value: "; cin >> el -> val;
		el -> next = new_list;
		new_list = el;
	}
	return (new_list);
}

// FL0.1
p_list radom_headGen_list (int n) {
	p_list new_list, el;
	new_list = NULL;
	for (int i = 0; i < n; i++) {
		el = new List;
		el -> val = (rand() % limit); // srand(time(0))
		el -> next = new_list;
		new_list = el;
	}
	return (new_list);
}

// FL1
void print_ole (p_list p) {
	while (p != NULL){
		cout << "Element: " << p -> val;
		cout << "  ;  Next: " << p -> next << endl;
		p = p -> next;
	}
}

// FL2
p_list newElement (int n) {
  p_list newList = new List;
  newList -> val = n;
  newList -> next = NULL;
  return newList;
}

// FL3
p_list headInsert (p_list in_list, int n) {
  p_list newEl = newElement (n);
  if (in_list == NULL) return newEl;
  newEl -> next = in_list;
  return newEl; // Ritorna tutta la lista col nuovo elemento in testa
}

// FL3.1
p_list bottomInsert (p_list in_list, int n) {
  p_list head = in_list, new_el = newElement (n);
  while (in_list -> next != NULL) {
    in_list = in_list -> next;
  }
  in_list -> next = new_el;
  return head;
}

// FL4
p_list remove (p_list in_list, int n) {
  if (in_list == NULL) return in_list;
  p_list head = in_list, pre_el = in_list, post_el = NULL;
  // Non serve controllare il primo elemento in quanto se in_list == NULL salta il ciclo e ritorna direttamente in_list
  while (in_list != NULL) {
  	if (in_list -> val == n) {
			if (in_list == head) { 			    // Controllo qualora il primo elemento fosse in cima
				head = in_list -> next; 	    // head punta al secondo elemento della lista
				delete in_list;  							// Il primo elemento della lista
				in_list = head; 							// lista ed head sono di nuovo uguali
			} else {												// Se non è al primo elemento
				post_el = in_list -> next;	  // post_el punta all'elemento successivo
				delete in_list;								// Cancella l'elemento corrente
				pre_el -> next = post_el;
			}
		}
		pre_el = in_list; // Si aggiorna pre_el in modo tale da farlo puntare sempre ll'elemento corrente, e NON ALLA TESTA, altrimenti sarebbe inutile.
		in_list = in_list -> next;
	}
	return head;
}

// FL4.1
p_list bottom_remove (p_list in_list, int n) {
	//p_list head = in_list, new_el = newElement(n);
  p_list head = in_list;

  if (in_list == NULL) return in_list;
	else if (in_list -> next == NULL) {
		delete in_list;
		in_list = NULL;
	} else {
		while (in_list -> next -> next != NULL) in_list = in_list -> next;
		delete in_list -> next;
		in_list -> next = NULL;
	}
	return head;
}

// FL5
double average_ole (p_list p) {
	double average = 0; int counter = 0;
	while (p != NULL) {
		average += p -> val;
		counter++;
		p = p -> next;
	}
	return (average / counter);
}

// FL6
p_list reverse_list (p_list in_list) {
  p_list new_reversed_list = NULL, new_el = NULL;
  while (in_list != NULL) {
    new_el = new List;
    new_el -> val = in_list -> val;
    new_el -> next = new_reversed_list;
    new_reversed_list = new_el;
    in_list = in_list -> next;
  }
  return new_reversed_list;
}

// FL7
p_list listUnion (p_list in_list_1, p_list in_list_2) {
    p_list tmp = in_list_1, head = tmp;
    while (tmp -> next != NULL) tmp = tmp -> next;			// Si scorre fino al penultimo elemento
    tmp -> next = in_list_2;
    return head;
}

int main() {

	p_list t1 = new List; t1 -> val = 1; t1 -> next = NULL;
	p_list t2 = new List; t2 -> val = 2; t2 -> next = t1;
	p_list t3 = new List; t3 -> val = 3; t3 -> next = t2;
	p_list t4 = new List; t4 -> val = 4; t4 -> next = t3;

	print_ole (remove (t4, 2));

	return(0) ;
}
