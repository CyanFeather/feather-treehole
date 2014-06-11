/**
 * helpers.h
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n, bool bSorted);

/**
 * Sorts array of n values(from low to high).
 */
void quick_sort(int values[], int low, int high);
