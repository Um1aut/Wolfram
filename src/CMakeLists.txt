add_executable(Wolfram Wolfram.h init.cpp model_loader.h stb_image.h)

set(source "${CMAKE_SOURCE_DIR}/resources")
set(destination "${CMAKE_CURRENT_BINARY_DIR}/resources")

# Compile shaders
if(UNIX)
	add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND /bin/sh ${CMAKE_SOURCE_DIR}/resources/shaders/compile.sh)
endif(UNIX)
if(WIN32)
	add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_SOURCE_DIR}/resources/shaders/compile.bat)
endif(WIN32)
add_custom_command(TARGET ${PROJECT_NAME}
COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
DEPENDS ${destination}
COMMENT "symbolic link resource folder from ${source} => ${destination}")
