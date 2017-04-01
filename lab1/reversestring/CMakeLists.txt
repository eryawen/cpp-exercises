project(reversestring)

set(HEDEAR_FILES ReverseString.h)
set(SOURCE_FILES ReverseString.cpp)

add_library(libreversestring STATIC ${SOURCE_FILES})
target_include_directories(libreversestring PUBLIC .)

add_executable(reversestring ${SOURCE_FILES} ../reversestring/ReverseString.h)
#add_executable(reversestring ${SOURCE_FILES} main.cpp ../reversestring/ReverseString.h)

target_link_libraries(reversestring libreversestring)
