# 42_pipex

O objetivo deste projeto é simular o funcionamento do pipe no bash utilizando C.

## Sobre o projeto
O projeto simula o comportamento do bash "~ < file_1 cmd_1 | cmd_2 > file_2", onde cada "cmd" é um comando que será executado pelo bash, e o símbolo "|" indica que o comando à esquerda será conectado ao comando à direita, formando uma "cadeia" ou "pipeline" de comandos. A notação "~ < file_1" e "> file_2" indica que o arquivo "file_1" será usado como entrada para o primeiro comando e o arquivo "file_2" será usado como saída do último comando da cadeia.
É possível adicionar quantos comandos quiser na cadeia. Utilizo a biblioteca de funções standart libft para organizar os argumentos e crio um processo para cada argumento de comando, executando-os com a função execve(). Além disso, faço a comunicação entre os processos e arquivos usando as funções pipe() e dup2().
Fique à vontade para contribuir ou fazer sugestões de melhorias.

## Como utilizar?
* Realize o comando "make"
* Para utilizar o programa "pipex", execute o comando "./pipex <file_1> <cmd_1> <cmd_2> <file_2>"
* Os arquivos "file_1" e "file_2" podem ser quaisquer arquivos.
* Os comandos "cmd_1" e "cmd_2" podem ser quaisquer comandos do bash.
* Você também pode adicionar quantos comandos quiser na cadeia de comandos, basta seguir o mesmo formato.

## Outras funcionalidades
O projeto permite simular a utilização dos operadores "<<" e ">>" de maneira fácil e prática, seguindo a seguinte comportamento do bash: "~ cmd_1 << EOF | cmd_2 >> file".

O operador "<<" (here document) é um mecanismo de entrada de dados que permite ao usuário fornecer uma série de linhas de texto como entrada para um comando através da entrada padrão do bash. É preciso usar uma string "EOF" para indicar o final da leitura, mas essa string pode ser qualquer coisa.

O operador ">>" representa o redirecionamento da saída padrão do bash para um arquivo. A diferença em relação ao operador ">" é que o ">>" adiciona o conteúdo ao final do arquivo, ao invés de substituir o conteúdo existente pelo resultado do comando.