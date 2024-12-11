# Name our Project
project(Sapling)

# Define the sapling static library
file(GLOB_RECURSE SaplingSources RELATIVE ${PROJECT_SOURCE_DIR}
src/**.cpp
src/**.h
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "src" FILES *.cpp *.h)
add_library(Sapling STATIC ${SaplingSources})

# Don't include opengl in GLFW (we use glad)
target_compile_definitions(Sapling PRIVATE GLFW_INCLUDE_NONE)

# Precompiled header
target_precompile_headers(Sapling PRIVATE src/sappch.h)

# Set platform defines
if (WIN32)
message("Windows detected")
target_compile_definitions(Sapling PRIVATE WIN32)
endif()

# Include directories for Sapling
target_include_directories(Sapling PRIVATE
"${IncludeDir_Sapling}"
"${IncludeDir_GLFW}"
"${IncludeDir_Glad}"
"${IncludeDir_ImGui}"
"${IncludeDir_glm}"
)

target_link_libraries(Sapling PRIVATE
  glfw
  Glad
  ImGui
  glm
)