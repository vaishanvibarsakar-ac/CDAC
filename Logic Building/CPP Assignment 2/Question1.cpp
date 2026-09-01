#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productId , quantity;
    string name;
    double price;


public:
    void acceptDetails() {
        cout << "Enter Product ID: ";
        cin >> productId;
        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const {
        cout << productId << "  "
             << name << "  "
             << price << "  "
             << quantity << "  "
             << totalValue() << endl;
    }

    double totalValue() const {
        return price * quantity;
    }

    bool isLowStock(int threshold) const {
        return quantity < threshold;
    }
};

int main1() {
    int size ;
    Product products[size];

    cout<<"Enter the size of the array :";
    cin >> size ;

    cout << "Enter details for " << size << " products:\n";
    for (int i = 0; i < size; i++) {
        cout << "\n--- Product " << (i + 1) << " ---\n";
        products[i].acceptDetails();
    }

    cout << "\n ----------------INVENTORY REPORT ----------------\n";
    cout << "ID  Name  Price  Qty  TotalValue\n";

    double maxValue = -1;
    int maxIndex = -1;

    for (int i = 0; i < size; i++) {
        products[i].displayDetails();
        if (products[i].totalValue() > maxValue) {
            maxValue = products[i].totalValue();
            maxIndex = i;
        }
    }

    cout << "\nHighest Value Product:\n";
    products[maxIndex].displayDetails();

    int threshold;
    cout << "\nEnter stock threshold: ";
    cin >> threshold;

    cout << "\nProducts below threshold (" << threshold << "):\n";
    cout << "ID  Name  Price  Qty  TotalValue\n";
    for (int i = 0; i < size; i++) {
        if (products[i].isLowStock(threshold)) {
            products[i].displayDetails();
        }
    }

    return 0;
}
