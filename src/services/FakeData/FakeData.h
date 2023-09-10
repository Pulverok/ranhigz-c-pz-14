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


        static std::string GenerateName();
        static std::string GenerateSurname();
        static std::string generatePatronomic();

        static std::string GeneratePassportID();
        static std::string GenerateTaxID();
        static std::string GeneratePhoneNumber();
        static std::string GenerateEmail();
        static uint32_t GenerateAge();

        static entities::Address GenerateAddress();
        static student::Scores GenerateScores(uint32_t course);

        static std::string GenerateGroup();
        static uint32_t GenerateCourse();

    public:
        static entities::Student GenerateStudent();
    };
}

#endif //INC_18_FAKE_DATA_SERVICE_H
