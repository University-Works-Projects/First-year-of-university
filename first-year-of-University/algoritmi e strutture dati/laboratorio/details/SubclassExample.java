public class SubclassExample {
    
    public static class Class1 {
        public int var1;
        public Class1 (int in_var1) { this.var1 = in_var1; }
        public int getVar1 () { return this.var1; }
        public void setVar1 (int in_var1) { this.var1 = in_var1; }
    }
    
    public static class Class2 extends Class1 {
        public int var2;
        public Class2 (int in_var1, int in_var2) {
            super (in_var1);
            this.var2 = in_var2;
        }
        public int getVar1 () { return this.var1; }
        public int getVar2 () { return this.var2; }
        public void setVars (int in_var1, int in_var2) {
            this.var1 = in_var1;
            this.var2 = in_var2;
        }
    }
    
	public static void main(String[] args) {
	    Class1 tmp1 = new Class1 (5);
	    Class2 tmp2 = new Class2 (5, 6);
	    
		System.out.println("tmp1 value: " + tmp1.getVar1());
		System.out.println("tmp2 values: " + tmp2.getVar1() + " " + tmp2.getVar2());
	}
	
}