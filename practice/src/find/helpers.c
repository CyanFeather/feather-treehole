/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <stdio.h>
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n, bool bSorted)
{
    // Implement a searching algorithm
   
    if (bSorted == true)
    {
        int low = 0;
        int high = n - 1;	
        while(low < high)
        {
            // printf("Low: %d; High: %d\n", low, high);
            if (value < values[(low + high) / 2])
            {
                high = (low + high) / 2 - 1;
		continue;
            }
	    else if (value > values[(low + high) / 2])
            {
                low = (low + high) / 2 + 1;
		continue;
            }
	    else
                return true;
        }

        if ((low == high) && (value == values[low]))
                return true;
    }
    else
    {
        int index;

        for (index = 0; index < n; index ++)
        {
            if (values[index] == value)
                return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void quick_sort(int array[], int low, int high)
{

    // Implement an O(nlogn) sorting algorithm
    int start = low;
    int end = high;
    int pivot = array[low];

    if (low >= high)
        return;

    //printf("Sort from %d to %d\n", start, end);

    // Only 2 elements
    if (end == (start + 1))
    {
        if (array[start] > array[end])
        {
            int tmp = array[start];
            array[start] = array[end];
            array[end] = tmp;
        }
        return;
    }

    while(low < high)
    {
        while (low < high && array[high] >= pivot)
            high --;

        array[low] = array[high];

        while (low < high && array[low] <= pivot)
            low ++;

        array[high] = array[low];
    }
    array[low] = pivot;

    quick_sort(array, start, low - 1);
    quick_sort(array, low + 1, end);
}

