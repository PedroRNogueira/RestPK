add_library(restpk_backend STATIC
    src/Player.cpp
    src/World.cpp
)

target_compile_features(restpk_backend PUBLIC cxx_std_20)

target_include_directories(restpk_backend
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)

target_link_libraries(restpk_backend
    PUBLIC
        restpk_shared
)
