public class Main {
    
    public class Vagone {       // Classe padre
        public int codice;
        public int pesoVagone;
        public int anno;
        public String azienda;

    }

    public class VagonePasseggeri extends Vagone {
        public int classe;
        public int postiDisponibili;
        public int postioccupati;
    }

    public class VagoneMerci extends Vagone {
        public int volume;
        public int pesoMax;
        public int pesoEffettivo;
    }

}
