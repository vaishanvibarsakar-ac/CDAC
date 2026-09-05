/*
 * Question4.cpp
 *
 *  Created on: 03-Sept-2026
 *      Author: user
 */


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


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

class CSVProcessor : public DataProcessor {
    vector<string> records;
public:
    void loadData(const string& source) override {
        records = {"row1,data", "row2,data", "row3,data"};
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
    double mean{};
public:
    void loadData(const string& source) override {
        readings = {23.4, 21.8, 25.1, 22.5};
    }
    void processData() override {
        double sum = 0;
        for (double r : readings) sum += r;
        mean = sum / readings.size();
    }
    void exportResult(const string& destination) override {
        cout << "[Sensor EXPORT -> " << destination << "]" << endl;
        cout << "Mean: " << mean << endl;
    }
    string processorType() const override { return "Sensor Stream Processor"; }
    int recordCount() const override { return readings.size(); }
    double getMean() const { return mean; }
};

int main5() {
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

    for (auto* p : pipeline) {
        if (auto* csv = dynamic_cast<CSVProcessor*>(p)) {
            cout << "Found CSV Processor with " << csv->recordCount() << " records." << endl;
        } else if (auto* sensor = dynamic_cast<SensorStreamProcessor*>(p)) {
            cout << "Found Sensor Processor — Mean: " << sensor->getMean() << endl;
        }
    }
    for (auto* p : pipeline) delete p;
    return 0;
}


