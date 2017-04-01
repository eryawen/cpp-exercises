project(factorial)

set(HEDEAR_FILES Factorial.h) #działa?
set(SOURCE_FILES Factorial.cpp)

add_library(libfactorial STATIC ${SOURCE_FILES})
target_include_directories(libfactorial PUBLIC .)

add_executable(factorial ${SOURCE_FILES} main.cpp ../palindrome/Palindrome.h)

target_link_libraries(factorial libfactorial)
