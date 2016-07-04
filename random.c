#include <stdio.h>
#include <inttypes.h>
#include "random.h"

static uint32_t rnd_kiss_x = 123456789;
static uint32_t rnd_kiss_y = 26;
static uint32_t rnd_kiss_z = 551241;
static uint32_t rnd_kiss_c = 12312313;

uint32_t get_kiss32() {
	uint64_t t;

	rnd_kiss_x = 69069 * rnd_kiss_x + 12345;

	rnd_kiss_y ^= rnd_kiss_y << 13;
	rnd_kiss_y ^= rnd_kiss_y >> 17;
	rnd_kiss_y ^= rnd_kiss_y << 5;

	t = 698769069ULL * rnd_kiss_z + rnd_kiss_c;
	rnd_kiss_c = t >> 32;
	rnd_kiss_z = (uint32_t) t;

	return rnd_kiss_x + rnd_kiss_y + rnd_kiss_z;
}

uint32_t put_seed_rand32(uint32_t seed) {
#ifdef RANDOM_DEBUG
	printf("seeding RNG with 0x%x\n", seed);
#endif
	rnd_kiss_x = rnd_kiss_x ^ seed;

	return rnd_kiss_x;
}

