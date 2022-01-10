/* A-TEAM SOS PROJECT

Author: Gian Sandrova (NIM)
		Raka Mahardika Maulana (NIM)
		Syifa Khairina (211524063) 
		
Kelas 1B D4 TEKNIK INFORMATIKA, POLITEKNIK NEGERI BANDUNG

Program ini dibuat untuk memenuhi Tugas Besar Mata Kuliah Dasar-Dasar Pemrograman

*/

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>

#define BLACK           0
#define DARK_BLUE       1
#define GREEN           2
#define TURQUOISE       3
#define DARK_RED        4
#define PURPLE          5
#define FOREST_GREEN    6
#define LIGHT_GRAY      7
#define GRAY            8
#define BLUE            9
#define LIGHT_GREEN    10
#define LIGHT_BLUE     11
#define RED            12
#define PINK           13
#define YELLOW         14
#define WHITE          15
#define STDALERT      140
#define STDHEADER     143
#define STDBACKGROUND 159


void gotoxy(int x, int y);
 

// Variabel global
 int dimensi, sCol, sRow, sos[10][10]; // variabel kolom, baris, juga array 2 dimensi dengan dimensi=dimensi
 char huruf; // var global untuk huruf S dan O
 int got=0;
 int comp=0;
 int scores[3] = { 0,0 }; // save players scores
 int counter = 1; // round counter
 int currentPlayer = 0; // save current player, can be 0 or 1
 char namaPlayer[2][20]; // save player nicks


// modul yang digunakan dalam permainan

void gotoxy(int x, int y); // modul ini digunakan untuk membantu peletakan karakter maupun tempat input
void warnateks(int warna); // modul untuk memberi warna ke karakter
void kecepatan(float seconds); // digunakan untuk menentukan waktu berjalannya suatu perintah dalam program 
void screenawal(); // menampilkan nama kelompok sebagai pembuka program
void loading(); // menampilkan gambar loading sebagai pembuka program
void TampilLoading(); //menampilkan screen loading
void TampilAwal(); //menampilkan judul game "SOS"
void Menu(); //menampilkan pilihan menu
void TampilMenu(); // menampilkan screen menu
void HowToPlay(); // untuk menampilkan instruksi permainan
void gameCredits(); // untuk menampilkan kredit
void TampilModePermainan(); // untuk menampilkan screen pilih mode permainan
void TampilInputNamaPlayer1(); // untuk menampilkan screen input nama pemain di mode Player VS Player
void TampilInputNamaPlayer2(); // untuk menampilkan screen input nama pemain di mode Player VS Computer 
void InputNamaPlayer1(); // modul untuk input nama pemain di mode Player VS Player 
void InputNamaPlayer2(); // modul untuk input nama pemain di mode Player VS Computer level noob
void TampilLevelPermainan(); // untuk memampilkan screen pilih level permainan, Noob dan Pro
void drawScoreboard(); // menampilkan scoreboard yang berisi nama dan skor player
void drawGameboard(); // menggambar papan permainan
int takeInput(); // mengambil input dari player (return 1 if did valid input, otherwise 0)
int controlSOS(); // mengecek susunan huruf "SOS" di papan (return 1 if scored, otherwise 0)
void gamePlayPVP(); // modul yang berisi alur permainan Player VS Player
void TampilInputBot(int a, int b, char c); //,modul untuk menampilkan input yang dipilih oleh bot
void RandomSOS(); // modul yang berisi kecerdasan bot computer level noob
int CekKotak(); // untuk  mengecek kekosongan kotak (return 1 jika kotak kosong, sebaliknya 0)
void screenPemenangComp(); // untuk menampilkan screen pemenang jika computer menang
void screenDraw(); // untuk menampilkan screen jika skor seri
void screenPemenangPlayer(); // untuk menampilkan screen pemenang jika player menang
void pemenangGamePVP(); //untuk mengecek pemenang permainan di mode Player VS Player
void pemenangGamePVC(); //untuk mengecek pemenang permainan di mode Player VS Computer level noob
void ResetBoard(); // modul untuk mengembalikan board ke keadaan awal (kosong)
void gamePlayPVC();// modul yang berisi alur permainan Player VS Computer level noob

// modul bot level pro
int compFindOS(); //modul kecerdasan bot untuk mencari susunan OS di board
int compFindSS(); // modul kecerdasan bot untuk mencari susunan SS di board
void compMovePro(); //modul yang berisi pergerakan bot level pro
void drawgameboardPro(); // modul papan pada gameboard pro pada mode Player VS Computer 
int FindKotakKosong(); // modul agar computer dapat menemukan kotak kosong untuk peletakan S/O secara Random
void gamePlayPVCPro(); // modul yang berisi alur permainan Player VS Computer level pro
void pemenangGamePVCPro(); // mengecek pemenang di permainan Player VS Computer level pro
int takeInputVScom(); // untuk menginput huruf 'S' dan 'O' dalam permainan Player VS Computer level pro
int controlSOSPro(int kotak, int player, char huruf); // modul untuk mengecek susunan 'SOS' dalam permainan Player VS Computer level pro
int CekKotakKosong(int kotak); // modul untuk mengetahui apakah masih ada kotak yang kosong



void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

  
void warnateks(int warna) //modul yang berfungsi untuk memberi warna ke karakter
{ 
	HANDLE hConsole; 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, warna);
}

void kecepatan(float seconds){
	clock_t endwait;
	endwait=clock()+seconds*CLOCKS_PER_SEC;
	while(clock()<endwait){};
}
void screenawal(){
system("cls");
warnateks(FOREST_GREEN);
printf("\n\n\n");
printf("\t\t         лл                 ллллллллллллл лллллллллл        лл        лллл       лллл \n  ");
printf("\t\t        л  л                      л       л                л  л       лл  лл   лл  лл \n  ");
printf("\t\t       л    л                     л       л               л    л      лл   лл лл   лл \n  ");
printf("\t\t      л      л      ллллллллл     л       лллллллллл     л      л     лл    л л    лл \n  ");
printf("\t\t     л лллллл л                   л       л             л лллллл л    лл     л     лл \n  ");
printf("\t\t    л          л                  л       л            л          л   лл           лл \n  ");
printf("\t\t   л            л                 л       лллллллллл  л            л  лл           лл \n ");
}

void loading(){ 
	int x = 42, y = 15 , n;
	warnateks(WHITE);
	gotoxy(x,15); printf("         SABAR NGABBB PROSES");
	gotoxy(x,16);  printf("     ЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
	gotoxy(x,17);printf("     К                        К");
	gotoxy(x,18);printf("     ШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");
	for(n=48;n<=70;n++){
		gotoxy(n,17);printf("л");
		kecepatan(0.1);
	};
}
void TampilLoading(){
	screenawal();
	loading();
}

void TampilAwal(){
    printf("\n\n\n");
    printf("\t\t\t\t\t ллллллл         ллллл         ллллллл\n");
    printf("\t\t\t\t\tлл             лл     лл      лл     \n");
    printf("\t\t\t\t\tлл             лл     лл      лл\n");
    printf("\t\t\t\t\t ллллллл       лл     лл       ллллллл\n");
    printf("\t\t\t\t\t       лл      лл     лл             лл\n");
    printf("\t\t\t\t\t       лл      лл     лл             лл\n");
    printf("\t\t\t\t\t ллллллл         ллллл         ллллллл\n");
    printf("\n\n");
    printf("\t\t\t\t\t          A-Team's Project \n");
}
void Menu(){
	printf("\n\n\t\t\t\t\tЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭ\n");
	printf("\t\t\t\t\t             MENU GAME    \n");
	printf("\t\t\t\t\t                       \n");
	printf("\t\t\t\t\t           1.Play The Game       \n");
	printf("\t\t\t\t\t           2.How To Play     \n");
	printf("\t\t\t\t\t           3.Game credits      \n");
	printf("\t\t\t\t\t           4.exit       \n");
	printf("\t\t\t\t\t                   \n");
	printf("\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t          CHOOSE THE MENU :  \n");
	printf("\t\t\t\t\tЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭ\n");
}
void TampilMenu(){
	system("cls");
	system ("color 0E");
	CONSOLE_SCREEN_BUFFER_INFOEX info={0};
	int width,height, input;
	HANDLE hConsole=NULL;
	TampilAwal();
	Menu();

}


void HowToPlay(){
	system("cls");
	int input;
	printf("\n________________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t\t       HOW TO PLAY\n");     
	printf("\n________________________________________________________________________________________________________________________\n\n");
	
	FILE *how_to_play = NULL;
	int nomor = 0;
	char isiHowToPlay[250];
	
	how_to_play = fopen("HowToPlay.txt", "r");
	if(how_to_play == NULL){
		printf("File Doesn't Exist");
	}else {
		while(fscanf(how_to_play,"%[^\n]%*c", isiHowToPlay) == 1){
			nomor++;
			printf("\n%d. %s\n", nomor, isiHowToPlay);
		}
	}
	fclose(how_to_play);
	printf("\n\n________________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t    Input 0 for back to Main menu..."); scanf("%d", &input);
		if(input == 0){                                                                 
	printf("\n\n________________________________________________________________________________________________________________________\n");
		TampilMenu();
	}else {
		HowToPlay();
	}
	system ("pause");
}

void gameCredits() {
	system("cls");
	int input;
	printf("\n________________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t\t       GAME CREDITS\n");
	FILE*game_credits = NULL;     
	printf("\n________________________________________________________________________________________________________________________\n\n");
	char a[500];
	
	game_credits=fopen("gamecredits.txt","r");
	if(game_credits == NULL){
	
		printf("data tidak ada");
	}else {
		while(fscanf(game_credits, "%[^\n]%*c", a) == 1){
			printf("%s\n", a);
		}		
	}
	fclose(game_credits);
	printf("\n\n________________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t    Input 0 for back to Main menu : "); scanf("%d", &input);
	if(input == 0){                                                                 
	printf("\n\n________________________________________________________________________________________________________________________\n");
		TampilMenu();
	}else {
		gameCredits();
	}
}

void TampilModePermainan(){
	system("cls");
	int input3;
	printf("\n________________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t\t        GAME MODE\n");
	printf("\n________________________________________________________________________________________________________________________\n\n");
	printf("\n\t\t\t\t1. Player1 vs Player2                 2. Player1 vs Computer \n");
	printf("\n\n________________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t       Choose the game mode : ");                                                              
	printf("\n\n________________________________________________________________________________________________________________________\n");
	
} 


void TampilInputNamaPlayer1(){
	system("cls");
	printf("\n________________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t           Input Player's Name'\n");
	printf("\n________________________________________________________________________________________________________________________\n\n");
	printf("\n						Player1:");
	printf("\n\n						Player2:");
	printf("\n\n________________________________________________________________________________________________________________________\n");
	
}

void InputNamaPlayer1(char *namaPlayer1, char *namaPlayer2){
    gotoxy(57,8); scanf("%s", &(namaPlayer[0][0]));
	gotoxy(57,10); scanf("%s", &(namaPlayer[1][0]));
}

void TampilInputNamaPlayer2(){
	system("cls");
	printf("\n________________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t\t     Input Player's Name\n");
	printf("\n________________________________________________________________________________________________________________________\n\n");
	printf("\n\t\t			Player1:");
	printf("\n\n________________________________________________________________________________________________________________________\n");
	
}

void InputNamaPlayer2(char *namaPlayer1, char *namaPlayer2){
	gotoxy(49,8); 
	scanf("%s", &(namaPlayer[0][0]));
	strcpy(namaPlayer[1], "Computer"); // inisialisasi nama untuk bot Computer	
	printf("%s", namaPlayer[1]);
}

void TampilLevelPermainan(){
	system("cls");
	int input4;
	printf("\n________________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t\t       GAME LEVEL\n");
	printf("\n________________________________________________________________________________________________________________________\n\n");
	printf("\n\t\t\t\t      1. NOOB                \t\t 2. PRO   \n");
	printf("\n\n________________________________________________________________________________________________________________________\n");
	printf("\n\t\t\t\t\t   Choose the game level...\n\n\n");                                                           
	printf("\n\n________________________________________________________________________________________________________________________\n");
	
	
} 

void drawScoreboard() {
	printf("%s %d : %d %s\n\n", namaPlayer[0], scores[0], scores[1], namaPlayer[1]);
	
}

void drawScoreboardPVC(){
	char com[10]= ("computer");
	printf("%s %d : %d %s\n\n", namaPlayer[0], scores[0], scores[2], com);
}



void drawGameboard() {
	int i, j;
	printf("\n\n\n");
	// top line
	for (i = 1; i < (dimensi + 2) * 6 + 2; i++) {
		printf("\xdb");
	}
	printf("\n\xdb\xdb ");
	for (i = 0; i <= dimensi; i++) {
		if (!i) printf("\xda\xc4\xc4\xc4\xc4\xc4\xc2");
		else if (i == dimensi) printf("\xc4\xc4\xc4\xc4\xc4\xbf");
		else printf("\xc4\xc4\xc4\xc4\xc4\xc2");
	}
	 // gameboard
	printf(" \xdb\xdb");
	for (i = 0; i <= dimensi; i++) {
		printf("\n\xdb\xdb ");
		for (j = 0; j <= dimensi; j++) {
		if (!i && !j) printf("\xb3     ");
		else if (!i && j == dimensi) printf("\xb3 %2d  \xb3 ", j);
		else if (!i) printf("\xb3 %2d  ", j);
		else if (!j) printf("\xb3 %2d  \xb3 ", i);
		else if (sRow && sCol && sRow == i && sCol == j) printf("\xdb\xdb  \xb3 ");
		else if (sos[i - 1][j - 1] == 'S' || sos[i - 1][j - 1] == 'O') printf(" %c  \xb3 ", sos[i - 1][j - 1]);
		else printf("  %c  \xb3 ", sos[i - 1][j - 1]);
		}
		printf("\xdb\xdb\n\xdb\xdb ");
		for (j = 0; j <= dimensi; j++) {
		if (i == dimensi && !j) printf("\xc0\xc4\xc4\xc4\xc4\xc4");
		else if (i == dimensi) printf("\xc1\xc4\xc4\xc4\xc4\xc4");
		else if (!j) printf("\xc3\xc4\xc4\xc4\xc4\xc4");
		else printf("\xc5\xc4\xc4\xc4\xc4\xc4");
		if (i == dimensi && j == dimensi) printf("\xd9");
		else if (j == dimensi) printf("\xb4");
		}
		printf(" \xdb\xdb");
	}
	 // bottom line
	printf("\n");
	for (i = 1; i < (dimensi + 2) * 6 + 2; i++) {
		printf("\xdb");
	}
}

void drawgameboardPro() {
	int i, j;
	printf("\n\n\n");
	// top line
	for (i = 1; i < (dimensi + 2) * 6 + 2; i++) {
		printf("\xdb");
	}
	printf("\n\xdb\xdb ");
	for (i = 0; i <= dimensi; i++) {
		if (!i) printf("\xda\xc4\xc4\xc4\xc4\xc4\xc2");
		else if (i == dimensi) printf("\xc4\xc4\xc4\xc4\xc4\xbf");
		else printf("\xc4\xc4\xc4\xc4\xc4\xc2");
	}
	 // gameboard
	printf(" \xdb\xdb");
	for (i = 0; i <= dimensi; i++) {
		printf("\n\xdb\xdb ");
		for (j = 0; j <= dimensi; j++) {
		if (!i && !j) printf("\xb3     ");
		else if (!i && j == dimensi) printf("\xb3 %2d  \xb3 ", j);
		else if (!i) printf("\xb3 %2d  ", j);
		else if (!j) printf("\xb3 %2d  \xb3 ", i);
		else if (sRow && sCol && sRow == i && sCol == j) printf("\xdb\xdb  \xb3 ");
		else if (sos[i - 1][j - 1] == 'S' || sos[i - 1][j - 1] == 'O') printf(" %c  \xb3 ", sos[i - 1][j - 1]);
		else printf("  %c \xb3 ", sos[i - 1][j - 1]);
		}
		printf("\xdb\xdb\n\xdb\xdb ");
		for (j = 0; j <= dimensi; j++) {
		if (i == dimensi && !j) printf("\xc0\xc4\xc4\xc4\xc4\xc4");
		else if (i == dimensi) printf("\xc1\xc4\xc4\xc4\xc4\xc4");
		else if (!j) printf("\xc3\xc4\xc4\xc4\xc4\xc4");
		else printf("\xc5\xc4\xc4\xc4\xc4\xc4");
		if (i == dimensi && j == dimensi) printf("\xd9");
		else if (j == dimensi) printf("\xb4");
		}
		printf(" \xdb\xdb");
	}
	 // bottom line
	printf("\n");
	for (i = 1; i < (dimensi + 2) * 6 + 2; i++) {
		printf("\xdb");
	}
}


int takeInput() {
	do {
	fflush(stdin);
	printf("\n\n\xaf Player turn: %s\n", namaPlayer[currentPlayer]);
	printf("\xaf Row: ");
	scanf("%d", &sRow);
	printf("\xaf Column: ");
	scanf("%d", &sCol);
	}while(!(sRow > 0 && sRow <= dimensi && sCol > 0 && sCol <= dimensi));
	
	if (!(sRow > 0 && sRow <= dimensi && sCol > 0 && sCol <= dimensi)) {
		printf("\xaf\xaf Invalid position!!\n\xaf\xaf Press any key to continue!!");
		getch();
		return 0;
	}
	switch (sos[sRow - 1][sCol - 1]) {

	case 'S':
	case 'O':  
	 printf("\xaf\xaf Invalid position!!\n\xaf\xaf Press any key to continue!!");
	 getch();
    
		return 0;

	default:   
	 system("cls");
		drawScoreboard();
		drawGameboard();
		printf("\n\n\xaf Player turn: %s\n\xaf Row: %d\n\xaf Column: %d\n\xaf\xaf S/O? ", namaPlayer[currentPlayer], sRow, sCol);
		char ch;
		scanf(" %c", &ch);
		switch (ch) {
		case 's':
		case 'S': sos[sRow - 1][sCol - 1] = 'S'; return 1;
		case 'o':
		case 'O': sos[sRow - 1][sCol - 1] = 'O'; return 1;
		}

		printf("\xaf\xaf Invalid letter!!\n\xaf\xaf Press any key to continue!!");
		getch();
		return 0;
	}
}

int controlSOS() {
	if (sos[sRow - 1][sCol - 1] == 'S') { // ngecek dari huruf s
		if (sos[sRow - 3][sCol - 3] == 'S' && sos[sRow - 2][sCol - 2] == 'O') return 1; // ngecek horizontal 
		if (sos[sRow - 3][sCol - 1] == 'S' && sos[sRow - 2][sCol - 1] == 'O') return 1; // ngecek vertikal keatas 
		if (sos[sRow - 3][sCol + 1] == 'S' && sos[sRow - 2][sCol] == 'O') return 1; // ngecek diagonal 
		if (sos[sRow - 1][sCol - 3] == 'S' && sos[sRow - 1][sCol - 2] == 'O') return 1; //ngecek horizontal
		if (sos[sRow - 1][sCol + 1] == 'S' && sos[sRow - 1][sCol] == 'O') return 1; //ngecek vertikal
		if (sos[sRow + 1][sCol - 3] == 'S' && sos[sRow][sCol - 2] == 'O') return 1; // ngecek diagonal
		if (sos[sRow + 1][sCol - 1] == 'S' && sos[sRow][sCol - 1] == 'O') return 1; // ngecek vertikal
		if (sos[sRow + 1][sCol + 1] == 'S' && sos[sRow][sCol] == 'O') return 1; // ngecek diagonal kanan bawah 
	}
	else {
		if (sos[sRow - 2][sCol - 2] == 'S' && sos[sRow][sCol] == 'S') return 1; // ngecek diagonal dari huruf O
		if (sos[sRow - 2][sCol - 1] == 'S' && sos[sRow][sCol - 1] == 'S') return 1; // ngecek vertikal dari huruf O
		if (sos[sRow - 2][sCol] == 'S' && sos[sRow][sCol - 2] == 'S') return 1; // ngecek diagonal dari huruf O
		if (sos[sRow - 1][sCol - 2] == 'S' && sos[sRow - 1][sCol] == 'S') return 1; // ngecek horizontal dari huruf O
	}
	return 0;
}

void gamePlayPVP(){
    while (counter <= dimensi * dimensi){
    	system("cls");
		sRow = 0; sCol = 0;
		drawScoreboard();
		drawGameboard();
		int input = takeInput();
			if(input){
			int point = controlSOS(); // untuk ngecek kalau misal bener membentuk SOS maka bakal nambah poin
			if (!point) {
				printf("\xaf\xaf\xaf Sorry, you didn't get point! The turn passed to the other player!");
				getch();
				currentPlayer = (currentPlayer + 1) % 2;
			}
			else {
				scores[currentPlayer] = scores[currentPlayer] + 1;
				printf("\xaf\xaf\xaf Congratulations, you take point! Play again!");
				getch();
			}
			counter++;
		}
	}
		system("pause");
}    		
	
void TampilInputBot (int a,int b,char c){
	
	printf("COM menginput di sRow %d, sCol %d, huruf %c",a,b,c);
	getch();

}

void RandomSOS(){
	int y;
	srand(time(NULL));
	do{
	sRow=(rand()%dimensi) + 1;
	sCol=(rand()%dimensi) + 1;
	
	
	}while(sos[sRow - 1][sCol - 1]!= 0);
	y= rand()% 2;
		if(y==1){
			huruf = 'S';
		}else{
			huruf = 'O';
		}
	sos[sRow - 1][sCol - 1]=huruf;
	
}


int CekKotak(){	
	for(sRow=0; sRow<dimensi; sRow++){
		for(sCol=0; sCol<dimensi; sCol++){
			if (sos[sRow][sCol] == ' '){
				return 0;
			}
		}
	}
	return 1;
}

int CekKotakKosong(int kotak){
   if(kotak>0&&kotak<((dimensi*dimensi)+1)){
		sRow = (kotak-1)/dimensi;
		sCol = (kotak-1)%dimensi;

		if (sos[sRow][sCol]==' '){
			return 1;
		}
		else {
			return 0;
		} 
	}
  	else{
		return 0;	
  	}
}

int compFindOS(){
	int kotak;

	for (sRow=0; sRow<dimensi; sRow++){
		for(sCol=0; sCol<dimensi; sCol++){
		   kotak = ((sRow*dimensi) +sCol)+1;
			if(CekKotakKosong(kotak)){
				if((sos[sRow][sCol+1] == 'O') && (sos[sRow][sCol+2] == 'S')){
					return kotak;
				}
                if((sos[sRow][sCol-1] == 'O') && (sos[sRow][sCol-2] == 'S')){
                    return kotak;
                        }
				if((sos[sRow+1][sCol] == 'O') && (sos[sRow+2][sCol] =='S')){
					return kotak;
				}
                if((sos[sRow-1][sCol] == 'O') && (sos[sRow-2][sCol] =='S')){
                    return kotak;
                }
				if((sos[sRow+1][sCol+1] == 'O') && (sos[sRow+2][sCol+2] == 'S')){
                    return kotak;
                }
                if((sos[sRow-1][sCol-1] == 'O') && (sos[sRow-2][sCol-2] == 'S')){
                    return kotak;
                }
                if((sos[sRow+1][sCol-1] == 'O') && (sos[sRow+2][sCol-2] == 'S')){
                    return kotak;
                }
                if((sos[sRow-1][sCol+1] == 'O') && (sos[sRow-2][sCol+2] == 'S')){
                    return kotak;
                }
		  	}
		}
	}
	return 0;
}

int compFindSS(){
	int kotak;
	
    for (int sRow=0; sRow<dimensi; sRow++){
        for(int sCol=0; sCol<dimensi; sCol++){  
        
            kotak = ((sRow*dimensi) +sCol)+1;
            if(CekKotakKosong(kotak)){
		        if((sos[sRow][sCol+1] == 'S') && (sos[sRow][sCol-1] == 'S')){
                    return kotak;
            	}
                if ((sos[sRow+1][sCol] == 'S') && (sos[sRow-1][sCol] =='S')){
                    return kotak;
        		}
                if((sos[sRow+1][sCol+1] == 'S') && (sos[sRow-1][sCol-1] == 'S')){
                    return kotak;
                }
                if((sos[sRow+1][sCol-1] == 'S') && (sos[sRow-1][sCol+1] == 'S')){
                    return kotak;
                }
            }
		}
    }
	return 0;
}

int FindKotakKosong(){
	int kotak;
	
	srand(time(NULL));
	
	do{
	kotak =(rand()) + 1;
	
	sRow = (kotak-1)/dimensi;
	sCol = (kotak-1)%dimensi;
		
	}while(sos[sRow][sCol] != ' ');
	return kotak;	
}

int controlSOSPro (int kotak,int player,char huruf){
	int get;
	
	sRow = (kotak-1)/dimensi;
	sCol = (kotak-1)%dimensi;
	get = 0;
	
  	if(huruf == 'S'){
		if ((sos[sRow][sCol-2] == 'S') && (sos[sRow][sCol-1] == 'O')){
			get++;
		}
		if ((sos[sRow][sCol+1]== 'O') && (sos[sRow][sCol+2] == 'S')){
			get++;
		}	
		if((sos[sRow+1][sCol] == 'O') && (sos[sRow+2][sCol] == 'S')){
			get++;
		}
		if((sos[sRow-1][sCol] == 'O') && (sos[sRow-2][sCol] == 'S')){
			get++;
		}
		if((sos[sRow+1][sCol+1] == 'O') && (sos[sRow+2][sCol+2] == 'S')){
			get++;
		}
		if((sos[sRow-1][sCol-1] == 'O') && (sos[sRow-2][sCol-2] == 'S')){
			get++;
		}
		if((sos[sRow+1][sCol-1] == 'O') && (sos[sRow+2][sCol-2] == 'S')){
			get++;
		}
		if((sos[sRow-1][sCol+1] == 'O') && (sos[sRow-2][sCol+2] == 'S')){
			get++;
		}
  	}
  	else if(huruf == 'O'){
		if((sos[sRow+1][sCol] == 'S') && (sos[sRow-1][sCol] == 'S')){
			get++;
		}
		if((sos[sRow][sCol+1] == 'S') && (sos[sRow][sCol-1] == 'S')){
			get++;
		}
		if((sos[sRow+1][sCol+1] == 'S') && (sos[sRow-1][sCol-1] == 'S')){
			get++;
		}
		if((sos[sRow+1][sCol-1] == 'S') && (sos[sRow-1][sCol+1] == 'S')){
			get++;
		}
  	}
    scores[currentPlayer] = scores[currentPlayer] + get;

	if(get>0){
		got=1;
		return 1;
	}
	else{
		currentPlayer=0;
		got=0;
		return 0;
	}
}


	
	
void compMovePro(){
	int kotak,comp;
	char huruf;

  	do{
  		system("cls");
  		drawScoreboardPVC();
    	drawgameboardPro();
    	
    	if(comp=0){
    		if(compFindOS()){
				kotak = compFindOS();
				huruf = 'S';
			}
			else if(compFindSS()){
				kotak = compFindSS();
				huruf = 'O';
			}
			else{
				kotak = FindKotakKosong();
				huruf = 'S';
			}
			sRow = (kotak-1)/dimensi;
			sCol = (kotak-1)%dimensi;
        	
   			sos[sRow][sCol] = huruf;
   			if(got==0){
   				if(huruf == 'S'){
   					printf("\n\xaf\xaf Computer putting  %c in [%d][%d] \n", huruf, sRow+1, sCol+1);
					system("pause");
				}else if(huruf == 'O'){
					printf("\n\xaf\xaf Computer putting  %c in [%d][%d] \n", huruf, sRow+1, sCol+1);
					system("pause");
				}
			}
			else if(got==1){
				system("cls");
				drawScoreboardPVC();
    			drawGameboard();
    			if(huruf == 'S'){
   					printf("\n\xaf\xaf Computer putting a %c in [%d][%d] \n", huruf, sRow+1, sCol+1);
   					printf("\xaf\xaf\xaf Computer get point! \n");
					system("pause");
				}else if(huruf == 'O'){
					printf("\n\xaf\xaf Computer putting  %c in [%d][%d] \n", huruf, sRow+1, sCol+1);
					printf("\xaf\xaf\xaf Computer get point! \n");
					system("pause");
				}
			}
		}
		
		else{
			if(compFindOS()){
				kotak = compFindOS();
				huruf = 'S';
			}
			else if(compFindSS()){
				kotak = compFindSS();
				huruf = 'O';
			}
			else{
				kotak = FindKotakKosong();
				huruf = 'O';
			}
			sRow = (kotak-1)/dimensi;
			sCol = (kotak-1)%dimensi;
        	
   			sos[sRow][sCol] = huruf;
   			if(got==0){
   				if(huruf == 'S'){
   					printf("\n\xaf\xaf Computer putting  %c in [%d][%d] \n", huruf, sRow+1, sCol+1);
					system("pause");
				}else if(huruf == 'O'){
					printf("\n\xaf\xaf Computer putting  %c in [%d][%d] \n", huruf, sRow+1, sCol+1);
					system("pause");
				}
			}
			else if(got==1){
				system("cls");
				drawScoreboardPVC();
    			drawgameboardPro();
    			if(huruf == 'S'){
   					printf("\n\xaf\xaf Computer putting  %c in [%d][%d] \n", huruf, sRow+1, sCol+1);
   					printf("\xaf\xaf\xaf Computer get point! \n");
					system("pause");
				}else if(huruf == 'O'){
					printf("\n\xaf\xaf Computer putting  %c in [%d][%d] \n", huruf, sRow+1, sCol+1);
					printf("\xaf\xaf\xaf Computer get point! \n");
					system("pause");
				}
			}
		}
    	
   }while(controlSOSPro(kotak,2,huruf) && (!CekKotak()));

   return;
}



int takeInputVScom() {
	do {
	fflush(stdin);
	printf("\n\n\xaf Player turn: %s\n", namaPlayer[currentPlayer]);
	printf("\xaf Row: ");
	scanf("%d", &sRow);
	printf("\xaf Column: ");
	scanf("%d", &sCol);
	}while(!(sRow > 0 && sRow <= dimensi && sCol > 0 && sCol <= dimensi));
	
	if (!(sRow > 0 && sRow <= dimensi && sCol > 0 && sCol <= dimensi)) {
		printf("\xaf\xaf Invalid position!!\n\xaf\xaf Press any key to continue!!");
		getch();
		return 0;
	}
	switch (sos[sRow - 1][sCol - 1]) {

	case 'S':
	case 'O':  
	 printf("\xaf\xaf Invalid position!!\n\xaf\xaf Press any key to continue!!");
	 getch();
    
		return 0;

	default:   
	 system("cls");
		drawScoreboard();
		drawgameboardPro();
		printf("\n\n\xaf Player turn: %s\n\xaf Row: %d\n\xaf Column: %d\n\xaf\xaf S/O? ", namaPlayer[currentPlayer], sRow, sCol);
		char ch;
		scanf(" %c", &ch);
		switch (ch) {
		case 's':
		case 'S': sos[sRow - 1][sCol - 1] = 'S'; return 1;
		case 'o':
		case 'O': sos[sRow - 1][sCol - 1] = 'O'; return 1;
		}

		printf("\xaf\xaf Invalid letter!!\n\xaf\xaf Press any key to continue!!");
		getch();
		return 0;
	}
	
}




void screenPemenangComp(){
	system("cls");
	warnateks(FOREST_GREEN);
	printf("\n\n\n\n\n");
	printf("\t\t\t  лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл \n ");
	gotoxy(54,8);
	warnateks(WHITE);
	printf("COMPUTER WIN ");
}

void screenDraw(){
	system("cls");
	warnateks(FOREST_GREEN);
	printf("\n\n\n\n\n");
	printf("\t\t\t  лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл \n ");
	gotoxy(54,8);
	warnateks(WHITE);
	printf("GAME IS DRAW \n\n\n\n\n\n\n ");
}

void screenPemenangPlayer(){
	system("cls"); 
	warnateks(FOREST_GREEN);
	printf("\n\n\n");
	printf("\t     лллллллл    ллллл     лллл      лл     ллллллллл   ллллллллл           ллллл      лллллллллллл ллллллллл \n  ");
	printf("\t   лл          лл     лл   лл лл     лл   лл            лл      лл         лл   лл          лл      лл           \n");
	printf("\t   лл          лл     лл   лл  лл    лл   лл            лл      лл        лл     лл         лл      лл           \n  ");
	printf("\t   лл          лл     лл   лл   лл   лл   лл     ллллл  ллллллллл        ллллллллллл        лл      ллллллллл \n");
	printf("\t   лл          лл     лл   лл    лл  лл   лл        лл  лл      лл      лл         лл       лл             лл \n  ");
	printf("\t   лл          лл     лл   лл     лл лл   лл        лл  лл       лл    лл           лл      лл             лл \n  ");
	printf("\t     лллллллл    ллллл     лл      лллл     лллллллллл  лл        лл  лл             лл     лл      ллллллллл \n ");
	warnateks(WHITE);
	printf("\n\n\t\t\t  лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лл                                                              лл \n");
	printf("\t\t\t  лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл \n ");
}


void pemenangGamePVP(){
	if (scores[0]> scores[1]){
	screenPemenangPlayer();
	gotoxy(45,16);
	warnateks(FOREST_GREEN);
	printf("THE WINNER IS %s ", namaPlayer[0]);
	printf("\n\n\n\n\n\n");
	system("pause");
	}
	else if (scores[0]== scores [1]){
	screenDraw();
	printf("\n\n\n\n\n\n");
	system("pause");	
	}
	else {
	screenPemenangPlayer();
	gotoxy(45,16);
	warnateks(FOREST_GREEN);
	printf("THE WINNER IS %s ", namaPlayer[1]);
	printf("\n\n\n\n\n\n");
	system("pause");	
		
	}
}

void pemenangGamePVC(){
	if (scores[0]> scores[1]){
	screenPemenangPlayer();
	gotoxy(45,16);
	warnateks(FOREST_GREEN);
	printf("THE WINNER IS %s ", namaPlayer[0]);
	printf("\n\n\n\n\n\n");
	system("pause");
	}
	else if (scores[0]==scores [1]){
	screenDraw();
	printf("\n\n\n\n\n\n");
	system("pause");	
	}
	else {
	screenPemenangComp();
	printf("\n\n\n\n\n\n");
	system("pause");			
	}
}

void pemenangGamePVCPro(){
	if (scores[0]> scores[2]){
	screenPemenangPlayer();
	gotoxy(45,16);
	warnateks(FOREST_GREEN);
	printf("THE WINNER IS %s ", namaPlayer[0]);
	printf("\n\n\n\n\n\n");
	system("pause");
	}
	else if (scores[0]==scores [2]){
	screenDraw();
	printf("\n\n\n\n\n\n");
	system("pause");	
	}
	else {
	screenPemenangComp();
	printf("\n\n\n\n\n\n");
	system("pause");			
	}
}

void ResetBoard(){
	for (int i = 0; i < dimensi; i++)
		for (int j = 0; j < dimensi; j++)
			sos[i][j] = ' ';
}



void gamePlayPVC(){
	while(counter<=dimensi*dimensi){
	system("cls");
	drawScoreboard();
	drawGameboard();
	if (currentPlayer==0){
		int input = takeInput();
		if(input){
			int point = controlSOS();
			if (!point) {
				printf("\xaf\xaf\xaf Sorry, you didn't get point! The turn passed to the other player!");
				getch();
				currentPlayer = (currentPlayer + 1) % 2;
			}
			else {
				scores[currentPlayer] = scores[currentPlayer] + 1;
				printf("\xaf\xaf\xaf Congratulations, you take point! Play again!");
				getch();
			}
		
		}
	}
	else{
	
			RandomSOS();
			int point = controlSOS();
			if (!point) {
		
				currentPlayer = (currentPlayer + 1) % 2;
			}
			else {
				scores[currentPlayer] = scores[currentPlayer] + 1;
				printf("\xaf\xaf\xaf Congratulations, you take point! Play again!");
				getch();
			}
			printf("\n\n");
			TampilInputBot (sRow,sCol,huruf);
		}
	counter++;
	}
	pemenangGamePVC();
	ResetBoard();
	system("pause");	

}

void gamePlayPVCPro(){
	currentPlayer=0;
	drawScoreboardPVC();
	ResetBoard();
	while(!CekKotak()) {
		system("cls");
		sRow = 0; sCol = 0;
		drawScoreboardPVC();
		drawgameboardPro();
		if(currentPlayer==0){
			int input = takeInputVScom();
			if(input){
				int point = controlSOS();
				if (!point) {
					printf("\xaf\xaf\xaf Sorry, you didn't get point! The turn passed to the computer!\n");
					system("pause");
					currentPlayer = 2;
				}
				else {
					scores[currentPlayer] = scores[currentPlayer] + 1;
					printf("\xaf\xaf\xaf Congratulations, you take point! Play again!\n");
					system("pause");
				}
			}
		}
		else if(currentPlayer==2){
			compMovePro();

		}
	

	}
	pemenangGamePVCPro();
	ResetBoard();
	system("pause");

}


int main(){
	int input, InputGameMode, InputGameLevel, InputLevelPermainan;
	char Player1[20], Player2[20];
	
	TampilLoading();

	do{
		system("cls");
		TampilMenu();
		gotoxy(67,24);
	    scanf("%d", &input);
	    
		if(input==1){
			TampilModePermainan();
			gotoxy (71,13);
			scanf("%d", &InputGameMode);
			if (InputGameMode == 1){
				TampilInputNamaPlayer1();
				InputNamaPlayer1(Player1 , Player2);
				TampilLevelPermainan();
				gotoxy (71,13);
				scanf("%d", &InputLevelPermainan);
				switch (InputLevelPermainan){
					case 1 : 
					dimensi=5;
					break;
					case 2 :
					dimensi=7;
					break;
					
				}
				system("cls");
				drawScoreboard();
				drawGameboard();
				gamePlayPVP();
				pemenangGamePVP();
				ResetBoard();
				system("pause");
			}
			else if (InputGameMode == 2){
				TampilInputNamaPlayer2();
				InputNamaPlayer2(Player1, Player2);
				TampilLevelPermainan();
				gotoxy (71,13);
				scanf("%d", &InputLevelPermainan);
				switch (InputLevelPermainan){
					case 1 : 
					dimensi=5;
					system("cls");
					drawScoreboard();
					drawGameboard();
					gamePlayPVC();
					system("pause");
					break;
					case 2 :
					dimensi=7;
					system("cls");
					drawScoreboard();
					drawgameboardPro();
					gamePlayPVCPro();
					system("pause");
					break;	
				}
			
			}
				
			
	}
		else if(input==2){
			HowToPlay();
		}
		else if(input==3){
			gameCredits();
		}
		

	}while (input!=4);
	return(0);
	
}


