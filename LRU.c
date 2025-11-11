#include<stdio.h>

int findLRU(int time[], int n){
	int i, minimum = time[0], pos = 0;

	for(i = 1; i < n; ++i){
		if(time[i] < minimum){
			minimum = time[i];
			pos = i;
		}
	}
	
	return pos;
}

int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
	printf("Enter number of frames: ");
	scanf("%d", &no_of_frames);
	// Input: Enter number of frames (e.g., 3)
	
	printf("Enter number of pages: ");
	scanf("%d", &no_of_pages);
	// Input: Enter number of page references (e.g., 10)
	
	printf("Enter reference string: ");
	// Input: Enter page numbers separated by spaces (e.g., 7 0 1 2 0 3 0 4 2 3)
    for(i = 0; i < no_of_pages; ++i){
    	scanf("%d", &pages[i]);
    }
    
	for(i = 0; i < no_of_frames; ++i){
    	frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
    	flag1 = flag2 = 0;
    	
    	for(j = 0; j < no_of_frames; ++j){
    		if(frames[j] == pages[i]){
	    		counter++;
	    		time[j] = counter;
	   			flag1 = flag2 = 1;
	   			break;
   			}
    	}
    	
    	if(flag1 == 0){
			for(j = 0; j < no_of_frames; ++j){
	    		if(frames[j] == -1){
	    			counter++;
	    			faults++;
	    			frames[j] = pages[i];
	    			time[j] = counter;
	    			flag2 = 1;
	    			break;
	    		}
    		}	
    	}
    	
    	if(flag2 == 0){
    		pos = findLRU(time, no_of_frames);
    		counter++;
    		faults++;
    		frames[pos] = pages[i];
    		time[pos] = counter;
    	}
    	
    	printf("\n");
    	
    	for(j = 0; j < no_of_frames; ++j){
    		printf("%d\t", frames[j]);
    	}
	}
	
	printf("\n\nTotal Page Faults = %d", faults);
    
    return 0;
}

/*
 * COMPILATION:
 * gcc LRU.c -o LRU
 * 
 * RUN:
 * ./LRU
 * 
 * DESCRIPTION:
 * Least Recently Used (LRU) page replacement algorithm
 * Takes user input for number of frames, pages, and reference string
 * 
 * FIXES NEEDED:
 * None - code should work as-is
 * 
 * EXPECTED OUTPUT:
 * Enter number of frames: 3
 * Enter number of pages: 10
 * Enter reference string: 7 0 1 2 0 3 0 4 2 3
 * 
 * 7    -1    -1
 * 7    0     -1
 * 7    0     1
 * 2    0     1
 * 2    0     1
 * 2    0     3
 * 2    0     3
 * 4    0     3
 * 4    0     2
 * 4    3     2
 * 
 * Total Page Faults = 8
 */
