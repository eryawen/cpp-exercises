
project(comparable)

set(HEDEAR_FILES ../../lab6/academia/StudentRepository.h Comparable.h)
set(SOURCE_FILES  ../../lab6/academia/StudentRepository.cpp Comparable.cpp)

add_library(libcomparable STATIC ${SOURCE_FILES})
target_include_directories(libcomparable PUBLIC .)

add_executable(comparable ${SOURCE_FILES})

target_link_libraries(comparable libcomparable)

