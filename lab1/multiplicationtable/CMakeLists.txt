project(multiplicationtable)

set(HEDEAR_FILES MultiplicationTable.h)
set(SOURCE_FILES MultiplicationTable.cpp)

add_library(libmultiplicationtable STATIC ${SOURCE_FILES})
target_include_directories(libmultiplicationtable PUBLIC .)

add_executable(multiplicationtable ${SOURCE_FILES} ../multiplicationtable/MultiplicationTable.h)

target_link_libraries(multiplicationtable libmultiplicationtable)

