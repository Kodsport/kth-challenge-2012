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
//Solution by Lukáš Poláček (lukasP)

import java.io.*;
import java.util.*;
import java.lang.Math;

public class Xormax {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        String s[] = in.readLine().split(" ");
        int l = 60;
        BitSet w[] = new BitSet[l];
        for (int i = 0; i < l; ++i)
            w[i] = new BitSet(n + l);

        for (int i = 0; i < n; ++i)
        {
            long a = Long.parseLong(s[i]);
            for (int j = 0; j < l; ++j)
                w[l - j - 1].set(i, (a & (1L << j)) > 0);
        }
        for (int p = 0; p < l; p++)
            w[p].set(n + p, true);

        int v = n + l;
        boolean val[] = new boolean[l];
        for (int p = 0; p < l; p++)
        {
            int u = -1;
            for (int i = 0; i < v; i++)
                if (w[p].get(i))
            {
                u = i;
                break;
            }

            if (u < n)
                val[p] = true;
            else
                for (int i = n; i < n + p; i++)
                    val[p] ^= w[p].get(i);
            w[p].set(n + p, val[p]);
            for (int j = p + 1; j < l; j++)
                if (w[j].get(u))
                    w[j].xor(w[p]);
        }

        long res = 0;
        for (int p = 0; p < l; p++)
            res = 2 * res + (val[p] ? 1 : 0);
        System.out.println(res);
    }
}
