# Trabalhos e atividades da disciplina de Estrutura de Dados


Para executar os projetos é necessário utilizar o CMake e o GoogleTest


## Configs

É necessário clonar o projeto googletest para a pasta do projeto

`git clone https://github.com/google/googletest`

Após isso é necessário criar uma pasta build na raiz do projeto

Caso esteja utilizando o VSCode recomendo utilizar a extensão CMake Tools

Então basta executar o projeto com o CMake

`cd build`

`cmake ..`

`make`

## CMake config
É necessário criar um arquivo CMakeLists.txt com essa configuração dentro da pasta root

    cmake_minimum_required(VERSION 3.12) # version can be different

    set(CMAKE_CXX_STANDARD 17)

    project(NOMEDOPROJETO) #name of your project

    add_subdirectory(googletest) # add googletest subdirectory

    include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

    add_executable(mytests main.cpp) # add this executable

    target_link_libraries(mytests PRIVATE gtest) # link google test to this executable

## Debug
Configuração de debug do VSCode

    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${command:cmake.launchTargetPath}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
