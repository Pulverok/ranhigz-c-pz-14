#include <numeric>
#include "Scores.h"

using namespace student;

Scores::Scores(std::vector<std::map<SubjectsEnum, uint8_t>> scores) {
    this->scores = std::move(scores);
}

std::vector<std::map<SubjectsEnum, uint8_t>> Scores::GetScores() {
    return this->scores;
}
