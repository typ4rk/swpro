#include<iostream>
#include <algorithm> // std::srot()  

using namespace std;

int col_check[8] = { 0,0,0,0,0,0,0,0 };
int max_score = 0;
int N;
int calc_max[8][8];

void backtracking(int row, int score) {
	if (row == N) {
		if (score > max_score) max_score = score;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (col_check[i] == false) {
			col_check[i] = true;
			backtracking(row + 1, score + calc_max[row][i]);
			col_check[i] = false;
		}
	}
	return;
}


int main() {
	int card[3][8];
	int check_card[33];
	int mycard[8];
	//int calc_max[3][8];

	int T;

	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);

		for (int i = 1; i <= 4 * N; i++) {
			check_card[i] = 0;
		}

		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < N; i++) {
				scanf("%d", &card[j][i]);
				check_card[card[j][i]] = 1;
			}
		}


		// for ( int i=1; i<=4*N; i++){
		//  printf("%d ", check_card[i]);
		//}
		for (int i = 1, j = 0; i <= 4 * N; i++) {
			if (check_card[i] == 0) {
				mycard[j] = i;
				j++;
			}
		}

		//printf("\n=================\n");
	   // for ( int j=0; j<3; j++){
	   //   for ( int i=0; i<N; i++){
	   //    printf("%d ", card[j][i]);
	   //   }
	   //   printf("\n");
	   //     }   
	  // // 
	  //  printf("\n========== my card =======\n");
	  //   for ( int i=0; i<N; i++){
	  //    printf("%d ", mycard[i]);
	  //   }
	   // 

		//calc_max[3][8];
		for (int myCard = 0; myCard < N; myCard++) {

			for (int i = 0; i < N; i++) { //³îÀÌ È½¼ö 
				int sort_card[4];
				int max_value;

				sort_card[0] = mycard[myCard];
				for (int k = 1; k < 4; k++) {
					sort_card[k] = card[k - 1][i];
				}

				//             printf("\n==== before sort =============\n");
				//    for ( int k=0; k < 4; k ++){
				//     printf("%d ", sort_card[k]);
				//    }

				sort(sort_card, sort_card + 4);

				//printf("\n==== after sort =============\n");
			//    for ( int k=0; k < 4; k ++){
			//     printf("%d ", sort_card[k]);
			//    }
			//                printf("%n");

							// max°ª Ã£±â 
				for (int k = 0; k < 4; k++) {
					if (k == 0 && mycard[myCard] == sort_card[k]) {
						max_value = sort_card[3];
						continue;
					}

					if (mycard[myCard] == sort_card[k]) {
						max_value = sort_card[k - 1];
					}
				}
				calc_max[myCard][i] = max_value;
			}

		}


		max_score = 0;
		backtracking(0, 0);
		printf("#%d %d\n", tc, max_score);
	}
	return 0;
}
