#include "AdditionalInfo.h"

using namespace person;

AdditionalInfo::AdditionalInfo(std::string IDNumber, std::string taxNumber, std::string phoneNumber, std::string email, uint8_t age) {
    this->idNumber = std::move(IDNumber);
    this->taxNumber = std::move(taxNumber);
    this->phoneNumber = std::move(phoneNumber);
    this->email = std::move(email);
    this->age = age;
}

std::string AdditionalInfo::GetIdNumber() {
    return this->idNumber;
}

std::string AdditionalInfo::GetTaxNumber() {
    return this->taxNumber;
}

std::string AdditionalInfo::GetPhoneNumber() {
    return this->phoneNumber;
}

std::string AdditionalInfo::GetEmail() {
    return this->email;
}

uint8_t AdditionalInfo::GetAge() {
    return this->age;
}
