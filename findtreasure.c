#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100



int** find_treasure(int** sub_matrix,int** key,int** map,int key_row_size,int key_column_size,FILE* output)
{	
	static int current_i=0,current_j=0;
	int center_i,center_j;
	int i=0,j=0;
	int center=(key_row_size/2);
	center_i=current_i+center;
	center_j=current_j+center;
	int result_of_mul=0;
	int mod=0;

	for(i=0;i<key_row_size;i++)
	{
		for(j=0;j<key_column_size;j++)
		{ 
			result_of_mul=result_of_mul+(sub_matrix[i][j]*key[i][j]);
		}
	}
	//finding mod
	mod=result_of_mul%5;
	
	//printing in the output file
	fprintf(output,"%d,%d:%d\n",center_i,center_j,result_of_mul);
	
	//we checking every possible situation			
	if(mod==0)
	{	
		return sub_matrix;
	}
	else if(mod==1)
	{	
		int zero_counter=0;
		for(i=0;i<key_column_size;i++)
		{
			if(sub_matrix[0][i]==0)
			{
				zero_counter++;
			}
		}
		if(zero_counter==key_row_size)
		{
			current_i+=key_column_size;
			for(i=0;i<key_row_size;i++)
			{
				for(j=0;j<key_column_size;j++)
				{
					sub_matrix[i][j]=map[current_i][current_j++];
				}
				current_j-=key_column_size;
				current_i+=1;
			}
			current_i-=key_column_size;
			return find_treasure(sub_matrix,key,map,key_row_size,key_column_size,output);
		}
		else{
			current_i-=key_column_size;
				for(i=0;i<key_row_size;i++)
				{
					for(j=0;j<key_column_size;j++)
					{
						sub_matrix[i][j]=map[current_i][current_j++];
					}
					current_i+=1;
					current_j-=key_column_size;
				}
				current_i-=key_column_size;
				return find_treasure(sub_matrix,key,map,key_row_size,key_column_size,output);
	
			}		
	}
	else if(mod==2)
	{	
		int zero_counter=0;
		for(i=0;i<key_column_size;i++)
		{
			if(sub_matrix[key_row_size-1][i]==0)
			{	
				zero_counter++;
			}
		}
		if(zero_counter==key_row_size)
		{	
			current_i-=key_column_size;
			for(i=0;i<key_row_size;i++)
			{
				for(j=0;j<key_column_size;j++)
				{
					sub_matrix[i][j]=map[current_i][current_j++];
				}
				current_i+=1;
				current_j-=key_column_size;
			}
			current_i-=key_column_size;
			return find_treasure(sub_matrix,key,map,key_row_size,key_column_size,output);
		}
	 	else{
			current_i+=key_column_size;
			for(i=0;i<key_row_size;i++)
			{
				for(j=0;j<key_column_size;j++)
				{
					sub_matrix[i][j]=map[current_i][current_j++];
				}
				current_j-=key_column_size;
				current_i+=1;
			}
			current_i-=key_column_size;
			return find_treasure(sub_matrix,key,map,key_row_size,key_column_size,output);
			}
	}	
	else if(mod==3)
	{	
		int zero_counter=0;
		for(i=0;i<key_column_size;i++)
		{
			if(sub_matrix[i][key_row_size-1]==0)
			{
				zero_counter++;
			}
		}
		if(zero_counter==key_row_size)
		{	
			current_j-=key_column_size;
			for(i=0;i<key_row_size;i++)
			{
				for(j=0;j<key_column_size;j++)
				{
				sub_matrix[i][j]=map[current_i][current_j++];
				}
				current_j-=key_column_size;
				current_i++;
			}
			current_i-=key_column_size;
			return find_treasure(sub_matrix,key,map,key_row_size,key_column_size,output);	
		}
		else
		{	
			current_j+=key_column_size;
			for(i=0;i<key_row_size;i++)
			{
				for(j=0;j<key_column_size;j++)
				{
					sub_matrix[i][j]=map[current_i][current_j++];
				}
				current_j-=key_column_size;
				current_i++;
			}	
			current_i-=key_column_size;
			return find_treasure(sub_matrix,key,map,key_row_size,key_column_size,output);	
		}
	}
	else if(mod==4)
	{	
		int zero_counter=0;
		for(i=0;i<key_column_size;i++)
		{
			if(sub_matrix[i][0]==0)
			{
				zero_counter++;
			}
		}
		if(zero_counter==key_row_size)
		{
			current_j+=key_column_size;
			for(i=0;i<key_row_size;i++)
			{
				for(j=0;j<key_column_size;j++)
				{
				sub_matrix[i][j]=map[current_i][current_j++];
				}
				current_j-=key_column_size;
				current_i++;
			}
			current_i-=key_column_size;
			return find_treasure(sub_matrix,key,map,key_row_size,key_column_size,output);	
		}	
		else
		{
			current_j-=key_column_size;
			for(i=0;i<key_row_size;i++)
			{
				for(j=0;j<key_column_size;j++)
				{
				sub_matrix[i][j]=map[current_i][current_j++];
				}
				current_j-=key_column_size;
				current_i++;
			}
			current_i-=key_column_size;
			return find_treasure(sub_matrix,key,map,key_row_size,key_column_size,output);
		}	
	}
	
	return sub_matrix;
}

int main(int argc, char *argv[]){
	
	//WE DEFINED VARIABLES
	int map_row_size;
	int map_column_size;
	int key_row_size;
	int key_column_size;
	int i=0,j=0;
	int map_row_counter=0,map_column_counter,key_row_counter=0,key_column_counter;
	char map_store[MAX],key_store[MAX];
	char *map_str,*key_str,*token;
	int** map;
	int** key;
	int** sub_matrix;
	
	token = strtok(argv[1],"x");
	
	map_row_size = atoi(token);
	
	while(token != NULL)
	{
		map_column_size = atoi(token);
		
		token = strtok(NULL,"\n");
	}
	
	key_column_size = atoi(argv[2]);
	key_row_size = atoi(argv[2]);
	
	//WE OPENED GIVEN FILES
	FILE * map_file=fopen(argv[3],"r");				
	FILE * key_file=fopen(argv[4],"r");
	FILE * output=fopen(argv[5],"w");
	
	//WE CHECKED IF THE FILES EMPTY OR NOT
	if(map_file==NULL || key_file==NULL)
	{
		printf("Error opening file");
	}
	
	//WE ALLOCATED THE SPACE FOR MAP DYNAMICALLY
    
    map=(int**)malloc(map_row_size*sizeof(int*));
    
    for(i=0;i<map_row_size;i++){
        map[i]=(int*)malloc(map_column_size*sizeof(int));
     }
    
    //WE ALLOCATED THE SPACE FOR KEYMAP DYNAMICALLY
    
    key=(int**)malloc(key_row_size*sizeof(int*));
    
    for(i=0;i<key_row_size;i++){
        key[i]=(int*)malloc(key_column_size*sizeof(int));
    }
   	
   	//WE ALLOCATED THE SPACE FOR SUB-MATRIX DYNAMICALLY
    
    sub_matrix=(int**)malloc(key_row_size*sizeof(int*));
    
    for(i=0;i<key_row_size;i++){
        sub_matrix[i]=(int*)malloc(key_column_size*sizeof(int));
    }
   	
    //WE TOOK THE FIRST LINE OF MAP
	map_str = fgets(map_store,300,map_file);
	//WE FILLED THE MAP WITH VALUES WHICH ARE IN THE FILE	
	while(map_str!=NULL)
	{		
		for(i=0;i<map_column_size;i++)
		{
			map_column_counter=i;
			if(map_column_counter==0 )
			{
				map[map_row_counter][map_column_counter]= atoi((strtok(map_store," ")));
				
			}
			else if(map_column_counter==map_column_size-1)
			{
				map[map_row_counter][map_column_counter]= atoi((strtok(NULL,"\n")));
			}
			else
			{
				map[map_row_counter][map_column_counter]= atoi((strtok(NULL," ")));
			}
		}
		map_str = fgets(map_store,MAX,map_file); //we took the next line
		map_row_counter++;
	}
	
	//WE TOOK THE FIRST LINE OF KEYMAP
	key_str = fgets(key_store,300,key_file);
	//WE FILLED THE MAP WITH VALUES WHÝCH ARE IN THE FILE	
	while(key_str!=NULL)
	{		
		for(i=0;i<key_column_size;i++)
		{
			key_column_counter=i;
			if(key_column_counter==0 )
			{
				key[key_row_counter][key_column_counter]= atoi((strtok(key_store," ")));
				
			}
			else if(key_column_counter==key_column_size-1)
			{
				key[key_row_counter][key_column_counter]= atoi((strtok(NULL,"\n")));
		
			}
			else
			{
				key[key_row_counter][key_column_counter]= atoi((strtok(NULL," ")));
				
			}
		}
		key_str = fgets(key_store,MAX,key_file); // we took the next line
		key_row_counter++;
	}
	
	//WE TOOK THE FÝRST SUBMATRÝX OF MAP
		for(i=0;i<key_row_size;i++)
	{
        for(j=0;j<key_column_size;j++)
		{
            sub_matrix[i][j]=map[i][j];
        }
      
    }
    
    //CALLED THE FUNCTÝON THAT FÝND THE TREASURE
	sub_matrix=find_treasure(sub_matrix,key,map,key_row_size,key_column_size,output);
	
	fclose(map_file);
	fclose(key_file);
	
	free(map);
	free(key);
	free(sub_matrix);
	return 0;
}
