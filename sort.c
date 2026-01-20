/* MODIFY this file */

#include "sort.h"

void ssort(int * arr, int size) {
	/* For step 3, fill this in to perform a selection sort
	   For step 4, add conditional compilation flags to perform an ascending selection sort instead */
	for (int i = 0; i < size; i++) {
		
		int minIdx = i;
		
		for (int j = (i + 1); j < size; j++) {
			#ifdef ASCENDING
			minIdx = (arr[j] < arr[minIdx]) ? j : minIdx;
			#else
			minIdx = (arr[j] > arr[minIdx]) ? j : minIdx;
			#endif
		}

		int swap = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = swap;
	
	}
}
