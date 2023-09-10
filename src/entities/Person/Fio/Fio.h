#ifndef INC_18_FIO_PERSON_H
#define INC_18_FIO_PERSON_H
#include <string>
namespace person {
    struct Fio {
    private:
        std::string name, surname, patronymic;
    public:
        explicit Fio(std::string name, std::string surname, std::string patronymic);

        std::string GetName();
        std::string GetSurname();
        std::string GetPatronymic();
        std::string GetFullName();
    };
}
#endif //INC_18_FIO_PERSON_H
