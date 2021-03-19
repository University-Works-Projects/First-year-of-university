public class MixedCouple <A, B> {
    protected A primo;
    protected B secondo;

    public CoppiaMista(A primo, B secondo) {
        this.primo = primo;
        this.secondo = secondo;
    }
    
    public A getPrimo() { return primo; }
    public B getSecondo() { return secondo; }
    
    public Boolean checkOmogenei(){
        return (this.primo.getClass() == this.secondo.getClass());
    }
}
