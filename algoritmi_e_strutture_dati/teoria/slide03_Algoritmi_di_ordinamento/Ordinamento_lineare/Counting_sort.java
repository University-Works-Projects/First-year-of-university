package first_year_of_university.algoritmi_e_strutture_dati.teoria.slide03_Algoritmi_di_ordinamento.Ordinamento_lineare;

public class Counting_sort {
    
    public static void countingSort (int[] A, int k) {
        int[] Y = new int[k];
        int j = 0;
        for (int i = 0; i < k; i++) Y[i] = 0;
        for (int i = 0; i < A.length; i++) Y[A[i]]++;
        for (int i = 0; i < k; i++) {
            while (Y[i] > 0) {
                A[j] = i;
                j++;
                Y[i]--;
            }
        }
    }

    public static void main (String[] args) {

    }

}
