#ifndef INC_18_SCORE_SERVICE_H
#define INC_18_SCORE_SERVICE_H

#include <map>
#include "../../../enum/Subjects.h"
#include "../../../entities/Student/Scores/Scores.h"

namespace services {
    class Score {
    public:
        static std::map<SubjectsEnum, float> CalculateAvgScore(student::Scores scores);
    };
};
#endif //INC_18_SCORE_SERVICE_H
