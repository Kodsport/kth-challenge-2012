/* This is an example solution to the "Toilet Seat" problem from
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

public class Toilet {
    static boolean bool(int a)
    {
        if (a == 1)
            return true;
        return false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s = in.readLine();
        int n = s.length();

        boolean state[] = new boolean[3];
        for (int i = 0; i < 3; i++)
            state[i] = s.charAt(0) == 'D';

        int res[] = new int[3];
        for (int i = 1; i < s.length(); i++)
        {
            boolean cur = s.charAt(i) == 'D';
            for (int k = 0; k < 3; k++)
            {
                if (state[k] != cur)
                    res[k]++;
                state[k] = cur;

                if (k < 2)
                {
                    if (state[k] != bool(k))
                        res[k]++;
                    state[k] = bool(k);
                }
            }
        }

        for (int k = 0; k < 3; k++)
            System.out.println(res[k]);
    }
}
