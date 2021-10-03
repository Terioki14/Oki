workspace "Oki"
	architecture "x64"
	startproject "Sandbox"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Oki/vendor/GLFW/include"
IncludeDir["Glad"] = "Oki/vendor/Glad/include"
IncludeDir["ImGui"] = "Oki/vendor/imgui"

include "Oki/vendor/GLFW"
include "Oki/vendor/Glad"
include "Oki/vendor/imgui"

project "Oki"
	location "Oki"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "okipch.h"
	pchsource "Oki/src/okipch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines 
		{
			"OKI_PLATFORM_WINDOWS",
			"OKI_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "OKI_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "OKI_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "OKI_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Oki/vendor/spdlog/include",
		"Oki/src"
	}

	links 
	{
		"Oki"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines 
		{
			"OKI_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "OKI_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "OKI_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "OKI_Dist"
		runtime "Release"
		optimize "On"