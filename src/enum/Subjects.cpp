#include <string>

#include "Subjects.h"

std::string Subjects::ToString(SubjectsEnum subject) {
    switch (subject) {
        case MATH:
            return "Math";
        case PHYSICS:
            return "Physics";
        case ENGLISH:
            return "English";
        case HISTORY:
            return "History";
        case PROGRAMMING:
            return "Programming";
        case CHEMISTRY:
            return "Chemistry";
        default:
            return "Unknown";
    }
}