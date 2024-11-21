#include "get_next_line.h"

char *check_newlines(char *storage_buffer,size_t *old_len)
{
    size_t len;
    char *sub;

    len = 0;
    if (!storage_buffer || *old_len >= strlen(storage_buffer)){
        return NULL;
	}
    while(storage_buffer[*old_len + len] != '\n' && storage_buffer[*old_len + len] != '\0')
        len++;
    sub = ft_substr(storage_buffer,*old_len,len + 1);
    *old_len += len + 1;
    return sub;
}
int count_new_line(char *arr,int *len){
	int count;
	count = 0;
	while(arr[*len]){
		if(arr[*len] == '\n')

			count++;
		*len += 1 ;
	}
	return count;
}
char *read_allocate(char *reading_buffer,char *printing_buffer,int fd)
{
    static char *storage_buffer;
	static int len;
	static size_t old_len;
	ssize_t read_bytes;
	char * temp;

	while(1){
		reading_buffer = (char *)malloc((BUFFER_SIZE + 1 ) * sizeof(char));
		if(!reading_buffer)
			return NULL;
		read_bytes = read(fd,reading_buffer,BUFFER_SIZE);

		if (read_bytes < 0){
			free(reading_buffer);
			free(storage_buffer);
			free(printing_buffer);
			printing_buffer = NULL;
			storage_buffer = NULL;
			reading_buffer = NULL;
			len = 0;
			old_len = 0;
			return NULL;
		}
		reading_buffer[read_bytes] = '\0';

		temp = storage_buffer;
		storage_buffer = ft_strjoin(storage_buffer,reading_buffer);
		free(temp);
		free(reading_buffer);


		if(count_new_line(storage_buffer,&len) > 0 || read_bytes == 0){
			printing_buffer = check_newlines(storage_buffer,&old_len);
			if (!printing_buffer)
			{
				free(storage_buffer);
				storage_buffer = NULL;
			}
			break;
		}
	}
    return printing_buffer;
}

char *get_next_line(int fd)
{
    static char *reading_buffer;
    static char *printing_buffer;

    if (!reading_buffer){
        printing_buffer = read_allocate(reading_buffer,printing_buffer,fd);
        if(!printing_buffer){
            return NULL;
		}
    }
    return printing_buffer;
}

int main(){
    char *str;
    int fd = open("multiple_line_no_nl",O_RDONLY);
    while((str = get_next_line(fd)) != NULL){
        printf("%s",str);
    }
}