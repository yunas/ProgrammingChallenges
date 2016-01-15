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
			
			
			
			
			for (int i=0; i<N; i++) {
			
				long long x = (long long)[inputIntegers[i] integerValue];
				long long y = x;
				int flag = 0;
				while (y%3 != 0 ) {
					y -= 5;
				}
				
				if (y < 0){
					printf("-1");
				}
				else{
					
					for (int j = 0; j < y; j++){
						printf("5");
					}			
					for (int j = 0; j < (x-y); j++){
						printf("3");
					}			
				}
				printf("\n");								
			}	
			
	}
	return 0;
}
