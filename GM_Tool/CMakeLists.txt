find_package(asio CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp src/*.h)

add_executable(GMTool ${SOURCES})

target_link_libraries(GMTool PRIVATE SharedProtocol asio::asio)