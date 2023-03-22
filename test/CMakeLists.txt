cmake_minimum_required(VERSION 3.0.0)
project(trie-test VERSION 0.1.0)

add_executable(trie-test main.c)
target_include_directories(trie-test PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(trie-test trie)

add_executable(trie-test-two two.c)
target_include_directories(trie-test-two PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(trie-test-two trie)
