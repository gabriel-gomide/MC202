/* 
Registro:
- Uma coleção de variáveis relacionadas de vários tipos, organizadas em uma 
única estrutura e referenciadas por um nome comum
- Cada variável é chamada de membro do registro, os membros são acessados por um nome na estrutura,
cada estrutura define um novo tipo, com as mesmas características de um tipo
padrão da linguagem

Declaração da estrutura:
struct identificador {
    tipo1 membro1;
    tipo2 membro2;
    ...
    tipoN membroN;
};
*/

/* Declarando um registro */
struct identificador nome_registro;

/* Exemplo de estrutura */
struct data
{
    int dia;
    int mes;
    int ano;
};
struct ficha_aluno
{
    int ra;
    int telefone;
    char nome[30];
    char endereco[100];
    struct data nascimento;
};

/* Usando um registro
registro.membro */
int main(){
struct ficha_aluno aluno;
printf("Aluno: %s\n", aluno.nome);
}
