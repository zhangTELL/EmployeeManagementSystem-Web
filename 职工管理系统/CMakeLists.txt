cmake_minimum_required(VERSION 3.15)
project(EmployeeManagementSystem VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 在Windows上禁用控制台窗口的快速编辑模式（可选）
if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# 设置包含目录（当前目录）
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 添加可执行文件
add_executable(emp_manager
    main.cpp
    workerManager.cpp
    boss.cpp
    employee.cpp
    manager.cpp
)

# 设置输出目录到项目根目录的build文件夹（可选）
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/build)

# 安装目标（可选）
install(TARGETS emp_manager DESTINATION bin)