/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported
 * License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/14396742/important-but-non-fatal-log-messages-in-logging-frameworks-log4j-log4net-log4/14396983#14396929
 */

package com.example;

import org.apache.log4j.PropertyConfigurator;

public class Test {

   public static void main(String[] args) {
      PropertyConfigurator.configure("log4j.properties");

      Always.log("Starting up ...");

      System.out.println("Hello World");

      Always.log("App done.");
   }

}
