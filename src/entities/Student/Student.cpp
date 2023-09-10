#include "Student.h"

#include <utility>

using namespace entities;

Student::Student(
    Person  person,
    student::Scores  scores,
    std::string group,
    uint32_t course
) : person(std::move(person)), scores(std::move(scores)) {
    this->group = std::move(group);
    this->course = course;
}

Person Student::GetPerson() const {
    return this->person;
}

student::Scores Student::GetScores() const {
    return this->scores;
}

std::string Student::GetGroup() const {
    return this->group;
}

uint32_t Student::GetCourse() const {
    return this->course;
}
