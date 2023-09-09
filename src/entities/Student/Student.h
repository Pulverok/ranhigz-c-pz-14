#ifndef INC_18_STUDENT_ENTITY_H
#define INC_18_STUDENT_ENTITY_H

#include <cstdint>
#include "../Person/Person.h"
#include "Scores/Scores.h"

namespace entities {
    struct Student {
    private:
        entities::Person person;
        student::Scores scores;

        std::string group;
        uint8_t course;
    public:
        Student(
            entities::Person  person,
            student::Scores  scores,
            std::string group,
            uint8_t course
        );
        [[nodiscard]] Person GetPerson() const;
        [[nodiscard]] student::Scores GetScores() const;
        [[nodiscard]] std::string GetGroup() const;
        [[nodiscard]] uint8_t GetCourse() const;
    };
}

#endif //INC_18_STUDENT_ENTITY_H
