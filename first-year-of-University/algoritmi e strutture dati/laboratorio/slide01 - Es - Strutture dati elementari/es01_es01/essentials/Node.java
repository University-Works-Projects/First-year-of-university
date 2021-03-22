// Monodirection record

package es01_es01.essentials;

public final class Node {
    
    public int intValue;
    public Node nextNode;

    public Node (int in_intValue, Node in_nextNode) {
        this.intValue = in_intValue;
        this.nextNode = in_nextNode;
    }

    public int getIntValue () { return this.intValue; }
    
    public void setIntValue (int in_intValue) { this.intValue = in_intValue; }

    public Node getNextNode () { return this.nextNode; }
    
    public void setNextNode (Node in_nextNode) { this.nextNode = in_nextNode; }

}