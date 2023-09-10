#ifndef INC_18_ADDRESS_ENTITY_H
#define INC_18_ADDRESS_ENTITY_H
#include <string>

namespace entities {
    struct Address {
    private:
        std::string city, street, house, apartment;
    public:
        explicit Address(std::string city, std::string street, std::string house, std::string apartment);
        std::string GetCity();
        std::string GetStreet();
        std::string GetHouse();
        std::string GetApartment();
        std::string GetFullAddress();
    };
}

#endif //INC_18_ADDRESS_ENTITY_H
