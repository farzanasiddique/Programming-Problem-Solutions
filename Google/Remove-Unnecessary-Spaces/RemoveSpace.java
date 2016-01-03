package practice;

public class RemoveSpace {
	public String solver(String input)
	{
		char[] result = new char[input.length()];
		int index = 0, numOfSpace = 0;
		for(char ch : input.toCharArray())
		{
			if(ch != ' ')
			{
				result[index++] = ch;
				numOfSpace = 0;
			}
			else
			{
				if(numOfSpace == 0)
					result[index++] = ch;
				numOfSpace++;
			}
		}
		return new String(result);
	}
}
