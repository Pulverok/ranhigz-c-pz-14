#include "Fio.h"

using namespace person;

Fio::Fio(std::string name, std::string surname, std::string patronymic) {
    this->name = std::move(name);
    this->surname = std::move(surname);
    this->patronymic = std::move(patronymic);
}

std::string Fio::GetName() {
    return this->name;
}

std::string Fio::GetSurname() {
    return this->surname;
}

std::string Fio::GetPatronymic() {
    return this->patronymic;
}

std::string Fio::GetFullName() {
    return this->GetSurname() + " " + this->GetName() + " " + this->GetPatronymic();
}
