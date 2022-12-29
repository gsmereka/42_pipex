# 42_pipex

O objetivo deste projeto é simular o funcionamento do pipe no bash utilizando C.

## Sobre o projeto
Este repositório contém um projeto que simula o comportamento do bash "~ < file_1 cmd_1 | cmd_2 > file_2", onde cada "cmd" é um comando que será executado pelo bash, e o símbolo "|" indica que o comando à esquerda será conectado ao comando à direita, formando uma "cadeia" ou "pipeline" de comandos. A notação "~ < file_1" e "> file_2" indica que o arquivo "file_1" será usado como entrada para o primeiro comando e o arquivo "file_2" será usado como saída do último comando da cadeia. É possível adicionar quantos comandos quiser na cadeia. Utilizo a biblioteca de funções standart libft para organizar os argumentos e crio um processo para cada argumento de comando, executando-os com a função execve(). Além disso, faço a comunicação entre os processos e arquivos usando as funções pipe() e dup2(). Fique à vontade para contribuir ou fazer sugestões de melhorias.
