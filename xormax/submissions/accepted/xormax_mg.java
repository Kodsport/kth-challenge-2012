/* This is an example solution to the "Xor Maximization" problem from
 * KTH Challenge 2012, held on March 3, 2012.
 *
 * The solution is provided as-is, is not documented, and may be
 * generally difficult to read.
 *
 * This work by KTH CSC (http://www.csc.kth.se/) is licensed under a Creative
 * Commons Attribution-Share Alike 2.5 Sweden License
 * (http://creativecommons.org/licenses/by-sa/2.5/se/deed.en).  You are free to
 * redistribute it as you like as long as this license information is not
 * removed.
 */
// Solution to xormax by Mikael Goldmann

import java.util.StringTokenizer;
import java.io.*;

public class xormax_mg {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args)  throws Exception {
	long[] x = new long[63];
	// x[i] is a (maybe empty) linear combination of the longs in the input
	// where x[i] == 0 or (1<<i) <= x[i] < (1<<(i+1)).
	// If you think of x as a matrix it is triangular
	int n = Integer.parseInt(in.readLine().trim());
	StringTokenizer st = new StringTokenizer(in.readLine());
	while (n-->0) {
	    long y = Long.parseLong(st.nextToken());
	    for (int k=62; k >=0; --k)
		if (y >= (1L<<k)) {
		    if (x[k] == 0) {
			x[k] = y;
			break;
		    }
		    else
			y ^= x[k];
		}
	}
	// Greedy linear combination of the x[i] gives a miximal value
	long z = 0;
	for (int k=62; k >=0; --k)
	    if ((z ^ x[k]) > z) z ^= x[k];
	System.out.println(z);
    }
}
