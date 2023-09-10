#ifndef INC_18_PERSON_ENTITY_H
#define INC_18_PERSON_ENTITY_H

#include <string>
#include "Fio/Fio.h"
#include "../Address/Address.h"
#include "AdditionalInfo/AdditionalInfo.h"
namespace entities {
    struct Person {
    private:
        person::Fio fio;
        person::AdditionalInfo additionalInfo;
        Address address;
    public:
        Person(
                const person::Fio& fio,
                const person::AdditionalInfo& additionalInfo,
                const Address& address
        );
        [[nodiscard]] person::Fio GetFio() const;
        [[nodiscard]] person::AdditionalInfo GetAdditionalInfo() const;
        [[nodiscard]] Address GetAddress() const;
    };
}

#endif //INC_18_PERSON_ENTITY_H
