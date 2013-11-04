
public class CountingSort {
    public static int[] countingSort(int[] A) {
        int[] B = new int[A.length];
        int max = A[0];
        for (int i = 1; i < A.length; ++i)
            if (max < A[i])
                max = A[i];
        countingSort(A, B, ++max);
        return B;
    }

    private static void countingSort(int[] A, int[] B, int k) {
        int[] C = new int[k];
        for (int i = 0; i < A.length; ++i)
            ++C[A[i]];
        for (int i = 1; i < k; ++i)
            C[i] += C[i-1];
        for (int i = A.length - 1; i >= 0; --i) {
            B[C[A[i]]-1] = A[i];
            --C[A[i]];
        }
    }
    public static void main(String[] argv) {
        int[] a = CountingSort.countingSort(new int[]{16, 4, 10, 12, 32, 55, 0,
                                                      99, 13, 88, 44});
        for (int i = 0; i < a.length; ++i)
            System.out.print(" "+a[i]);
        System.out.println();
    }
}
