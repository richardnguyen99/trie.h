cmake_minimum_required(VERSION 3.0.0)
project(trie.h VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(${CMAKE_SOURCE_DIR})

add_library(trie OBJECT trie.c)

add_executable(main main.c)
target_link_libraries(main PRIVATE trie)

add_subdirectory(test)

add_test(NAME dummy-trie-test-1 COMMAND trie-test)
add_test(NAME dummy-trie-test-2 COMMAND trie-test-two)
add_test(NAME trie-test-mktrie COMMAND trie-make)
add_test(NAME trie-test-add COMMAND trie-add)
add_test(NAME trie-test-search COMMAND trie-search)
add_test(NAME trie-test-delete COMMAND trie-delete)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
