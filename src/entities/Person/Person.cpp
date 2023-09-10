#include "Person.h"

using namespace entities;
using namespace person;

Person::Person(
    const Fio& fio,
    const AdditionalInfo& additionalInfo,
    const Address& address
) : fio(fio), additionalInfo(additionalInfo), address(address) {
    this->fio = fio;
    this->additionalInfo = additionalInfo;
    this->address = address;
}

Fio Person::GetFio() const {
    return this->fio;
}

AdditionalInfo Person::GetAdditionalInfo() const {
    return this->additionalInfo;
}

Address Person::GetAddress() const {
    return this->address;
}
