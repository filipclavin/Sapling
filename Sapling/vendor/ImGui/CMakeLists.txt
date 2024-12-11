cmake_minimum_required(VERSION 3.16)
project(ImGui)

file(GLOB ImGuiSources repo/*.cpp)
file(GLOB ImGuiHeaders repo/*.h)

set(ImGuiSrcAndHeaders ${ImGuiSources} ${ImGuiHeaders})

add_library(ImGui
    ${ImGuiSrcAndHeaders}
    repo/backends/imgui_impl_glfw.cpp
    repo/backends/imgui_impl_glfw.h
    repo/backends/imgui_impl_opengl3.cpp
    repo/backends/imgui_impl_opengl3.h
    repo/misc/debuggers/imgui.natvis
    repo/misc/debuggers/imgui.natstepfilter
    repo/misc/cpp/imgui_stdlib.cpp
    repo/misc/cpp/imgui_stdlib.h
)

target_include_directories(ImGui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/repo
    ${IncludeDir_GLFW}
)
