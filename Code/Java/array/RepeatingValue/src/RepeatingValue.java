/**
 * Created by debarshighosh on 17/06/17.
 */
public class RepeatingValue {
    public static void printRepeating(int[] arr, int size){
        int div = size - 1;
        for (int i = 0; i < size; ++i)
            arr[arr[i] % div - 1] += div;
        for (int i = 0; i < div; i++) {
            if(arr[i] / div == 2)
                System.out.print((i + 1) + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr = {4, 2, 4, 5, 2, 3, 1};
        printRepeating(arr, arr.length);
    }
}
