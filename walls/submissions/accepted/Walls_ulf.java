/* This is an example solution to the "Lifting Walls" problem from
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

import java.io.*;
import java.util.*;

public class Walls_ulf {
    static int x[], y[], A[];
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int l = sc.nextInt(), w = sc.nextInt(), n = sc.nextInt(), r = sc.nextInt();

        x = new int[n];
        y = new int[n];
        A = new int[n];
        int x0[] = {-l, l, 0, 0};
        int y0[] = {0, 0, -w, w};
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt()*2;
            y[i] = sc.nextInt()*2;
            A[i] = 0;
            for (int j = 0; j < 4; ++j) {
                int d2 = (x[i]-x0[j])*(x[i]-x0[j])+(y[i]-y0[j])*(y[i]-y0[j]);
                if (d2<=4*r*r)
                    A[i] = A[i]|(1<<j);
            }
        }
        int res = rec(0,0);
        if (res == 10)
            System.out.println("Impossible");
        else
            System.out.println(res);
    }
    static int rec(int mask, int depth) {
        if (mask == (1<<4)-1)
            return depth;
        if (depth == 4)
            return 10;
        int res = 10;
        for (int i = 0; i < x.length; ++i)
            res = Math.min(res,rec(mask|A[i],depth+1));
        return res;
    }
}
