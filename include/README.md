Este diretório destina-se a arquivos de cabeçalho do projeto.

Um arquivo de cabeçalho é um arquivo contendo declarações em C e definições de macro para serem compartilhadas entre vários arquivos fonte do projeto. Você solicita o uso de um arquivo de cabeçalho em seu arquivo fonte do projeto (C, C++, etc) localizado na pasta `src` incluindo-o, com a diretiva de pré-processamento em C `#include`.

```src/main.c

#include "header.h"

int main (void)
{
 ...
}
```

Incluir um arquivo de cabeçalho produz os mesmos resultados que copiar o arquivo de cabeçalho em cada arquivo fonte que precisa dele. Tal cópia seria demorada e propensa a erros. Com um arquivo de cabeçalho, as declarações relacionadas aparecem em apenas um lugar. Se precisarem ser alteradas, podem ser alteradas em um único lugar, e programas que incluem o arquivo de cabeçalho usarão automaticamente a nova versão na próxima recompilação. O arquivo de cabeçalho elimina o trabalho de encontrar e alterar todas as cópias, bem como o risco de falha ao encontrar uma cópia resultará em inconsistências dentro de um programa.

Em C, a convenção usual é dar aos arquivos de cabeçalho nomes que terminam com `.h'. É mais portátil usar apenas letras, dígitos, traços e sublinhados nos nomes de arquivos de cabeçalho, e no máximo um ponto.

Saiba mais sobre o uso de arquivos de cabeçalho na documentação oficial do GCC:

- Sintaxe de Inclusão
- Operação de Inclusão
- Cabeçalhos Somente Uma Vez
- Inclusões Computadas

https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html
