cmake_minimum_required(VERSION 3.0.0)
project(trie-test VERSION 0.1.0)

add_executable(trie-test main.c)
target_include_directories(trie-test PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(trie-test trie)

add_executable(trie-test-two two.c)
target_include_directories(trie-test-two PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(trie-test-two trie)

add_executable(trie-make mktrie.c)
target_include_directories(trie-make PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(trie-make trie)

add_executable(trie-add addtrie.c)
target_include_directories(trie-add PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(trie-add trie)

add_executable(trie-search searchtrie.c)
target_include_directories(trie-search PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(trie-search trie)

add_executable(trie-delete deltrie.c)
target_include_directories(trie-delete PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(trie-delete trie)
