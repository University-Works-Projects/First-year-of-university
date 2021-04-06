public class Main {

    public static class Pilota {
      public String nome;
      public int tempo;       // Quantità di secondi: 45s
      public int codice;
  
      public Pilota (String nome, int tempo, int codice) {
        this.nome = nome;
        this.tempo = tempo;
        this.codice = codice;
      }
  
      public String getNome(){ return nome; }
      public void setNome(String nome){ this.nome=nome; }
      public int getTempo(){ return tempo; }
      public void setTempo(int tempo){ this.tempo=tempo; }
      public int getCodice(){ return codice; }
      public void setCodie(int codice){ this.codice=codice; }
  
    }
  
    public static class Tabellone {
  
      public Pilota[] arrayPiloti;
      public static int codiceProgressivo = 0;
  
      public Tabellone (int lunghezza) {
        this.arrayPiloti = new Pilota[lunghezza];               // Gli elementi dell'array inizializzati a null
      }
      public void incrementaCodice () { this.codiceProgressivo += 1; }
      public void decrementaCodice () { this.codiceProgressivo -= 1; }
  
      public void newPilota (Pilota nuovoPilota) {
        boolean inserimento = false;
        for (int i = codiceProgressivo; i < arrayPiloti.length; i++) {
          if (arrayPiloti[i] == null) {
            arrayPiloti[i] = nuovoPilota;
            inserimento = true;
            incrementaCodice ();
            break;
          }
        }
        if (inserimento) System.out.println ("Inserimento riuscito");
        else System.out.println ("Inserimento non riuscito");
      }
  
      public void rimuoviPilota (int codice) {
        boolean rimozione = false;
        for (int i = codiceProgressivo; i > 0; i--) {
          if (arrayPiloti[i] != null && arrayPiloti[i].getCodice() == codice) {
            arrayPiloti[i] = null;
            rimozione = true;
            decrementaCodice ();
            break;
          }
        }
        if (rimozione) System.out.println ("Rimozione riuscita");
        else System.out.println ("Rimozione non riuscita");
      }
  
      public void aggiornaTempo (int codice, int tempo) {
        boolean aggiornamento = false;
        for (int i = 0; i < arrayPiloti.length; i++) {
          if (arrayPiloti[i] != null && arrayPiloti[i].getCodice() == codice) {
            arrayPiloti[i].setTempo(tempo);
            aggiornamento = true;
            break;
          }
        }
        if (aggiornamento) System.out.println ("Aggiornamento riuscito");
        else System.out.println ("Aggiornamento non riuscito");
      }
  
      public void infoPilota () {
        int tempoMigliore = 1000000;        // Il tempo migliore è il più basso
        for (int i = 0; i < arrayPiloti.length; i++) {  // Ricerca del tempo migliore
          if (arrayPiloti[i] != null && arrayPiloti[i].getTempo() < tempoMigliore) {
            tempoMigliore = arrayPiloti[i].getTempo();
          }
        }
        // Alla fine del for, si avrà la variabile tempoMigliore = il tempo più basso fatto dai piloti
  
        for (int i = 0; i < arrayPiloti.length; i++) {
          if (arrayPiloti[i] != null && arrayPiloti[i].getTempo() == tempoMigliore) {
            // Stampa delle informaizoni
            System.out.println ("informaizoni");
          }
        }
  
      }
  
      public void stampaPiloti () {
        for (int i = 0; i < arrayPiloti.length; i++){
          System.out.println (arrayPiloti[i]);
        }
      }
    
    }
  
    public static void main (String[] args) {
  
      // Creazione dell'array contenente 6 piloti
      Tabellone tab = new Tabellone(5);     // Creazione dell'array (inizializzato a null)
      tab.stampaPiloti();                   // Stampa dell'array inizializzato a null
      
      // Creazione dei piloti
      Pilota p1 = new Pilota ("n1", 10, 0);
      Pilota p2 = new Pilota ("n2", 20, 1);
  
      try {
        Pilota p3 = new Pilota (7, 30, 2);
      }
      catch (nomeErrore e) {
        System.out.println ("codice catch");    
      }
      
      System.out.println ("");
  
      // Assegnazione dei piloti nell'array
      tab.newPilota(p1);
      tab.newPilota(p2);
      tab.newPilota(p3);
      System.out.println ("");
  
      // Stampa dell'array
      System.out.println ("Piloti nell'array: ");
      tab.stampaPiloti();                   // Stampa dell'array inizializzato a null
      System.out.println ("");
  
      // Rimozione pilota
      System.out.println ("Rimozione di un pilota: ");
      tab.rimuoviPilota(1);
      System.out.println ("");
  
      // Stampa dell'array
      System.out.println ("Piloti nell'array: ");
      tab.stampaPiloti();                   // Stampa dell'array inizializzato a null
  
    }
  
  }