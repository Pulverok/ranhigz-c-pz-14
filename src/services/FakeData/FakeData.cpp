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


    int FakeData::GenerateNumberInRange(int min, int max) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(min, max);

        return dist(mt);
    }

    std::string FakeData::GenerateName() {
        int index = FakeData::GenerateNumberInRange(0, FakeData::NAMES.size() - 1);
        return FakeData::NAMES[index];
    }

    std::string FakeData::GenerateSurname() {
        int index = FakeData::GenerateNumberInRange(0, FakeData::SURNAMES.size() - 1);
        return FakeData::SURNAMES[index];
    }

    std::string FakeData::GeneratePatronomic() {
        int index = FakeData::GenerateNumberInRange(0, FakeData::PATRONOMICS.size() - 1);
        return FakeData::PATRONOMICS[index];
    }

    std::string FakeData::GeneratePassportID() {
        return std::to_string(FakeData::GenerateNumberInRange(1000000000, 1410065407));
    }

    std::string FakeData::GenerateTaxID() {
        return std::to_string(FakeData::GenerateNumberInRange(1000000000, 1410065407));
    }

    std::string FakeData::GeneratePhoneNumber() {
        int index = FakeData::GenerateNumberInRange(0, FakeData::PHONE_NUMBERS.size() - 1);
        return FakeData::PHONE_NUMBERS[index];
    }

    std::string FakeData::GenerateEmail() {
        int index = FakeData::GenerateNumberInRange(0, FakeData::EMAILS.size() - 1);
        return FakeData::EMAILS[index];
    }

    uint8_t FakeData::GenerateAge() {
        return GenerateNumberInRange(FakeData::MIN_AGE, FakeData::MAX_AGE);;
    }

    entities::Address FakeData::GenerateAddress() {
        int cityIndex = FakeData::GenerateNumberInRange(0, FakeData::CITIES.size() - 1);
        int streetIndex = FakeData::GenerateNumberInRange(0, FakeData::STREETS.size() - 1);

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
        int index = FakeData::GenerateNumberInRange(0, FakeData::GROUPS.size() - 1);
        return FakeData::GROUPS[index];
    }

    uint8_t FakeData::GenerateCourse() {
        return GenerateNumberInRange(FakeData::MIN_COURSE, FakeData::MAX_COURSE);
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