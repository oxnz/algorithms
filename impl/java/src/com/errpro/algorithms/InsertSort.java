package com.errpro.algorithms;

import com.errpro.utils.array;

public class InsertSort {

	public static void insertSort(int a[]) {
		for (int i = 1; i < a.length; ++i) {
			for (int j = i; j > 0 && a[j] < a[j-1]; --j) {
				array.swap(a, j, j-1);
			}
		}
	}
	
}
