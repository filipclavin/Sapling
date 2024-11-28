workspace "Sapling"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Sapling/vendor/GLFW/include"

include "Sapling/vendor/GLFW"

project "Sapling"
	location "Sapling"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sappch.h"
	pchsource "Sapling/src/sappch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SAP_PLATFORM_WINDOWS",
			"SAP_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SAP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SAP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SAP_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Sapling/src"
	}

	links
	{
		"Sapling"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SAP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SAP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SAP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SAP_DIST"
		optimize "On"