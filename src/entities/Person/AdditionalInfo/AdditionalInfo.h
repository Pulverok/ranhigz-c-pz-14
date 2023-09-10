#ifndef INC_18_ADDITIONAL_INFO_PERSON_H
#define INC_18_ADDITIONAL_INFO_PERSON_H

#include <string>
#include <cstdint>

namespace person {
    struct AdditionalInfo {
    private:
        std::string idNumber, taxNumber, phoneNumber, email;
        uint32_t age;
    public:
        explicit AdditionalInfo(std::string idNumber, std::string taxNumber, std::string phoneNumber, std::string email, uint32_t age);
        std::string GetIdNumber();
        std::string GetTaxNumber();
        std::string GetPhoneNumber();
        std::string GetEmail();
        uint32_t GetAge();
    };
}

#endif //INC_18_ADDITIONAL_INFO_PERSON_H
