#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "consegna5COMMENTATA.h"

// Head insert dell'elemento nella lista
struct simTable* insert (struct simTable* el, int new_data, char* simble){
      struct simTable* new_node = (struct simTable*) malloc (sizeof (struct simTable));
      new_node-> val = new_data;
      strcpy (new_node-> simbolo, simble);
      new_node-> next = el;

      return (new_node);
}

// Funzione volta al creare una lista contenente tutte le casistiche sintattiche "non canoniche" che si possono incontrare
struct simTable* define (){
  struct simTable* el = (struct simTable*) malloc (sizeof (struct simTable));
  strcpy (el-> simbolo,"0");

  el->next = NULL;
  el = insert (el, 0, "SP");
  el = insert (el, 1, "LCL");
  el = insert (el, 2, "ARG");
  el = insert (el, 3, "THIS");
  el = insert (el, 4, "THAT");
  el = insert (el, 16384, "SCREEN");
  el = insert (el, 24576, "KBD");
  el = insert (el, 0, "R0");
  el = insert (el, 1, "R1");
  el = insert (el, 2, "R2");
  el = insert (el, 3, "R3");
  el = insert (el, 4, "R4");
  el = insert (el, 5, "R5");
  el = insert (el, 6, "R6");
  el = insert (el, 7, "R7");
  el = insert (el, 8, "R8");
  el = insert (el, 9, "R9");
  el = insert (el, 10, "R10");
  el = insert (el, 11, "R11");
  el = insert (el, 12, "R12");
  el = insert (el, 13, "R13");
  el = insert (el, 14, "R14");
  el = insert (el, 15, "R15");

  return (el);
}

// Funzione che rimuove gli spazi dalla riga, "pulendola"
void removeSpace (char *line){
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t' || line[i] == '\r'){
      int j = i;
      while (line[j] != '\0'){
        line[j] = line[j + 1];
        j++;
      }
    } else i++;
  }

}

// Scorrendo la lista dei segni, controlla se il simbolo è presente in essa (funzione di controllo)
int newSimbol (struct simTable* el, char* line){
  while (el != NULL) {
    if (strcmp (el->simbolo, line) == 0) return 0;  // Ritorna 0 se è presete un simbolo
    el = el->next;
  }
  return 1; // Se non è presente alcun simbolo della simble table ritorna 1

}

// Converte la stringa in intero (p.e: stringa = "123" --> conversione in int i = 123)
int convertData (char *str){
  int val;
  val = 0;
  while (*str){
    if (*str >= '0' && *str <= '9'){
      val *= 10;
      val += *str - '0';
    }
    else return val;
    str++;
  }
  return val;

}

// Converte un numero int i = 4, in un numero binario (salvato in un array di int) --> 0000000000000100
void convertBinary (int n, FILE* fOut){
  int a[15], i;
  for (i = 0; n > 0; i++){
    a[i] = n % 2;
    n = n / 2;
  } for (int j = 14 - i; j >= 0; j--){
    fprintf(fOut, "0");
  } for (i = i - 1; i >= 0; i--){
    fprintf(fOut, "%d", a[i]);
  }

}

// Funzione per la creazione della A instruction
struct simTable* aInstruction(char *line, struct simTable* table, FILE *fOut){
  int cnt = 0;
  struct simTable* el = table;
  int j = 0;

  while (line[j] != '\0'){
    line[j] = line[j + 1];
    j++;
  }
  j = 0;

  // Qualora l'utente bbia inserito un numero n (sottoforma di stringa) t.c: 0 <= n <= 9
  if (line[0] >= '0' && line[0] <= '9'){
    int num = convertData(line);
    fprintf(fOut, "%d", 0);
    convertBinary(num,fOut);
    fprintf(fOut, "\n");
  } else { // Se il numero inserito non è compreso tra 0 e 9
    if (newSimbol (el, line) == 1){ // Se non è presente alcun simblo conosciuto
      table = insert (table, 16 + cnt, line); // Lo aggiunge alla simble table
      cnt++;
    }
    el = table;

    while (el != NULL) {
      // Controlla se è presente un simbolo particolare
      if (strcmp (line, el->simbolo) == 0){ // Se è presente
        int num = el->val;  // Converte in binario il valore del simbolo particolare in questione
        fprintf (fOut, "%d", 0);  // Poi lo stampa
        convertBinary (num, fOut);
        fprintf (fOut, "\n");
      }
      el = el->next;
    }
  }
  return table;

}

// "Pulisce" la riga di codice dai commenti
void checkComment (char *line){
  int i = 0;
  while (line[i] != '\0') {
    if(line[i] == '/' && line[i + 1] == '/') line[i] = '\0';
    else i++;
  }

}

// Si definiscono i bits DEST della C instruction
void destA(char *line, char* C_instr){
  int counter = 0, equal = 0;
  while (line[counter] != '\0'){
    if (line[counter] == '=') equal = 1;{
      counter++;
    }
  }

  if (equal == 1){
    C_instr[10] = '\0';
    if (line[0] == 'A' && line[1] == 'M' && line[2] == 'D') {strcat(C_instr, "111");}
    else if (line[0] == 'A' && line[1] == 'D') {strcat(C_instr,"110");}
    else if (line[0] == 'A' && line[1] == 'M') {strcat(C_instr,"101");}
    else if (line[0] == 'A') {strcat(C_instr,"100");}
    else if (line[0] == 'M' && line[1] == 'D') {strcat(C_instr,"011");}
    else if (line[0] == 'D') {strcat(C_instr,"010");}
    else if (line[0] == 'M') {strcat(C_instr,"001");}
    else {strcat(C_instr,"000");}
  }
  else strcat(C_instr,"000");

}

// Si definiscono i bits JUMP della C instruction
void jumpA(char *line, char* C_instr){
  int i = 0;
  C_instr[13] = '\0';

  while (line[i] != '\0'){
    if (line[i] == ';' && line[i+1] == 'J'){
      if (line[i+2] == 'M' && line[i+3] == 'P'){strcat(C_instr,"111");}
        else if (line[i+2] == 'L' && line[i+3] == 'E') {strcat(C_instr,"110");}
        else if (line[i+2] == 'N' && line[i+3] == 'E') {strcat(C_instr,"101");}
        else if (line[i+2] == 'L' && line[i+3] == 'T') {strcat(C_instr,"100");}
        else if (line[i+2] == 'G' && line[i+3] == 'E') {strcat(C_instr,"011");}
        else if (line[i+2] == 'E' && line[i+3] == 'Q') {strcat(C_instr,"010");}
        else if (line[i+2] == 'G' && line[i+3] == 'T') {strcat(C_instr,"001");}
      }
      i++;
    }
  if (C_instr[13] == '\0') strcat(C_instr, "000");

}

// Si definiscono i bits COMP della C instruction
void compA(char *riga, char* C_instr){
  char comp[3];
  C_instr[3] = '\0';
  int counter = 0, CInstructionA = 0;

  while (riga[counter] != '=' && riga[counter] != '\0') {
    counter++;
  }
  int i = counter, j = 0;

  while (riga[i] != '\0'){
    if (riga[i] == 'M'){
      CInstructionA = 1;
    }
    i++;
  }

  if (riga[counter] != '='){
    strncpy(comp,riga,3);
  } else {
    comp[0] = riga[counter + 1];
    comp[1] = riga[counter + 2];
    comp[2] = riga[counter + 3];
  }

  while (comp[j] != '\0'){
    j++;
    if (comp[j] == ';') {
      comp[j] = '\0';
    }
  }

  // Parte di effettiva assegnazione dei bits della C instructions

  if (CInstructionA == 1){
    if (strncmp (comp, "D|M", 3) == 0) {strcat (C_instr, "1010101");}
    else if (strncmp (comp, "D&M", 3) == 0) {strcat (C_instr, "1000000");}
    else if (strncmp (comp, "M-D", 3) == 0) {strcat (C_instr, "1000111");}
    else if (strncmp (comp, "D-M", 3) == 0) {strcat (C_instr, "1010011");}
    else if (strncmp (comp, "D+M", 3) == 0) {strcat (C_instr, "1000010");}
    else if (strncmp (comp, "M-1", 3) == 0) {strcat (C_instr, "1110010");}
    else if (strncmp (comp, "M+1", 3) == 0) {strcat (C_instr, "1110111");}
    else if (strncmp (comp, "-M",2 )== 0 ){ strcat (C_instr, "1110011");}
    else if (strncmp (comp, "!M", 2) == 0) {strcat (C_instr, "1110001");}
    else if (strncmp (comp, "M", 1) == 0) {strcat (C_instr, "1110000");}
  }

  else if (CInstructionA == 0){
    if (strncmp (comp, "D|A", 3) == 0) {strcat (C_instr, "0010101");}
    else if (strncmp (comp, "D&A", 3) == 0) {strcat (C_instr, "0000000");}
    else if (strncmp (comp, "A-D", 3) == 0) {strcat (C_instr, "0000111");}
    else if (strncmp (comp, "D-A", 3) == 0) {strcat (C_instr, "0010011");}
    else if (strncmp (comp, "D+A", 3) == 0) {strcat (C_instr, "0000010");}
    else if (strncmp (comp, "A-1", 3) == 0) {strcat (C_instr, "0110010");}
    else if (strncmp (comp, "D-1", 3) == 0) {strcat (C_instr, "0001110");}
    else if (strncmp (comp, "A+1", 3) == 0) {strcat (C_instr, "0110111");}
    else if (strncmp (comp, "D+1", 3) == 0) {strcat (C_instr, "0011111");}
    else if (strncmp (comp, "-A", 2) == 0) {strcat (C_instr, "0110011");}
    else if (strncmp (comp, "-D", 2) == 0) {strcat (C_instr, "0001111");}
    else if (strncmp (comp, "!A", 2) == 0) {strcat (C_instr, "0110001");}
    else if (strncmp (comp, "!D", 2) == 0) {strcat (C_instr, "0001101");}
    else if (strncmp (comp, "A", 1) == 0) {strcat (C_instr, "0110000");}
    else if (strncmp (comp, "D", 1) == 0) {strcat (C_instr, "0001100");}
    else if (strncmp (comp, "-1", 2) == 0) {strcat (C_instr, "0111010");}
    else if (strncmp (comp, "1", 1) == 0) {strcat (C_instr, "0111111");}
    else if (strncmp (comp, "0", 1) == 0) {strcat (C_instr, "0101010");}
  }

}

// Si "uniscono" i valori creando la C instruction
char* cInstruction (char *riga, char *C_instr){
  strcat (C_instr, "111");
  compA (riga, C_instr);
  destA (riga, C_instr);
  jumpA (riga, C_instr);
  C_instr[17] = '\0';
  return (C_instr);
}


/*
  Nel main si chiamano le funzioni e si fa la parte "sporca" della creazione del file
*/

// argc: Indica il numero di elementi passati come parametro
// argv: Continene gli argomenti
int main (int argc, char **argv) {
  FILE *fin, *fOut,*fin2;
  fin = fopen(argv[1], "r"); // fin contiene il file da leggere
  fin2 = fopen(argv[1], "r");
  int str_len = strlen (argv[1]) + 1, k = 0;
  char nome[str_len];
  strncpy(nome,argv[1], str_len);

  // Si cambia l'estensione del file
  for (int i = 0; i < str_len; i++) {
    if (nome[i] == '.'){
      nome[i+1] = '\0';
      strcat(nome,"hack");
      i = str_len;
    }
  }

  struct simTable* table = define(); // Si definisce la simble table
  char riga[128];
  int scarto = 1, numberline = 0;

  //
  while (!feof(fin2)) { // feof legge il file, e termina una volta arrivato in fondo
    fgets(riga, 128, fin2); // Funzione per leggere ogni riga del codice
    removeSpace (riga);
    checkComment (riga);

    // Se la riga di codice è effetivamente "pulita"
    if (riga[0] != '\n' && riga[0] != '\0' && riga[0] != '\t' && riga[0] != '\r'){ // ---
      numberline++;

      // Controlla se vi sono parentesi tonde ed ignora tutto quello che vi è all'interno
      if (riga[0] == '(' ){ // Controllo della presenza di parentesi tonde, che devono essere ignorate
        int q = 0;
        // Si scorre fino in fondo
        while (riga[q] != '\0'){
          riga[q] = riga[q + 1];
          q++;
        }
        k = 0;
        while (riga[k] != '\0') {
          if (riga[k] ==')' ) riga[k] = '\0';
          else k++;
        }
        if (newSimbol (table, riga) == 1){ // Se è un simbolo "nuovo", ovvero non presente nella simble table
          table = insert (table, numberline - scarto, riga); scarto++;  // Lo si inserisce
        }

      }

    } // ---

    riga[0] = '\0';
  }

  numberline = 0;
  fOut = fopen (nome, "w"); // Apre un file vuoto in cui scrivere, se non esiste lo crea in automatico la funzione fopen

  while (!feof(fin)){ // Legge tutto il file, riga per riga
    fgets (riga, 256, fin); // Si prende in considerazione ogni singola riga
    str_len = strlen (riga);
    removeSpace (riga); // Pulizia della riga
    checkComment (riga);

    if (riga[0] != '\n' && riga[0] != '\0' && riga[0] != '\t' && riga[0] != '\r' && riga[0] != '(' ){ // Controllo se la rgia è effettivamente pulita
      if (riga[0] != '@'){ // Se non è un comando di "indirizzamento" (Ti dice a che indirizzo di memoria andare)
        // In queste 4 righe si crea la C instructions e la si stampa
        char C_instr[18];
        C_instr[0] = '\0';
        strncpy (riga, cInstruction (riga, C_instr), 17);
        fprintf (fOut, "%s\n", riga);
      } else { // Altruimenti è una A instruction
        table = aInstruction (riga, table, fOut);
      }
      riga[0]='\0';
    }

  }

  // Funzioni per la chiusura dei due file
  fclose (fin);
  fclose (fOut);

  return 0;

}


