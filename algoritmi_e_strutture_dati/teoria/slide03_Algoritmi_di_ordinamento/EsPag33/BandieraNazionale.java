package first_year_of_university.algoritmi_e_strutture_dati.teoria.slide03_Algoritmi_di_ordinamento.EsPag33;

import java.lang.Math.*;

public class BandieraNazionale {

  public static final int SIZE = 15;
  public static final int LIMIT = 3;

  public static void change (Colors[] in_arr, int in_pos, boolean in_last) {
    Colors tmp = in_arr[in_pos];
    if (in_last) {
      in_arr[in_pos] = in_arr[in_arr.length - 1];
      in_arr[in_arr.length - 1] = tmp;
    } else {
      in_arr[in_pos] = in_arr[0];
      in_arr[0] = tmp;
    }
  }

  public static void reorder (Colors[] in_arr) {
    for (int pos = 0; pos < in_arr.length; pos++) {                // Per ogni elemento dell'array
      if (in_arr[pos] == Colors.GREEN) {                           // Se il colore è bianco
        System.out.println("V ; pos: " + pos + " ; in_arr[pos]: " + in_arr[pos]);
        change (in_arr, pos, false);                      // Lo si sposta l'elemento in questione in cima all'array
      } else if (in_arr[pos] == Colors.RED) {                         // Se il colore è rosso
        System.out.println("R ; pos: " + pos + " ; in_arr[pos]: " + in_arr[pos]);
        change (in_arr, pos, true);                       // Lo si sposta in fondo
      }

    }
    printArr (in_arr);

  }

  public static void printArr (Colors[] in_arr) {
    for (int pos = 0; pos < in_arr.length; pos++) {
      System.out.println("colore n." + pos + " -> " + in_arr[pos]);
    }
  }

  public static void main (String[] args) {
    Colors[] colorArr = new Colors[SIZE];

    for (int el = 0; el < SIZE; el++) {
      int n = (int) (Math.random() * LIMIT);          // Genera numeri n:  0 <= n < LIMIT
      if (n == 0) colorArr[el] = Colors.WHITE;
      else if (n == 1) colorArr[el] = Colors.RED;
      else colorArr[el] = Colors.GREEN;
    }

    printArr (colorArr);
    reorder (colorArr);

    System.out.println("");
    System.out.println("");
    System.out.println("");

    //printArr (colorArr);

  }


}
