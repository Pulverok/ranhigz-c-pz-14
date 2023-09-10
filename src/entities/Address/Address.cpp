#include "Address.h"

using namespace entities;

Address::Address(std::string city, std::string street, std::string house, std::string apartment) {
    this->city = std::move(city);
    this->street = std::move(street);
    this->house = std::move(house);
    this->apartment = std::move(apartment);
}

std::string Address::GetCity() {
    return this->city;
}

std::string Address::GetStreet() {
    return this->street;
}

std::string Address::GetHouse() {
    return this->house;
}

std::string Address::GetApartment() {
    return this->apartment;
}

std::string Address::GetFullAddress() {
    return this->GetCity() + ", " + this->GetStreet() + ", " + this->GetHouse() + ", apartments: " + this->GetApartment();
}
