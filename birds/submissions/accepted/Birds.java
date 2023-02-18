/* This is an example solution to the "Birds on Wire" problem from
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
//Solution by Emma Enström

//Input: Length of wire, birds social distance, number of birds
//A line for each bird with an integer denoting how far from the first pole it is sitting.

import java.io.*;
import java.util.Arrays;

public class Birds{

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static int pole_dist = 6;
    static int L;
    static int D;
    static int N;

    public static void main(String[] args) throws IOException {
        Birds B = new Birds();
        int birds[] = B.readInput();
        Arrays.sort(birds);
        for (int i=0;i<N;i++) {
            System.err.println(birds[i]);
        }

        int added_birds = 0;
        if (!B.wireTooShort()) {
            System.err.println("Line was not too short.");
            if (N == 0) {
                added_birds += B.wireEmpty(birds);
                System.err.println("There were no birds in the beginning.");
            }
            else {
                System.err.println("Adding birds between birds.");
                added_birds += B.addEndpointBirds(birds);
                System.err.println("Adding birds at endpoints.");
                added_birds += B.addBirds(birds);
            }
        }


        // Test cases: Wire shorter than 12
        // Wire full
        // Wire empty

        System.out.println(added_birds);
    } 

    public int[] readInput() throws IOException {
        String[] rad1 = in.readLine().split("\\s+");
        L = Integer.parseInt(rad1[0]);
        D = Integer.parseInt(rad1[1]);
        N = Integer.parseInt(rad1[2]);

        int[] birds = new int[N];

        for (int i = 0; i<N; i++) {
            birds[i] = Integer.parseInt(in.readLine());
        }

        return birds;
    }

    public int wireEmpty(int[] birds) {
        return (int)(Math.max(Math.floor((L-2*pole_dist)/D)+1, 0));
    }

    public boolean wireTooShort() {
        return !((L-2*pole_dist)>=0);
    }

    public int addEndpointBirds(int[] birds) {
        double start_birds = Math.floor((birds[0]-pole_dist)/D);
        double end_birds = Math.floor((L-pole_dist-birds[N-1])/D);
        int birds_to_add_start = Math.max((int)start_birds, 0);
        int birds_to_add_end = Math.max((int)end_birds, 0);
        System.err.println("Adding "+ birds_to_add_start + " birds in the beginning.");
        System.err.println("Adding "+ birds_to_add_end + " birds near the end.");
        return birds_to_add_start+birds_to_add_end;
    }

    public int addBirds(int[] birds) {
        int birds_to_add = 0;
        int start, end;
        double q;
        for (int i = 1; i<N; i++) {
            start = birds[i-1];
            end = birds[i];
            q = Math.floor((end-start)/D);
            System.err.println("Quotient = "+q);
            birds_to_add += Math.max((int)q-1,0);
            System.err.println("Adding " +Math.max((int)q-1,0)+" birds between positions "+start+" and " +end+".");
        }
        return birds_to_add;
    }

}
