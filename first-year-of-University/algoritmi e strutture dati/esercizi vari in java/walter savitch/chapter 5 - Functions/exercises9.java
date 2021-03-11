/**
 * Selection sort
*/

public class exercises9 {

    /**
        public static void change (int a&, int b&){
            System.out.println("First: " + a + " :: " + b);
            int tmp = a; a = b; b = tmp;
            System.out.println("After: " + a + " :: " + b); 
        }
        
        public static void main (String[] args){
            Scanner UserInput = new Scanner(System.in);
            int a = 4, b = 3;
            change(a&, b%);
            System.out.println("AfterAfter: " + a + " :: " + b);
        }
     */

    public static void printsArraysElement (int[] in_a){
        for (int i = 0; i < in_a.length; i++) System.out.println(in_a[i]);
    }

    public static void selectionSort (int[] in_a){
        int tmp = 0;
        for (int i = 0; i < in_a.length; i++){
            tmp = in_a[i];
            for (int j = i; j < in_a.length; j++){
                if (in_a[j] < in_a[i]) {
                    tmp = in_a[j];
                    in_a[j] = in_a[i];
                    in_a[i] = tmp;
                }
            }
        }
    }

    public static void main (String[] args){

        int[] a = {33,44,22,11,43};
        selectionSort(a);
        printsArraysElement (a);

    }

}