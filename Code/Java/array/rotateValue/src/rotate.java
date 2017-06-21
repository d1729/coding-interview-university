/**
 * Created by debarshighosh on 10/06/17.
 */
public class rotate {
    public static void reverseArray(int[] arr, int start, int end){
        int i = start;
        int j = end - 1;
        while(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            ++i;
            --j;
        }
    }

    public static void rotate(int[] arr, int d){
        int n = arr.length;
        d %= n;
        reverseArray(arr, 0, d);
        reverseArray(arr, d, n);
        reverseArray(arr, 0, n);
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        rotate(arr, 2);
        for (int i :
                arr) {
            System.out.print(i+ " ");
        }
        System.out.println();
    }
}
