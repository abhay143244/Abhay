#include <iostream>
#include <string>
using namespace std;

class Product {
public:

    enum Category {
        FOOD,
        STATIONERY,
        CLOTHES
    };

private:
    int productID;
    string name;
    float price;
    int stock;
    Category category;

public:

    // Constructor
    Product(int id, string n, float p, int s, Category c) {
        productID = id;
        name = n;
        price = p;
        stock = s;
        category = c;
    }

    // Display product
    void displayProduct() {
        cout << "\n--- Product Details ---\n";
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;

        cout << "Category: ";

        if (category == FOOD)
            cout << "Food";
        else if (category == STATIONERY)
            cout << "Stationery";
        else
            cout << "Clothes";

        cout << endl;
    }

    // Update stock
    void updateStock(int quantity) {

        if (stock + quantity >= 0) {
            stock = stock + quantity;
            cout << "Stock updated successfully.\n";
            cout << "New stock: " << stock << endl;
        }
        else {
            cout << "Stock cannot be negative.\n";
        }
    }

    // Check availability
    void checkAvailability() {

        if (stock > 0)
            cout << name << " is Available.\n";
        else
            cout << name << " is Not Available.\n";
    }
};


// ================= CUSTOMER =================

class Customer {

private:
    int customerID;
    string name;
    string email;
    string phone;
    string address;

public:

    // Constructor
    Customer(int id, string n, string e, string p, string a) {
        customerID = id;
        name = n;
        email = e;
        phone = p;
        address = a;
    }

    // Display customer
    void displayCustomer() {

        cout << "\n--- Customer Details ---\n";
        cout << "Customer ID: " << customerID << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
    }

    // Update customer details
    void updateCustomer(string n, string e, string p, string a) {

        name = n;
        email = e;
        phone = p;
        address = a;

        cout << "Customer details updated successfully.\n";
    }
};


// ================= ORDER =================

// Order status enum
enum OrderStatus {
    PENDING,
    CONFIRMED,
    CANCELLED
};

// Payment status enum
enum PaymentStatus {
    PAYMENT_PENDING,
    PAYMENT_COMPLETED
};

// Payment method enum
enum PaymentMethod {
    CREDIT_CARD,
    UPI,
    CASH
};


// ================= PAYMENT UNION =================

union Payment {

    long long cardNumber;
    char upiID[50];
    float cashAmount;
};


// ================= ORDER STRUCT =================

struct Order {

    int orderID;
    int customerID;
    float totalAmount;

    OrderStatus orderStatus;
    PaymentStatus paymentStatus;

    PaymentMethod paymentMethod;
    Payment payment;


    // Create order
    void createOrder(int oid, int cid, float amount,
                     PaymentMethod method) {

        orderID = oid;
        customerID = cid;
        totalAmount = amount;

        orderStatus = PENDING;
        paymentStatus = PAYMENT_PENDING;

        paymentMethod = method;

        cout << "Order created successfully.\n";
    }


    // Confirm order
    void confirmOrder() {

        if (orderStatus == CANCELLED) {
            cout << "Cancelled order cannot be confirmed.\n";
        }
        else {
            orderStatus = CONFIRMED;
            cout << "Order confirmed.\n";
        }
    }


    // Cancel order
    void cancelOrder() {

        if (orderStatus == CONFIRMED) {
            cout << "Confirmed order cannot be cancelled.\n";
        }
        else {
            orderStatus = CANCELLED;
            cout << "Order cancelled.\n";
        }
    }


    // Update order
    void updateOrder(float amount) {

        if (orderStatus == PENDING) {
            totalAmount = amount;
            cout << "Order updated successfully.\n";
        }
        else {
            cout << "Only pending orders can be updated.\n";
        }
    }


    // Display order
    void displayOrder() {

        cout << "\n--- Order Details ---\n";

        cout << "Order ID: " << orderID << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Total Amount: " << totalAmount << endl;


        cout << "Order Status: ";

        if (orderStatus == PENDING)
            cout << "Pending";
        else if (orderStatus == CONFIRMED)
            cout << "Confirmed";
        else
            cout << "Cancelled";

        cout << endl;


        cout << "Payment Status: ";

        if (paymentStatus == PAYMENT_PENDING)
            cout << "Pending";
        else
            cout << "Completed";

        cout << endl;


        cout << "Payment Method: ";

        if (paymentMethod == CREDIT_CARD)
            cout << "Credit Card";
        else if (paymentMethod == UPI)
            cout << "UPI";
        else
            cout << "Cash";

        cout << endl;
    }
};


// ================= MAIN =================

int main() {

    // ---------- PRODUCTS ----------

    Product p1(101, "Apple", 30, 10, Product::FOOD);

    Product p2(102, "Pen", 5, 20, Product::STATIONERY);

    Product p3(103, "Shirt", 500, 5, Product::CLOTHES);


    p1.displayProduct();
    p2.displayProduct();
    p3.displayProduct();

    p1.checkAvailability();

    p1.updateStock(5);

    p1.displayProduct();


    // ---------- CUSTOMER ----------

    Customer c1(
        201,
        "Abhay",
        "abhay@gmail.com",
        "9876543210",
        "Ludhiana"
    );

    c1.displayCustomer();


    // Update customer

    c1.updateCustomer(
        "Abhay Kumar",
        "abhay123@gmail.com",
        "9999999999",
        "Punjab"
    );

    c1.displayCustomer();


    // ---------- ORDER ----------

    Order o1;

    o1.createOrder(
        301,
        201,
        530,
        UPI
    );

    o1.displayOrder();


    // Confirm order

    o1.confirmOrder();

    o1.displayOrder();


    return 0;
}