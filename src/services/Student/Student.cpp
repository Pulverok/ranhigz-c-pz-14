#include <iomanip>
#include "Student.h"

namespace services {
    void services::Student::PrintStudents(int count) {
        for (int i = 0; i < count; i++) {
            entities::Student student = this->fakeData.GenerateStudent();

            std::cout << "Name: " << student.GetPerson().GetFio().GetFullName() << std::endl;
            std::cout << "Age: " << static_cast<unsigned>(student.GetPerson().GetAdditionalInfo().GetAge()) << std::endl;
            std::cout << "Group: " << student.GetGroup() << std::endl;
            std::cout << "Course: " << static_cast<unsigned>(student.GetCourse()) << std::endl;
            std::cout << "Address: " << student.GetPerson().GetAddress().GetFullAddress() << std::endl;

            std::cout << "Pasport Number: " << student.GetPerson().GetAdditionalInfo().GetIdNumber() << std::endl;
            std::cout << "Tax ID number: " << student.GetPerson().GetAdditionalInfo().GetTaxNumber() << std::endl;
            std::cout << "Phone Number: " << student.GetPerson().GetAdditionalInfo().GetPhoneNumber() << std::endl;
            std::cout << "Email: " << student.GetPerson().GetAdditionalInfo().GetEmail() << std::endl;

            std::cout << std::fixed << std::setprecision(2);
            std::map<SubjectsEnum, float> avgScore = services::Score::CalculateAvgScore(student.GetScores());
            for (auto& [subject, score] : avgScore) {
                std::cout << "Average score by " << Subjects::ToString(subject) << ": " << score << std::endl;
            }

            std::cout << std::endl;
        }
    }

    Student::Student(FakeData &fakeData) : fakeData(fakeData) {}
}
