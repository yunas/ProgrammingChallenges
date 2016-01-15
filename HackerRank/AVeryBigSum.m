#import <Foundation/Foundation.h>

int main(int argc, char *argv[]) {
	@autoreleasepool {

			int N;
			scanf("%d", &N);
			NSMutableArray *inputIntegers = [NSMutableArray new];

			for (int i=0; i<N; i++) {
				int inputElement;
				scanf("%d", &inputElement);
				[inputIntegers addObject:[NSNumber numberWithInt:inputElement]];
			}

			//to print a specific element:
			long long int sum = 0;
			for (int i=0; i<N; i++) {
				sum += (int)[inputIntegers[i] integerValue];
			}
			printf("%lld", sum);

	}
	return 0;
}
