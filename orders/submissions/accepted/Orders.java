/* This is an example solution to the "Restaurant Orders" problem from
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

public class Orders {
    private static class Kattio extends PrintWriter {
        public Kattio(InputStream i) {
            super(new BufferedOutputStream(System.out));
            r = new BufferedReader(new InputStreamReader(i));
        }
        public Kattio(InputStream i, OutputStream o) {
            super(new BufferedOutputStream(o));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public boolean hasMoreTokens() {
            return peekToken() != null;
        }

        public int getInt() {
            return Integer.parseInt(nextToken());
        }

        public double getDouble() { 
            return Double.parseDouble(nextToken());
        }

        public long getLong() {
            return Long.parseLong(nextToken());
        }

        public String getWord() {
            return nextToken();
        }



        private BufferedReader r;
        private String line;
        private StringTokenizer st;
        private String token;

        private String peekToken() {
            if (token == null)
                try {
                    while (st == null || !st.hasMoreTokens()) {
                        line = r.readLine();
                        if (line == null) return null;
                        st = new StringTokenizer(line);
                    }
                    token = st.nextToken();
                } catch (IOException e) { }
            return token;
        }

        private String nextToken() {
            String ans = peekToken();
            token = null;
            return ans;
        }
    }

    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt();

        int c[] = new int[n];
        int prev[] = new int[30001];
        Arrays.fill(prev, -1);
        prev[0] = 0;
        for (int i = 0; i < n; i++)
        {
            c[i] = io.getInt();
            for (int j = 0; j + c[i] < 30001; j++)
                if (prev[j] != -1)
                {
                    if (prev[j] == n || prev[j + c[i]] != -1)
                        prev[j + c[i]] = n;
                    else
                        prev[j + c[i]] = i;
                }
        }

        int m = io.getInt();
        for (int i = 0; i < m; i++)
        {
            int d = io.getInt();
            if (prev[d] == n)
                io.println("Ambiguous");
            else if (prev[d] == -1)
                io.println("Impossible");
            else
            {
                Vector<Integer> res = new Vector<Integer>();
                while (d > 0)
                {
                    res.add(prev[d] + 1);
                    d = d - c[prev[d]];
                }

                Collections.reverse(res);
                for (int j = 0; j < res.size(); j++)
                {
                    io.print(res.elementAt(j));
                    if (j + 1 < res.size())
                        io.print(" ");
                    else
                        io.println();
                }
            }
        }
        io.close();
    }
}
