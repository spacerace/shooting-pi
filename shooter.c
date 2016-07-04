#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "random.h"

/* calculate distance between x1/y1-x2/y2 in a 2D field */
double distance(double x1, double x2, double y1, double y2) {
	return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main(int argc, char **argv) {
	uint64_t shots, hits = 0;
	double pi, x, y;

	uint64_t max_shots;
	
	if(argc == 1) max_shots = 2147483647;
	else max_shots = atoi(argv[1]);

	printf("doing %lld shots....\n", (long long)max_shots);

	__drand32_init(time(NULL));

	for(shots = 0; shots < max_shots; shots++) {
		x = __drand32();
		y = __drand32();

		if(distance(x, 0, y, 0) <= 1.0) hits++;


		// show percentage of ongoing process
		if(!(shots % (max_shots/10))) {
			static int percentage_done = 0;
			printf("%d%% done.\n", percentage_done);

			percentage_done += 10;
		}
	}

	pi = (double)((hits/(double)max_shots*1.0)*4.0);

	printf("All done, i shot %lld times and hit %lld times (ratio=1:%f)\n\
			I calculated pi to be approx. %f\n", (long long)shots, (long long)hits, (double)((double)shots/hits),pi);

	return 0;
}
