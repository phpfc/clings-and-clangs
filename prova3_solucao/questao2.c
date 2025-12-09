#include <stdio.h>

/*----------------------------------------------------------*/
typedef struct {
    int codigoCliente;        
    char nome[51];
    int codigoCidade;
}CLIENTE;

typedef struct {
    int codigoCidade;            
    char nome[51];      
    char estado[3];     
} CIDADE;
/*----------------------------------------------------------*/
int main(){
	char clientes[] = "clientes.dat", cidades[] = "cidades.dat", saida[] = "saida.txt";
	
	FILE *f1 = fopen(clientes, "rb");
	if (  f1 == NULL ){
		printf("Erro ao abrir o arquivo %s\n", clientes);
		return 0;
	}
	
	FILE *f2 = fopen(cidades, "rb");
	if ( f2 == NULL ){
		printf("Erro ao abrir o arquivo %s\n", cidades);
		return 0;
	}
		
	FILE *s = fopen(saida, "w");
	if ( s == NULL ){
		printf("Erro ao abrir o arquivo %s\n", saida);
		return 0;
	}
	
	CLIENTE cli;
	CIDADE cid;
		
	while ( fread(&cli, sizeof(CLIENTE), 1, f1) ){
		while ( fread(&cid, sizeof(CIDADE), 1, f2) ){
			if ( cli.codigoCidade == cid.codigoCidade ){
				fprintf(s, "%d, %s, %s, %s\n", cli.codigoCliente, cli.nome, cid.nome, cid.estado);
			}
		}	
		rewind(f2);
	}
	
	fclose(f1);
	fclose(f2);
	fclose(s);
	
}

/*----------------------------------------------------------*/
