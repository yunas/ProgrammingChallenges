#import <Foundation/Foundation.h>

int main(int argc, char *argv[]) {
	@autoreleasepool {


			int N;
			float positiveNumbersCount = 0;
			float negativeNumbersCount = 0;
			float neutralNumbersCount = 0;
			
			scanf("%d", &N);

			for (int i=0; i<N; i++) {
				int inputElement;
				scanf("%d", &inputElement);
				if (inputElement > 0){
					positiveNumbersCount++;
				}
				else if (inputElement < 0){
					negativeNumbersCount++;
				}
				else{
					neutralNumbersCount++;
				}
			}
			

			printf("%.3f\n", positiveNumbersCount/N);
			printf("%.3f\n", negativeNumbersCount/N);
			printf("%.3f", neutralNumbersCount/N);						
	}
	return 0;
}
