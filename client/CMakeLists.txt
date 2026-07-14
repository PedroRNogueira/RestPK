add_executable(restpk_client
    src/main.cpp
)

target_compile_features(restpk_client PRIVATE cxx_std_20)

target_include_directories(restpk_client
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(restpk_client
    PRIVATE
        restpk_shared
        restpk_backend
        SDL3::SDL3
)
