# Name our Project
project(Sandbox)

# Define sandbox application
file(GLOB_RECURSE SandboxSources CONFIGURE_DEPENDS RELATIVE ${PROJECT_SOURCE_DIR}
  src/**.cpp
  src/**.h
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX src FILES *.cpp *.h)
add_executable(Sandbox ${SandboxSources})

target_include_directories(Sandbox PRIVATE ${IncludeDir_Sapling})

target_link_libraries(Sandbox PRIVATE Sapling)