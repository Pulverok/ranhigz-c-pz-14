#ifndef INC_18_FAKE_DATA_SERVICE_H
#define INC_18_FAKE_DATA_SERVICE_H

#include "../../entities/Address/Address.h"
#include "../../enum/Subjects.h"
#include "../../entities/Student/Scores/Scores.h"
#include "../../entities/Student/Student.h"
#include <string>
#include <cstdint>
#include <vector>
#include <map>

namespace services {
    class FakeData {
        enum {
            MAX_SCORE = 10,
            MIN_SCORE = 1,
            MAX_AGE = 60,
            MIN_AGE = 16,
            MIN_COURSE = 1,
            MAX_COURSE = 4,
        };
    private:
        static std::vector<std::string> NAMES;
        static std::vector<std::string> SURNAMES;
        static std::vector<std::string> PATRONOMICS;

        static std::vector<std::string> GROUPS;
        static std::vector<std::string> EMAILS;
        static std::vector<std::string> PHONE_NUMBERS;
        static std::vector<std::string> CITIES;
        static std::vector<std::string> STREETS;


        std::string GenerateName();
        std::string GenerateSurname();
        std::string GeneratePatronomic();

        std::string GeneratePassportID();
        std::string GenerateTaxID();
        std::string GeneratePhoneNumber();
        std::string GenerateEmail();
        uint8_t GenerateAge();

        entities::Address GenerateAddress();
        student::Scores GenerateScores(uint8_t course);

        std::string GenerateGroup();
        uint8_t GenerateCourse();

        template<typename CastType>
        CastType GenerateNumberInRange(int min, int max);

    public:
        entities::Student GenerateStudent();
    };
}

#endif //INC_18_FAKE_DATA_SERVICE_H
