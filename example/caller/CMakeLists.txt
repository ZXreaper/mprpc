# set(SRC_LIST calluserservice.cc ../user.pb.cc)
set(SRC_LIST callfriendlistservice.cc ../friend.pb.cc)

add_executable(consumer ${SRC_LIST})
# 需要链接的库
target_link_libraries(consumer mprpc protobuf)