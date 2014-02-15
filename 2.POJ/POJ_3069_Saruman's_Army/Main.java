import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Test().solve();
    }
}

class Test{
    int range;
    int n;              // 军队数量
    int[] positions;    // 军队位置
    
    public void solve(){
        Scanner in = new Scanner(System.in);
        range = in.nextInt();
        n = in.nextInt();
        
        while( range!=-1 && n!=-1 ){
            positions = new int[n];
            for(int i=0; i<n; i++){
                positions[i] = in.nextInt();
            }
            Arrays.sort(positions);
            int count = 0;
            
            int i=0;
            while( i<n ){
                int start = positions[i];   // 起始位置
                i++;
                while( i<n && positions[i] <= start+range ){
                    i++;
                }
                int p = positions[i-1];     // 放stone的位置
                count++;
                while( i<n && positions[i] <= p+range ){
                    i++;
                }
            }
            System.out.println(count);
            
            range = in.nextInt();
            n = in.nextInt();           
        }
        in.close();

    }
}
