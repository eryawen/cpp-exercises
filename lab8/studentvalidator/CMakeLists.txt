
project(studentvalidator)

set(HEDEAR_FILES StudentValidator.h)
set(SOURCE_FILES StudentValidator.cpp)

add_library(libstudentvalidator STATIC ${SOURCE_FILES})
target_include_directories(libstudentvalidator PUBLIC .)

add_executable(studentvalidator ${SOURCE_FILES})

target_link_libraries(studentvalidator libpesel)
target_link_libraries(studentvalidator libstudentvalidator)

