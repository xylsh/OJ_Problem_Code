import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Test().solve();
    }
}

class Test{
    int n,m;
    char[][] field;
    int count;
        
    public void solve(){
        getInput();
        
        count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( field[i][j]=='W' ){
                    dfs(i,j);
                    count++;
                }
            }
        }
        
        System.out.println(count);
    }
    // 深度优先遍历
    public void dfs(int i,int j){
        field[i][j] = '.';     // 访问过的'w'改为'.'，避免重复访问
        
        // 访问该点周围8个方向上的点
        int ni,nj;
        for(int k=-1; k<2; k++){
            for(int l=-1; l<2; l++){
                ni = i+k;
                nj = j+l;
                if( ni>=0 && ni<n && nj>=0 && nj<m && field[ni][nj]=='W' ){
                    dfs(ni,nj);
                }
            }
        }
    }
    public void getInput(){
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        field = new char[n][m];
        String tmp;
        for(int i=0; i<n; i++){
            tmp = in.next();
            for(int j=0; j<m; j++){
                field[i][j] = tmp.charAt(j);
            }
        }
        in.close();
    }
}
