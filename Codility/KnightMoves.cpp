#include<iostream>
#define N 200000000*
#define minVal -100000000
#define maxVal 100000000

using namespace std;

// defines a structure for chess moves
typedef struct chess_moves {
	// 'x' and 'y' coordinates on chess board
	int x,y;
}chess_moves;

// check if the next move (as per knight's constraints) is possible
bool isMovePossible(chess_moves next_move, int tour[N][N]) {
	int i = next_move.x;
	int j = next_move.y;
	if ((i >= minVal && i <= maxVal) && (j >= minVal && j < maxVal) && (tour[i][j] == 0))
		return true;
	return false;
}


// recursive function to find a knight tour
int findTour(int tour[N][N], chess_moves move_KT[],
					chess_moves curr_move, int move_count, int a, int b) {
	int i;
	chess_moves next_move;

	// try out the possible moves starting from the current coordinate
	for (i = 0; i < N; i++) {
		// get the next move

		if (curr_move.x == a && curr_move.y == b){
			return move_count;	
		}
		next_move.x = curr_move.x + move_KT[i].x;
		next_move.y = curr_move.y + move_KT[i].y;



		if (isMovePossible(next_move, tour)) {
			// if the move is possible
			// increment the move count and store it in tour matrix
			tour[next_move.x][next_move.y] = move_count+1;
			return findTour(tour, move_KT, next_move, move_count+1, a, b);
				tour[next_move.x][next_move.y] = 0;
		}
	}
	return false;
}

// wrapper function
int solution(int A, int B) {
	int tour[N][N];
	int i,j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			tour[i][j] = 0;
		}
	}

	chess_moves move_KT[8] = { {2,1},{1,2},{-1,2},{-2,1},
										{-2,-1},{-1,-2},{1,-2},{2,-1} };

	chess_moves curr_move = {N/2,N/2};

	return findTour(tour, move_KT, curr_move, 0, A, B);
	
}

// main
int main() {
	
	int a,b;
	cin >> a >> b;
	
	cout << solution(a,b);
	cout<<endl;
	return 0;
}
