# 42_pipex

O objetivo deste projeto é simular o funcionamento do pipe no bash utilizando C.

## Sobre o projeto

Este projeto simula o comportamento do bash "cmd_1 < file_1 | cmd_2 > file_2", onde cada "cmd" é um comando que será executado pelo bash, e o símbolo "|" indica que o comando à esquerda será conectado ao comando à direita, formando uma "cadeia" ou "pipeline" de comandos. A notação "cmd_1 < file_1" e "> file_2" indica que o arquivo "file_1" será usado como entrada para o primeiro comando e o arquivo "file_2" será usado como saída do último comando da cadeia.

É possível adicionar quantos comandos quiser na cadeia. Utilizamos a biblioteca de funções padrão libft para organizar os argumentos e criamos um processo para cada argumento de comando, executando-os com a função execve(). Além disso, fazemos a comunicação entre os processos e arquivos usando as funções pipe() e dup2(). Fique à vontade para contribuir ou fazer sugestões de melhorias.

## Como utilizar?

Para utilizar o programa "pipex", siga os seguintes passos:

1. Execute o comando "make" para compilar o projeto.
2. Execute o comando "./pipex <file_1> <cmd_1> <cmd_2> <file_2>" para utilizar o programa.
   - Os arquivos "file_1" e "file_2" podem ser qualquer arquivo.
   - Os comandos "cmd_1" e "cmd_2" podem ser qualquer comando do bash.
   - É possível adicionar quantos comandos quiser na cadeia de comandos, basta seguir o mesmo formato.

## Outras funcionalidades

Este projeto também permite simular a utilização dos operadores "<<" e ">>" de maneira fácil e prática, simulando o seguinte comportamento do bash: "cmd_1 << EOF | cmd_2 >> file".

O operador "<<" (here document) é um mecanismo de entrada de dados que permite ao usuário fornecer uma série de linhas de texto como entrada para um comando através da entrada padrão do bash. É preciso usar uma string "EOF" para indicar o final da leitura, mas essa string pode ser qualquer coisa.

O operador ">>" representa o redirecionamento da saída padrão do bash para um arquivo. A diferença em relação ao operador ">" é que o ">>" adiciona o conteúdo ao final do arquivo, ao invés de substituir o conteúdo existente pelo resultado do comando.

## Exemplos

* $> ./pipex infile "ls -l" "wc -l" outfile
	- Should behave like: < infile ls -l | wc -l > outfile

* $> ./pipex infile "grep a1" "wc -w" outfile
	- Should behave like: < infile grep a1 | wc -w > outfile

* $> ./pipex infile "grep a1" "wc -w" cat cat cat cat outfile
	- Should behave like: < infile grep a1 | wc -w | cat | cat | cat | cat > outfile

* $> ./pipex here_doc EOF "cat" "wc -l" outfile
	- Should behave like: cat << EOF | wc -l >> outfile

* $> ./pipex here_doc EOF "cat" "cat" outfile
	- Should behave like: cat << EOF | cat >> outfile

* $> ./pipex here_doc EOF "cat" "wc -l" cat cat outfile
	- Should behave like: cat << EOF | wc -l | cat | cat >> outfile