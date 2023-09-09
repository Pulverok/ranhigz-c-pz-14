#ifndef INC_18_SUBJECTS_H
#define INC_18_SUBJECTS_H

#include <string>
enum SubjectsEnum {
    MATH = 1,
    PHYSICS,
    ENGLISH,
    HISTORY,
    PROGRAMMING,
    CHEMISTRY,
};

namespace Subjects {
    std::string ToString(SubjectsEnum subject);
}
#endif //INC_18_SUBJECTS_H
