#import <Foundation/Foundation.h>


long long isCompleteDiviser(int num, int divisor){
	
	int lastDigit = divisor % 10;
	divisor = divisor/10;

	if (divisor == 0){
		return 0;
	}
	
	if (lastDigit == 0){
		return 0 + isCompleteDiviser(num, divisor);		
	}
	
	if (num % lastDigit == 0){
		return 1 + isCompleteDiviser(num, divisor);
	}

	return 0 + isCompleteDiviser(num, divisor);
}


int main(int argc, char *argv[]) {
	@autoreleasepool {



/********************************************************************************************************
 *
 * READ ALL INPUT
 *
 ********************************************************************************************************/
			int N;
			scanf("%d", &N);
				
			NSMutableArray *inputIntegers = [NSMutableArray new];
			for (int i=0; i<N; i++) {
					long long inputElement;
					scanf("%lld", &inputElement);
					[inputIntegers addObject:[NSNumber numberWithLongLong:inputElement]];
			}

/********************************************************************************************************
 *
 * PROCESS INPUT
 *
 ********************************************************************************************************/
			long long count = 0;
			for (int i=0; i<N; i++) {
				long long x = (long long)[inputIntegers[i] integerValue];			
					long long completeDivisor = isCompleteDiviser(x, x);
				printf("%lld\n",completeDivisor+1);								
			}	
			
	}
	return 0;
}
