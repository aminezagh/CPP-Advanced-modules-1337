#include <iostream>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <ctime>

int main()
{
    double d = (double)47115.93 * (double)353.688;
    std::cout << d << std::endl;
}

// // Function to convert date to timestamp
// std::time_t convertDateToTimestamp(const std::string& dateStr)
// {
//     // Define the format of the input date
//     std::tm tm = {};
//     std::istringstream dateStream(dateStr);
//     dateStream >> std::get_time(&tm, "%d-%m-%Y");

//     if (dateStream.fail()) {
//         std::cerr << "Error: Invalid date format." << std::endl;
//         // Return an invalid timestamp (for example, -1)
//         return -1;
//     }

//     // Convert tm to time_t
//     std::time_t timestamp = std::mktime(&tm);

//     if (timestamp == -1) {
//         std::cerr << "Error: Unable to convert date to timestamp." << std::endl;
//         // Return an invalid timestamp
//         return -1;
//     }

//     return timestamp;
// }

// int main()
// {
//     // Example usage
//     std::string dateStr = "01-12-2015";
//     std::time_t timestamp = convertDateToTimestamp(dateStr);

//     if (timestamp != -1) {
//         std::cout << "Timestamp for " << dateStr << ": " << timestamp << std::endl;
//     }

//     return 0;
// }
