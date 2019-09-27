#include <stdio.h>
#include <string.h>

static int    dose_it_me(void *a, const void *b, size_t n)
{
    size_t    i;
    size_t    j;
    
    i = 0;
    j = 0;
    while (i <= n)
    {
        while (j <= n)
        {
            if (&a[i] == &b[j])
                return (0);
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}

void        *ft_memccpy(void *out, const void *in, int c, size_t n)
{
    char    *a;
    char    *b;
    size_t    i;
    
    a = (char *)out;
    b = (char *)in;
    i = 0;
    if (n == 0 || dose_it_me(out, in, n) == 0)
        return (NULL);
    while (i < n)
    {
        a[i] = b[i];
        if (a[i] == (char)c)
            return (a + i + 1);
        i++;
    }
    return (NULL);
}

int		main(void)
{
	unsigned char	a[] = "p\200rivet_mir";
//	char	b[] = "vesna";
	unsigned char	*temp;
//	char	c = '\200';
//	unsigned char	h = '\200';

	temp = &a[5];
	printf("\n##### IT WAS BEFORE #####\n");
	printf("%s\n%s\n", a, temp);
	printf ("\nMEMCCPY return: %s\n", memccpy(temp, a, '\200', 3));
	printf("\n##### BECAME  AFTER #####\n");
//	printf("%d %d\n", c, h);
	printf("%s\n%s\n", a, temp);

	unsigned char    c[] = "p\200rivet_mir";
//	char    d[] = "vesna";
	unsigned char	*tmp;

	tmp = &c[5];
	printf("\n##### IT WAS BEFORE #####\n");
    printf("%s\n%s\n", c, tmp);
	printf ("\nFT_MEMCCPY return: %s\n", ft_memccpy(tmp, c, '\200', 3));
	printf("\n##### BECAME  AFTER #####\n");
//  printf("%d %d\n", c, h);
	printf("%s\n%s\n", c, tmp);

	
	return (0);
}
