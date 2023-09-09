cmake_minimum_required(VERSION 3.26)
project(18)

set(CMAKE_CXX_STANDARD 17)

add_executable(18 main.cpp
        src/entities/Person/Person.h
        src/entities/Person/Fio/Fio.h
        src/entities/Person/AdditionalInfo/AdditionalInfo.h
        src/entities/Address/Address.h
        src/entities/Student/Scores/Scores.h
        src/entities/Student/Student.h

        src/entities/Person/Person.cpp
        src/entities/Person/Fio/Fio.cpp
        src/entities/Person/AdditionalInfo/AdditionalInfo.cpp
        src/entities/Address/Address.cpp
        src/entities/Student/Scores/Scores.cpp
        src/entities/Student/Student.cpp
        src/enum/Subjects.h
        src/enum/Subjects.cpp
        src/services/FakeData/FakeData.cpp
        src/services/FakeData/FakeData.h
        src/services/Student/Student.cpp
        src/services/Student/Student.h
        src/services/Student/Score/Score.h
        src/services/Student/Score/Score.cpp
)
