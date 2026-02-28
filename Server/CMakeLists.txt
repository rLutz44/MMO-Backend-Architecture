add_executable(GameServer src/main.cpp "src/ClientState.h" "src/CoreStateEngine.h" "src/CoreStateEngine.cpp")
target_link_libraries(GameServer PRIVATE SharedProtocol)