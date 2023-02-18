/* This is an example solution to the "Three Digits" problem from
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
import java.util.Scanner;
import java.lang.Math;

public class ThreeDigits {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());

        long p52 = 0, rest = 1;
        for (int i = 2; i <= n; i++)
        {
            int j = i;
            while (j % 2 == 0)
            {
                j /= 2;
                p52++;
            }
            while (j % 5 == 0)
            {
                j /= 5;
                p52--;
            }
            rest = rest * j % 1000;
        }

        for (int i = 0; i < p52; i++)
            rest = rest * 2 % 1000;
        if (n <= 6)
            System.out.println(rest);
        else
            System.out.format("%03d\n", rest);
    }
}
