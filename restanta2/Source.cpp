#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

//#define _SCL_SECURE_NO_WARNINGS

void problema1(char *filename, int n, int n1)
{
	FILE *f;
	f = fopen(filename, "r");
	char buffer[1000];
	char *p, *m[100][100];
	int i = 0, j, v[100], nrl = 0, k = 0;

	while (!feof(f))
	{
		j = 0;
		fgets(buffer, 1000, f);
		nrl++;
		p = strtok(buffer, " ");
		while (p)
		{
			 m[i][j] = (char*)malloc(strlen(p));
			 strcpy(m[i][j], p);
			 j++;
			 p = strtok(NULL, " ");
		}
	
		
		v[i] = j;
		i++;
	}

	for (i = 0;i < nrl;i++)
	{

		for (j = 0;j < n;j++)
		{
			printf("%s ", m[i][j]);
		}
			for(k = v[i] - n1 ; k < v[i]; k++)
		{
			printf("%s ", m[i][k]);
		}
		printf("\n");
	}
	fclose(f);

}

void problema2(char *filename)
{
	FILE *f = fopen(filename, "r");
	char *p, *v[1000], buffer[250];
	int i = 0, n;
	while (!feof(f))
	{
		fgets(buffer, 250, f);
		p = strtok(buffer, " \n");
		while (p)
		{
			v[i] = (char*)malloc(strlen(p));
			strcpy(v[i], p);
			i++;
			p = strtok(NULL, " \n");
		}
		//i++;
	}
	n = i;
	//printf("%d\n", n);
	int ok = 0;
	for (i = 0; i < n; i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (strcmp(v[i], v[j]) == 0)
			{
				ok++;
			}
			
		}
		if (ok == 1)
		{
			printf("%s ", v[i]);
		}
		ok = 0;
		//printf("\n");
	}

	fclose(f);
}

bool palindrom(char *s)
{
	char s1[100];
	strcpy(s1, s);
	strrev(s1);
	if (strcmp(s1,s) == 0)
		return true;
	return false;
}

int palindrom2(char *s)
{
	int i;

	for (i = 0;i < strlen(s) / 2;i++)
	{
		if (s[i] != s[strlen(s) - i - 1]) return 0;
		return 1;
	}
}

void problema3(char *filename)
{
	FILE *f, *f1;
	f = fopen(filename, "r");
	f1 = fopen("out.txt", "w");
	char buffer[1000];
	char *p, *m[100][100];
	int i = 0, j, v[100], nrl = 0, k = 0;

	while (!feof(f))
	{
		j = 0;
		fgets(buffer, 1000, f);
		nrl++;
		p = strtok(buffer, " ");
		while (p)
		{
			m[i][j] = (char*)malloc(strlen(p));
			strcpy(m[i][j], p);
			j++;
			p = strtok(NULL, " ");
		}


		v[i] = j;
		i++;
	}

	for (i = 0;i < nrl;i++)
	{
		for (j = 0;j < v[i];j++)
		{
			if (palindrom2(m[i][j]) == 1)
				fprintf(f1, "%s", m[i][j]);
		}
		printf("\n");
	}



	fclose(f);
	fclose(f1);
}

void problema4(char *filename)
{

}

void main(int argc, char *argv[])
{
	int n, n1;
	n = atoi(argv[2]);
	n1 = atoi(argv[3]);
	//problema1(argv[1], n, n1);
	//problema2(argv[1]);
	//problema3(argv[1]);
}