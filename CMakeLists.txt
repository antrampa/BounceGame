cmake_minimum_required(VERSION 3.28)
project(Bounce CXX)

include(FetchContent)
FetchContent_Declare(sfml GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.0.2)
FetchContent_MakeAvailable(sfml)

file(GLOB SOURCES CONFIGURE_DEPENDS Source/*.cpp)
add_executable(Bounce ${SOURCES})

target_include_directories(Bounce PRIVATE Include)
target_compile_features(Bounce PRIVATE cxx_std_20)
target_link_libraries(Bounce PRIVATE SFML::Graphics SFML::Audio)


# --------------------------------------------------
# Copy SFML DLLs next to the executable on Windows
# --------------------------------------------------

if(WIN32)
    add_custom_command(TARGET Bounce POST_BUILD

        # SFML Graphics
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SFML::Graphics>
            $<TARGET_FILE_DIR:Bounce>

        # SFML Window
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SFML::Window>
            $<TARGET_FILE_DIR:Bounce>

        # SFML System
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SFML::System>
            $<TARGET_FILE_DIR:Bounce>

        # SFML Audio
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SFML::Audio>
            $<TARGET_FILE_DIR:Bounce>

        # OpenAL (required by SFML Audio)
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:OpenAL>
            $<TARGET_FILE_DIR:Bounce>
    )
endif()
