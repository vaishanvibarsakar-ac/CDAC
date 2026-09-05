/*
 * Question3A.cpp
 *
 *  Created on: 03-Sept-2026
 *      Author: user
 */



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ===== Abstract Base Class =====
class DataProcessor {
public:
    virtual void loadData(const string& source) = 0;
    virtual void processData() = 0;
    virtual void exportResult(const string& destination) = 0;
    virtual string processorType() const = 0;
    virtual int recordCount() const = 0;

    virtual void printSummary() const {
        cout << "[Summary] Processor: " << processorType()
             << " | Records: " << recordCount() << endl;
    }

    virtual ~DataProcessor() = default;
};

// ===== CSV Processor =====
class CSVProcessor : public DataProcessor {
    vector<string> records;
public:
    void loadData(const string& source) override {
        cout << "[CSV Load] from " << source << endl;
        records = {"row1,data", "row2,data", "row3,data", "row4,data", "row5,data"};
    }

    void processData() override {
        for (auto& r : records)
            transform(r.begin(), r.end(), r.begin(), ::toupper);
    }

    void exportResult(const string& destination) override {
        cout << "[CSV EXPORT -> " << destination << "]" << endl;
        for (auto& r : records) cout << r << endl;
    }

    string processorType() const override { return "CSV Processor"; }
    int recordCount() const override { return records.size(); }
};


class SensorStreamProcessor : public DataProcessor {
    vector<double> readings;
    double mean{}, minVal{}, maxVal{};
public:
    void loadData(const string& source) override {
        cout << "[Sensor Load] from " << source << endl;
        readings = {23.4, 21.8, 25.1, 22.5, 24.0, 23.9, 22.1, 25.0};
    }

    void processData() override {
        double sum = 0;
        minVal = readings[0]; maxVal = readings[0];
        for (double r : readings) {
            sum += r;
            if (r < minVal) minVal = r;
            if (r > maxVal) maxVal = r;
        }
        mean = sum / readings.size();
    }

    void exportResult(const string& destination) override {
        cout << "[Sensor EXPORT -> " << destination << "]" << endl;
        cout << "Mean: " << mean << ", Min: " << minVal << ", Max: " << maxVal << endl;
    }

    string processorType() const override { return "Sensor Stream Processor"; }
    int recordCount() const override { return readings.size(); }
};

// ===== Main Demonstration =====
int main3() {
    vector<DataProcessor*> pipeline;
    pipeline.push_back(new CSVProcessor());
    pipeline.push_back(new SensorStreamProcessor());

    for (auto* p : pipeline) {
        p->loadData("source_data");
        p->processData();
        p->printSummary();
        p->exportResult("output_dir");
        cout << "---" << endl;
    }

    // Cleanup
    for (auto* p : pipeline) delete p;

    // Uncommenting the line below will cause a compile error
    // DataProcessor dp; // ❌ Cannot instantiate abstract class

    return 0;
}

