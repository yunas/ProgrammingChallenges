#import <Foundation/Foundation.h>

int main(int argc, char *argv[]) {
	@autoreleasepool {

		int N;
		scanf("%d", &N);

		for (int i=0; i<N; i++) {
			for (int j=0; j<N-i-1; j++) {
				printf(" ");
			}
			for (int j=0; j<=i; j++) {
				printf("#");
			}
			printf("\n");				
		}
	}
	return 0;
}
