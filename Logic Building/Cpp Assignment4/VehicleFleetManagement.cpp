#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ===== Base Class =====
class Vehicle {
protected:
    string registrationNo;
    string ownerName;
    double kmDriven;

public:
    Vehicle(const string& reg, const string& owner, double km)
        : registrationNo(reg), ownerName(owner), kmDriven(km) {
        cout << "[Vehicle Constructor] " << registrationNo << endl;
    }

    virtual ~Vehicle() {
        cout << "[Vehicle Destructor] " << registrationNo << endl;
    }

    virtual double fuelCost(double kmToTravel) const = 0;
    virtual void describe() const {
        cout << registrationNo << " owned by " << ownerName
             << " (Km Driven: " << kmDriven << ")";
    }
    virtual string vehicleType() const = 0;

    string getRegNo() const { return registrationNo; }
    double getKmDriven() const { return kmDriven; }
};

// ===== Car =====
class Car : public Vehicle {
    string fuelType;
    double mileageKmpl;

public:
    Car(const string& reg, const string& owner, double km,
        const string& fuel, double mileage)
        : Vehicle(reg, owner, km), fuelType(fuel), mileageKmpl(mileage) {
        cout << "[Car Constructor] " << registrationNo << endl;
    }

    ~Car() { cout << "[Car Destructor] " << registrationNo << endl; }

    double fuelCost(double kmToTravel) const override {
        double price = (fuelType == "Petrol") ? 106.0 : 93.0;
        return (kmToTravel / mileageKmpl) * price;
    }

    string vehicleType() const override { return "Car"; }

    void describe() const override {
        Vehicle::describe();
        cout << " | Fuel: " << fuelType << ", Mileage: " << mileageKmpl << " kmpl";
    }
};

// ===== Truck =====
class Truck : public Vehicle {
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:
    Truck(const string& reg, const string& owner, double km,
          double payload, double efficiency)
        : Vehicle(reg, owner, km),
          payloadCapacityTons(payload), fuelEfficiencyKmpl(efficiency) {
        cout << "[Truck Constructor] " << registrationNo << endl;
    }

    ~Truck() { cout << "[Truck Destructor] " << registrationNo << endl; }

    double fuelCost(double kmToTravel) const override {
        double effectiveEfficiency = fuelEfficiencyKmpl * (1 - 0.05 * payloadCapacityTons);
        return (kmToTravel / effectiveEfficiency) * 93.0; // Diesel
    }

    string vehicleType() const override { return "Truck"; }

    void describe() const override {
        Vehicle::describe();
        cout << " | Payload: " << payloadCapacityTons << " tons, Efficiency: "
             << fuelEfficiencyKmpl << " kmpl";
    }
};

// ===== ElectricTruck =====
class ElectricTruck : public Truck {
    double batteryCapacityKWh;
    double rangePerChargeKm;

public:
    ElectricTruck(const string& reg, const string& owner, double km,
                  double payload, double efficiency,
                  double battery, double range)
        : Truck(reg, owner, km, payload, efficiency),
          batteryCapacityKWh(battery), rangePerChargeKm(range) {
        cout << "[ElectricTruck Constructor] " << registrationNo << endl;
    }

    ~ElectricTruck() { cout << "[ElectricTruck Destructor] " << registrationNo << endl; }

    double fuelCost(double kmToTravel) const override {
        return (kmToTravel / rangePerChargeKm) * batteryCapacityKWh * 9.5;
    }

    string vehicleType() const override { return "Electric Truck"; }

    void describe() const override {
        Truck::describe();
        cout << " | Battery: " << batteryCapacityKWh << " kWh, Range: "
             << rangePerChargeKm << " km";
    }
};

// ===== Van =====
class Van : public Vehicle {
    int seatingCapacity;
    double mileageKmpl;

public:
    Van(const string& reg, const string& owner, double km,
        int seats, double mileage)
        : Vehicle(reg, owner, km), seatingCapacity(seats), mileageKmpl(mileage) {
        cout << "[Van Constructor] " << registrationNo << endl;
    }

    ~Van() { cout << "[Van Destructor] " << registrationNo << endl; }

    double fuelCost(double kmToTravel) const override {
        return (kmToTravel / mileageKmpl) * 106.0; // Petrol
    }

    string vehicleType() const override { return "Van"; }

    void describe() const override {
        Vehicle::describe();
        cout << " | Seats: " << seatingCapacity << ", Mileage: " << mileageKmpl << " kmpl";
    }
};

// ===== Fleet Report =====
void printFleetReport(const vector<Vehicle*>& fleet, double tripKm) {
    cout << "\n===== FLEET REPORT – Trip Distance: " << tripKm << " km =====\n";
    for (auto v : fleet) {
        v->describe();
        cout << " | Type: " << v->vehicleType()
             << " | Cost: Rs. " << v->fuelCost(tripKm) << endl;
    }
}

int main() {
    vector<Vehicle*> fleet;
    fleet.push_back(new Car("KA01AA001", "Ramesh Kumar", 45200, "Petrol", 16.0));
    fleet.push_back(new Truck("MH04BB002", "Shyam Logistics", 123500, 10, 5.0));
    fleet.push_back(new ElectricTruck("GJ07CC003", "Green Fleet Co", 89000, 5, 6.0, 300, 200));
    fleet.push_back(new Van("DL08DD004", "City Transport", 60500, 12, 14.0));

    printFleetReport(fleet, 200);

    // Cleanup
    for (auto v : fleet) delete v;
    return 0;
}
