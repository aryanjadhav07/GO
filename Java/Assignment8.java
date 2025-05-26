import java.util.*;

interface sortable{
    void sort(int arr[]);
}

class Bubblesort implements sortable{
    public void sort(int arr[]){
        int n = arr.length;
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
}

class Selectionsort implements sortable{
    public void sort(int arr[]){
        int n = arr.length;
        for(int i = 0; i < n-1; i++){
            int minIndex = i;
            for(int j = i+1; j < n; j++){
                if(arr[j] < arr[minIndex]){
                    minIndex = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

public class Assignment8{
    public static void printArray(int arr[]){
        for(int num : arr){
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int arr1[] = { 5,2,9,1,3};
        int arr2[] = { 8,4,6,7,0};

        sortable bubble = new Bubblesort();
        sortable selection = new Selectionsort();

        System.out.println("Bubble sort : ");
        bubble.sort(arr1);
        printArray(arr1);

        System.out.println("Selection sort : ");
        selection.sort(arr2);
        printArray(arr2);

    }
}