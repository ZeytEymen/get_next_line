#include <stdio.h>

void sayaciArttir() {
    // static değişken tanımlanır ve sadece bu fonksiyon içinde görünür.
    int sayac = 0;

    // Sayaç her çağrıldığında arttırılır.
    sayac++;

    // Son değeri ekrana yazdırılır.
    printf("Sayaç Değeri: %d\n", sayac);
}

int deneme(char *str)
{
    if (str == "bir")
    {
        return(1);
    }
    else if (str == "iki")
    {
        return(2);
    }
    return 0;
    
}

int main()
{
    int a = deneme("bir");
    printf("%d", a);
}


// char *ft_write_and_next_line(char *str, int i)
// {
// 	int line_index;
// 	char *line;
// 	char *next_line;
// 	int c = 0;
// 	while ((str[c] && str[c] != '\n') && i == 0)
// 		c++;
// 	if (str[c] == '\0' && i == 0)
// 	{
// 			free(str);
// 			return (NULL);
// 	}
// 	if (!str[c] && i == 1)
// 	{
// 		free(next_line);
// 		return (NULL);
// 	}
		
// 	line_index = ft_strchr(str,'\n') - str + 1;
// 	next_line = ft_substr(str,line_index,ft_strlen(str) - line_index);
// 	line = ft_substr(str,0,line_index);
// 	if (i == 1)
// 	{
// 		free(next_line);
// 		return (line);
// 	}
// 	else
// 	{
// 		free(str);
// 		free(line);
// 		return (next_line);
// 	}
// }


// int main()
// {
//     int fd = open("metin.txt", O_RDONLY);
// 	char *str = get_next_line(fd);
// 	printf("%s",str );
// 	free(str);
// 	system("leaks a.out");
// 	// for (int x = 0; x <= 5; x++)
// 	// {
// 	// 	printf("%s",get_next_line(fd));
// 	// }

	
// }