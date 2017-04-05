
project(doublebasepalindromes)

set(HEDEAR_FILES DoubleBasePalindromes.h)
set(SOURCE_FILES DoubleBasePalindromes.cpp)

add_library(libdoublebasepalindromes STATIC ${SOURCE_FILES})
target_include_directories(libdoublebasepalindromes PUBLIC .)

add_executable(doublebasepalindromes ${SOURCE_FILES})

target_link_libraries(doublebasepalindromes libdoublebasepalindromes)

