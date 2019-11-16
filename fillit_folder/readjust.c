
#include "fillit.h"
#include <stdio.h> // remove

int		board_size(size_t len)
{
	float		temp;
	float		sqrt;
	int			base;

	//printf("This is len %zu\n", len);
	base = len * 4;
	//printf("This is base %d\n", base);
    sqrt = base / 2;
    temp = 0;
	//printf("%d\n", base);
	while(sqrt != temp)
	{
		temp = sqrt;
	    sqrt = (base / temp + temp) / 2;
	}
	//printf("This is sqrt%f\n", sqrt);
	return (sqrt);
}

static char				*purify(char *adjusted, size_t total)
{
	char		*pure;
	size_t 		i;
	size_t		j;

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

static char 			*re_adjust(char *tblock, size_t len)
{
	char		*adjusted;
	size_t		i;
	size_t		j;
	size_t		c;

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
		(i % (len + 1) == 0) ? adjusted[i] = '\n' : 0;
		adjusted[i++] = tblock[j++];
	}
	while (i < (((len + 1) * len) + 1))
	{	
		adjusted[i] = '.';
		(i % (len + 1) == 0 && i != 0) ? adjusted[i] = '\n' : 0;
		i++;
	}
	adjusted[i] = '\0';
	return (adjusted = purify(adjusted, ((len + 1) * len)));
}

int main()
{
	char *tblock = "..#.\n###.\n....\n....\n";
	char *board7 = ".......\n.......\n.......\n.......\n.......\n.......\n.......\n";
	char *board10 = "..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n";
	//int len = 0;
	//int len2 = 0;
	//int total = 0;
	
	//printf("This is a tetris block\n");
	//printf("%s", tblock);
	//printf("This is a fresh board, which is too big\n");
	//printf("%s", board10);
	//while (board10[len] != '\n')
	//	len++;
	//while (board10[total])
	//	total++;
	//printf("This is total of empty board %d\n", total);
	//while (tblock[len2] != '\n')
	//	len2++;
	printf("SQRT of 9: %d\n", board_size(9));
	if (ft_strclen(board10, '\n') > ft_strclen(tblock, '\n'))
		tblock = re_adjust(tblock, board_size(9));
	printf("%s", tblock);
	return (0);
}