#include <stdio.h>

/*----------------------------------------------------------*/
int main(){
	char funcionarios[] = "funcionarios.dat", atualizado[] = "atualizado.dat";
	
	FILE *f = fopen(funcionarios, "rb");
	if ( f == NULL ){
		printf("Erro ao abrir o arquivo %s\n", funcionarios);
		return 0;
	}
	
	FILE *s = fopen(atualizado, "wb");
	if ( s == NULL ){
		printf("Erro ao abrir o arquivo %s\n", atualizado);
		return 0;
	}
	
	unsigned int dados, cod, horas, atraso;
	
	while ( fread(&dados, sizeof(unsigned int), 1, f) ){
		cod = ( dados >> 15 ) & 0x7f;
		horas = (dados >> 6 ) & 0x1ff;
		atraso = (dados >> 1) & 0x1f;
		if ( horas >= 150 && atraso < 5){
			dados += 1;
		}
		fwrite(&dados, sizeof(unsigned int), 1, s);
	}
	
	fclose(f);
	fclose(s);
	
}

/*----------------------------------------------------------*/
