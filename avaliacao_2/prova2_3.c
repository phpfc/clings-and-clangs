/*
 QUESIAO 3) (3,5 PONTOS) Considere um programa que armazena os dados de
 contatos em um vetor de estruturas do tipo ST_CONTATO, definido conforme o
 seguinte tipo:

  struct st_contato {
      char nome[50];
      char email[100];
  };
  typedef struct st_contato ST_CONTATO;

 3.1) Implemente uma função que receba um vetor de estruturas do tipo
 ST_CONTATO e um inteiro n, representando a quantidade de contatos no vetor. A
 função deve retornar uma nova string contendo todos os e-mails presentes no
 vetor, separados por ponto e vírgula (;). A string resultante deve ter o
 tamanho exato necessário para armazenar todos os e-mails e os separadores
 (;). Importante: o último e-mail também deve ser seguido por ponto e vírgula.
 O protócpo a seguir deve ser utlizado obrigatoriamente: char
 buscaEmails(ST_CONTATO *c, int n);

 3.2) Complete o código a seguir, declarando outras variáveis, se necessário,
 e chamando corretamente a função buscaEmails. Após a chamada da função, exiba
 o conteúdo da string retornada na saída padrão. Por fim, certifique-se de
 desalocar corretamente a memória utilizada.

 int main() (
 ST_CONTATO contatos [5] = {
 (ALIce Santos", "aUcegeeall.con°), Bruno Lea brunofesall.coa")
 Carla Souza®
 ( Dandol costa: "carlagcoall.cos"),
 ,danlel@eaall.coa"),
 (Eduarda Pires®, °eduardafceall.con°)
 */
