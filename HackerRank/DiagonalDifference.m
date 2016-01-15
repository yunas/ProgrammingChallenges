#import <Foundation/Foundation.h>

int main(int argc, char *argv[]) {
	@autoreleasepool {


			int N;
			scanf("%d", &N);


			NSMutableArray *rowsArray = [NSMutableArray new];

			for (int i=0; i<N; i++) {
				NSMutableArray *inputIntegers = [NSMutableArray new];
				for (int i=0; i<N; i++) {
					int inputElement;
					scanf("%d", &inputElement);
					[inputIntegers addObject:[NSNumber numberWithInt:inputElement]];
				}
				[rowsArray addObject:inputIntegers];
			}
			
			
			//Left Diagonal
			int sumLeftDiagonal = 0;
			int sumRightDiagonal = 0;
			
			for (int i=0; i<N; i++) {
				NSArray *inputIntegers = rowsArray[i];
				sumLeftDiagonal += (int)[inputIntegers[i] integerValue];
			}	
			
			

			for (int i=0; i<N; i++) {
				NSArray *inputIntegers = rowsArray[N-1-i];
				sumRightDiagonal += (int)[inputIntegers[i] integerValue];
			}	
		
			int absSum = abs(sumLeftDiagonal - sumRightDiagonal);
			printf("%d", absSum);
	}
	return 0;
}
