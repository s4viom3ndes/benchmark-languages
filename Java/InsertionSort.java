import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import java.util.stream.Collectors;
import java.io.FileNotFoundException;

// Average complexity: O(n^2)
// Worst case complexity: O(n^2)

public class InsertionSort {

    private static final int MAX_SIZE = 1000000;

    public static void main(String args[]) {
        String fileName = "dataset_95_sorted.txt";
        if (args.length != 0) {
            fileName = args[0];
        }

        try {
            int[] dataset = readDataset(fileName);

            long startTime = System.currentTimeMillis();
            insertionSort(dataset);
            long endTime = System.currentTimeMillis();

            long elapsedTime = endTime - startTime;

            System.out.println("Elapsed time: " + elapsedTime + " miliseconds");
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    // Read txt file (integers separated by new space)
    public static int[] readDataset(String filename) throws FileNotFoundException {
        File file = new File(filename);
        Scanner scanner = new Scanner(file);
        List<Integer> numbers = new ArrayList<>();
        while (scanner.hasNext()) {
            if (numbers.size() == MAX_SIZE) {
                break;
            }
            numbers.add(scanner.nextInt());
        }
        scanner.close();
        return numbers.stream().mapToInt(i -> i).toArray();
    }

    public static void insertionSort(int[] numbers) {
        for (int currentIndex = 1; currentIndex < numbers.length; currentIndex++) {
            int currentNumber = numbers[currentIndex];
            int previousIndex = currentIndex - 1;
            while (previousIndex >= 0 && numbers[previousIndex] > currentNumber) {
                numbers[previousIndex + 1] = numbers[previousIndex];
                previousIndex = previousIndex - 1;
            }
            numbers[previousIndex + 1] = currentNumber;
        }
    }
}