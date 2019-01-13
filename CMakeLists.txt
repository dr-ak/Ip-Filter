cmake_minimum_required(VERSION 3.0)

project(ipfilter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(GTest REQUIRED)

find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(ip_filter main.cpp)

add_library(lib_ip_filter lib_ip_filter.cpp)

add_executable(gtest gtest.cpp)

set_target_properties(ip_filter lib_ip_filter gtest PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(ip_filter
    lib_ip_filter
)

target_link_libraries(gtest
    ${GTEST_LIBRARIES} 
    ${CMAKE_THREAD_LIBS_INIT}
    lib_ip_filter
)


install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alex-r-1982@mail.ru)

include(CPack)

enable_testing()

add_test(gtest gtest)