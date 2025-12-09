#include <stdio.h>

/*----------------------------------------------------------*/
struct entregador{
	char nome[21];
	int qtd;
	float valor;
	int dist;
};
typedef struct entregador ENTREGADOR;

/*----------------------------------------------------------*/
int main(){
	ENTREGADOR v[100];
	char entrada[] = "entregadores.txt", saida[] = "relatorio.txt";
	
	FILE *f = fopen(entrada, "r");
	if ( f == NULL ){
		printf("Erro ao abrir o arquivo %s\n", entrada);
		return 0;
	}
	
	FILE *s = fopen(saida, "w");
	if ( s == NULL ){
		printf("Erro ao abrir o arquivo %s\n", saida);
		return 0;
	}
	
	int qtd = 0;
	while (fscanf(f, "%s %d %f %d", v[qtd].nome, &v[qtd].qtd, &v[qtd].valor, &v[qtd].dist) == 4) {
		qtd++;
	} 
	
	int i, j;
	ENTREGADOR aux;
	for(i=0; i<qtd-1; i++){
		for(j=0; j<qtd-1-i; j++){
			if ( v[j].valor < v[j+1].valor){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;		
			}
		}
	}
	
	float total;
	fprintf(s, "Nr.  %-12s %-9s %-14s %s\n", "Entregador", "Entregas", "Faturamento", "Distancia (km)");
    	for (i = 0; i < qtd; i++) {
        	fprintf(s, "%-4d %-12s %-9d %11.2f %10d\n", i + 1, v[i].nome, v[i].qtd, v[i].valor, v[i].dist);	
	        total += v[i].valor;
	}
    	fprintf(s, "\nFaturamento total: %.2f\n", total);
    	fprintf(s, "Faturamento médio por entregador: %.2f\n", total / qtd);
	
	fclose(f);
	fclose(s);
}

/*----------------------------------------------------------*/
