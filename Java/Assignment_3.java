public class Assignment_3{

    public static void main(String[] args) {
        String s1 = "    Hey Aryan    ";
        String s2 = "Hey Aryan";
    
        char c = s1.charAt(4);
        System.out.println("Character at index 4 : " + c);
    
        int result = s1.compareTo(s2);
        System.out.println("Comparison result : " + result);
    
        String concat_String = s1.concat(s2);
        System.out.println("Conacatenated String is " + concat_String);
    
        boolean result1 = s1.equals(s2);
        System.out.println("The result is : " + result1);
    
        String replace_String = s1.replace('n', 'a');
        System.out.println("Replaced String is : " + replace_String);
    
        String[] words = s1.split("\\s+");
        System.out.println("Word after splitting are : ");
    
        for(String word : words){
            System.out.println(word);
        }
    
        String trim_String = s1.trim();
        System.out.println("Trimmed String is : " + trim_String);
    }
    
    }