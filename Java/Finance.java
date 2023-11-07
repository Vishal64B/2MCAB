//Implement the concept of Class, Data members, Methods, Access Specifier,  Default Constructor, Method Overloading (minimum 3 methods), Constructor overloading (minimum of 2) in your selected domain.

import javax.crypto.spec.DESKeySpec;

public class Finance {

    private String accNumber;
    private String accHolder;
    private double cashBalance;
    private double stockBalance;

    public Finance() {
        System.out.println();
        System.out.println("\t\tWelcome\t\t"); // Default Constructor
    }

    public Finance(String accNumber, String accHolder) {
        this.accNumber = accNumber;
        this.accHolder = accHolder; // Parameterized Constructor. creates Account
        this.cashBalance = 0.0;
        this.stockBalance = 0.0;
    }

    public void createAccount(String accNumber, String accHolder) {
        this.accNumber = accNumber;
        this.accHolder = accHolder; // creates Account

        System.out.println("Account successfully created!!!!\r\n");
        System.out.println("Account Number: " + accNumber);
        System.out.println("Account Holder: " + accHolder);
    }
     public void createAccount(String accNumber, String accHolder, double cashBalance, double stockBalance) {
        this.accNumber = accNumber;
        this.accHolder = accHolder; 
        this.cashBalance = cashBalance;
        this.stockBalance = stockBalance;

        System.out.println("Account successfully created!!!!\r\n");
        System.out.println("Account Number: " + accNumber);
        System.out.println("Account Holder: " + accHolder);
        System.out.println("Cash Balance: " + cashBalance);
        System.out.println("Stock Balance: " + stockBalance);
    }

    public void depositCash(double amount) {
        if (amount > 0) {
            cashBalance += amount; // Deposit Cash
            System.out.println();
            System.out.println("Rs " + amount + " deposited to cash balance.\r\nNew cash balance: Rs " + cashBalance);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    public void depositCash(double amount, String assetType) {
        if (amount > 0) {
            if (assetType.equals("Cash")) {
                cashBalance += amount;
                System.out.println();
                System.out
                        .println("Rs " + amount + " deposited to cash balance.\r\nNew cash balance: Rs" + cashBalance);
            } else if (assetType.equals("Stock")) {

                System.out.println("Stock deposit not supported in this method.You can only deposit Cash");
            } else {
                System.out.println("Invalid asset type.");
            }
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    public void buyStock(double amount) {
        if (amount > 0 && cashBalance >= amount) {
            cashBalance -= amount;
            stockBalance += amount;
            System.out.println("Rs " + amount + " used to buy stocks. New stock balance: Rs" + stockBalance);
        } else {
            System.out.println("Invalid purchase amount or insufficient cash balance.");
        }
    }

    public void displayBalances() {
        System.out.println("Account Balances for " + accHolder + ":");
        System.out.println("Cash Balance: Rs " + cashBalance);
        System.out.println("Stock Balance: Rs " + stockBalance);
    }

    public static void main(String[] args) {

        ///Using default constructor
        Finance p1 = new Finance();
        p1.createAccount("101", "Jack");
        p1.depositCash(1000);
        p1.depositCash(500, "Cash");

        p1.displayBalances();

        //using paramterized constructor
        Finance p2 = new Finance("102", "Vishal");

        p2.depositCash(5000);
        p2.depositCash(3000, "Cash");
        p2.buyStock(3000);

        p2.displayBalances();

        
        Finance p3 = new Finance();
        p3.createAccount("103", "Vikram" , 1304 , 4000);
        p2.displayBalances();;



    }
}