/* This is an example solution to the "Pub-lic Good" problem from
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

public class Pubs {
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
        int n = io.getInt(), m = io.getInt();

        Vector<LinkedList<Integer> > g = new Vector<LinkedList<Integer>> ();
        for (int i = 0; i < n; i++)
            g.add(new LinkedList<Integer>());

        for (int i = 0; i < m; i++)
        {
            int a, b;
            a = io.getInt();
            b = io.getInt();
            a--; b--;
            g.elementAt(a).add(b);
            g.elementAt(b).add(a);
        }

        for (int i = 0; i < n; i++) if (g.elementAt(i).size() == 0)
        {
            io.println("Impossible");
            io.close();
            return;
        }

        LinkedList<Integer> q = new LinkedList<Integer> ();
        boolean seen[] = new boolean[n], col[] = new boolean[n];
        for (int i = 0; i < n; i++) if (!seen[i])
        {
            seen[i] = true;
            for (q.add(i); q.size() > 0; q.removeFirst())
            {
                int u = q.getFirst();
                for (Integer j : g.elementAt(u))
                    if (!seen[j])
                    {
                        q.add(j);
                        col[j] = !col[u];
                        seen[j] = true;
                    }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (col[i])
                io.print("house");
            else
                io.print("pub");
            if (i + 1 < n)
                io.print(" ");
            else
                io.println();
        }
        io.close();
    }
}
