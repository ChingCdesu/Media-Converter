cmake_minimum_required(VERSION 3.9)
project(media-converter) # 项目名称

set(CMAKE_CXX_STANDARD 17) # c++版本：c++17

if (MSVC)
    set(OS Windows)
    if (CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(platform x86)
    else()
        set(platform x64)
    endif()
elseif(APPLE)
    set(OS macOS)
    set(platform x64)
else()
    message(ERROR "Unsupported OS or Platform.")
endif()

include_directories(./include) # 包含文件夹

file(GLOB_RECURSE CPP_SRC_LIST src/*.cc) # 源代码文件夹

add_definitions("-DELPP_NO_LOG_TO_FILE -DELPP_NO_DEFAULT_LOG_FILE -DMINGW") # 取消logger文件输出

add_executable(${PROJECT_NAME} ${CPP_SRC_LIST} main.cpp)
# target_link_libraries(${PROJECT_NAME} wsock32 ws2_32)