#import <Foundation/Foundation.h>

long long sum (long long val1, long long val2, long long price1, long long price2, long long conversion) {
	long long optimizedSum = 0;

	long long diff = abs(price1 - price2);
	if (diff > conversion){
		
		if (price1 > price2){
			optimizedSum = val1*(price2+conversion) + val2*price2;				
		}
		else{
			optimizedSum = val1*price1 + val2*(price1+conversion);				
		}
	}
	else{
		optimizedSum = val1*price1 + val2*price2;						
	}				

	return optimizedSum;
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
				
			NSMutableArray *itemsArray = [NSMutableArray new];
			NSMutableArray *pricesArray = [NSMutableArray new];

			for (int i=0; i<N*2; i++) {
				if (i%2 == 0){
					NSMutableArray *inputIntegers = [NSMutableArray new];
					for (int j=0; j<2; j++) {
						int inputElement;
//						printf("InputNumber %d: ",j);
						scanf("%d", &inputElement);

						[inputIntegers addObject:[NSNumber numberWithLongLong:inputElement]];
					}
					[itemsArray addObject:inputIntegers];
				}	
				else{
					NSMutableArray *inputIntegers = [NSMutableArray new];
					for (int j=0; j<3; j++) {
						int inputElement;
//						printf("Values %d: ",j);						
						scanf("%d", &inputElement);
						[inputIntegers addObject:[NSNumber numberWithLongLong:inputElement]];
					}
					[pricesArray addObject:inputIntegers];
				}
				
			}

/********************************************************************************************************
 *
 * PROCESS INPUT
 *
 ********************************************************************************************************/
			
			
			
			
			for (int i=0; i<N; i++) {
			
			NSArray *itemArr = itemsArray[i];
			NSArray *valueArr = pricesArray[i];
			
			
				long long sumVal =	sum((int)[itemArr[0] integerValue],(int)[itemArr[1] integerValue],(int)[valueArr[0] integerValue],(int)[valueArr[1] integerValue],(int)[valueArr[2] integerValue]);
				printf("%lld\n", sumVal);
			}	
			
			

			
	}
	return 0;
}
