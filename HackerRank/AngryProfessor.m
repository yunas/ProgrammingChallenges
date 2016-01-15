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
				
			NSMutableArray *manaualArr = [NSMutableArray new];
			NSMutableArray *sPresenceArr = [NSMutableArray new];
			int qTotalStudent = 0;

			for (int i=0; i<N*2; i++) {
				
				if (i%2 == 0){
					NSMutableArray *inputIntegers = [NSMutableArray new];
					for (int j=0; j<2; j++) {
						int inputElement;
						scanf("%d", &inputElement);
						[inputIntegers addObject:[NSNumber numberWithLongLong:inputElement]];
						if (j==0){
							qTotalStudent = inputElement;
						}
					}
					
					[manaualArr addObject:inputIntegers];
				}	
				else{
					NSMutableArray *inputIntegers = [NSMutableArray new];
					for (int j=0; j<qTotalStudent; j++) {
						int inputElement;
//						printf("Values %d: ",j);						
						scanf("%d", &inputElement);
						[inputIntegers addObject:[NSNumber numberWithLongLong:inputElement]];
					}
					[sPresenceArr addObject:inputIntegers];
				}
				
			}

/********************************************************************************************************
 *
 * PROCESS INPUT
 *
 ********************************************************************************************************/
			
			
			
			
			for (int i=0; i<N; i++) {
			
				NSArray *instructionArr = manaualArr[i];
				NSArray *studentsArr = sPresenceArr[i];
				
				int totalStudent = (int)[instructionArr[0] integerValue];
				int threshold = (int)[instructionArr[1] integerValue];
				int studentsB4Class = 0;
				
				for (int j = 0; j < studentsArr.count; j++){
					if ((int)[studentsArr[j] integerValue]<=0){
						studentsB4Class++;
					}
				}			
		
				if (studentsB4Class < threshold){
					printf("YES\n");
				}
				else{
					printf("NO\n");
				}
								
			}	
			
			

			
	}
	return 0;
}
