#include<stdio.h>
#include<stdbool.h>

int length(char* in)
{
	int i=0;
	while(in[i] != '\0')
		i++;
	return i+1;
}

int main()
{
	char regex[1000];
	printf("Enter the regular expression (use only * and +): ");
	fgets(regex,1000,stdin);
	
    printf("\nThe generated NFA is: ");
	char ch = regex[0];
	int index = 0,state_no=0;
	
	while(regex[index] != '\0')
	{
		if(regex[index] >= 'a' && regex[index] <= 'z')
		{
			if(regex[index+1] == '*')
			{
				printf("%d-%c+-",state_no,regex[index]);
				state_no++;
				index++;
			}
			else if(regex[index+1] == '+')
			{
				printf("%d-%c-%d-%c+-",state_no,regex[index],state_no+1,regex[index]);
				state_no+=1;
				index++;
			}
			else
				printf("%d-%c-",state_no++,regex[index]);
			index++;
		}
		else
			break;
	}
	
	printf("\nEnter string : ");
	char input[1000];
	fflush(stdin);
	fgets(input,1000,stdin);
	
	int i_r=0,i_i=0;
	bool accept=true;
	int regex_n = length(regex), input_n = length(input);
	
	while(i_i < input_n && i_r < regex_n)
	{
		if(regex[i_r+1] == '*')
		{
			while(1)
			{
				if(regex[i_r] == input[i_i])
					i_i++;
				else 
					break;
			}
			i_r+=2;
		}	
		else if(regex[i_r+1] == '+')
		{
			if(regex[i_r] != input[i_i])
			{	
				accept = false;
				break;
			}
			i_i++;
			while(1)
			{
				if(regex[i_r] == input[i_i])
					i_i++;
				else 
					break;
			}
			i_r+=2;
		}
		else if(regex[i_r] == input[i_i])
		{
			i_r++;
			i_i++;
		}
		else 
		{
			accept = false;
			break;
		}
	}
	
	if(accept){
        printf("String Accepted.\n");
    }else{
        printf("String Rejected.\n");
    } 

    return 0;

}