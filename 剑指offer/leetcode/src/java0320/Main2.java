package java0320;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String[] rowArr = input.next().split(";");
        int[][] arr = new int[rowArr.length][rowArr[0].split(",").length];
        for (int i=0;i<rowArr.length;i++){
            String[] temp = rowArr[i].split(",");
            for (int j=0;j<temp.length;j++){
                arr[i][j] = Integer.parseInt(temp[j]);
            }
        }
        System.out.println(dfs(arr));
    }

    static int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
    static int row,col;
    public static int dfs(int[][] arr){
        row = arr.length;
        col = arr[0].length;
        if (arr[0][0]==0||arr[row-1][col-1]==0)return 0;
        Queue<int[]> queue = new LinkedList<>();
        arr[0][0] = 1;
        queue.add(new int[]{0,0});
        while (!queue.isEmpty()&&arr[row-1][col-1]==1){
            int[] temp = queue.remove();
            int length = arr[temp[0]][temp[1]];
            for (int i=0;i<4;i++){
                int newX =temp[0] + dir[i][0];
                int newY = temp[1] + dir[i][1];
                if (inGrip(newX,newY)&&arr[newX][newY]==1){
                    queue.add(new int[]{newX,newY});
                    arr[newX][newY] = length+1;
                }
            }
        }
        return arr[row-1][col-1]==0?0:arr[row-1][col-1];
    }

    private static boolean inGrip(int newX, int newY) {
        return newX>=0&&newX<row&&newY>=0&&newY<col;
    }
}
