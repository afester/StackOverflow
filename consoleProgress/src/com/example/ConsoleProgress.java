/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported
 * License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/14458609/java-display-changing-progress-on-command-line
 */

package com.example;

public class ConsoleProgress {

   public static void main(String[] argv) throws InterruptedException {
      int[] step = {10,20,300,400,50};
      
      // Backspace approach (note: output is messed up if the numbers have 
      // a length other than 3 characters)
      System.out.print("$> processed < ");
      for (int i : step) {
         System.out.print(i + " > records.\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
         Thread.sleep(500);
      }

      System.out.println();
      System.out.println();

      // Newline approach:
      for (int i : step) {
         System.out.print("$> processed < " + i + " > records.\r");
         Thread.sleep(500);
      }
   }
}
