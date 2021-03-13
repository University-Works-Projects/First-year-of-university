public class es6 {

    public int sellItems;
    public int totalSellItems;
    public int totalsDiscounted;
    public int oneItemPrice;
    public int lot;
    public int discountedLot;

    public es6 (int in_sellItems, int in_totalSellItems, int in_totalsDiscounted, int in_oneItemPrice, int in_lot, int in_discountedLot) {
        this.sellItems = in_sellItems;
        this.totalSellItems = in_totalSellItems;
        this.totalsDiscounted = in_totalsDiscounted;
        this.oneItemPrice = in_oneItemPrice;
        this.lot = in_lot;
        this.discountedLot = in_discountedLot;
    }

    public void updateSellItems (int in_sellItems) {
        if (in_sellItems > this.lot) {
            this.sellItems += in_sellItems;
            this.oneItemPrice = (this.oneItemPrice / 100) * (100 - this. discountedLot);    // 1% of the original price * dicsountedPrice% = new scounted price 
            this.totalSellItems +=  in_sellItems;
        } else {
            this.sellItems = in_sellItems;
            this.totalSellItems +=  in_sellItems;
        }
    }

    public void showSellItems () {
        System.out.println("Sell items: " + this.sellItems);
        System.out.println("Total of sell items: " + this.totalSellItems);
        System.out.println("Discount: " + this.discountedLot);
    }

    public static void main (String[] args) {
        es6 tmp = new es6 (40, 45, 0, 10, 200, 30);
        tmp.showSellItems();
        System.out.println();
        tmp.updateSellItems(5000);
        tmp.showSellItems();
    }
}