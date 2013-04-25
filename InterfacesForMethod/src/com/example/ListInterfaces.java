/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported
 * License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/16190642/how-do-i-find-the-java-interface-whose-method-is-implemented-in-a-given-class
 */

package com.example;


import java.lang.reflect.Method;
import java.util.HashSet;
import java.util.Set;

/**
 * Sample class/interface hierarchy with some methods
 */
interface A {
   void methodA();
}

interface B extends A {
   void methodB();
}

class C implements A, B {
   public void methodA() {
   }

   public void methodB() {
   }
}


/**
 * An InterfaceLister can be used to list all interfaces of a given class.
 */
class InterfaceLister {
   private Set<String> implementedInterfaces = new HashSet<>();

   private void traverse(Class<?> cls) {
      for (Class<?> c : cls.getInterfaces()) {
         implementedInterfaces.add(c.getName());
         traverse(c);
      }
   }

   public Set<String> getInterfaces(Class<?> cls) {
      implementedInterfaces.clear();
      traverse(cls);
      return implementedInterfaces;
   }

}


/**
 * A MethodQuery can be used to list all interfaces which declare a specific 
 * method.
 */
class MethodQuery {
   private Set<Class<?>> result = new HashSet<>();
   private String theMethodName;

   private void traverse(Class<?> cls) {
      for (Class<?> c : cls.getInterfaces()) {
         for (Method m : c.getDeclaredMethods()) {
            if (theMethodName.equals(m.getName())) {
               result.add(c);
            }
         }

         traverse(c);
      }
   }

   public Set<Class<?>> getInterfacesForMethod(Class<?> cls, String methodName) {
      result.clear();
      theMethodName = methodName;
      traverse(cls);
      return result;
   }
}

/**
 * Test code
 */
public class ListInterfaces {

   public static void main(String[] args) {
      InterfaceLister ifList = new InterfaceLister();

      Set<String> result1 = ifList.getInterfaces(C.class);
      System.out.println(result1);

      Set<String> result2 = ifList.getInterfaces(java.util.TreeSet.class);
      System.out.println(result2);

/*****************************************************************************/

      MethodQuery methodQuery = new MethodQuery();

      Set<Class<?>> result3 = methodQuery.getInterfacesForMethod(java.util.Vector.class, "addAll");
      System.out.println(result3);

      Set<Class<?>> result4 = methodQuery.getInterfacesForMethod(C.class, "methodA");
      System.out.println(result4);
   }

}
