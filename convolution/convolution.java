public class convolution {
	public static double[] convolution(double a[], double b[]) {
		int len = a.length + b.length - 1;
		double ret[] = new double[len];
		for (int i = 0; i < len; ++i) {
			ret[i] = 0; // set zero before sum
			for (int j = 0; j < a.length; ++j) {
				if (j > i || j <= i - b.length)
					continue;
				ret[i] += a[j]*b[i-j]; // convolve: multiply and accumulate
			}
		}
		return ret;
	}
	public static void draw(double a[]) {
		for (int i = 0; i < a.length; ++i) {
			System.out.printf("%02.2f: ", a[i]);
			for (int j = 0; j < Math.abs(4*a[i]); ++j) {
				System.out.print('#');
			}
			System.out.println();
		}
	}
	public static void main(String[] args) {
		double a[] = {2, 12, 18, 20, 18, 12, 2};
		double b[] = {0.3333, 0.3333, 0.3333};
		double c[] = {0.01, 0.03, 0.05, 0.08, 0.12, 0.17, 0.22, 0.22, 0.17, 0.12, 0.08, 0.05, 0.03, 0.01};
		double f[] = {-0.3, 0.1, 0.4, 0.7, 0.4, 0.1, -0.3};
		double[] d = convolution(a, b);
		double[] e = convolution(a, c);
		System.out.println("Orig:");
		draw(a);
		System.out.println("Average:");
		draw(d);
		System.out.println("Convolution:");
		draw(e);
		System.out.println("Negtive convolution:");
		draw(convolution(a, f));
	}
}
