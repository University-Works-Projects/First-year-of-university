public class es6 {

    public int sellItems;
    public int totalSellItems;
    public int totalsDiscounted;
    public int oneItemPrice;
    public int lot;
    public int discountedLot;

    public es6 (int in_sellItems, int in_totalSellItems, int in_totalsDiscounted, int in_oneItemPrice int in_lot, int in_discountedLot) {
        this.sellItems = in_sellItems;
        this.totalSellItems = in_sellItems;
        this.totalsDiscounted = in_totalsDiscounte;
        this.oneItemPrice = in_oneItemPrice;
        this.lot = in_lot;
        this.discountedLot = in_discountedLot;
    }

    public void updateSellItems (int in_sellItems) {
        if (in_sellItems > this.lot) {
            this.oneItemPrice = (this.oneItemPrice / 100) * (100 - this. discountedLot);    // 1% of the original price * dicsountedPrice% = new scounted price 
        } else {
            this.sellItems = in_sellItems;           
        }
    }

    public void showSellItems () {
        System.out.println("Sell items: " + this.sellItems);
        System.out.println("Total of sell items: " + this.totalSellItems);
        System.out.println("Discount: " + this.discountedLot);
    }

    public static void main (String[] args) {
        System.out.println("lol");
    }
}