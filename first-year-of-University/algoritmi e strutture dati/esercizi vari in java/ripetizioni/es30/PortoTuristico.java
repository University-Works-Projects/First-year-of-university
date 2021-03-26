public class PortoTuristico {
    public static final int posti = 100;
  
    public static class Barca {
      public String nome;
      public String nazione;
      public float lunghezza;
      public float peso;            // Espresso in tonnellate
      public boolean motore;
      public boolean vela;
  
      public Barca (String in_nome, String in_nazione, float in_lunghezza,  float in_peso, boolean in_motore) {
        this.nome = in_nome;
        this.nazione = in_nazione;
        this.lunghezza = in_lunghezza;
        this.peso = in_peso;
        this.motore = in_motore;
        this.vela = !in_motore;
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
      public void setMotore (boolean in_motore) { this.motore = in_motore; this.vela = !in_motore; }
      
    }
  
    public static class StackBarche {
      protected Barca[] arrayBarche;
      protected int posM, posV, barcheM, barcheV;
      protected final int prezzoM;
      protected final int prezzoV;
  
      public StackBarche () {
        this.arrayBarche = new Barca[posti];    // Gli elementi (in questo caso gli oggetti Barca) sono inizializzati a null !!!!!
        this.posM = 0;                        // La posizione indicherà il primo spazio disponibile nell'array, dunque ponendo che vi sia almeno un barcha a motore --> posM = null, posM - 1 = barca
        this.posV = 50;
        this.barcheM = 0;
        this.barcheV = 0;
        this.prezzoM = 20;
        this.prezzoV = 10;
      }
      
      public int getPosM () { return this.posM; }
      public void setPosM ( int in_posM ) { this.posM = in_posM; }
  
      public int getPosV () { return this.posV; }
      public void setPosV ( int in_posV ) { this.posV = in_posV; }
      
      public int getBarcheM () { return this.barcheM; }
      public void setBarcheM ( int in_barcheM ) { this.barcheM = in_barcheM; }
      
      public int getBarcheV () { return this.barcheV; }
      public void setBarcheV ( int in_barcheV ) { this.barcheV = in_barcheV; }
  
      public int getPrezzoV () { return this.prezzoM; }
      public int getPrezzoM () { return this.prezzoV; }
  
      public void increasePosM () { this.posM += 1; }
      public void increasePosV () { this.posV += 1; }
      public void increaseBarcheM () { this.barcheM += 1; }
      public void increaseBarcheV () { this.barcheV += 1; }
  
      public Barca getBarca (int in_pos) { return arrayBarche[in_pos]; }
  
      public void assegnaPosto (Barca in_barca) {
        //try {...} catch (outofboundaaaaa)
        if (in_barca.getMotore()) {
          if (in_barca.getLunghezza() > 10) {
            for (int i = 20; i < 50; i++) {                                                     // Si scorrono tutti i 30 posti per le barche con lunghezza > 10m per trovarne uno libero
              if (arrayBarche[i] != null) {
                arrayBarche[posM] = in_barca;
                increasePosM ();
                increaseBarcheM ();
                break;
              }
            }
            System.out.println ("Barca a motore con lunghezza > 10m, posto non disponibile.");  // Se il programma arriva qui significa che non c'è posto
          } else {
            for (int i = 0; i < 50; i++) {
              if (arrayBarche[i] != null) {
                arrayBarche[posM] = in_barca;
                increasePosM ();
                increaseBarcheM ();
                break;
              }
            }
          }
        } else {
          for (int i = 50; i < 100; i++) {
              if (arrayBarche[i] != null) {
                arrayBarche[posV] = in_barca;
                increasePosV ();
                increaseBarcheV ();
                break;
              }
            }
        }
        // catch (..) {..}
      }
  
      public int rimozione (int in_pos, int in_giorni) {
        //try
        if (arrayBarche[in_pos] != null) {
          if (arrayBarche[in_pos].getMotore()){                  // NOTA BENE LA SINTASSI arrayBarche.getBarca (in_pos) è ERRATO !!!
            arrayBarche[in_pos] = null;                          // Si elimina la barca
            return this.prezzoM * in_giorni; 
          } else {
            arrayBarche[in_pos] = null;                          // Si elimina la barca
            return this.prezzoM * in_giorni;           
          }
        } else {
          System.out.println("Posizione in input invalida, la posizione selezionata è libera.");
          return -1;
        }
        //catch
      }
  
      public void infoBarca (int in_pos) {
        // controllo (in_pos)     //funzione che controlla l'inserimento di una posizione valida
        // Fa i vari System.out.println() delle info della barca
      }
  
      public String[] nazioni (String in_nazione) {
        String[] arrayNazioni = new String[posti];
        int arrayPos = 0;
        for (int i = 0; i < 100; i++) {
          if (arrayBarche[i].getNazione() == in_nazione) {
            arrayNazioni[arrayPos] = arrayBarche[i].getNome();
            arrayPos++;
          }
        }
        return arrayNazioni;
      }
  
    }
  
    public static void main (String[] args) {
      Barca tmp = new Barca ("tag","it",4,3,true);
      System.out.println(tmp.motore);                 // Questa cosa è lecita, stmpa il relativo valore booleano
      
      StackBarche porto = new StackBarche ();
      
  
    }
  }