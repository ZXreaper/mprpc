# set(SRC_LIST userservice.cc friendservice.cc ../user.pb.cc ../friend.pb.cc)
set(SRC_LIST friendservice.cc ../friend.pb.cc)

add_executable(provider ${SRC_LIST})
# 需要链接的库
target_link_libraries(provider mprpc protobuf)