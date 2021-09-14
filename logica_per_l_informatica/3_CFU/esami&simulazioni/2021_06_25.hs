-- Es 1

    {-
    Considerate il seguente frammento di codice che legge da un database un elenco di dipendenti con i rispettivi volumi di vendita,
    seleziona il dipendente migliore e gli invia una mail di ringraziamento.
    -}

    thanks (dbname, password) = process (query_db (open_db (dbname, password), "SELECT * FROM dipendenti"), DUMMY)

    process ([], migliore) = ringrazia(migliore)
    process (dip :: L, migliore) =
        if migliore = DUMMY || dip.vendite > migliore.vendite then process(L, dip)
        else process(L,migliore)

    ringrazia (migliore) = send_mail (migliore.indirizzo_mail, "Sei stato il più bravo, grazie a te i proprietari hanno guadagnato di più, continua così!")

    {- 
    Dove:
        - Un dipendente è un record avente (almeno) i campi vendite e indirizzo_mail
        - La funzione open_db prende l'indirizzo di un database e una password e restituisce una connessione al database
        - La funzione query_db prende una connessione a un database e una query e restituisce il risultato della query
        - La query usata nel codice restituisce la lista di tutti i dipendenti presa da una tabella del database di nome "dipendenti"
        - La funzione send_mail invia una mail a un dipendente prendendo l'indirizzo del dipendente e il messaggio


    Il codice viola l'architettura esagonale in quanto il codice mischia la business logic, ovvero la parte algoritmica che prende decisioni a partire dai dati,
    con le system dependencies, ovvero il codice che interagisce con gli elementi architetturali del sistema (file system, database, connessione a server come quello di posta, etc.).
    Questo comporta una serie di problemi, quali:
        1. Per testare la business logic (per capire se effettivamente seleziona il miglior dipendente) è necessario avere installato un database e un server di posta.
        2. Per apportare modifiche architetturali al sistema, per esempio sostituire il database locale a un servizio cloud remoto,
           oppure l'invio di mail all'invio di un SMS o alla pubblicazione di una pagina Web pubblica, bisogna ritoccare il codice per chiamare nuove funzioni o passare
           nuovi parametri (es. magari un'installazione locale diversa di un database può non richiedere la password)
        3. Non si distingue l'intenzione del codice, che fa parte della business logic (es: recuperare la lista di dipendenti, gratificare un dipendente),
           dalla sua implementazione tramite scelte di sistema.
        
    Riscrivere tutto il codice (thanks/process/ringrazia) in modo da rendere l'architettura esagonale.
    In particolare il nuovo codice dovrà astrarre completamente sulle operazioni di recupero della lista dei dipendenti e sul modo in cui i dipendenti vengono gratificati.
    Più esplicitamente viene richiesto di:
        1. Mostrare una versione generica del codice che usa funzioni di ordine superiore, ovvero dove le funzioni prendono in input altre funzioni
          per astrarre le operazioni da compiere.
          NOTA: Non si può prendere in input direttamente la lista di dipendenti e dare in output il nome del dipendente, bisogna necessariamente astrarre sull'operazione
                che restituisce la lista di dipendenti e su quella che lo gratifica.
        2. Mostrare un'istanza del codice generico che sia equivalente al programma originale
        3. Mostrare un'istanza differente di testing dove il codice ottenga la lista prefissata di dipendenti: -}
               { indirizzo_mail = "csc@badcompany.org", vendite = "666999" } ::
               { indirizzo_mail = "best_of_the_best@badcompany.org", vendite = "33" } :: []
        -- e dove la gratificazione verifichi che l'indirizzo_mail del migliore sia "csc@badcompany.org" e stampi un errore altrimenti usando la chiamata print("errore").


{- Es 2

    Sia G = (𝔾, ⋆, $, e) un gruppo, dove e è l'elemento neutro di ⋆ ed $ l'operazione inversa.

    Per ogni elemento x di 𝔾, si chiama centralizzatore di x l'insieme Z(x) = { g ∈ 𝔾 | x ⋆ g = g ⋆ x }.

    Domande:
        1. Per ogni x, Z(x) è un sottogruppo del gruppo G? se sì dimostrarlo, altrimenti fornire un controesempio.
        2. A quale insieme corrisponde Z(x) quando G è abeliano?
        3. A quale insieme corrisponde Z(e)?
        3. Se Z(x) = Z(y), allora x = y: vero o falso? (motivare la risposta attraverso una prova o un controesempio).
        4. Sia f un morfismo di gruppi da G a un altro gruppo H e sia x un elemento di 𝔾.
           Dimostrare che f(Z(x)) ⊆ Z(f(x)), ovvero che l'immagine del centralizzatore di x è contenuta nel centralizzatore dell'immagine di x.
           (Ovviamente il secondo centralizzatore è definito in termini di ℍ e non di 𝔾).
        5. Proseguendo il punto precedente, f(Z(x)) = Z(f(x)): vero o falso? (motivare la risposta attraverso una prova o un controesempio).

-}

{- Es 3

    Domande:
    1. Sia 𝟘 = { 0 } (l'insieme contenente solo lo 0).
       Dimostrare che (𝟘, +, 0, -) è un gruppo, dove + ed - sono le usuali definizioni di somma e sottrazione su numeri interi.
    2. Indichiamo con 2ℤ l'insieme di tutti i numeri pari, ovvero 2ℤ = { 2*z | z ∈ ℤ }.
       Dimostrare che (2ℤ, +, 0, -) è un gruppo, dove + e - sono le usuali definizioni di somma e sottrazione su numeri interi.
    3. Quanti morfismi diversi esistono dal gruppo 𝟘 al gruppo ℤ?
       Se non ne esistono dimostrare perchè.
       Se ne esistono elencarli tutti e per ognuno calcolarne il nucleo (Ker) e l'immagine (Imm).
    4. Considerare l'operazione f(z) = 2z di dominio ℤ e codominio 2ℤ.
       Dire se f è un morfismo e, se lo è, dimostrarlo tale e calcolarne il nucleo (Ker) e l'immagine (Imm).
    5. Imm(f) è un sottogruppo normale di 2ℤ? Perchè?
    6. Esplicitare il gruppo quoziente ℤ/2ℤ (sia il sostegno, sia le operazioni di gruppo).
    7. Quanti morfismi diversi esistono dal gruppo ℤ/2ℤ al gruppo 𝟘?
       Se non ne esistono dimostrare perchè.
       Se ne esistono elencarli tutti e per ognuno calcolarne il nucleo (Ker) e l'immagine (Imm).
    8. La sequenza di domande precedenti ha chiesto di costruire una sequenza di morfismi di gruppo 𝟘 → ℤ→ 2ℤ→ ℤ/2ℤ→𝟘 dove ogni freccia rappresenta un morfismo
       dal gruppo che precede la freccia a quello che segue la freccia.
       Una tale sequenza si dice esatta se per ogni tripla A → B → C nella sequenza l'immagine del primo morfismo (la prima freccia) è uguale al nucleo della seconda.
       Dire se la sequenza 𝟘 → ℤ→ 2ℤ→ ℤ/2ℤ→𝟘 è esatta o meno.

-}
