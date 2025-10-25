/*
 QUESTÃO 2) (3,5 PONTOS) A estrutura ST_ PROJETO foi projetada para
 representar um projeto, contendo o nome do projeto, o nome do responsável e
 uma lista fixa de tarefas. Ela uliliza a diretiva #define
 QTDTAREFAS 5 para definir o número de tarefas associadas a cada projeto

 #define QTDTAREFAS 5
 typedef struct (
 char projeto[50];
 char responsavel[50];
 TAREFA tarefas[QTDTAREFAS];
 ) ST_PROJETO;

 A estrutura ST_TAREFA representa uma tarefa individual, contendo uma string
 chamada descricao que detalha a tarefa, além de um inteiro concluida que
 indica se a tarefa foi finalizada (valor 1) ou ainda está pendente (valor 0).

 typedef struct (
 char descrícao[100];
 int concluida; // 0 ou 1
 ) ST_TAREFA;
 2.1) Implemente uma função em linguagem C que receba um vetor de estruturas
 do tipo ST_PROJETO, juntamente com a quantidade de elementos presentes nesse
 vetor. Essa função deverá retornar, por meio de um ponteiro para uma
 estrutura do tipo ST_PROJETO, o projeto que possui o maior número de tarefas
 concluídas. No caso de haver dois ou mais projetos com a mesma quantidade de
 tarefas concluídas, deve ser retornado aquele cujo nome do projeto seja o
 menor em ordem alfabética. Além disso, por meio de um ponteiro para inteiro,
 a função deve retornar a quantidade de tarefas finalizadas nesse projeto. O
 protótipo a seguir deve ser utilizado obrigatoriamente:
 void maisTarefasConcluidas(ST_PROJETO * v, int ...) -- TENTAR VER QUAL ERA O
 PROTÓTIPO!
 */
