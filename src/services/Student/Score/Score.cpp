#include <numeric>
#include "Score.h"

namespace services {
    std::map<SubjectsEnum, float> services::Score::CalculateAvgScore(student::Scores scores) {
        std::map<SubjectsEnum, float> avgScores;
        std::map<SubjectsEnum, std::vector<uint32_t>> subjects;

        for (auto& score : scores.GetScores()) {
            for (auto& [subject, value] : score) {
                subjects[subject].push_back(value);
            }
        }

        for (auto& [subject, values] : subjects) {
            if (values.empty()) {
                avgScores[subject] = 0;
                continue;
            }

            avgScores[subject] = static_cast<float>(
                std::accumulate(
                    values.begin(),
                    values.end(),
                    0
                )
            ) / static_cast<float>(values.size());
        }

        return avgScores;
    }
}
