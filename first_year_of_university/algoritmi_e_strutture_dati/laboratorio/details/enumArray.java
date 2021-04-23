package first_year_of_university.algoritmi_e_strutture_dati.laboratorio.details;

//

public class enumArray {

  public static void main (String[] args) {
    Prova[] arr = new Prova[5];   // Creazione di array con 5 elemneti enum
    arr[0] = Prova.VAL1;          // Si setta il primo elemento 
    System.out.println(arr[0]);   // Stampa del primo elemento

  }

}


enum Prova {
  VAL1,
  VAL2,
  VAL3;
}
