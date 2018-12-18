import java.util.*;
public class mergeSort{

  /**
   * Helper method to MergeSort to merge two double arrays.
   * @param array of doubles
   * @param array of doubles
   * @return array of doubles that contains all elements from both parameters given
   */
  private static double[] merge(double[] a, double[] b){
    double[] temp = new double[a.length + b.length];
    int i = 0, j = 0;
    for(int k = 0; k < temp.length; k++){
      if (i >= a.length) temp[k] = b[j++];
      else if(j >= b.length) temp[k] = a[i++];
      else if (a[i] <= b[j]) temp[k] = a[i++];
      else temp[k] = b[j++];
    }
    return temp;
  }

  /**
   * Merge Sort that takes one array of doubles.
   * @param array of doubles
   * @return sorted array of doubles
   */
  public static double[] mergeSort(double[] input){
    int length = input.length;
    if(length <= 1) return input;
    double[] a = new double[length/2];
    double[] b = new double[length - (length/2)];
    for(int i = 0; i < a.length; i++){
      a[i] = input[i];
    }
    for(int i = 0; i < b.length; i++){
      b[i] = input[i + length/2];
    }
    return merge(mergeSort(a), mergeSort(b));
  }

  /**
   * Checks to see if given array is sorted.
   * @param array of doubles
   * @return boolean as to whether array is sorted
   */
   private static boolean isSorted(double[] a){
     for(int i = 1; i < a.length; i++){
       if(a[i] < a[i-1]) return false;
     }
     return true;
   }

   public static void main(String[] args){
     Scanner scanner = new Scanner(System.in);

     System.out.println("Here's a randomly generated array of 50:");
     double[] given = new double[50];
     for(int i = 0; i < given.length; i++){
       given[i] = Math.random() * 100;
     }
     System.out.println(Arrays.toString(given));
     System.out.println("Here it is again, sorted:");
     System.out.println(Arrays.toString(mergeSort(given)));
  }




}
