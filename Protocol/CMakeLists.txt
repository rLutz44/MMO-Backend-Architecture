find_package(Protobuf REQUIRED)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS messages.proto)

add_library(SharedProtocol ${PROTO_SRCS} ${PROTO_HDRS})

target_link_libraries(SharedProtocol PUBLIC protobuf::libprotobuf)

target_include_directories(SharedProtocol PUBLIC ${CMAKE_CURRENT_BINARY_DIR})