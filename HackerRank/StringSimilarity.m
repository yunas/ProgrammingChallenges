#import <Foundation/Foundation.h>


long long getSelfSubStringCount(NSString* str, NSString *subStr){
	
	int count = MIN(str.length, subStr.length);
	int matchCount = 0;
	int i;
	for (i = 0; i < count ; i++){
		if ([str characterAtIndex:i] != [subStr characterAtIndex:i]){
			break;
		}
		matchCount++;
	}
	return matchCount;
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
				
			NSMutableArray *inputArr = [NSMutableArray new];
			for (int i=0; i<N; i++) {
					char inputStr[100000];
					scanf("%s",inputStr);
					[inputArr addObject: [NSString stringWithUTF8String:inputStr]];
			}

/******************************************************************************************************
* PROCESS INPUT
*
******************************************************************************************************/
			long long count = 0;
			for (int i=0; i<N; i++) {
				
				NSString *inputStr = inputArr[i];
				int offSet = 1;
				NSString *subStr = [inputStr substringFromIndex:offSet++];
				int matchCount = subStr.length+1;
				while (subStr.length !=0){
					
					int count = subStr.length;
					for (int j = 0; j < count ; j++){
						if ([inputStr characterAtIndex:j] != [subStr characterAtIndex:j]){
							break;
						}
						matchCount++;
					}
					
					//matchCount += getSelfSubStringCount(inputStr, subStr);
					subStr = [inputStr substringFromIndex:offSet++];
				}
				printf("%d\n",matchCount);				
				
			}	
			
	}
	return 0;
}
