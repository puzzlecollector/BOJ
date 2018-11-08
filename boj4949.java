import java.util.*; 
import java.io.*; 
public class boj4949{ // change to public class Main for submission. 
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);  
		String strLine; // read line by line
		while ((strLine = sc.nextLine()) != null){
			if (strLine.equals(".")) break; 
			Stack<Character> stack = new Stack<>();    
			boolean cannot = false; 
			for (int i = 0; i < strLine.length(); i++){
				if (strLine.charAt(i) == '(' || strLine.charAt(i) == '['){
					stack.push(strLine.charAt(i)); 
				}else if (strLine.charAt(i) == ')'){
					if (stack.isEmpty()){
						cannot = true;  
						System.out.println("no"); 
						break; 
					}else if (stack.peek() == '('){
						stack.pop(); 
					}else{
						cannot = true; 
						System.out.println("no"); 
						break; 
					}
				}else if (strLine.charAt(i) == ']'){
					if (stack.isEmpty()){
						cannot = true; 
						System.out.println("no"); 
						break; 
					}else if (stack.peek() == '['){
						stack.pop(); 
					}else{
						cannot = true; 
						System.out.println("no"); 
						break; 
					}
				}
			}
			if (!cannot){
				if (stack.isEmpty()) System.out.println("yes");  
				else System.out.println("no"); 
			}  
		}
	}
}
