# TowerSort : An efficient in-place sorting algorithm for linked lists of integers

The algorithm sorts the numbers by their bits starting from their least significant bit (LSB) and going to their most significant bit (MSB).
This algorithm works only with linked list structures, allowing insertions in constant time and easily manipulating the order of elements with pointers. This enables this algorithm to sort each level of bits in linear time complexity without taking any additional space.

The logic behind this algorithm is similar to LSD Radix Sort (base 2), but it doesn't use any buckets or counting sorting and instead sorts the list using manipulations of pointers.

- Time complexity (worst case) : `O(n*log2(k))` with `n` the size of the array and `k` the maximum number in the array.
- Space complexity : `O(1)`. If you're already working with a linked list and need to sort it in-place, the sorting process won't take any significant memory.

TowerSort works with any integer value (including negative values).

You don't need to know in advance the maximum value, the algorithm will know after each layer of sorting if it's necessary to go to the next level or not. This is why it is called Tower Sort.

------

This algorithm has been compared to other implementations and showed way better performances compared to QuickSort at the conditions of having values not too big (8~16 bits).
It is slower than RadixSort at the cost of having constant space complexity.

------

How to compile to test : `gcc -o TowerSortTest TowerSortTest.c -lm`

Execute : `./TowerSortTest <n> <range> <print?>`
This will test the sorting algorithm with a set `n` values randomly chosen in-between `-range` and `+range` (exclusive).
Put `1` as a third parameter to print the list before and after sorting.

Special note : I had the idea for this algorithm before knowing the existence of LSD Radix Sort.
