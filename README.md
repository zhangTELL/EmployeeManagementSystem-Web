# EmployeeManagementSystem-Web

> 职工管理系统 Web 版 — Vibe Coding 演示

这是我大一 C++ 课程设计项目的网页改版。后端逻辑由我纯手写 C++ 实现，前端界面则借助 Vibe Coding 搭配 WorkBuddy 快速搭建生成。

注：这个项目并非追求功能极致完善，而是希望记录一次开发模式的转变：体验vibe coding的感觉，让AI快速产出可直接使用的前端页面；但核心逻辑、底层架构与项目整体把控，依旧需要依靠人来主导实现。

C++ 原版项目 👉 [EmployeeManagementSystem](https://github.com/zhangTELL/EmployeeManagementSystem)

## 功能特性

### C++ 控制台版本

- **增** — 添加新职工信息
- **删** — 删除指定职工
- **改** — 修改职工信息（编号、姓名、职位）
- **查** — 按编号或姓名查找职工
- **排** — 按编号升序/降序排序
- **存** — 文件持久化存储
- **清** — 清空所有数据

### Web 版本（Vibe Coding 生成）

在 C++ 版本功能基础上，增加了：

- 🎨 深色 / 浅色 / 跟随系统三种主题切换
- 📊 仪表盘（总人数、各职位统计）
- ➕ 批量添加职工
- 🕐 添加时间记录
- ⚠️ 清空前预览所有数据
- 💾 localStorage 本地持久化

直接打开 `web/index.html` 即可使用，无需任何服务器。

## 技术要点

### C++ 后端

- **多态** — 抽象基类 `Worker` + 派生类 `Employee` / `Manager` / `Boss`
- **虚函数** — `ShowInfo()` 和 `GetDeptID()` 实现运行时多态
- **文件 IO** — `fstream` 实现数据持久化
- **动态数组** — 指针数组管理职工对象
- **STL** — `std::sort` + Lambda 实现排序

### Web 前端（Vibe Coding）

- 单文件 HTML + CSS + JS，零依赖
- CSS 变量驱动主题切换
- `prefers-color-scheme` 媒体查询实现跟随系统
- localStorage 模拟文件持久化

## 项目结构

**C++ 源码 (`职工管理系统/`)**

| 文件 | 说明 |
|------|------|
| worker.h | 职工抽象基类 |
| workerManager.h / .cpp | 管理系统类 |
| employee.h / .cpp | 普通员工类 |
| manager.h / .cpp | 经理类 |
| boss.h / .cpp | 老板类 |
| main.cpp | 程序入口 |
| CMakeLists.txt | CMake 构建配置 |

**Web 版本 (`web/`)**

- index.html — Web 版本（Vibe Coding 生成，单文件零依赖）

## 编译运行 C++ 版本

### CMake

```bash
mkdir build && cd build
cmake .. && cmake --build .
./emp_manager
```

### g++

```bash
cd 职工管理系统
g++ -o emp main.cpp workerManager.cpp employee.cpp manager.cpp boss.cpp
./emp
```

## 作者

大一学生练手项目 | 大括号换行党 😄

PS：作者很菜，轻喷
