/*
    Data una lista: el1 : el2 : el3 : el4 : NULL

    Eliminare un elemento (ad esempio el1):
        in_list = el1
        ...
        return (el1.next()) --> Ritornerà: el2 : el3 : el4 : NULL
    
    Modificare la lista dopo un dato elemento e restituirla:
        in_list = el1
        ...si modifica l'ordine degli elementi...
        return in_list --> Ritornerà: el1 : el4 : el2 : el3 : NULL

    Inserire un nuovo elemento:
        in_list = el1
        List tmp = new List(...)
        tmp.next() = el1
        ...
        return tmp ---> Ritornerà: el0(tmp) : el1 : el4 : el2 : el3 : NULL


*/