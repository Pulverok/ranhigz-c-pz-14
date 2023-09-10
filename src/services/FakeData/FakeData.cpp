#include "FakeData.h"
#include <random>

namespace services {
    std::vector<std::string> FakeData::NAMES = {"Sofia", "Maria", "Anna", "Daria", "Arina", "Polina"};
    std::vector<std::string> FakeData::SURNAMES = {"Lenchenko", "Ivanova", "Petrova", "Sergeeva", "Vladimirova", "Dmitrieva"};
    std::vector<std::string> FakeData::PATRONOMICS = {"Olegovna", "Ivanovna", "Petrovna", "Sergeevna", "Vladimirovna", "Dmitrievna"};

    std::vector<std::string> FakeData::GROUPS = {"IU7-21B", "IU7-21M", "IU7-21K", "IU7-21A", "IU7-21C", "IU7-21D"};
    std::vector<std::string> FakeData::EMAILS = {"user@edu.com", "cringe@edu.com", "michanos@edu.com", "crispy@edu.com", "mamagoba@edu.com"};
    std::vector<std::string> FakeData::PHONE_NUMBERS = {"+301234567890", "+490987654321", "+181231231231", "+453213213213", "+384564564564"};
    std::vector<std::string> FakeData::CITIES = {"Moscow", "Saint-Petersburg", "Kazan", "Novosibirsk", "Yekaterinburg", "Nizhny Novgorod"};
    std::vector<std::string> FakeData::STREETS = {"Lenina", "Kirova", "Gagarina", "Krasina", "Krasnaya", "Sovetskaya"};

    template <typename CastType = int>
    CastType FakeData::GenerateNumberInRange(int min, int max) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(min, max);

        return static_cast<CastType>(dist(mt));
    }

    int GetVectorSize(const std::vector<std::string>& vector) {
        return static_cast<int>(vector.size());
    }

    std::string FakeData::GenerateName() {
        auto index = FakeData::GenerateNumberInRange<uint32_t>(0, GetVectorSize(FakeData::NAMES) - 1);
        return FakeData::NAMES[index];
    }

    std::string FakeData::GenerateSurname() {
        auto index = FakeData::GenerateNumberInRange<uint32_t>(0, GetVectorSize(FakeData::SURNAMES) - 1);
        return FakeData::SURNAMES[index];
    }

    std::string FakeData::GeneratePatronomic() {
        auto index = FakeData::GenerateNumberInRange<uint32_t>(0, GetVectorSize(FakeData::PATRONOMICS) - 1);
        return FakeData::PATRONOMICS[index];
    }

    std::string FakeData::GeneratePassportID() {
        return std::to_string(FakeData::GenerateNumberInRange(1000000000, 1410065407));
    }

    std::string FakeData::GenerateTaxID() {
        return std::to_string(FakeData::GenerateNumberInRange(1000000000, 1410065407));
    }

    std::string FakeData::GeneratePhoneNumber() {
        auto index = FakeData::GenerateNumberInRange<uint32_t>(0, GetVectorSize(FakeData::PHONE_NUMBERS) - 1);
        return FakeData::PHONE_NUMBERS[index];
    }

    std::string FakeData::GenerateEmail() {
        auto index = FakeData::GenerateNumberInRange<uint32_t>(0, GetVectorSize(FakeData::EMAILS) - 1);
        return FakeData::EMAILS[index];
    }

    uint8_t FakeData::GenerateAge() {
        return GenerateNumberInRange<uint8_t>(FakeData::MIN_AGE, FakeData::MAX_AGE);
    }

    entities::Address FakeData::GenerateAddress() {
        auto cityIndex = FakeData::GenerateNumberInRange<uint32_t>(0, GetVectorSize(FakeData::CITIES) - 1);
        auto streetIndex = FakeData::GenerateNumberInRange<uint32_t>(0, GetVectorSize(FakeData::STREETS) - 1);

        std::string cityName = FakeData::CITIES[cityIndex];
        std::string streetName = FakeData::STREETS[streetIndex];
        std::string houseNumber = std::to_string(FakeData::GenerateNumberInRange(1, 100));
        std::string aptNumber = std::to_string(FakeData::GenerateNumberInRange(1, 100));

        return entities::Address(cityName, streetName, houseNumber, aptNumber);
    }

    student::Scores FakeData::GenerateScores(uint8_t course) {
        std::vector<std::map<SubjectsEnum, uint8_t>> scores;

        for (int i = 0; i < course; i++) {
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
        auto index = FakeData::GenerateNumberInRange<uint32_t>(0, GetVectorSize(FakeData::GROUPS) - 1);
        return FakeData::GROUPS[index];
    }

    uint8_t FakeData::GenerateCourse() {
        return GenerateNumberInRange<uint8_t>(FakeData::MIN_COURSE, FakeData::MAX_COURSE);
    }

    entities::Student FakeData::GenerateStudent() {
        uint8_t course = FakeData::GenerateCourse();
        return {
            entities::Person(
                person::Fio(
                    FakeData::GenerateName(),
                    FakeData::GenerateSurname(),
                    FakeData::GeneratePatronomic()
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