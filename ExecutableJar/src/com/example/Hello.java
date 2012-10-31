/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13031057/java-application-does-not-work-properly-outside-ide
 */

package com.example;

public class Hello {

	public static void main(String[] args) {
		System.out.println("Hello World");
		throw new sun.plugin.dom.exception.InvalidAccessException("Error");
	}
}
