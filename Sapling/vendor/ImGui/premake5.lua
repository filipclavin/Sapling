project "ImGui"
    kind "StaticLib"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "*.cpp",
        "*.h",
        "backends/imgui_impl_glfw.cpp",
        "backends/imgui_impl_glfw.h",
        "backends/imgui_impl_opengl3.cpp",
        "backends/imgui_impl_opengl3.h",
        "misc/debuggers/imgui.natvis",
        "misc/debuggers/imgui.natstepfilter",
        "misc/cpp/imgui_stdlib.*",
    }

    includedirs {
        _WORKING_DIR .. "/" .. IncludeDir["ImGui"],
        _WORKING_DIR .. "/" .. IncludeDir["GLFW"]
    }

    defines { "IMGUI_API=__declspec(dllexport)" }
