add_library(subhook STATIC subhook/subhook.c)
target_compile_definitions(subhook PUBLIC SUBHOOK_STATIC)
target_include_directories(subhook PUBLIC subhook)