#import <Foundation/Foundation.h>


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
			long long sum = 0;
			for (int i=0; i<N; i++) {
				long long x = (long long)[inputIntegers[i] integerValue];			
				for (int j = 0 ; j<=x ; j++ ){
					if (j % 2 == 0){
						sum +=1;
					}
					else{
						sum = sum*2;
					}
				}
				
				printf("%lld\n",sum);								
				sum = 0;
			}	
			
	}
	return 0;
}
