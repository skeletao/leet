int strStr(char* haystack, char* needle) {

	int i = 0, j = 0, len = 0;

	while (needle[i])
	{
		i++;
	}

	len = i;

	if (len == 0)
	{
		return 0;
	}

	i = 0;

	while (haystack[i+len-1])
	{
		if (haystack[i] == needle[0] )
		{
			j = 1;
			while (j < len)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
				j++;
			}
			if (j == len)
			{
				return i;
			}
		}
		i++;
	}

	return -1;
}