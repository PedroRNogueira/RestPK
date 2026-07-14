add_library(restpk_backend INTERFACE)

target_compile_features(restpk_backend INTERFACE cxx_std_20)

target_include_directories(restpk_backend
    INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

target_link_libraries(restpk_backend
    INTERFACE
        restpk_shared
)
