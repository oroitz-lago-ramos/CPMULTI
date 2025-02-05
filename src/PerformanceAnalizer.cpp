//
// Created by Oroitz on 23/01/2025.
//
#include "../include/PerformanceAnalyzer.h"

void PerformanceAnalyzer::start(const std::string& phase) {
    startTimes[phase] = std::chrono::steady_clock::now();
}

double PerformanceAnalyzer::stop(const std::string& phase) {
    auto end = std::chrono::steady_clock::now();
    double duration = std::chrono::duration<double, std::milli>(end - startTimes[phase]).count();
    durations[phase] = duration;
    return duration;
}

void PerformanceAnalyzer::printResults() const {
    std::cout << "\n=== Execution time by phase ===" << std::endl;
    for (const auto& p : durations) {
        std::cout << p.first << " : " << p.second << " ms" << std::endl;
    }
}