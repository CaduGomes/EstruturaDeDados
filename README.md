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
