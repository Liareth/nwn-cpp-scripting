set(sources
    "EntryPoint.cpp"
    "Game/Example.cpp"
    "Game/Example.hpp"
    "Game/Systems/Combat.cpp"
    "Game/Systems/Combat.hpp"
    "Game/Systems/Scripting.cpp"
    "Game/Systems/Scripting.hpp"
    "Game/Scripts/Module/Heartbeat.cpp"
    "Game/Scripts/Placeable/CombatDummy/Damaged.cpp"
    "NWN/Addresses.cpp"
    "NWN/Addresses.hpp"
	"NWN/Constants.hpp"
	"NWN/Functions.cpp"
	"NWN/Functions.hpp"
    "NWN/Structs.cpp"
    "NWN/Structs.hpp"
    "NWN/Scripts/NWScript.cpp"
    "NWN/Scripts/NWScript.hpp"
    "NWN/Scripts/NWScriptVM.cpp"
    "NWN/Scripts/NWScriptVM.hpp"
    "Platform/ASLR.cpp"
    "Platform/ASLR.hpp"
    "Platform/Assembly.cpp"
    "Platform/Assembly.hpp"
    "Platform/Assembly.inl"
    "Platform/Hook.cpp"
    "Platform/Hook.hpp"
    "Util/Assert.cpp"
    "Util/Assert.hpp")

add_library(Example SHARED ${sources})

target_link_libraries(Example subhook)
target_include_directories(Example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(Example PRIVATE _CRT_SECURE_NO_WARNINGS)

if (WIN32)
    target_compile_definitions(Example PRIVATE WINDOWS=1 LINUX=0)
else()
    target_compile_definitions(Example PRIVATE WINDOWS=0 LINUX=1)
endif()


# Credit to
# https://stackoverflow.com/questions/31422680/how-to-set-visual-studio-filters-for-nested-sub-directory-using-cmake/31423421
function(assign_source_group)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source}")
        else()
            set(_source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
endfunction(assign_source_group)

assign_source_group(${sources})
