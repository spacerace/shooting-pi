#ifndef __RANDOM_H__
#define __RANDOM_H__

uint32_t get_kiss32();
uint32_t put_seed_rand32(uint32_t seed);

#define RANDOM_DEBUG
#define __drand32() 		(((double)get_kiss32())/((double)0xffffffff))
#define __drand32_init(s)	put_seed_rand32(s)

#endif

