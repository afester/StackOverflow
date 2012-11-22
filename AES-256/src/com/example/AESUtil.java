/**
 * This work is licensed under the Creative Commons Attribution 3.0 Unported 
 * License. To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
 * Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 */

/* StackOverflow reference:
 * http://stackoverflow.com/questions/13467343/want-to-use-aes-256-cbc-with-32-bytes-but-it-shows-java-security-invalidalgorith
 */

package com.example;

import java.io.UnsupportedEncodingException;
import java.security.Key;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.spec.AlgorithmParameterSpec;

import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

/* mock class - does not do any actual encoding/decoding */
class Base64 {
   public static String encodeBytes(byte[] doFinal) {
      return new String(doFinal);
   }

   public static byte[] decode(String src) {
      return src.getBytes();
   }
}

public class AESUtil {
   private static String ENCRYPTION_IV;
   private static String ENCRYPTION_KEY;

/* BEGIN code from question */
   public static void setENCRYPTION_IV(String ENCRYPTION_IV) {
      AESUtil.ENCRYPTION_IV = ENCRYPTION_IV;
   }

   public static void setENCRYPTION_KEY(String ENCRYPTION_KEY) {
      AESUtil.ENCRYPTION_KEY = ENCRYPTION_KEY;
   }

   public static String encrypt(String src) {
      try {
         Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
         cipher.init(Cipher.ENCRYPT_MODE, makeKey(), makeIv());
         return Base64.encodeBytes(cipher.doFinal(src.getBytes()));
      } catch (Exception e) {
         throw new RuntimeException(e);
      }
   }

   public static String decrypt(String src) {
      String decrypted = "";
      try {
         Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
         cipher.init(Cipher.DECRYPT_MODE, makeKey(), makeIv());
         decrypted = new String(cipher.doFinal(Base64.decode(src)));
      } catch (Exception e) {
         throw new RuntimeException(e);
      }
      return decrypted;
   }

   static AlgorithmParameterSpec makeIv() {
      try {
         return new IvParameterSpec(ENCRYPTION_IV.getBytes("UTF-8"));
      } catch (UnsupportedEncodingException e) {
         e.printStackTrace();
      }
      return null;
   }

   static Key makeKey() {
      try {
         MessageDigest md = MessageDigest.getInstance("SHA-256");
         byte[] key = md.digest(ENCRYPTION_KEY.getBytes("UTF-8"));
         return new SecretKeySpec(key, "AES");
      } catch (NoSuchAlgorithmException e) {
         e.printStackTrace();
      } catch (UnsupportedEncodingException e) {
         e.printStackTrace();
      }

      return null;
   }
/* END code from question */

   public static void main(String[] args) {
      AESUtil.setENCRYPTION_KEY("96161d7958c29a943a6537901ff0e913efaad15bd5e7c566f047412179504ffb");
    //AESUtil.setENCRYPTION_IV("d41361ed2399251f535e65f84a8f1c57");
      AESUtil.setENCRYPTION_IV("d41361ed2399251f");

      String encrypted = encrypt("Hello World");
      System.out.println(encrypted);
      System.out.println(decrypt(encrypted));
   }
}
