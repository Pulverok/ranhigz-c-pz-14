cmake_minimum_required(VERSION 3.26)
project(Laboratory_Work_14)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo
)

add_executable(Laboratory_Work_14 main.cpp
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
