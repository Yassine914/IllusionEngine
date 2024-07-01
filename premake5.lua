workspace "dev"
configurations { "debug", "release" }

outputdir = "${cfg.build.cfg}%{cfg.system}%{cfg.architecture}"

project "IllusionEngine"
	-- location "../IllusionEngine"
	kind "WindowedApp"
	language "C++"

targetdir("bin/" .. outputdir .. "/")
objdir("bin-obj/" .. outputdir .. "/")

files
{
	"src/**.h",
	"src/**.cpp"
}

includedirs { "include/*/" }

filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"

filter "configurations:debug"
	defines { "DEBUG" }
	symbols "On"

filter "configurations:release"
	defines { "NDEBUG" }
	optimize "On"