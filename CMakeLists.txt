cmake_minimum_required(VERSION 3.16)

if(NOT CMAKE_GENERATOR_PLATFORM)
    set(CMAKE_GENERATOR_PLATFORM x64)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(Sapling)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(IncludeDir_Sapling ${CMAKE_SOURCE_DIR}/Sapling/src)
set(IncludeDir_GLFW ${CMAKE_SOURCE_DIR}/Sapling/vendor/GLFW/repo/include)
set(IncludeDir_Glad ${CMAKE_SOURCE_DIR}/Sapling/vendor/Glad/include)
set(IncludeDir_ImGui ${CMAKE_SOURCE_DIR}/Sapling/vendor/ImGui/repo)
set(IncludeDir_glm ${CMAKE_SOURCE_DIR}/Sapling/vendor/glm/repo)

add_subdirectory(Sapling/vendor/GLFW/repo)
add_subdirectory(Sapling/vendor/Glad)
add_subdirectory(Sapling/vendor/ImGui)
add_subdirectory(Sapling/vendor/glm/repo)
add_subdirectory(Sapling)
add_subdirectory(Sandbox)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Sandbox)