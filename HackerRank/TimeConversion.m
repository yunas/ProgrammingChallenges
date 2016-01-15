#import <Foundation/Foundation.h>

int main(int argc, char *argv[]) {
	@autoreleasepool {


		char word [11];
		scanf("%s",word);		
		
		NSString * userInput = [[NSString alloc] initWithCString: word encoding: NSUTF8StringEncoding];
		
		if ([userInput containsString:@"PM"]){
			userInput = [userInput stringByReplacingOccurrencesOfString:@"PM" withString:@""];
			NSArray *arr = [userInput componentsSeparatedByString:@":"];
			int h = (int)[arr[0]integerValue] ;
			if (h != 12){
				h += 12;
			}

			userInput = [NSString stringWithFormat:@"%02d:%@:%2@",h,arr[1],arr[2]];	
		}
		else{
			userInput = [userInput stringByReplacingOccurrencesOfString:@"AM" withString:@""];							
			NSArray *arr = [userInput componentsSeparatedByString:@":"];
			int h = (int)[arr[0]integerValue];
			if (h == 12){
				h = 00;
			}
			userInput = [NSString stringWithFormat:@"%02d:%@:%2@",h,arr[1],arr[2]];	

		}	

		const char *newTime = [userInput UTF8String];
		printf("%s",newTime);		
	}
	return 0;
}
