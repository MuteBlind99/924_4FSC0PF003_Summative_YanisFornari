﻿message("2_Factorize CMake Build")

# Packages : external libraries managed by
file(GLOB_RECURSE SRC_FILES src/*.cc)
file(GLOB_RECURSE HEADER_FILES include/*.h)

add_executable(2_Factorize ${SRC_FILES} ${HEADER_FILES}
        include/key_manager.h
        src/key_manager.cc
        include/render_manager.h
        src/render_manager.cc
        include/event_manager.h
        src/event_manager.cc
        src/text_manager.cc
        include/Text_manager.h)
target_include_directories(2_Factorize PRIVATE include/)

target_link_libraries(2_Factorize PUBLIC SFML::System SFML::Graphics SFML::Window)

# Manage Ressources
# Delete all and copy
add_custom_target(2_Factorize_AssetsCopy ALL
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/2_factorize/_assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/2_factorize/_assets ${CMAKE_BINARY_DIR}/2_factorize/_assets
        COMMENT "🔄 Copying all resources to build directory"
)
add_dependencies(2_Factorize 2_Factorize_AssetsCopy)

