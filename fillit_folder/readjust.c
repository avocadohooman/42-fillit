
#include "fillit.h"
#include <stdio.h>

char			*purify(char *adjusted, int total)
{
	char	*pure;
	int 	i;
	int		j;

	i = 0;
	j = 0;
	pure = (char*)malloc(sizeof(char) * total + 1);
	while (adjusted[i])
	{
		if (adjusted[i] == '\n' && adjusted[i + 1] == '\n')
			i++;
		pure[j] = adjusted[i];
		i++;
		j++; 
	}
	pure[j] = '\0';
	return (pure);
}

char 			*re_adjust(char *tblock, int len)
{
	char	*adjusted;
	int		i;
	int		j;
	int		c;

	i = 0;
	j = 0;
	c = 0;
	adjusted = (char *)malloc(sizeof(char) * ((len + 1) * len) + 1);
	while (tblock[j])
	{
		while (tblock[j] == '\n' && c < (len - 4))
		{
			adjusted[i] = '.';
			i++;
			c++;
		}
		c = 0;
		if (i % (len + 1) == 0)
			adjusted[i] = '\n';
		adjusted[i++] = tblock[j++];
	}
	while (i < ((len + 1) * len))
	{	
		adjusted[i] = '.';
		if (i % (len + 1) == 0)
			adjusted[i] = '\n';
		i++;
	}
	//adjusted[i] = '\0';
	return (adjusted = purify(adjusted, ((len + 1) * len)));
}

int main()
{
	char *tblock = ".#..\n###.\n....\n....\n";
	char *board7 = ".......\n.......\n.......\n.......\n.......\n.......\n.......\n";
	char *board10 = "..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n";
	int len = 0;
	int len2 = 0;
	int total = 0;
	
	printf("This is a tetris block\n");
	printf("%s\n", tblock);
	printf("This is a fresh board, which is too big\n");
	printf("%s\n", board7);
	while (board7[len] != '\n')
		len++;
	while (board7[total])
		total++;
	//printf("This is total of empty board %d\n", total);
	while (tblock[len2] != '\n')
		len2++;
	if (len > len2)
		tblock = re_adjust(tblock, len);
	printf("This is an adjusted tetris block\n");
	printf("%s\n", tblock);
	return (0);
}