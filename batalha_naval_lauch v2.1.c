#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void check_ship(int *ship, int n, int *total_ships) {
	
	int i;
	
	for (i=0;i<n;i++) {
		if (ship[i] <= 0) {
			ship[i] = 9;
			*total_ships -= 1;
			printf("\nO navio de tamanho %d afundou!\n", i+2);
		}
	}
	
	if (*total_ships <= 0) {
		printf("\n\n\n--- Parabens! Voce Ganhou! ---\n");
		exit(0);
	}
}

void print_board(int (*board)[7]) {
	int i, j;
	
	printf("\n");
	
	for (i=0;i<7;i++) {
		printf("|");
		for (j=0;j<7;j++) {
			if(board[i][j] == 9) {
				printf(" X |");
			} else if (board[i][j] == 10) {
				printf(" A |");
			} else {
				printf(" ? |");
			}
		}
		printf("\n");
	}
}

void move (int x, int y, int (*board)[7], int *ship) {
	
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
}

void place_ship (int (*board)[7], int size, int s_code) {
	
	int i, sp, orient, flag = 0;
	 
	orient = rand() % 2;
	
	sp = rand() % (7-size);
	
		
	
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
	
	int (*board)[7] = malloc(sizeof(int [7][7]));
	
	for (i=0;i<7;i++) {
		for (j=0;j<7;j++) {
			board[i][j] = 0;
		}
	}
	
	printf("Qual dificuldade?\nFacil (2) | Medio (3) | Dificil (4)\n-> ");
	scanf("%d", &d_modifier);
	
	int *ship_hp = malloc(sizeof(int[d_modifier]));
	
	int total_ships = 0;
	
	for (i=0;i<d_modifier;i++) {
		place_ship(board, 2+i, 2+i);
		ship_hp[i] = 2+i;
		total_ships += 1;
	}
	
	print_board(board);
	
	for (i=0;i<12;i++) {
		printf("\n\n--- Jogada ---\n\n");
		printf("Insira a primeira coordenada [0-6]: \n");
		scanf("%d", &x);
		
		printf("Insira a segunda coordenada [0-6]: \n");
		scanf("%d", &y);
		
		if (x > 6 || y > 6) {
			printf("\nValor muito alto, insira de novo!\n");
		} else {
			move(x, y, board, ship_hp);
			check_ship(ship_hp, d_modifier, &total_ships);
		}
		print_board(board);
	}
}
