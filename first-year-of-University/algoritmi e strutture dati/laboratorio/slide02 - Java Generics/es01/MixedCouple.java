package es01;

public class MixedCouple <A, B> {
    protected A first;
    protected B second;

    public CoppiaMista(A in_first, B in_second) {
        this.first = in_first;
        this.second = in_second;
    }
    
    public A getFirst() { return primo; }
    public B getSecond() { return secondo; }
    
    public Boolean checkOmogenei(){
        return (this.primo.getClass() == this.secondo.getClass());
    }
}
