import java.util.Scanner;
import java.math.BigInteger;

/* 
 * URL：http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=115&page=show_problem&problem=1275
 * 1. 设折射n次的方法数为f(n),记图中的直线从上到下依次为L1,L2,L3.
 * 2. 递推法。
 *    折射的方法有2类：
 *      第1类：第一次折射发生在L2。那么，下一次折射就只能发生L1,所以剩下还有n-2次折射机会，有f(n-2)种方法。
 *      第2类：第一次折射发生在L3。那么，下一次折射可能发生在L2或L1，并不能根据这一步确定下一步的折射位置，
 *                                       所以剩下还有f(n-1)种方法。
 *    综上，f(n) = f(n-1) + f(n-2),即fibonacci数列。
 * 3. n最大值为1000，即使用double也会溢出，要使用高精度运算。
 * 4. UVaOJ用java提交一定要把类名命名为Main。
 */

class Main{
    public static BigInteger []fibo = new BigInteger[1010];

    public static BigInteger getFibo(int n){  
        if( fibo[n] == null )
            fibo[n] = getFibo(n-1).add( getFibo(n-2) );
        return fibo[n];
    }

    public static void main(String []args){
        Scanner in = new Scanner(System.in);

        fibo[0] = BigInteger.ONE;
        fibo[1] = BigInteger.valueOf(2);

        int n;
        while( in.hasNextInt() ){  
            n = in.nextInt();
            System.out.println( getFibo(n).toString() );
        }

    }
}
