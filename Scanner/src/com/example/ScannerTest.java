/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13374826/java-scanner-does-not-wait-for-input
 */

package com.example;

import java.util.Scanner;
import java.util.Set;
import static java.lang.System.out;

public class ScannerTest {
    int p = 0;
    String name = "Test";

    public void startGame() {
        out.println("Player1: 1 for dumb player, 2 for smart player, 3 for human player.");
        Scanner scan = new Scanner(System.in);
        p = scan.nextInt();

        out.println("Result1: " + p);

        out.println("Player2: 1 for dumb player, 2 for smart player, 3 for human player.");
        p = scan.nextInt();

        out.println("Result2: " + p);

        // scan.close();
    }

    public int findBestMove(Set<Integer> moves, Object /*Board*/ b) {
        out.println("Player " +name+ ", select a column from 1-7: ");
        Scanner scan = new Scanner(System.in);
        int move = scan.nextInt(); //  <--here it should wait for input, but does not!
        // scan.close();

        out.println("Move: " + move);

        return 0;
    }

    public void run() {
        startGame();
        findBestMove(null, null);
    }

    public static void main(String[] args) {
        ScannerTest st = new ScannerTest();
        st.run();
    }
}
