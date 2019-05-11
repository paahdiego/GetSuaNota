# GetSuaNota

Programa e código em C++ para calculo de média e CRA.

## Getting Started

MacOS (Talvez Linux):
Para executar o código basta abrir o arquivo program no terminal do MacOS.

Windows:
Necessário abrir código fonte:
1 - Substituir system("read -p...); por system("pause");
2 - Substituir system("clear"); por system("cls");
3 - Compilar para criar executavel com MinGW ou TDM GCC (usar "g++ -std=c++0x filename.cpp -o filename" caso dê algum erro)
4 - Executar o executável pelo terminal.
### Prerequisites

Unico pré-requisito é zerar o csv notas, para que possa cadastrar suas notas. Certifique-se de limpar todos os valores e linhas.


## Versioning

Beta v1: 
1 - Cadastra Cadeiras {Nome, Peso, Notas}.
2 - Exibe as cadeiras cadastradas informando a média.
3 - Calculo de CRA.
4 - Lê e salva os dados em um CSV para que não seja necessário cadastrar todas as cadeiras sempre que executar o programa.
  

## Authors

* **Patrick Diego** - *GetSuaNota* - [Paahdiego](https://github.com/Paahdiego)
