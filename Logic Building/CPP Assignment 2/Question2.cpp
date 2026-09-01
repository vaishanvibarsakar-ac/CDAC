#include <iostream>
using namespace std;


double reorderCost(int qty, double unitPrice) {
    return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice) {
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate) {
    return qty * unitPrice * (1 + taxRate);
}


double applyDiscount(double price, double discountPercent = 10.0) {
    return price - (price * discountPercent / 100.0);
}

int main2() {

    cout << "Reorder cost (int qty): " << reorderCost(50, 20.0) << endl;
    cout << "Reorder cost (double qty): " << reorderCost(12.5, 15.0) << endl;
    cout << "Reorder cost (with tax): " << reorderCost(100, 5.0, 0.18) << endl;
    cout << "Price after default discount: " << applyDiscount(200.0) << endl;
    cout << "Price after 25% discount: " << applyDiscount(200.0, 25.0) << endl;

    return 0;
}
