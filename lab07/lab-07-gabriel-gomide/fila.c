/*

  gerenciador.c - Implementação do TAD para manipulação de uma Fila de Prioridade
                  utilizada no contexto de um sistema de atendimento de uma clínica médica.

  Autor: Gabriel Barbiero Fagundes Gomide 247734.

  MC202G+H - 2 semestre de 2023.

  Última alteração: 1/12/2023.

*/

#include "fila.h"

#define PAI(i) ((i - 1) / 2)
#define F_ESQ(i) (2 * i + 1)
#define F_DIR(i) (2 * i + 2)

/* TODO: implemente aqui as funções da interface! */
void troca(Item *a, Item *b)
{
  Item t = *a;
  *a = *b;
  *b = t;
}

// Cria a fila de prioridade com tamanho definido.
p_fp criar_filaprio(int tam)
{
  p_fp fprio = malloc(sizeof(FP));
  fprio->v = malloc((tam+1) * sizeof(Item));
  fprio->n = 0;
  fprio->tamanho = tam;
  return fprio;
}
/*int compara_tempo(p_fp fprio, int k, int k2)
{

  if (fprio->v[k].chegada.hora > fprio->v[k2].chegada.hora)
  {
    return 2;
  }
  else if (fprio->v[k].chegada.hora < fprio->v[k2].chegada.hora)
  {
    return 1;
  }
  else if (fprio->v[k].chegada.minuto > fprio->v[k2].chegada.minuto)
  {
    return 2;
  }
  else
  {
    return 1;
  }
}*/

void sobe_no_heap(p_fp fprio, int k)
{
  //int a = 0;
  if (k > 0 && fprio->v[PAI(k)].chave > fprio->v[k].chave)
  {
    troca(&fprio->v[k], &fprio->v[PAI(k)]);
    sobe_no_heap(fprio, PAI(k));
  }

  /*if (k > 0 && fprio->v[PAI(k)].chave == fprio->v[k].chave)
  {
    a = compara_tempo(fprio, k, PAI(k));
    if (a == 1)
    {
      troca(&fprio->v[k], &fprio->v[PAI(k)]);
      sobe_no_heap(fprio, PAI(k));
    }
  }*/
}

void desce_no_heap(p_fp fprio, int k)
{
  int maior_filho;
  //int a = 0;
  if (F_ESQ(k) < fprio->n)
  {
    maior_filho = F_ESQ(k);
    if (F_DIR(k) < fprio->n && fprio->v[F_ESQ(k)].chave > fprio->v[F_DIR(k)].chave)
    {
      maior_filho = F_DIR(k);
    }
    if (fprio->v[k].chave > fprio->v[maior_filho].chave)
    {
      troca(&fprio->v[k], &fprio->v[maior_filho]);
      desce_no_heap(fprio, maior_filho);
    }

    /*if (fprio->v[k].chave == fprio->v[maior_filho].chave)
    {
      a = compara_tempo(fprio, k, maior_filho);
      if (a == 1)
      {
        troca(&fprio->v[k], &fprio->v[maior_filho]);
        desce_no_heap(fprio, maior_filho);
      }
    }*/
  }
}
void desce_no_heap2(p_fp fprio, int n, int k)
{
  // int a = 0;
  int maior_filho;

  if (F_ESQ(k) < n)
  {
    maior_filho = F_ESQ(k);
    if (F_DIR(k) < n && fprio->v[F_ESQ(k)].chave < fprio->v[F_DIR(k)].chave)
      maior_filho = F_DIR(k);

    if (fprio->v[k].chave < fprio->v[maior_filho].chave)
    {
      troca(&fprio->v[k], &fprio->v[maior_filho]);
      desce_no_heap2(fprio, n, maior_filho);
    }

  }
}

void heapsort(p_fp fprio, int n)
{
  int k;
  for (k = n / 2; k >= 0; k--) /* transforma em heap */
    desce_no_heap2(fprio, n, k);
  while (n > 1)
  { /* extrai o máximo */
    troca(&fprio->v[0], &fprio->v[n - 1]);
    n--;
    desce_no_heap2(fprio, n, 0);
  }
  int i, j, trocou = 1;
  for (i = 0; i < fprio->n && trocou; i++)
  {
    trocou = 0;
    for (j = fprio->n - 1; j > i; j--)
    {
      if (fprio->v[j].chave == fprio->v[j - 1].chave && fprio->v[j].chegada.hora < fprio->v[j - 1].chegada.hora)
      {
        troca(&fprio->v[j - 1], &fprio->v[j]);
        trocou = 1;
      }
    }
  }
  trocou = 1;
  for (int l = 0; l < fprio->n && trocou; l++)
  {
    trocou = 0;
    for (int u = fprio->n - 1; u > l; u--)
    {
      if (fprio->v[u].chave == fprio->v[u - 1].chave && fprio->v[u].chegada.hora == fprio->v[u - 1].chegada.hora && fprio->v[u].chegada.minuto < fprio->v[u - 1].chegada.minuto)
      {
        troca(&fprio->v[u - 1], &fprio->v[u]);
        trocou = 1;
      }
    }
  }
}
// Insere um item na fila
void insere(p_fp fprio, Item item)
{
  if (fprio->n < fprio->tamanho){
  fprio->v[fprio->n] = item;
  fprio->n++;
  sobe_no_heap(fprio, fprio->n - 1);}
}

// Extrai o Item de maior prioridade
Item extrai_maximo(p_fp fprio)
{
  heapsort(fprio, fprio->n);
  Item item = fprio->v[0];
  troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
  fprio->n--;
  desce_no_heap(fprio, 0);
  return item;
}

// Verifica se a fila está vazia
int vazia(p_fp fprio)
{
  if (fprio->n == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// Veirifica se a fila está cheia
int cheia(p_fp fprio)
{
  if (fprio->n == fprio->tamanho)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int busca_nome(p_fp fprio, char nome[])
{
  for (int i = 0; i < fprio->n; i++)
  {
    if ((strcmp(fprio->v[i].nome, nome) == 0))
    {
      return i;
    }
  }
  return 0;
}

// Atualiza a gravidade de um paciente e reordena a fila

void atualizar_gravidade(p_fp fprio, char nome[], int nova_gravidade)
{

  int k = busca_nome(fprio, nome);

  if (fprio->v[k].chave > nova_gravidade)
  {
    fprio->v[k].chave = nova_gravidade;
    sobe_no_heap(fprio, k);
  }
  else
  {
    fprio->v[k].chave = nova_gravidade;
    desce_no_heap(fprio, k);
  }
}

void imprime(Item item)
{
  printf("Paciente: ");
  printf("%s, ", item.nome);
  printf("Gravidade: ");
  printf("%d, ", item.chave);
  printf("Chegada: ");
  printf("%02d:%02d\n", item.chegada.hora, item.chegada.minuto);
}

void imprime_fila(p_fp fprio)
{
  int job = fprio->n;
  heapsort(fprio, job);
  int m = 0;

  for (int y = 0; y < fprio->n; y++)
  {
    m = m + 1;
    printf("%d. ", m);
    imprime(fprio->v[y]);
  }

}
// Libera a fila de memória
void destroi_fila(p_fp fprio)
{
  free(fprio->v);
  free(fprio);
}

/*
   Fim do arquivo de implementação.
*/
