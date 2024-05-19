import java.util.Scanner;

public class Main 
{
	
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int P = input.nextInt();
		for(;P>0;P--)
			{
				int num = input.nextInt();
				String enter = input.nextLine();
				String line = input.nextLine();
				
				System.out.print(num);
				System.out.print(" ");
				System.out.print(countWord(line,"TTT"));
				System.out.print(" ");
				System.out.print(countWord(line,"TTH"));
				System.out.print(" ");
				System.out.print(countWord(line,"THT"));
				System.out.print(" ");
				System.out.print(countWord(line,"THH"));
				System.out.print(" ");
				System.out.print(countWord(line,"HTT"));
				System.out.print(" ");
				System.out.print(countWord(line,"HTH"));
				System.out.print(" ");
				System.out.print(countWord(line,"HHT"));
				System.out.print(" ");
				System.out.print(countWord(line,"HHH"));
				System.out.println();
				
			}
	}
	
	public static int countWord(String str,String search)
	{
		int len = search.length();
		int result = 0;
		int start = str.indexOf(search);
		while (start != -1)
		{
			result++;
			start = str.indexOf(search,start+1);
		}
		return result;	
	}
	
}
