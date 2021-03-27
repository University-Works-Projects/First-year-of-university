public class Main {
  public static final int posti = 100;

  public static class Barca {
    public String nome;
    public String nazione;
    public float lunghezza;
    public float peso;            // Espresso in tonnellate
    public boolean motore;

    public Barca (String in_nome, String in_nazione, float in_lunghezza,  float in_peso, boolean in_motore) {
      this.nome = in_nome;
      this.nazione = in_nazione;
      this.lunghezza = in_lunghezza;
      this.peso = in_peso;
      this.motore = in_motore;
    }

    public String getNome () { return this.nome; }
    public void setNome (String in_nome) { this.nome = in_nome; }

    public String getNazione () { return this.nazione; }
    public void setNazione (String in_nazione) { this.nazione = in_nazione; }

    public float getLunghezza () { return this.lunghezza; }
    public void setLunghezza (float in_lunghezza) { this.lunghezza = in_lunghezza; }

    public float getPeso () { return this.peso; }
    public void setPeso (float in_peso) { this.peso = in_peso; }
    
    public boolean getMotore () { return this.motore; }
    public void setMotore (boolean in_motore) { this.motore = in_motore; }

    @Override
    public String toString () {
      return "Nome: " + getNome () + "\nNazione: " + getNazione () + "\nLunghezza: " + getLunghezza () +"\nStazza: " + getPeso () + "\nMotore: " + getMotore ();
    }
    
  }

  public static class StackBarche {
    protected Barca[] arrayBarche;
    protected final int prezzoM;
    protected final int prezzoV;

    public StackBarche () {
      this.arrayBarche = new Barca[posti];    // Gli elementi (in questo caso gli oggetti Barca) sono inizializzati a null !!!
      this.prezzoM = 20;
      this.prezzoV = 10;
    }
    
    public int getPrezzoV () { return this.prezzoM; }
    public int getPrezzoM () { return this.prezzoV; }

    public Barca getBarca (int in_pos) { return arrayBarche[in_pos]; }

    public void assegnaPosto (Barca in_barca) {
      //try {...} catch (outofboundaaaaa)
      boolean postoNonTrovato = true;
      if (in_barca.getMotore()) {                         // Se è una barca a motore
        int pos = 0;
        if (in_barca.getLunghezza() > 10) pos = 20;       // Se lunghezza > 10m il controllo dei posti parte dalla posizione 20
        while (pos < 50) {                                // Se invece la lunghezza è < 10m va bene qualisasi posto
          if (this.arrayBarche[pos] == null) {
            this.arrayBarche[pos] = in_barca;
            postoNonTrovato = false;
            System.out.println ("Assegnamento posto riuscito, posto: " + pos);
            break;
          }
          pos++;
        }
      
      } else {                                  // Oppure se è una barca a vela
        for (int pos = 50; pos < 100; pos++) {
          if (this.arrayBarche[pos] == null) {
            this.arrayBarche[pos] = in_barca;
            postoNonTrovato = false;
            System.out.println ("Assegnamento posto riuscito, posto: " + pos);
            break;
          }
        }
      }
      if (postoNonTrovato) System.out.println ("Barca a motore con lunghezza > 10m, posto non disponibile.");

      // catch (..) {..}
    }

    public int rimozione (int in_pos, int in_giorni) {
      //try {...
      if (controlloPos (in_pos)) {
        if (arrayBarche[in_pos] != null) {
          if (arrayBarche[in_pos].getMotore()){                  // NOTA BENE LA SINTASSI. La sintassi: arrayBarche.getBarca (in_pos) è ERRATA !!! (Questo è il caso barca a motore)
            arrayBarche[in_pos] = null;                          // Si elimina la barca
            return this.prezzoM * in_giorni; 
          } else {                                               // Caso barca a vela
            arrayBarche[in_pos] = null;                          // Si elimina la barca
            return this.prezzoV * in_giorni;
          }
        } else {                                                 // Caso in cui si cerca di eliminare una barca da una posizione vuota
          System.out.println("La posizione selezionata è già libera.");
          return -1;
        }
      } else {
        System.out.println("Posizione inserita non valida, inserire una posizione: 0 <= pos <= 100.");
        return -1;
      }
      // ...}
      //catch
    }

    public void infoBarca (int in_pos) {
      if (controlloPos (in_pos)) {
        if (arrayBarche[in_pos] != null) System.out.println(arrayBarche[in_pos].getNome());   
        else System.out.println("Posizione vuota");
      } else {
        System.out.println("Posizione inserita non valida.");      
      }
    }

    public String[] nazioni (String in_nazione) {
      String[] arrayNazioni = new String[posti];
      int arrayPos = 0;
      for (int i = 0; i < 100; i++) {
        if (arrayBarche[i] != null && arrayBarche[i].getNazione() == in_nazione) {
          arrayNazioni[arrayPos] = arrayBarche[i].getNome();
          arrayPos++;
        }
      }
      return arrayNazioni;
    }

    public boolean controlloPos (int in_pos) {
      if (0 <= in_pos && in_pos <= 100) return true;
      else return false;
    }

  }

  public static void main (String[] args) {
    //System.out.println (tmp.motore);                 // Questa cosa è lecita, stampa il valore booleano della variabile
    
    // Creazione dello stack di barche rappresentante il porto
    StackBarche porto = new StackBarche ();

    // Creazione di 4 oggetti Barca
    System.out.println ("Creazione di 4 oggetti Barca e stampa dei ralativi toString");
    Barca b1 = new Barca ("barcaV1", "it", 14, 3, false);
    Barca b2 = new Barca ("barcaV2", "it", 6, 3, false);
    Barca b3 = new Barca ("barcaM3", "it", 22, 3, true);
    Barca b4 = new Barca ("barcaM4", "it", 4, 3, true);

    // Stampa dei toString dei 4 oggetti Barca appena creati
    System.out.println ("\n" + b1.toString ());
    System.out.println ("\n" + b2.toString ());
    System.out.println ("\n" + b3.toString ());
    System.out.println ("\n" + b4.toString ());
    System.out.println ("");

    // Inserimento delle barche nel porto
    System.out.println ("Inserimento delle barche nel porto");
    porto.assegnaPosto(b1);   // V  --> pos[50]
    porto.assegnaPosto(b2);   // V  --> pos[51]
    porto.assegnaPosto(b3);   // M con lunghezza 22 --> pos[20]
    porto.assegnaPosto(b4);   // M con lunghezza 4 --> pos[0]
    System.out.println ("");

    System.out.println ("Stampa posizioni:");
    System.out.print ("Alla posizione 50: "); porto.infoBarca(50);
    System.out.print ("Alla posizione 51: "); porto.infoBarca(51);
    System.out.print ("Alla posizione 20: "); porto.infoBarca(20);
    System.out.print ("Alla posizione 0: ");  porto.infoBarca(0);
    System.out.println ("");

    // Stampa dell'array contenente le barche italiane
    System.out.println ("Stampa dell'array contenente le barche di nazionalità italiana:");
    for (int i = 0; i < 100; i++) {
      if (porto.nazioni("it")[i] != null) System.out.println (porto.nazioni("it")[i]);
    }
     
  }
  
}