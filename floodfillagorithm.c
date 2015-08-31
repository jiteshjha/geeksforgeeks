#include<stdio.h>

void floodfill(int arr[][6], int a, int b, int prevC, int newC) {
	
	if(!(a >= 0 || a <= 5 || b >= 0 || b <= 5))
		return;
	if(arr[a][b] != prevC )
		return;
	
		arr[a][b] = newC;
		floodfill(arr, a, b+1, prevC, newC);
		floodfill(arr, a+1, b, prevC, newC);
		floodfill(arr, a-1, b, prevC, newC);
		floodfill(arr, a, b-1, prevC, newC);
}

int main() {
	int i, j;
	int arr[6][6] = {{1, 1, 1, 1, 1, 1},
		     {1, 0, 0, 0, 0, 1},
		     {1, 0, 0, 0, 0, 1},
	             {1, 0, 1, 1, 0, 1},
		     {1, 1, 1, 1, 0, 1},
		     {1, 1, 0, 0, 1, 1}
		};
	
	floodfill(arr, 2, 3, 0, 1);
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 6; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
