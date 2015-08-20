package com.errpro.test;

import com.errpro.algorithms.InsertSort;
import com.errpro.utils.io;

public class Test {

	public static void main(String[] args) {
		int[] a = {1, 3, 2, 4, 0, 8, 5, 9, 7, 6};
		io.print(a);
		InsertSort.insertSort(a);
		io.print(a);
	}
}
