package slide01;

private final class Record {
    public Object element;
    public Comparable key;
    public Record next;
    public Record prev;

    public Record (Object e, Comparable k) {
        this.elem = e;
        this.key = k;
        next = prev = null;
    }

}