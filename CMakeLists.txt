cmake_minimum_required(VERSION 3.25.1)

project (main)
set(CMAKE_CXX_STANDARD 11)
#set(BUILD_SHARED_LIBS FALSE)
#set(CMAKE_CXX_FLAGS "-static")
add_executable(main src/main.cpp)
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/src/h)
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/src/include)


# libs do Allegro
set (ALLEGRO_LIB_DIR ${CMAKE_SOURCE_DIR}/src/lib)
#set (GLFW_INC_DIR ${CMAKE_SOURCE_DIR}/libs/GLFW)

# libs do OpenGL
#set (GLEW_LIB_DIR ${CMAKE_SOURCE_DIR}/libs/GLEW/lib)
#set (GLFW_LIB_DIR ${CMAKE_SOURCE_DIR}/libs/GLFW/lib)

# includes de log
#set (LOG_INC_DIR ${CMAKE_SOURCE_DIR}/libs/Logging/include)

# fontes de log
#set (LOG_SRC_DIR ${CMAKE_SOURCE_DIR}/libs/Logging/src)

# diretorio dos fontes da aplicacao
#add_subdirectory(${CMAKE_SOURCE_DIR}/src)



#add_subdirectory(${CMAKE_SOURCE_DIR}/src/lib)
#add_subdirectory(nativefiledialog-extended-master)
#add_subdirectory(libzip-1.10.1)



target_link_libraries(main PUBLIC ${CMAKE_SOURCE_DIR}/src/lib/liballeg.so  ${CMAKE_SOURCE_DIR}/src/lib/liblogg.so ${CMAKE_SOURCE_DIR}/src/lib/liblogg.so.4.4 ${CMAKE_SOURCE_DIR}/src/lib/liblogg.so.4.4.3 )

#target_link_libraries(LibEasyPNG PRIVATE nfd libzip) 
