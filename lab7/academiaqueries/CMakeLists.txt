
project(studentrepositoryqueries)

set(HEDEAR_FILES ../../lab6/academia/StudentRepository.h StudentRepositoryQueries.h)
set(SOURCE_FILES ../../lab6/academia/StudentRepository.cpp StudentRepositoryQueries.cpp)

add_library(libstudentrepositoryqueries STATIC ${SOURCE_FILES})
target_include_directories(libstudentrepositoryqueries PUBLIC .)

add_executable(studentrepositoryqueries ${SOURCE_FILES})

target_link_libraries(studentrepositoryqueries libstudentrepositoryqueries)

