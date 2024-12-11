# Name our Project
project(Sandbox)

# Define sandbox application
file(GLOB_RECURSE SandboxSources RELATIVE ${PROJECT_SOURCE_DIR}
  src/**.cpp
  src/**.h
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "src" FILES *.cpp *.h)
add_executable(Sandbox ${SandboxSources})

# Include directories for the sandbox application
target_include_directories(Sandbox PRIVATE
  "${IncludeDir_Sapling}"
  "${IncludeDir_ImGui}"
  "${IncludeDir_glm}"
)

# Link Sandbox with the Sapling library
target_link_libraries(Sandbox PRIVATE Sapling)