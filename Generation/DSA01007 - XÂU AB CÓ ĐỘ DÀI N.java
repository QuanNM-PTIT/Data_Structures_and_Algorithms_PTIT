// Created by Nguyễn Mạnh Quân

import java.util.Scanner;

public class code
{
    static int n;
    static char[] a = new char[20];

    static void Try(int idx)
    {
        if(idx > n)
        {
            for(int j = 1; j <= n; ++j)
                System.out.print(a[j]);
            System.out.print(" ");
            return;
        }
        for(char j = 'A'; j <= 'B'; ++j)
        {
            a[idx] = j;
            Try(idx + 1);
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            n = sc.nextInt();
            Try(1);
            System.out.println();
        }
    }
}
