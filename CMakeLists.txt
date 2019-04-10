cmake_minimum_required(VERSION 3.13)
project(summarization)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS system filesystem REQUIRED)
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")
include_directories(${Boost_INCLUDE_DIRS})

set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR mysql-connector-c++)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/jdbc)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/cppconn)
link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib64)

set(SOURCE_FILES main.cpp Models/Word.cpp Models/Word.h Helpers/DB.cpp Helpers/DB.h)
add_executable(summarization ${SOURCE_FILES})

target_link_libraries(summarization ${Boost_LIBRARIES} curl mysqlcppconn)
target_compile_features(summarization PRIVATE cxx_range_for) #Optional