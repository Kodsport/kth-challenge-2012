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

public class Xormax2 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        Vector<Long> a = new Vector<Long> ();
        String s[] = in.readLine().split(" ");
        for (int i = 0; i < n; ++i)
            a.add(Long.parseLong(s[i]));

        long res = 0;
        for (int b = 60; b >= 0; --b)
        {
            for (int i = 0; i < a.size(); i++)
                if (a.get(i) >= 1L<<b)
            {
                Long cur = a.get(i);
                if ((res & 1L<<b) == 0)
                    res ^= cur;
                for (int j = 0; j < a.size(); j++)
                    if (a.get(j) >= 1L<<b)
                        a.set(j, a.elementAt(j) ^ cur);
                a.remove(i);
                break;
            }
        }
        System.out.println(res);
    }
}
