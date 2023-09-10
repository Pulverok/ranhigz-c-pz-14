#include "FakeData.h"
#include <random>

#include "../../helpers/helper.h"

using namespace helpers;

namespace services {
    std::vector<std::string> FakeData::NAMES = {"Sofia", "Maria", "Anna", "Daria", "Arina", "Polina"};
    std::vector<std::string> FakeData::SURNAMES = {"Lenchenko", "Ivanova", "Petrova", "Sergeeva", "Vladimirova", "Dmitrieva"};
    std::vector<std::string> FakeData::PATRONOMICS = {"Olegovna", "Ivanovna", "Petrovna", "Sergeevna", "Vladimirovna", "Dmitrievna"};

    std::vector<std::string> FakeData::GROUPS = {"IU7-21B", "IU7-21M", "IU7-21K", "IU7-21A", "IU7-21C", "IU7-21D"};
    std::vector<std::string> FakeData::EMAILS = {"user@edu.com", "cringe@edu.com", "michanos@edu.com", "crispy@edu.com", "mamagoba@edu.com"};
    std::vector<std::string> FakeData::PHONE_NUMBERS = {"+301234567890", "+490987654321", "+181231231231", "+453213213213", "+384564564564"};
    std::vector<std::string> FakeData::CITIES = {"Moscow", "Saint-Petersburg", "Kazan", "Novosibirsk", "Yekaterinburg", "Nizhny Novgorod"};
    std::vector<std::string> FakeData::STREETS = {"Lenina", "Kirova", "Gagarina", "Krasina", "Krasnaya", "Sovetskaya"};

    int GetVectorSize(const std::vector<std::string>& vector) {
        return static_cast<int>(vector.size());
    }

    std::string FakeData::GenerateName() {
        auto index = GenerateNumberInRange(0, GetVectorSize(FakeData::NAMES) - 1);
        return FakeData::NAMES[index];
    }

    std::string FakeData::GenerateSurname() {
        auto index = GenerateNumberInRange(0, GetVectorSize(FakeData::SURNAMES) - 1);
        return FakeData::SURNAMES[index];
    }

    std::string FakeData::generatePatronomic() {
        auto index = GenerateNumberInRange(0, GetVectorSize(FakeData::PATRONOMICS) - 1);
        return FakeData::PATRONOMICS[index];
    }

    std::string FakeData::GeneratePassportID() {
        int val = static_cast<int>(GenerateNumberInRange(1000000000, 1410065407));
        return std::to_string(val);
    }

    std::string FakeData::GenerateTaxID() {
        int val = static_cast<int>(GenerateNumberInRange(1000000000, 1410065407));
        return std::to_string(val);
    }

    std::string FakeData::GeneratePhoneNumber() {
        auto index = GenerateNumberInRange(0, GetVectorSize(FakeData::PHONE_NUMBERS) - 1);
        return FakeData::PHONE_NUMBERS[index];
    }

    std::string FakeData::GenerateEmail() {
        auto index = GenerateNumberInRange(0, GetVectorSize(FakeData::EMAILS) - 1);
        return FakeData::EMAILS[index];
    }

    uint32_t FakeData::GenerateAge() {
        return GenerateNumberInRange(FakeData::MIN_AGE, FakeData::MAX_AGE);
    }

    entities::Address FakeData::GenerateAddress() {
        auto cityIndex = GenerateNumberInRange(0, GetVectorSize(FakeData::CITIES) - 1);
        auto streetIndex = GenerateNumberInRange(0, GetVectorSize(FakeData::STREETS) - 1);

        std::string cityName = FakeData::CITIES[cityIndex];
        std::string streetName = FakeData::STREETS[streetIndex];
        std::string houseNumber = std::to_string(GenerateNumberInRange(1, 100));
        std::string aptNumber = std::to_string(GenerateNumberInRange(1, 100));

        return entities::Address(cityName, streetName, houseNumber, aptNumber);
    }

    student::Scores FakeData::GenerateScores(uint32_t course) {
        std::vector<std::map<SubjectsEnum, uint32_t>> scores;

        for (uint32_t i = 0; i < course; i++) {
            scores.push_back({
                {SubjectsEnum::MATH, GenerateNumberInRange(FakeData::MIN_SCORE, FakeData::MAX_SCORE)},
                {SubjectsEnum::PHYSICS, GenerateNumberInRange(FakeData::MIN_SCORE, FakeData::MAX_SCORE)},
                {SubjectsEnum::CHEMISTRY, GenerateNumberInRange(FakeData::MIN_SCORE, FakeData::MAX_SCORE)},
                {SubjectsEnum::HISTORY, GenerateNumberInRange(FakeData::MIN_SCORE, FakeData::MAX_SCORE)},
                {SubjectsEnum::ENGLISH, GenerateNumberInRange(FakeData::MIN_SCORE, FakeData::MAX_SCORE)},
                {SubjectsEnum::PROGRAMMING, GenerateNumberInRange(FakeData::MIN_SCORE, FakeData::MAX_SCORE)},
            });
        }

        return student::Scores(scores);
    }

    std::string FakeData::GenerateGroup() {
        auto index = GenerateNumberInRange(0, GetVectorSize(FakeData::GROUPS) - 1);
        return FakeData::GROUPS[index];
    }

    uint32_t FakeData::GenerateCourse() {
        return GenerateNumberInRange(FakeData::MIN_COURSE, FakeData::MAX_COURSE);
    }

    entities::Student FakeData::GenerateStudent() {
        auto course = FakeData::GenerateCourse();
        return {
            entities::Person(
                person::Fio(
                    FakeData::GenerateName(),
                    FakeData::GenerateSurname(),
                    FakeData::generatePatronomic()
                ),
                person::AdditionalInfo(
                    FakeData::GeneratePassportID(),
                    FakeData::GenerateTaxID(),
                    FakeData::GeneratePhoneNumber(),
                    FakeData::GenerateEmail(),
                    FakeData::GenerateAge()
                ),
                FakeData::GenerateAddress()
            ),
            FakeData::GenerateScores(course),
            FakeData::GenerateGroup(),
            course
        };
    }
}