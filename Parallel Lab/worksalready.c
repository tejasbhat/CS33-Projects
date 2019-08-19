//OpenMP version.  Edit and submit only this file.
/* Enter your details below
 * Name : Tejas Bhat
 * UCLA ID : 705199445
 * Email : tejasgbhat@gmail.com
 */

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#include "utils.h"

void work_it_par(long *old, long *new) {
    const int DIM_SQUARED = DIM * DIM;
    const int DIM_PLUS_DIM = DIM + DIM;
    
    int memory_address = 0;
    int new_memory_address = 0;
    
    int i, j, k;
    long u, u0, u1, u2, u3, u4, u5 ,u6, u7, u8, u9 = 0;
    long temp = 0;
    long compute_it;
    long aggregate = 1.0;
    
    #pragma omp parallel for private(j,k,memory_address, compute_it, new_memory_address, u) reduction(+: aggregate) reduction(+:temp) reduction(+:u0) reduction(+:u1) reduction(+:u2) reduction(+:u3) reduction(+:u4) reduction(+:u5) reduction(+:u6) reduction(+:u7) reduction(+:u8) reduction(+:u9)
    for (i=1; i<DIM-1; i++) {
        for (j=1; j<DIM-1; j++) {
            for (k=1; k<DIM-1; k++) {
                memory_address = i * DIM_SQUARED + j * DIM + k;
                compute_it = old[memory_address] * we_need_the_func();
                aggregate += compute_it / gimmie_the_func();
                temp = 0;
                
                new_memory_address = memory_address - DIM_SQUARED;
                
                new_memory_address -= DIM;
                temp += old[new_memory_address-1];
                temp += old[new_memory_address];
                temp += old[new_memory_address+1];
                new_memory_address += DIM;
                temp += old[new_memory_address-1];
                temp += old[new_memory_address];
                temp += old[new_memory_address+1];
                new_memory_address += DIM;
                temp += old[new_memory_address-1];
                temp += old[new_memory_address];
                temp += old[new_memory_address+1];
                
                
                new_memory_address = memory_address;
                
                new_memory_address -= DIM;
                temp += old[new_memory_address-1];
                temp += old[new_memory_address];
                temp += old[new_memory_address+1];
                new_memory_address += DIM;
                temp += old[new_memory_address-1];
                temp += old[new_memory_address];
                temp += old[new_memory_address+1];
                new_memory_address += DIM;
                temp += old[new_memory_address-1];
                temp += old[new_memory_address];
                temp += old[new_memory_address+1];
                
                
                new_memory_address = memory_address + DIM_SQUARED;
                
                new_memory_address -= DIM;
                temp += old[new_memory_address-1];
                temp += old[new_memory_address];
                temp += old[new_memory_address+1];
                new_memory_address += DIM;
                temp += old[new_memory_address-1];
                temp += old[new_memory_address];
                temp += old[new_memory_address+1];
                new_memory_address += DIM;
                temp += old[new_memory_address-1];
                temp += old[new_memory_address];
                temp += old[new_memory_address+1];
                
                temp /= 27;
                new[memory_address] = temp;
                u = (temp/100);
                if (u<=0) u0++;
                if (u>=9) u9++;
                switch (u) {
                    case 1:
                        u1++;
                        break;
                    case 2:
                        u2++;
                        break;
                    case 3:
                        u3++;
                        break;
                    case 4:
                        u4++;
                        break;
                    case 5:
                        u5++;
                        break;
                    case 6:
                        u6++;
                        break;
                    case 7:
                        u7++;
                        break;
                    case 8:
                        u8++;
                        break;
                }
            }
        }
    }
    printf("AGGR:%ld\n",aggregate);
    
    histogrammy[0] = u0;
    histogrammy[1] = u1;
    histogrammy[2] = u2;
    histogrammy[3] = u3;
    histogrammy[4] = u4;
    histogrammy[5] = u5;
    histogrammy[6] = u6;
    histogrammy[7] = u7;
    histogrammy[8] = u8;
    histogrammy[9] = u9;
    
}

