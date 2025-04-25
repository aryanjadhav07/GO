
abstract class Plan {
    protected double rate;

    abstract void setRate();

    public void calculateBill(int units) {
        System.out.println("Total Bill: ₹" + (rate * units));
    }
}


class DomesticPlan extends Plan {
    @Override
    void setRate() {
        rate = 3.50;
    }
}

class CommercialPlan extends Plan {
    @Override
    void setRate() {
        rate = 7.00;
    }
}

public class Assignment_5{

    public static void main(String[] args) {
        int units = 120;

        Plan domestic = new DomesticPlan();
        domestic.setRate();
        System.out.println("Domestic Plan:");
        domestic.calculateBill(units);

        Plan commercial = new CommercialPlan();
        commercial.setRate();
        System.out.println("\nCommercial Plan:");
        commercial.calculateBill(units);
    }
}

