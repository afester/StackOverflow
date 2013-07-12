package ghostclickerredux;

public class GlobbyMouse {

      {
         System.loadLibrary("MouseHooker");
      }
     
      public native int getMouseX();
      public native int getMouseY();
      public native int whatButton();

      public void run() {
         System.err.println("getMouseX():" + getMouseX());
         System.err.println("getMouseY():" + getMouseX());
         System.err.println("whatButton():" + whatButton());
      }

      public static void main(String[] args) {
         new GlobbyMouse().run();
      }
}
