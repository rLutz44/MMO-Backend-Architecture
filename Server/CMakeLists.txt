find_package(asio CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(GameServer ${SOURCES})

target_include_directories(GameServer PRIVATE src)


target_link_libraries(GameServer PRIVATE SharedProtocol asio::asio)

target_link_libraries(GameServer PRIVATE SharedProtocol)