#include <stdio.h>
#include <math.h>

#define THRESSHOLD 0.00000001

double Vn(int m) {
	double dv;
	double sum = 0.0;
	double last_sum = sum;

	int iteration = 0;
	do {
	    dv = 1.0 /pow(1.0 + (2.0 * (double)iteration), m);
        sum += dv;
		last_sum = sum;
		iteration++;
	} while (fabs(dv) > THRESSHOLD);
	
	return sum;
}

double series(double x) {
	double dv;
	double sum = 0.0;
	double last_sum = sum;
	double ratio = (2.0 * x) / M_PI;
	
	int iteration = 1;
	do {
	    dv = (1/iteration) * Vn(2*iteration) * pow(ratio, 2*iteration);
        sum += dv;
		last_sum = sum;
		iteration++;
	} while (fabs(dv) > THRESSHOLD);
	
	return sum;
}

int main() {
	double x;
	while (1) {
		printf("provide number: ");
		scanf("%lf", &x);
        
		if (fabs(x-2.00) <= THRESSHOLD) {
			return 0;
		}
		if ((x<=(-M_PI/2.0)) || (x>=(M_PI/2.0))) {
			printf("invalid input\n");
		}
		else {
			printf("output: %f\n", series(x));
		}
	}
	
	return -1;
}
