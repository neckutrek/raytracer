set(SOURCES
   main.cpp)

add_executable(main ${SOURCES})
target_include_directories(main PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(main ${SDL2_LIBRARIES})