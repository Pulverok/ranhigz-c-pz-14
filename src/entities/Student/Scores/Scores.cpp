#include <numeric>
#include "Scores.h"

using namespace student;

Scores::Scores(std::vector<std::map<SubjectsEnum, uint32_t>> scores) {
    this->scores = std::move(scores);
}

std::vector<std::map<SubjectsEnum, uint32_t>> Scores::GetScores() {
    return this->scores;
}
