cmake_Minimum_required(VERSION 2.6)
project(gridworld CXX)

INCLUDE_DIRECTORIES(include/
        /usr/local/allegro/include)
LINK_DIRECTORIES(/usr/include/allegro5)

SET(ALLEGRO_LIBS liballegro.so liballegro_primitives.so liballegro_image.so liballegro_font.so
                 liballegro_ttf.so)

find_package (Threads)

file(GLOB_RECURSE AGENT_SOURCES "agent/src/*.cpp")
file(GLOB_RECURSE EXPERIMENT_SOURCES "experiment/src/*.cpp")
file(GLOB_RECURSE GRID_SOURCES "grid/src/*.cpp")

add_executable(${PROJECT_NAME} ${AGENT_SOURCES} ${EXPERIMENT_SOURCES} ${GRID_SOURCES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${ALLEGRO_LIBS} ${CMAKE_THREAD_LIBS_INIT})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)
