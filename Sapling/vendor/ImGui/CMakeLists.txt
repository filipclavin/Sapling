cmake_minimum_required(VERSION 3.16)
project(ImGui)

file(GLOB ImGuiSources "*.cpp")
file(GLOB ImGuiHeaders "*.h")

set(ImGuiSrcAndHeaders ${ImGuiSources} ${ImGuiHeaders})

add_library(ImGui
    ${ImGuiSrcAndHeaders}
    "backends/imgui_impl_glfw.cpp"
    "backends/imgui_impl_glfw.h"
    "backends/imgui_impl_opengl3.cpp"
    "backends/imgui_impl_opengl3.h"
    "misc/debuggers/imgui.natvis"
    "misc/debuggers/imgui.natstepfilter"
    "misc/cpp/imgui_stdlib.cpp"
    "misc/cpp/imgui_stdlib.h"
)

target_include_directories(ImGui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    "${IncludeDir_GLFW}"
)
