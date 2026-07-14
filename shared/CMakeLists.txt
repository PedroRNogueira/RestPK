add_library(restpk_shared INTERFACE)

target_compile_features(restpk_shared INTERFACE cxx_std_20)

target_include_directories(restpk_shared
    INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)
