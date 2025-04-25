import java.io.*;
import java.util.Scanner;

public class FileStats {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the file name (with path if needed): ");
        String fileName = scanner.nextLine();

        int charCount = 0;
        int wordCount = 0;
        int lineCount = 0;

        try {
            File file = new File(fileName);
            Scanner fileScanner = new Scanner(file);

            while (fileScanner.hasNextLine()) {
                String line = fileScanner.nextLine();
                lineCount++;

                charCount += line.length();

                String[] words = line.trim().split("\\s+"); 
                if (!line.trim().isEmpty()) {
                    wordCount += words.length;
                }
            }

            fileScanner.close();

            System.out.println("\nFile Statistics:");
            System.out.println("Number of lines     : " + lineCount);
            System.out.println("Number of words     : " + wordCount);
            System.out.println("Number of characters: " + charCount);

        } catch (FileNotFoundException e) {
            System.out.println("File not found. Please check the file name and path.");
        }

        scanner.close();
    }
}
