package com.errpro.algorithms;

import com.errpro.utils.array;

public class BubbleSort {

	public static void sort(int[] a) {
		for (int i = 0; i < a.length-1; ++i) {
			for (int j = a.length-1; j > i; --j) {
				if (a[j] > a[j-1]) {
					array.swap(a, j, j-1);
				}
			}
		}
	}
	
}
