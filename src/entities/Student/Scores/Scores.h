#ifndef INC_18_SCORES_STUDENT_H
#define INC_18_SCORES_STUDENT_H

#include <iostream>
#include <vector>
#include <map>
#include <cstdint>

#include "../../../enum/Subjects.h"

namespace student {
    struct Scores {
    private:
        std::vector<std::map<SubjectsEnum, uint32_t>> scores;
    public:
        explicit Scores(std::vector<std::map<SubjectsEnum, uint32_t>> scores);
        std::vector<std::map<SubjectsEnum, uint32_t>> GetScores();
    };
}

#endif //INC_18_SCORES_STUDENT_H
