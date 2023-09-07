#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int idade = -1;
	int totalM = 0;
	int quantidadeMXP = 0;
	int acumuladorIdadeMXP = 0;
	int totalF = 0;
	int totalF35XP = 0;
	int menorIdadeFXP = 999;
	float mediaMXP;
	int M45 = 0;
	float porcentagemM45;


	char sexo;
	char xp;

	while (idade != 0) {
		printf("\n IDADE: ");
		scanf("%d", &idade);

		printf("\n SEXO   [M]   [F]   ");
		scanf(" %c", &sexo);
		fflush(stdin);
		sexo = toupper(sexo);

		printf("\n EXPERIENCIA  [S]   [N]   ");
		scanf(" %c", &xp);
		fflush(stdin);
		xp = toupper(xp);

		if (sexo == 'F') { totalF++; }

		if (sexo == 'M') { totalM++; }

		if (sexo == 'M' && xp == 'S') { quantidadeMXP++; acumuladorIdadeMXP += idade; }

		if (sexo == 'M' && idade > 45) { M45++; }

		if (sexo == 'F' && idade < 35 && xp == 'S') { totalF35XP++; }

		if (sexo == 'F' && xp == 'S' && idade < menorIdadeFXP) { menorIdadeFXP = idade; }

		mediaMXP = acumuladorIdadeMXP / quantidadeMXP;

		porcentagemM45 = M45 / totalM;
	}

	printf("\n TOTAL SEXO FEMININO: %d", totalF);
	printf("\n TOTAL SEXO MASCULINO: %d", totalM);
	printf("\n MEDIA IDADE HOMENS COM EXPERIENCIA: %.1f", mediaMXP);
	printf("\n PORCENTAGEM HOMENS COM +45 ENTRE O TOTAL DE HOMENS: %% %.2f", porcentagemM45);
	printf("\n TOTAL MULHERES COM -35 E COM EXPERIENCIA: %d", totalF35XP);
	printf("\n MENOR IDADE MULHERES COM EXPERIENCIA: %d", menorIdadeFXP);

	return 0;
}
