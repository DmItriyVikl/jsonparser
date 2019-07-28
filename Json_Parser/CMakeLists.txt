# CMakeList.txt : CMake project for Json_Parser, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set (CMAKE_CXX_STANDARD 17)

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "Json_Parser.cpp" "Json_Parser.h")
#-DCMAKE_TOOLCHAIN_FILE=C:/Users/ADMIN/Downloads/vcpkg-master/scripts/buildsystems/vcpkg.cmake
# TODO: Add tests and install targets if needed.
find_package(jsoncpp CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE jsoncpp_lib)
