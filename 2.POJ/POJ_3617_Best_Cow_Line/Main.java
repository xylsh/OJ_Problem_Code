import java.util.Scanner;

public class Main {
    public static void main(String[] args) {        
        new Fun().solve();
    }
}

class Fun{
    int n;
    char[] original;
    
    public void solve(){
        getInput();
        
        int i=0;     // i指向最前面
        int j=n-1;   // j指向最后面
        for(int k=0; k<n; k++){
            if( compare(i,j) ){
                System.out.print(original[i]);
                i++;
            }else{
                System.out.print(original[j]);
                j--;
            }
            if( (k+1)%80 == 0 ){
                System.out.println();
            }
        }
                
    }
    public boolean compare(int a,int b){
        if( a>b ){
            return true;
        }
        if( original[a]<original[b] ){
            return true;
        }else if( original[a]>original[b] ){
            return false;
        }else{
            return compare(++a,--b);
        }
    }
    public void getInput(){
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        original = new char[n];
        for(int i=0; i<n; i++){
            original[i] = in.next().charAt(0);
        }
        in.close();
    }
}
