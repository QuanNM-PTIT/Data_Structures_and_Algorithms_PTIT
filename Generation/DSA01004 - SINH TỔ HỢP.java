// Created by Nguyễn Mạnh Quân

import java.util.Scanner;

public class code
{
    static int n, k;
    static int[] a = new int[20];

    static void Try(int i, int idx)
    {
        if(idx > k)
        {
            for(int j = 1; j <= k; ++j)
                System.out.print(a[j]);
            System.out.print(" ");
            return;
        }
        for(int j = i; j <= n; ++j)
        {
            a[idx] = j;
            Try(j + 1, idx + 1);
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            n = sc.nextInt();
            k = sc.nextInt();
            Try(1, 1);
            System.out.println();
        }
    }
}
