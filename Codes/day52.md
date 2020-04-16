# Day 52 Code

Simple I/O java v1

```java

import java.util.*;
import java.io.*;

class Main
{
    public static void main(String [] args) throws Exception
    {
        BufferedReader br = 
             new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        PrintWriter pw = new PrintWriter(System.out);

        for (int i = 0; i < 3; i++)
            pw.println(br.readLine());

        pw.close();
    }
}
``` 
Simple I/O java v2

```java

import java.util.*;
import java.io.*;

class Main
{
    public static void main(String [] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 3; i++)
        {
            System.out.println(sc.nextInt());
        }
    }
}

```