find_package(asio CONFIG REQUIRED)

add_executable(GMTool src/main.cpp)

target_link_libraries(GMTool PRIVATE SharedProtocol asio::asio)