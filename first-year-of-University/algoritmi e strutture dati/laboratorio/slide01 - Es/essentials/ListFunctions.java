package essentials;

public class ListFunctions {
    private Node headNode;

    public ListFunctions () { this.headNode = null; }

    /**
     * Show intValue of list's elements
     */
    public void showIntValue () {
        Node tmpHeadNode = this.headNode;
        while (tmpHeadNode != null) {
            System.out.println (tmpHeadNode.getIntValue ());
            tmpHeadNode = tmpHeadNode.getNextNode ();
        }
    }

    /**
     * Return list's length
     */
    public int listLength () {
        Node tmpHeadNode = headNode;
        int length = 0;
        while (tmpHeadNode != null) {
            length++;
            tmpHeadNode = tmpHeadNode.getNextNode ();
        }
        return length;
    }

    /**
     * Head insert of existing node
     */
    public void headInsert (Node in_newNode) {
        this.headNode = in_newNode;
    }

    /**
     * Head insert of new node
     */
    public void newHeadInsert (int in_intValue) {
        this.headNode = new Node(in_intValue, this.headNode);
    }

    /**
     * Head remove
     */
    public void headremove () {
        if (headNode != null) headNode = headNode.getNextNode();
        else {
            System.out.println ("Nothing to remove");
            System.exit(0);
        }
    }



    public boolean searchElement (Node in_node) {

    }

    // Rimuovi un elemento specifico


}
