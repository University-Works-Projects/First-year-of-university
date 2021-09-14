//import java.util.Scanner;

public class fibonacci {

    // Es 1
    // SI ASSUME: n >= 0
    public static int fibonacci_v1 (int n){
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else return (fibonacci_v1 (--n) + fibonacci_v1 (n - 2));
    }

    /* INCOMPLETO
    public static int fibonacci_v1 (int n, int in_f1, int in_f2){
        if (n > 1){
            int f1 = in_f1, f2 = in_f2;

        }
        else if (n == 1) return 1;
        else return 0;
    }
    */


    // ------------------------------------------------------------------------------------------

    public static void main(String []args){

        


    }

}
