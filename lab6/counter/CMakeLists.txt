
project(wordcounter)

set(HEDEAR_FILES WordCounter.h Word.h Counts.h)
set(SOURCE_FILES WordCounter.cpp Word.cpp Counts.cpp)

add_library(libwordcounter STATIC ${SOURCE_FILES})
target_include_directories(libwordcounter PUBLIC .)

add_executable(wordcounter ${SOURCE_FILES})

target_link_libraries(wordcounter libwordcounter)

