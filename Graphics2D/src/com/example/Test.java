/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported
 * License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/14274988/why-is-the-image-saved-so-small
 */

package com.example; 

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

public class Test {

    public static void main(String args[]) throws IOException{

        int width = 400, height = 400;
        Test plot = new Test();

        BufferedImage bi = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);

        Graphics2D g2d = bi.createGraphics();
        g2d.setPaint(Color.red);

//        g2d.scale(3.0,  3.0);

        g2d.draw(new Line2D.Double(0,0,0,150));
        g2d.draw(new Line2D.Double(0,150,150,150));
        g2d.draw(new Line2D.Double(150,150,150,0));
        g2d.draw(new Line2D.Double(150,0,0,0));

        ImageIO.write(bi, "PNG", new File("d:\\sample.PNG"));
    }
}