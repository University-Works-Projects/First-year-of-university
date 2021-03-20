package es01;

import org.graalvm.compiler.phases.common.RemoveValueProxyPhase;

public class TreeNode {
    //public boolean radice;
    public int value;
    public TreeNode sxNode;
    public TreeNode dxNode;

    public Treenode (int in_value) {
        this.value = in_value;
        this.sxNode = null;
        this.dxNode = null;
    }

    public Treenode (int in_value, TreeNode in_sxNode, TreeNode in_dxNode) {
        this.value = in_value;
        this.sxNode = in_sxNode;
        this.dxNode = in_dxNode;
    }

    public int getValue () { return sthis.value; }

    public void setValue (int in_value) { this.value = in_value; }
    
    public TreeNode getSxNode () { return this.sxNode; }

    public void setSxNode (TreeNode in_sxNode) { this.sxNode = in_sxNode; }

    public TreeNode getDxNode () { return this.dxNode; }

    public void setDxNode (TreeNode in_dxNode) { this.dxNode = in_dxNode; }

}
