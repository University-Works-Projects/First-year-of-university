// Da aggiungere altre informazioni simil consegna


public class Main {
    public static class ProgramContainer {
        
        public Object[][] programContainer;    // [container] [program]
    
        public ProgramContainer (int in_containers, int in_programs) {
            this.programContainer = new Object[in_containers][in_programs];
            setEmpty ();
        }
        
        public void setEmpty () {
            for (int i = 0; i < programContainer.length; i++) {            // For all containers
                for (int j = 0; j < programContainer[i].length; j++) {     // For all programs
                    this.programContainer[i][j] = -1;
                }
            }
        }
        
        public void printAllContainters () {
            for (int i = 0; i < programContainer.length; i++) {            // For all containers
                System.out.print("Container: " + i + " --> Elements: ");
                for (int j = 0; j < programContainer[i].length; j++) {     // For all programs
                    System.out.print(programContainer[i][j] + " ");
                }
                System.out.println("");
            }
        }
        
        public void printContainer (int in_container) {
            for (int i = 0; i < programContainer[in_container].length; i++){
                System.out.print(programContainer[in_container][i] + " ");
            }
            //System.out.println("");
        }
        
        public Object getProgram (int in_container, int in_program) {
            return this.programContainer[in_container][in_program];
        }
        
        public void setProgram (int in_container, int in_program, Object in_newProgram) {
            this.programContainer[in_container][in_program] = in_newProgram;
        }
        
        public void deleteProgram (int in_container, int in_program) {
            this.programContainer[in_container][in_program] = -1;
        }
    
        public int getN (int in_container) {
            int res = 0; Object tmp = -1;
            for (int i = 0; i < programContainer[in_container].length; i++) {
                if (programContainer[in_container][i] != tmp) res++;
            }
            return res;
        }
        
        public int elementPosition (int in_container, Object in_searchedProgram) {
            for (int i = 0; i < programContainer[in_container].length; i++) {
                if (programContainer[in_container][i] == in_searchedProgram) return i;
            }
            return -1;
        }
        
        public String toString (int in_container) {
            String tmp = "";
            for (int i = 0; i < programContainer[in_container].length; i++) {
                tmp += programContainer[in_container][i];
            }
            return tmp;
        }
        
        public int compareConteiners (int in_container1, int in_container2) {  // Si assume in_container1 == in_container2
            int counter = 0;
            for (int i = 0; i < in_container1; i++) {
                if (programContainer[in_container1][i] == programContainer[in_container2][i]) counter++;
            }
            return counter;
        }
    
    }

    public static void main (String[] args) {
        // Creazione dell'oggetto
        System.out.println("Creating a new ProgramContainer (5x5) and set it empty:");
        ProgramContainer tmp1 = new ProgramContainer (5, 5);
        tmp1.setEmpty();
        tmp1.printAllContainters();
        System.out.println("");
        
        // Setting di un'elemento specifico e stampa del container
        System.out.println("Set program 3 of contianer 2 to 44 (print container 2):");
        tmp1.setProgram(2, 3, 44);
        tmp1.printContainer(2);
        System.out.println("\n");
        
        // Getting di un'elemento specifico + Deleting di un'elemento specifo + stampe
        System.out.println("Getting program 3 from container 2: " + tmp1.getProgram(2, 3));
        System.out.println("Delete  program 3 from container 2");
        tmp1.deleteProgram(2,3);
        System.out.println("Getting program 3 from container 2 (after deleting): " + tmp1.getProgram(2, 3));
        System.out.println("");
        
        // Setting di un'intero container e stampa di quest'ultimo
        System.out.println("Setting programs of container 1 from 0 to 4");
        tmp1.setProgram(0, 0, 23);
        tmp1.setProgram(0, 1, 23);
        tmp1.setProgram(0, 2, 23);
        tmp1.setProgram(0, 2, 23);
        tmp1.setProgram(0, 4, 23);
        System.out.println("Print of container 0: ");
        tmp1.printContainer(2);
        System.out.println("\n");
        
        // Stampa del numero di elementi presenti in due diversi containers
        System.out.println("Number of programs in:");
        System.out.print("Container 0 (");
        tmp1.printContainer(0);
        System.out.println(") --> " + tmp1.getN(0));
        System.out.print("Container 3 (");
        tmp1.printContainer(3);
        System.out.println(") --> " + tmp1.getN(3));
        System.out.println("");
        
        
        // Setting di un'elemento specifico e stampa della sua posizione + Stmapa posizione di un elemento non presente
        System.out.println("Setting program 4 of container 4 to 5:"); 
        tmp1.setProgram(4, 4, 5);
        tmp1.printContainer(3);
        System.out.println("");
        System.out.println("Print the position of element 5 in container 5: " + tmp1.elementPosition(4, 5));
        System.out.println("Print the position of element 3 in container 5: " + tmp1.elementPosition(4, 2));
        System.out.println("");
        
        // Test del metodo toString --> Ritorna sottoforma di stringa il contenuto di un container
        System.out.println("toString method (return the programs of a container in a string form): ");
        System.out.println(tmp1.toString(3));
        System.out.println("");
        
        // Stampa la quantità di elementi in comune dei containers 2 e 4
        System.out.println("Print commons elements of containers 4 and 2: " + tmp1.compareConteiners(4, 2));
        
    }

}