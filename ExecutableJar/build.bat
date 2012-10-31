@ECHO OFF
@REM
@REM This work is licensed under the Creative Commons Attribution 3.0 Unported 
@REM License. To view a copy of this license, visit 
@REM http://creativecommons.org/licenses/by/3.0/ or send a letter to Creative 
@REM Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.

@REM StackOverflow reference:
@REM http://stackoverflow.com/questions/13031057/java-application-does-not-work-properly-outside-ide

SET JDK_HOME="\Program Files\Java\jdk1.7.0_09"
SET JAVA=%JDK_HOME%\bin\java
SET JAVAC=%JDK_HOME%\bin\javac
SET JAR=%JDK_HOME%\bin\jar

rem Build
%JAVAC% -d bin -classpath %JDK_HOME%\jre\lib\plugin.jar src\com\example\Hello.java
%JAR% cvfm app.jar src\MANIFEST.MF -C bin .

rem Run from file system
echo "Running from file system ..."
%JAVA% -classpath %JDK_HOME%\jre\lib\plugin.jar;bin com.example.Hello

rem Run from jar file
echo "Running from jar file ..."
%JAVA% -classpath %JDK_HOME%\jre\lib\plugin.jar -jar app.jar
