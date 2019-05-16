add_executable(Loader Main Loader)
target_link_libraries(Loader shlwapi)
target_compile_definitions(Loader PRIVATE _CRT_SECURE_NO_WARNINGS)