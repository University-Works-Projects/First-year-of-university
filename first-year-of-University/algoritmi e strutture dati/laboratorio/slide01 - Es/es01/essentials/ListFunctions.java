package es01.essentials;

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
     * Return list's length from head node
     */
    public int listLength (Node in_headNode) {
        int length = 0;
        while (in_headNode != null) {
            length++;
            in_headNode = in_headNode.getNextNode ();
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
    public void headRemove () {
        if (headNode != null) headNode = headNode.getNextNode();
        else {
            System.out.println ("Nothing to remove");
            System.exit(0);
        }
    }

    /**
     * Search an element in a list
     */
    public boolean searchElement (int in_intValue) {
        Node tmpHeadNode = this.headNode;
        while (tmpHeadNode != null) {
            if (tmpHeadNode.getIntValue() == in_intValue) return true;
            tmpHeadNode = tmpHeadNode.getNextNode ();
        }
        return false;
    }

    /** DA TESTARE
     * Remove all elements with intValue equals to input intValue
     */
    public void removeElement (int in_intValue) {
        Node tmpHeadNode = this.headNode;
        while (tmpHeadNode != null) {
            if (tmpHeadNode.getIntValue() == in_intValue) tmpHeadNode = tmpHeadNode.getNextNode();
            tmpHeadNode = tmpHeadNode.getNextNode ();
        }
    }

}
