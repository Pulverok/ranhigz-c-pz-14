#ifndef INC_18_STUDENT_SERVICE_H
#define INC_18_STUDENT_SERVICE_H

#include <map>
#include "Score/Score.h"
#include "../FakeData/FakeData.h"
#include "../../enum/Subjects.h"
#include "../../entities/Student/Scores/Scores.h"
#include "../../entities/Student/Student.h"

namespace services {
    class Student {
    public:
        static void PrintStudents(int count);
    };
}

#endif //INC_18_STUDENT_SERVICE_H
