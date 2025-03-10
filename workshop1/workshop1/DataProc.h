#pragma once
#ifndef DATAPROC_H
#define DATAPROC_H

#include <vector>
#include <string>

class DataProcessor {
public:
    DataProcessor(const std::string& inputFileName);

    void readData();
    void calculateMean();
    void calculateDeviations();
    void calculateAbsoluteErrors();
    void calculateStandardDeviation(); 
    void calculateMeanError();         
    double getMaxDelta() const;
    double getStandardDeviation() const;  
    double getMeanError() const;          
    const std::vector<double>& getDeviations() const;
    const std::vector<double>& getSquaredDeviations() const;
    double getMean() const;

private:
    std::string inputFileName;
    std::vector<double> data;
    double mean;
    std::vector<double> deviations;
    std::vector<double> squaredDeviations;
    std::vector<double> deltas;
    double maxDelta;
    double standardDeviation; 
    double meanError;         
};

#endif