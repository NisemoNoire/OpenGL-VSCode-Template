# OpenGL-VSCode-Template
A template of OpenGL C++ project for Windows based on:
> OpenGL 4.6 + VSCode + MSVC + CMake

Include `GLFW`, `GLAD`, `GLM`, `stb_image`.

The file directory would be like:
```shell
 |-bin         #(*.exe & *.dll)
 |-build       #(CMake files)
 |-include     #(*.h & *.hpp)
 |-lib         #(*.lib)
 |-src
    |-[example_1]         # project folder
       |-main.cpp
       |-CMakeLists.txt
    |-...
    |-CMakeLists.txt      # modify this
 |-CMakeLists.txt
```
How to use:
1. Add `C/C++` & `Cmake Tools` extension for VSCode.
2. Clone this repo.
3. On the bottom-toolbar in VSCode, you'll find a `BUILD` button and a `RUN` button. Press `RUN`.
4. If it's 1st time to run. Press the `BUILD` button before to generate the `/build` folder.

If you have multiple project folders. You can switch to each by modifying the `src/CMakeLists.txt`:
```cmake
add_subdirectory(example_1)    # modify this
```

There are some examples included in the template, witch come from https://learnopengl.com/
___
Windows系统下的OpenGL项目模板，基于以下工具搭建：
> OpenGL 4.6 + VSCode + MSVC + CMake

已包含`GLFW`, `GLAD`, `GLM`, `stb_image`库。
项目文件结构如下：
```shell
 |-bin         #(可执行文件和动态库)
 |-build       #(CMake文件)
 |-include     #(头文件)
 |-lib         #(静态库)
 |-src
    |-[example_1]         # 项目文件夹
       |-main.cpp
       |-CMakeLists.txt
    |-...
    |-CMakeLists.txt      # 修改这里
 |-CMakeLists.txt
```
使用方式:
1. 确保VSCode里有 `C/C++` 和 `Cmake Tools` 插件
2. 复制这个项目文件
3. 在VSCode的底部工具栏里找到`生成`和`运行`按钮，直接点运行即可
4. 如果是第一次运行，先点生成，构建`/build`目录

有多个项目文件夹时，修改 `src/CMakeLists.txt` 进行切换:
```cmake
add_subdirectory(example_1)    # 改成对应目录
```

项目已经包含了一些 https://learnopengl-cn.github.io/ 中的示例