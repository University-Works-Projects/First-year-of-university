// Circolar record

package essentials;

//protected final class RecordForEx {
public final class RecordForEx {
    
    public int value;
    public Record next;
    public Record prev;

    public RecordForEx (int in_value) {
        this.value = in_value;
        next = prev = null;
    }

}