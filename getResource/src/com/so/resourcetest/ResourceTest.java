package com.so.resourcetest;

import java.net.URL;

public class ResourceTest {

    public static void main(String[] args) {
        ResourceTest app = new ResourceTest ();
    }

    public ResourceTest () {
        doClassLoaderGetResource ("/subdir/readme.txt");
        doClassGetResource ("/subdir/readme.txt");
        doClassLoaderGetResource ("subdir/readme.txt");
        doClassGetResource ("subdir/readme.txt");
    }

    private void doClassLoaderGetResource (String sPath) {
        URL url  = getClass().getClassLoader().getResource(sPath);
        if (url == null)
            System.out.println("ClassLoader.getResource(" + sPath + "): NULL");
        else
            System.out.println("ClassLoader.getResource(" + sPath + "): SUCCESS");
    }

    private void doClassGetResource (String sPath) {
        URL url  = getClass().getResource(sPath);
        if (url == null)
            System.out.println("Class.getResource(" + sPath + "): NULL");
        else
            System.out.println("Class.getResource(" + sPath + "): SUCCESS");
    }
}
