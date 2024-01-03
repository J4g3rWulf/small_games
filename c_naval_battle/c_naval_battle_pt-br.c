#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void check_ship(int *ship, int n, int *total_ships) {
	
	int i;
	
	for (i=0;i<n;i++) {
		if (ship[i] <= 0) {
			ship[i] = 9;
			*total_ships -= 1;
			printf("\nO navio de tamanho %d afundou!\n", i+2);
			sleep(2);
		}
	}
	
	if (*total_ships <= 0) {
		printf("\n\n\n--- Parabens, Voce Ganhou! ---\n");
		exit(0);
	}
}

void print_board(int (*board)[8]) {
	int i, j;
	
	printf(ANSI_COLOR_YELLOW "      1   2   3   4   5   6   7   8  \n\n" ANSI_COLOR_RESET);
	
	for (i=0;i<8;i++) {
		printf(ANSI_COLOR_YELLOW "%d   " ANSI_COLOR_RESET, i+1);
		printf("|");
		for (j=0;j<8;j++) {
			if(board[i][j] == 9) {
				printf(ANSI_COLOR_RED " X " ANSI_COLOR_RESET);
				printf("|");
			} else if (board[i][j] == 10) {
				printf(ANSI_COLOR_CYAN " A " ANSI_COLOR_RESET);
				printf("|");
			} else {
				printf(" ? |");
			}
		}
		printf("\n");
	}
}

void move (int x, int y, int (*board)[8], int *ship) {
	
	switch (board[x][y]) {
		case 2:
			printf("Acerto!\n");
			board[x][y] = 9;
			ship[0] -= 1;
			break;
		case 3:
			printf("Acerto!\n");
			board[x][y] = 9;
			ship[1] -= 1;
			break;
		case 4:
			printf("Acerto!\n");
			board[x][y] = 9;
			ship[2] -= 1;
			break;
		case 5:
			printf("Acerto!\n");
			board[x][y] = 9;
			ship[3] -= 1;
			break;
		case 9:
			printf("Voce ja atacou esse quadrante!\n");
			break;
		case 10:
			printf("Voce ja atacou esse quadrante!\n");
			break;
		default:
			printf("Agua!\n");
			board[x][y] = 10;
			break;
	}
	sleep(1);
}

void place_ship (int (*board)[8], int size, int s_code) {
	
	int i, sp, orient, flag = 0;
	 
	orient = rand() % 2;
	
	sp = rand() % (8-size);
	
		
	
	if (orient == 0) {
		for (i=0;i<size;i++) {
			if (board[sp][sp + i] == 0) {
				continue;
			} else {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			place_ship (board, size, s_code);
		} else {
			for (i=0;i<size;i++) {
				board[sp][sp + i] = s_code;
			}
		} 
	} else {
		for (i=0;i<size;i++) { 
			if (board[sp + i][sp] == 0) {
				continue;
			} else {
				flag = 1;
				break;
			}
		}
	
		if (flag == 1) {
			place_ship (board, size, s_code);
		} else {
			for (i=0;i<size;i++) {
				board[sp + i][sp] = s_code;
			}
		} 
	}
}

int main(void) {
	int i, j, x, y, d_modifier;
	
	srand(time(NULL));
	
	int (*board)[8] = malloc(sizeof(int [8][8]));
	
	for (i=0;i<8;i++) {
		for (j=0;j<8;j++) {
			board[i][j] = 0;
		}
	}
	
	do{
		
	printf("Qual dificuldade?\n2 -> Dificil (2 Navios)\n3 -> Medio (3 Navios)\n4 -> Facil (4 Navios)\n-> ");
	scanf("%d", &d_modifier);
	
	} while(d_modifier < 2 || d_modifier > 4);
	
	int *ship_hp = malloc(sizeof(int[d_modifier]));
	
	int total_ships = 0;
	
	for (i=0;i<d_modifier;i++) {
		place_ship(board, 2+i, 2+i);
		ship_hp[i] = 2+i;
		total_ships += 1;
	}
	
	system("cls");
	
	for (i=0;i<40;i++) {
		print_board(board);
		printf("\n\n--- Jogada ---\n\n");
		printf("Insira a primeira coordenada [1-8]: \n[Fileira] --> ");
		scanf("%d", &x);
		
		printf("Insira a segunda coordenada [1-8]: \n[Coluna] -->");
		scanf("%d", &y);
		
		if (x > 8 || y > 8) {
			printf("\nValor muito alto, insira de novo!\n");
			sleep(1);
		} else if (x < 1 || y < 1) {
			printf("\nValor muito baixo, insira de novo!\n");
			sleep(1);
		} else {
			move(x-1, y-1, board, ship_hp);
		}
		check_ship(ship_hp, d_modifier, &total_ships);
		system("cls");
	}
}
