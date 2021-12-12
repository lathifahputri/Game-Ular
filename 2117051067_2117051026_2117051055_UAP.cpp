//Kelas D Kelompok 1 : 
//1. Lathifah Putri A. (2117051026)
//2. Dwika Pangestuti (2117051055)
//3. Rafli Ashari J.  (2117051067)

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
using namespace std;

char map[10][20];
char player = '^';
char tail = '*';
char food ='*';
int yFood, xFood;
int y=5, x=5;
int yTail[10];
int xTail[10];
int p=20, l=10;
int nTail = 2;
int maxTail = 10;
int score = 0;

void generateMap();
void displayMap();
void moveUp();
void moveDown();
void moveRight();
void moveLeft();

int main(){
	score = 0;
	int i, n, npm;
	int username[3]={2117051026, 2117051055, 2117051067};
	time_t t;
	char move;
	srand((unsigned) time(&t));
	yFood = rand() % 8 + 1;
	xFood = rand() % 18 + 1;
	yTail[0] = y+1;
	xTail[0] = x;
	yTail[1] = y+2;
	xTail[1] = x;
	
	cout << "Masukkan Username : ";
	cin >> npm;
	
	if(npm == username[0] || npm == username[1] || npm == username[2]){
		do{
			system("cls");
			generateMap();
			displayMap();
			move = getch();
			
			switch(move){
				case 'w':
					player ='^';
					moveUp();
					break;
				case 's':
					player ='v';
					moveDown();
					break;
				case 'a':
					player ='<';
					moveLeft();
					break;
				case 'd':
					player ='>';
					moveRight();
					break;
			}
			if(y == yFood && x == xFood){
				map[y][x] = player;
				score++;
				if(nTail < 10){
					nTail++;
				}
				yFood = rand() % 8 + 1;
				xFood = rand() % 18 + 1;
			}
			for(i=9; i>=0; i--){
				yTail[i] = yTail[i-1];
				xTail[i] = xTail[i-1];
			}
		}while(score <= 10);
		
		cout << endl;
		printf("SELAMAT\n");
		printf("Skor Anda : %d",score-1);
		char jawab;
		cout << "Press y to play again or press n to exit" << endl;
		cin >> jawab;
		switch(jawab){
			case 'y' :
				system("cls");
				main();
				break;
			case 'n' :
				system("cls");
				exit(0);
				break;
		}
		
	}else{
		cout << "Username salah" << endl;
		Sleep(2000);
		system("cls");
		main();
	}
	
		return 0;
}

void generateMap(){
	int i,j;
	for(i=0; i<10; i++){
		for(j=0; j<20; j++){
			if(i == 0 || i==9){
				map[i][j] = '-';
			}else if (j == 0 || j == 19){
				map[i][j] = '|';
			}
			else{
				map[i][j] = ' ';
			}
		
		}
	}
	map[y][x] = player;
	map[yFood][xFood]= food;
	for(i=0; i<=nTail; i++){
		map[yTail[i]][xTail[i]] = tail;
	}
}

void displayMap(){
	int i,j;
	for(i=0; i<10; i++){
		for(j=0; j<20; j++){
			printf("%c", map [i][j]);
		}
		printf("\n");
	}
	printf("score : %d",score);
}

void moveUp(){
	if(y-1 > 0){
		yTail[0] = y; xTail[0] = x;
		y--;
	}else{
		system ("cls");
		cout << "GAME OVER" << endl;
//		cout << "Anda Kalah" << endl;
//		cout << "Permainan Berakhir" << endl;
		char jawab;
		cout << "Press y to play again or press n to exit" << endl;
		cin >> jawab;
		switch(jawab){
			case 'y' :
				system("cls");
				main();
				break;
			case 'n' :
				system("cls");
				exit(0);
				break;
		}
	}
}
void moveDown(){
	if(y+1 < l-1){
		yTail[0] = y; xTail[0] = x;
		y++;
	}else{
		system ("cls");
		cout << "GAME OVER" << endl;
//		cout << "Anda Kalah" << endl;
//		cout << "Permainan Berakhir" << endl;
		char jawab;
		cout << "Press y to play again or press n to exit" << endl;
		cin >> jawab;
		switch(jawab){
			case 'y' :
				system("cls");
				main();
				break;
			case 'n' :
				system("cls");
				exit(0);
				break;
		}
	}
}
void moveLeft(){
	if(x-1 > 0){
		yTail[0] = y; xTail[0] = x;
		x--;
	}else{
		system ("cls");
		cout << "GAME OVER" << endl;
//		cout << "Anda Kalah" << endl;
//		cout << "Permainan Berakhir" << endl;
		char jawab;
		cout << "Press y to play again or press n to exit" << endl;
		cin >> jawab;
		switch(jawab){
			case 'y' :
				system("cls");
				main();
				break;
			case 'n' :
				system("cls");
				exit(0);
				break;
		}
	}
}
void moveRight(){
	if(x+1 < p-1){
		yTail[0] = y; xTail[0] = x;
		x++;
	}else{
		system ("cls");
		cout << "GAME OVER" << endl;
//		cout << "Anda Kalah" << endl;
//		cout << "Permainan Berakhir" << endl;
		char jawab;
		cout << "Press y to play again or press n to exit" << endl;
		cin >> jawab;
		switch(jawab){
			case 'y' :
				system("cls");
				main();
				break;
			case 'n' :
				system("cls");
				exit(0);
				break;
		}
	}
}
