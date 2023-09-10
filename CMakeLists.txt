cmake_minimum_required(VERSION 3.26)
project(Laboratory_Work_14)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compile_options(
            /W4
            /WX
    )
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
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
endif()

set(SOURCES
        main.cpp

        src/entities/Person/Person.cpp
        src/entities/Person/Fio/Fio.cpp
        src/entities/Person/AdditionalInfo/AdditionalInfo.cpp
        src/entities/Address/Address.cpp
        src/entities/Student/Scores/Scores.cpp
        src/entities/Student/Student.cpp

        src/helpers/helper.cpp

        src/enum/Subjects.cpp

        src/services/FakeData/FakeData.cpp
        src/services/Student/Student.cpp
        src/services/Student/Score/Score.cpp
)

add_executable(Laboratory_Work_14 ${SOURCES})
