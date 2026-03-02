
add_executable(GameServer src/main.cpp "src/ClientState.h" "src/CoreStateEngine.h" "src/CoreStateEngine.cpp")

find_package(asio CONFIG REQUIRED)
target_link_libraries(GameServer PRIVATE SharedProtocol asio::asio)

target_link_libraries(GameServer PRIVATE SharedProtocol)