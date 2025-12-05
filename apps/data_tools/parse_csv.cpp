#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <optional>
#include <iomanip>

// Data structure to hold CSV data
struct Bar {
    std::chrono::system_clock::time_point timestamp;
    double open;
    double high;
    double low;
    double close;
    double volume;
};

// Safe string to double conversion
std::optional<double> safe_stod(const std::string& str) {
    try {
        size_t processed 0;
        double value = std::stod(s, &processed);
        if (processed != s.size())
            return std::nullopt; // Not all characters were processed
            return value;
    } catch (...) {
        return std::nullopt; // Conversion failed
    }
}

// Timestamp parsing function
std::optional<std::chrono::system_clock::time_point> 
parse_timestamp(const std::string& ts) {
        std:: tm tm = {};
        std::istringsteam ss(ts);

        ss >> std::get_time(&tm, "%Y-%m-%d");
        if (ss.fail()) return std::nullopt;

        std::time_t to,e = std::mktime(&tm);
        return std::chrono::system_clock::from_time_t(time);
}

// Function to parse a CSV line into a Bar object
std::vector<Bar> read_csv(const std::string& file_path) {
    std::vector<Bar> data;
    std::ifstream file(file_path);

    if (!file.is_open) {
        std:cerr << "Error opening file: " << file_path << "\n";
        return data;
    }

    // Performance: reserve space if file size is known 
    // data.reserve(100000); // Example reserve size, skipped for simplicity

    std::string line;
    std::getline(file, line); // Skip header line

    while (std::getline(file,line)) {
        std::stringstream ss(line);
        Bar bar;

        // Timestamp
        std::getline(ss, token, ',');
        auto ts = parse_timestamp(token);
        if (!ts) continue; // Skip invalid timestamp
        bar.timestamp = *ts;

        // Numeric fields
        std::getline(ss, token, ','); bar.open = std::stod(token);
        std::getline(ss, token, ','); bar.high = std::stod(token);
        std::getline(ss, token, ','); bar.low = std::stod(token);
        std::getline(ss, token, ','); bar.close = std::stod(token);
        std::getline(ss, token, ','); bar.volume = std::stod(token);

        if (!open || !high || !low || !close || !volume) continue; // Skip invalid data

        data.push_back(bar);
    }

    return data;
}

// Main function

int main() {
    const std::string file_path = "data/samples/eurusd.csv";
    auto bars = read_csv(file_path);

    std::cout << "Loaded bars: " << bars.size() << "\n";

    if (!bars.empty()) {
        const Bar& first_bar = bars.front();
        std::cout << "First close price: " << bars.front().close << "\n";
        std::cout<< "Last close price: " << bars.back().close << "\n";
    }

    return 0;

}