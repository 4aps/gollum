cmake_minimum_required(VERSION 3.16)
project(gollum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(gollum
    src/main.cpp

    src/commands/init.cpp
    src/commands/hash-object.cpp
    src/commands/cat-file.cpp
    src/commands/write-tree.cpp
    src/commands/commit-tree.cpp
    src/commands/add.cpp
    src/commands/commit.cpp
    src/commands/branch.cpp
    src/commands/switch.cpp
    src/commands/log.cpp
    src/commands/status.cpp
    src/commands/update-ref.cpp

    src/utils/compress.cpp
    src/utils/objects.cpp
    src/utils/gollum.cpp
    src/utils/head.cpp
)

target_include_directories(gollum PUBLIC ${CMAKE_SOURCE_DIR}/include)

find_package(OpenSSL REQUIRED)
target_link_libraries(gollum PRIVATE OpenSSL::SSL OpenSSL::Crypto)

find_package(ZLIB REQUIRED)
target_link_libraries(gollum PRIVATE ZLIB::ZLIB)

if (APPLE)
    target_compile_definitions(gollum PRIVATE _DARWIN_C_SOURCE)
endif()

install(TARGETS gollum RUNTIME DESTINATION bin)

enable_testing()

