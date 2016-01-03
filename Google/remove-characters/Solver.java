package practice;

public class Solver {
	public String removeCharacters(String input)
	{
		char[] result = new char[input.length()];
		int index = 0, count = 0;
		for(char ch : input.toCharArray())
		{
			if(ch != 'b')
			{
				if(count == 1)
				{
					if(ch != 'c')
					{
						result[index++] = 'a';
						result[index++] = ch;
					}
					count = 0;
				}
				else
				{
					if((ch == input.charAt(input.length()-1) && ch == 'a') || ch != 'a')
						result[index++] = ch;
					else
						count = 1;
				}
			}
		}
		return new String(result);
	}
}
