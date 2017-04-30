
project(arrayfill)

set(HEDEAR_FILES FillArray.h Filler.h)
set(SOURCE_FILES FillArray.cpp Filler.cpp)

add_library(libarrayfill STATIC ${SOURCE_FILES})
target_include_directories(libarrayfill PUBLIC .)

add_executable(arrayfill ${SOURCE_FILES})

target_link_libraries(arrayfill libarrayfill)

