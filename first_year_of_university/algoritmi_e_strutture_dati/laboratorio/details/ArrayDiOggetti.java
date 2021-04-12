public class ArrayDiOggetti {
    
    public static class Martello {          // Classe dell'oggetto
        public int peso;
        public String nome;
        public Martello (int n, String in_nome) { this.peso = n; this.nome = in_nome; }
    }
    
    public static class ArrayMartelli {     // Classe dell'array dell'oggetto
        public Martello[] array;
        
        public ArrayMartelli (int n) {
            array = new Martello[n];
        }
        
        public void ass (Martello m, int pos) {this.array[pos] = m;} 
        
    }
    
    
	public static void main(String[] args) {
		ArrayMartelli tmp1 = new ArrayMartelli (3);
		
		for (int i = 0; i < tmp1.array.length; i++) {
		    System.out.println(tmp1.array[i]);
		}
		
		System.out.println("");
		System.out.println("");
		System.out.println("");

		Martello m1 = new Martello(1,"abc");
		Martello m2 = new Martello(2,"bac");
		Martello m3 = new Martello(3,"acb");
		tmp1.ass(m1, 0);
		tmp1.ass(m2, 1);
		tmp1.ass(m3, 2);
		
		for (int i = 0; i < tmp1.array.length; i++) {
		    System.out.println(tmp1.array[i]);
		}
		
	}
}
