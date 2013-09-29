import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Test().fun();
    }
}

class Test{
    private int w,h;
    private char[][] tiles;
    private int sx,sy;       // start point
    private int result = 0;  // 计数

    //4个方向的移动向量
    private final int[] dx = { 1, 0, -1, 0 };
    private final int[] dy = { 0, 1, 0, -1 };
    
    public void fun(){
        Scanner cin = new Scanner(System.in);
        w = cin.nextInt();   //with
        h = cin.nextInt();   //height  
        
        while(true){
            if(w==0 || h==0){
                break;
            }
            
            tiles = new char[h][w];

            //get input
            String temp;
            for(int i=0; i<h; i++){
                temp = cin.next();
                for(int j=0; j<w; j++){
                    tiles[i][j] = temp.charAt(j);
                    if( tiles[i][j]=='@' ){   //get start point
                        sx = i;
                        sy = j;
                    }  
                }
            }
            
            dfs(sx,sy);
            
            System.out.println(result);
            
            result = 0;
            
            w = cin.nextInt();   //with
            h = cin.nextInt();   //height  
        }

        cin.close();
    }
    
    //深度优先遍历
    public void dfs(int x,int y){
        tiles[x][y] = '#';

        result++;

        int tmpx,tmpy;
        for(int i=0; i<4; i++){
            tmpx = x + dx[i];
            tmpy = y + dy[i];
            if( tmpx>=0 && tmpx<h && tmpy>=0 && tmpy<w
                    && tiles[tmpx][tmpy]=='.' ){
                dfs(tmpx,tmpy);
            }
        }

    }
}

