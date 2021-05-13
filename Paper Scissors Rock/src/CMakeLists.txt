project(paperscissorsrock)

set(SRC
	controller.cpp
	console_drawer.cpp
	player.cpp
	main.cpp
)

add_executable(${PROJECT_NAME}
    ${SRC}
)

# Declare the library
add_library(lib${PROJECT_NAME} STATIC
    ${SRC}
)

include_directories (
  ${BASE_DIR}/include
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)