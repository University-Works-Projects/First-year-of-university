/*
    Scrivere un algoritmo che prende in input un albero
    binario T e cancella tutte le foglie
    • L’algoritmo ritorna il riferimento alla radice dell’albero
 */

package es02A_es01;

import TreeNode;

public class Main {
    
    public TreeNode deleteLeaf (TreeNode in_parentNode) {
        if (in_parentNode.getSxNode() != null) deleteLeaf (in_parentNode.getSxNode());
        if (in_parentNode.getDxNode() != null) deleteLeaf (in_parentNode.getDxNode());
        if (in_parentNode.getSxNode() == null && in_parentNode.getDxNode() == null) {
            return null;
        }
        return in_parentNode;

    /* Trash version
        if (in_parentNode.getSxNode() != null && in_parentNode.getDxNode() != null) {
            deleteLeaf (in_parentNode.getSxNode());
            deleteLeaf (in_parentNode.getDxNode());
        } else if (in_parentNode.getSxNode() != null && in_parentNode.getDxNode() == null) {
            deleteLeaf (in_parentNode.getSxNode());
        } else if (in_parentNode.getSxNode() == null && in_parentNode.getDxNode() != null) {
            deleteLeaf (in_parentNode.getDxNode());
        } else {
            return null;
        }
    */

    }

    public static void main (String[] args) {
        TreeNode root = root.TreeNode(7);
        TreeNode tmpSx = tmpSx.TreeNode(4);
        TreeNode tmpDx = tmpDx.TreeNode(3);
        root.setSxNode (tmpSx);
        root.setDxNode (tmpDx);

        System.out.println(root.getSxNode().getValue());
        System.out.println(root.getDxNode().getValue());

    }
}
