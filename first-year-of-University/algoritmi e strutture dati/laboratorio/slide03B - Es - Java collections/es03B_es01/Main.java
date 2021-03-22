// Import the LinkedList and ArrayDeque class
import java.util.LinkedList;
import java.util.ArrayDeque;

public class Main {


    public static void main (String[] args) {
        
        //LinkedList<Type> tmp1 = new LinkedList<Integer>();

        LinkedList<Integer> tmp1 = new LinkedList<Integer>();

        System.out.println("tmp1 is empty: " + tmp1);
        tmp1.add (5);
        tmp1.add (3);
        System.out.println("add 5 and 3: " + tmp1);
        tmp1.remove();
        tmp1.add (2);
        tmp1.add (8);
        System.out.println("remove first element (5), add 2 and 8: " + tmp1);
        tmp1.remove();
        tmp1.add (4);
        System.out.println("remove first element (3), add 4: " + tmp1);

        System.out.println("-----------------------------------------");

        LinkedList<Integer> tmp2 = new LinkedList<Integer>();

        System.out.println("tmp2 is empty: " + tmp2);
        tmp2.addFirst (3);
        System.out.println("addFirst 3: " + tmp2);
        tmp2.addLast (8);
        System.out.println("addLast 8: " + tmp2);
        tmp2.addFirst (2);
        System.out.println("addFirst 2: " + tmp2);
        tmp2.removeLast ();
        System.out.println("removeLast (8): " + tmp2);
        tmp2.addLast (7);
        System.out.println("addLast 7: " + tmp2);
        tmp2.addLast (4);
        System.out.println("addLast 4: " + tmp2);
        tmp2.removeFirst ();
        System.out.println("removeFirst (2): " + tmp2);
        tmp2.removeFirst ();
        System.out.println("removeFirst (3): " + tmp2);

    }
}
