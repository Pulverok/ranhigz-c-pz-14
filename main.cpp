#include "src/services/Student/Student.h"

int readIntFromConsole(const std::string& message) {
    int number;
    std::cout << message << std::endl;
    std::cin >> number;

    return number;
}

int main() {
    services::FakeData fakeData;
    services::Student student(fakeData);

    int count = readIntFromConsole("Enter count of students: ");
    if (count == 0) {
        std::cout << "Count of students must be greater than 0" << std::endl;
        return 0;
    }

    student.PrintStudents(count);

    return 0;
}
