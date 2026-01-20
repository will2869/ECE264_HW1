/* MODIFY this file */

#include "sort.h"

void ssort(int * arr, int size) {
	/* For step 3, fill this in to perform a selection sort
	   For step 4, add conditional compilation flags to perform an ascending selection sort instead */
	for (int i = 0; i < size; i++) { // for loop through array
		
		int minIdx = i; // minimum index
		
		for (int j = (i + 1); j < size; j++) { // loop through values after current index
			#ifdef ASCENDING // if ascending defined
			minIdx = (arr[j] < arr[minIdx]) ? j : minIdx; // if current index is < minimum, set new minimum
			#else
			minIdx = (arr[j] > arr[minIdx]) ? j : minIdx; // if current index is > minimum, set new minimum
			#endif
		}
		
		// swap current and minimum
		int swap = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = swap;
	
	}
}
