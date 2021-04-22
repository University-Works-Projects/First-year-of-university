package EsPag33;

import java.lang.Math.*;

public class BandieraNazionale {

  public static final int SIZE = 10;
  public static final int LIMIT = 3;



  public static void main (String[] args) {
    //Colors[] colorArr = new Colors[SIZE];
    char[] colorArr = new char[SIZE];

    for (int el = 0; el < SIZE; el++) {
      int n = (int) (Math.random() * LIMIT);      // Genera numeri n:  0 <= n < LIMIT
      System.out.println("random n: " + n);
      if (n == 0) colorArr[el] = 'v'; //Colors.GREEN;
      else if (n == 1) colorArr[el] = 'b'; //Colors.WHITE;
      else colorArr[el] = 'r'; //Colors.RED;
    }

  }


}
