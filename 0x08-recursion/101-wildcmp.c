/**
 * wildcmp - Compares two strings considering the * wildcard
 *
 * @s1: The first string to be compared
 * @s2: The second string to be compared, which can contain * wildcard
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	/* If both strings are empty, they are considered equal */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If the current character of s2 is '*', we can either match or skip it */
	if (*s2 == '*')
	{
		/* If we skip '*', we can try to match the rest of s2 with s1 */
		if (*(s2 + 1) != '\0' && *s1 == '\0')
			return (0);

		/* We try to match the rest of s1 with s2, considering the current '*' as empty */
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	}

	/* If the current characters of both strings match, we continue comparing */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* If the characters don't match, the strings can't be identical */
	return (0);
}
