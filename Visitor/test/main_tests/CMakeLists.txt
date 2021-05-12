file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(main_tests ${SRCS})

TARGET_LINK_LIBRARIES(main_tests 
	libvisitor   
	libgtest
    libgmock)

include_directories (
  ${BASE_DIR}/include
)

add_test(NAME main_tests
         COMMAND main_tests)