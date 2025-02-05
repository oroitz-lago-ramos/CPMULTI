#ifndef PERFORMANCE_ANALYZER_H
#define PERFORMANCE_ANALYZER_H

#include <chrono>
#include <string>
#include <unordered_map>
#include <iostream>

class PerformanceAnalyzer {
public:
    void start(const std::string& phase);
    double stop(const std::string& phase);

    void printResults() const;

private:
    std::unordered_map<std::string, std::chrono::steady_clock::time_point> startTimes;
    std::unordered_map<std::string, double> durations;
};

#endif // PERFORMANCE_ANALYZER_H
