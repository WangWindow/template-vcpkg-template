<div align="center">
  <h1>🚀 Modern C++ 项目模板</h1>
  <p>一个基于CMake和VCPKG清单模式的现代C++项目结构</p>

  ![C++](https://img.shields.io/badge/C++-23+-blue.svg)
  ![CMake](https://img.shields.io/badge/CMake-3.30+-green.svg)
  ![VCPKG](https://img.shields.io/badge/VCPKG-2025.03+-orange.svg)
  ![License](https://img.shields.io/badge/License-MIT-yellow.svg)
</div>

<p align="center">
  <a href="#-目录结构">目录结构</a> •
  <a href="#-特性">特性</a> •
  <a href="#-快速开始">快速开始</a> •
  <a href="#-依赖管理">依赖管理</a> •
  <a href="#-使用方法">使用方法</a> •
  <a href="#-贡献">贡献</a> •
  <a href="#-许可证">许可证</a>
</p>

## 📋 目录结构

```
project-root/
├── .github/             # GitHub相关配置（Actions等）
├── include/             # 公共头文件
├── lib/                 # 库代码目录
├── src/                 # 源代码
├── tests/               # 测试代码
├── .clang-format        # 代码格式化配置
├── .gitignore           # Git忽略配置
├── CMakeLists.txt       # 主CMake配置
├── vcpkg.json           # VCPKG依赖声明
├── LICENSE              # 许可证
└── README.md            # 本文件
```

## ✨ 特性

<table>
  <tr>
    <td><b>📦 模块化结构</b></td>
    <td>清晰分离的目录结构，便于大型项目管理</td>
  </tr>
  <tr>
    <td><b>🛠 现代CMake实践</b></td>
    <td>使用目标导向方法和预设(Presets)配置</td>
  </tr>
  <tr>
    <td><b>📚 VCPKG清单模式</b></td>
    <td>简化依赖管理，使用声明式依赖配置</td>
  </tr>
  <tr>
    <td><b>🧪 测试集成</b></td>
    <td>集成GoogleTest框架，支持单元和集成测试</td>
  </tr>
  <tr>
    <td><b>🔍 静态分析</b></td>
    <td>集成现代C++代码质量工具</td>
  </tr>
  <tr>
    <td><b>🔄 持续集成</b></td>
    <td>提供GitHub Actions工作流模板</td>
  </tr>
</table>

## 🚀 快速开始

### 前置要求

- CMake 3.30+
- 现代C++编译器(支持C++23)
- [VCPKG](https://github.com/microsoft/vcpkg) (已安装并集成)

### 构建项目

```bash
# 克隆项目
git clone https://github.com/yourusername/your-project.git
cd your-project

# 使用CMake预设配置和构建
cmake --preset=default
cmake --build --preset=default

# 运行测试
ctest --preset=default
```

<details>
<summary><b>手动构建步骤</b></summary>

```bash
# 创建并进入构建目录
mkdir build && cd build

# 配置 (VCPKG工具链自动集成)
cmake .. -DCMAKE_BUILD_TYPE=Release

# 构建
cmake --build . --config Release

# 运行测试
ctest -C Release
```
</details>

## 📚 依赖管理

本项目使用VCPKG清单模式管理依赖项。依赖配置位于根目录的`vcpkg.json`文件中。

<details>
<summary><b>vcpkg.json 示例</b></summary>

```json
{
  "name": "your-project",
  "version": "1.0.0",
  "description": "Modern C++ Project Template",
  "dependencies": [
    "fmt",
    "spdlog",
    {
      "name": "boost-filesystem",
      "version>=": "1.78.0"
    }
  ],
  "features": {
    "tests": {
      "description": "Build tests",
      "dependencies": [
        "gtest"
      ]
    }
  }
}
```
</details>

### VCPKG集成优势

- **声明式依赖管理**: 通过清单文件(manifest)明确定义所有依赖
- **版本控制**: 锁定特定版本的依赖，确保构建一致性
- **特性标记**: 按需启用可选组件
- **多平台支持**: 一致的依赖处理，跨Windows、Linux和macOS

## 📝 使用方法

### 作为模板使用

1. 点击GitHub上的"Use this template"按钮创建你的项目
2. 克隆新项目并按照以下步骤进行定制:

<details>
<summary><b>项目定制步骤</b></summary>

1. 修改`CMakeLists.txt`中的项目名称和版本
2. 更新`vcpkg.json`中的项目名称和依赖项
3. 调整目录结构和命名空间以匹配你的项目
4. 编写你的代码!
</details>

### 添加新组件

1. 在`src/components`目录下创建新文件夹
2. 添加对应的`CMakeLists.txt`文件
3. 在主`CMakeLists.txt`中引用新组件

### 添加新应用程序

1. 在`src/app`目录下创建新文件夹
2. 添加对应的`CMakeLists.txt`文件
3. 链接到所需库和组件

### 添加新测试

在`tests`目录下添加测试代码，遵循[GoogleTest框架](https://github.com/google/googletest)的使用指南。

## 🤝 贡献

欢迎提交问题和拉取请求！请确保遵循项目的代码规范和提交指南。

<details>
<summary><b>贡献指南</b></summary>

1. Fork项目
2. 创建您的特性分支 (`git checkout -b feature/amazing-feature`)
3. 提交您的修改 (`git commit -m 'Add some amazing feature'`)
4. 推送到分支 (`git push origin feature/amazing-feature`)
5. 提交Pull Request
</details>

## 📄 许可证

该项目采用MIT许可证 - 详见[LICENSE](LICENSE)文件
