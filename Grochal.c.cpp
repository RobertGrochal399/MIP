#include <iostream>
#include <stdio.h>
#pragma warning(disable: 4996)

int nacitanie(char *p) {
	FILE* fr;
	int pocitadlo = 0;
	char c;
	fr = fopen("sifra.txt", "r");
	if ((fr = fopen("sifra.txt", "r")) == NULL)
	{
		printf("Spravu sa nepodarilo nacitat");
	}
	else
	{
		while ((c = getc(fr)) != EOF) {
			p[pocitadlo] = c;
			pocitadlo = pocitadlo + 1;
		}
	}
	if (fclose(fr) == EOF)
	{
		printf("Subor sa nepodarilo zatvorit");
	}
	else
	{
		fclose(fr);
	}

	return pocitadlo;
}


int vypis(char* p, int Pocet) {
	if (Pocet == 0)
	{
		printf("Sprava nie je nacitana");
	}
	else
	{
		for (int i = 0; i < Pocet; i++)
		{
			printf("%c", p[i]);
		}
	}
	printf("\n");
	return 0;
}



int uprava(char* pP, char* pU, int Pocet) {
	int pocitadlo = 0;
	if (Pocet == 0)
	{
		printf("Sprava nie je nacitana");
	}
	else
	{
		for (int i = 0; i < Pocet; i++) {
			if (pP[i] >= 'A' && pP[i] <= 'Z' || pP[i] >= 'a' && pP[i] <= 'z')
			{
				pU[pocitadlo] = toupper(pP[i]);
				pocitadlo = pocitadlo + 1;
			}
		}
	}
	return pocitadlo;
}



int VypisUpravena(char* p, int Pocet) {
	if (Pocet == 0)
	{
		printf("Sprava nie je upravena");
	}
	else
	{
		for (int i = 0; i < Pocet; i++)
		{
			printf("%c", p[i]);
		}
	}
	printf("\n");
	return 0;
}


int slova(char* p, int Pocet) {
	int pocitadlo = 0, k = 0;
	scanf_s("%d", &k);
	if (Pocet == 0)
	{
		printf("Sprava nie je nacitana");
	}
	else
	{
		for (int i = 0; i < Pocet; i++) {
			if ((p[i] == ' ' || p[i] == '\n') && (p[i + k + 1] == ' ' || p[i + k + 1] == '\n'))
			{
				for (int l = 0; l < k; l++) {
					printf("%c", p[i + l + 1]);
				}
				printf("\n");
			}
		}
	}
	return 0;
	}

int sifra(char* p, int Pocet) {
	char c;
	int kluc = 0;
	scanf_s("%d", &kluc);
	if (Pocet == 0)
	{
		printf("Nie je k dispozicii upravena sprava");
	}
	else
	{
		for (int i = 0; i < Pocet; i++)
		{
			c = p[i];
			if (c >= 'A' && c <= 'Z')
			{
				c = c - kluc;
			}
			if (c < 'A')
			{
				c = c + 'Z' - 'A' + 1;
			}
			printf("%c", c);
		}
	}
	printf("\n");
	return 0;
}


int histogram(char* p, int Pocet) {
	int c = 0;
	int max = 0;
	int pismena[26] = { 0 };
	float cast[26] = { 0 };
	int znak[26] = { 0 };
	int stlpec[26] = { 0 };

	if (Pocet == 0) {
		printf("Nie je k dispozicii upravena sprava\n");
	}
	else {

		for (int i = 0; i < Pocet; i++) {
			c = p[i];
			pismena[c - 65] = pismena[c - 65]++;
		}

		for (int j = 0; j < 26; j++) {
			if (pismena[j] != 0) {
				cast[j] = ((100 * pismena[j]) / Pocet);
			}
		}

		for (int k = 0; k < 26; k++) {
			if ((0 < cast[k]) && (cast[k] <= 10)) {
				znak[k] = 1;
			}

			if ((10 < cast[k]) && (cast[k] <= 20)) {
				znak[k] = 2;
			}

			if ((20 < cast[k]) && (cast[k] <= 30)) {
				znak[k] = 3;
			}

			if ((30 < cast[k]) && (cast[k] <= 40)) {
				znak[k] = 4;
			}
			if ((40 < cast[k]) && (cast[k] <= 50)) {
				znak[k] = 5;
			}

			if ((50 < cast[k]) && (cast[k] <= 60)) {
				znak[k] = 6;
			}

			if ((60 < cast[k]) && (cast[k] <= 70)) {
				znak[k] = 7;
			}

			if ((70 < cast[k]) && (cast[k] <= 80)) {
				znak[k] = 8;
			}
			if ((80 < cast[k]) && (cast[k] <= 90)) {
				znak[k] = 9;
			}

			if ((90 < cast[k]) && (cast[k] <= 100)) {
				znak[k] = 10;
			}
		}

		for (int l = 0; l < 26; l++) {
			if (l == 0) {
				max = znak[l];
			}
			else {
				if (znak[l] > max) {
					max = znak[l];
				}
			}
		}


		for (int m = 0; m < max; m++) {
			for (int a = 0; a < 26; a++) {
				if (znak[a] == max - m) {
					stlpec[a] = 1;
				}

				if (stlpec[a] == 1) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}

			printf("\n");
		}



		for (int n = 0; n < 26; n++) {
			printf("%c", 'A' + n);
		}

		printf("\n");

	}
	return 0;
}

int vypis2(char *p, int pocet){
  int z = 0, k = 0;
  if(pocet == 0){
    printf("Sprava nieje nacitana");
  }
  else{
    scanf("%d %d\n", &z, &k);
    for(int i = z; i<=k; i++){
      if((p[i] >= 'A' && p[i] <= 'Z')||(p[i] >= 'a' && p[i]<= 'z')){
        printf("%c", p[i]);
      }
      else{
        printf("+");
      }
    }
  }
  printf("\n");
  return 0;
}

int vlozenie(char *p, int pocet){
  char r[10];
  int pocitadlo = 0;
  if(pocet == 0){
	  printf("Nie je k dispozicii upravena sprava");
  }
  else{
  while(r[pocitadlo] != '\n'){
    scanf("%c", &r[pocitadlo]);
    if(r[pocitadlo] >='A' && r[pocitadlo] <= 'Z'){
      pocitadlo++;
    }
    else{
      printf("Retazec nieje mozne vlozit");
      break;
    }
  }
    if((pocitadlo > 10) && (pocet % 2 != 0) && (pocet + pocitadlo > 1000)){
      printf("Retazec nieje mozne vlozit");
    }
    else{
      for(int i = 0; i< pocitadlo; i++){
        p[pocet % 2 +i]= r[i];
      }
	  printf("Retazec sa vlozil");
    }
  }
  return 0;
}


int main(){
	char Test, PovodnyText[1000] = { 0 }, UpravenyText[1000] = { 0 };
	int PocetZnakov = 0, PocetZnakovUpravena = 0;
	scanf_s("%c", &Test);
	while (Test != 'k')
	{
		switch (Test)
		{
		case 'n': PocetZnakov = nacitanie(PovodnyText); break;
		case 'v': vypis(PovodnyText, PocetZnakov); break;
		case 'u': PocetZnakovUpravena = uprava(PovodnyText, UpravenyText, PocetZnakov); break;
		case 's': VypisUpravena(UpravenyText, PocetZnakovUpravena); break;
		case 'd': slova(PovodnyText, PocetZnakov); break;
		case 'h': histogram(UpravenyText, PocetZnakovUpravena); break;
		case 'c': sifra(UpravenyText, PocetZnakovUpravena); break;
		}
		scanf_s("%c", &Test);
	}

}





