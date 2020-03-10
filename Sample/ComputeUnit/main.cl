

__kernel void main_func(__global int* argc, __global char* argv, __global int* out)
{ 
	int i = get_global_id(0);
	printf("argc %d\n", *argc);
	for (i = 0 ; i < *argc; i++)
	{ 
		printf("argv %c\n", argv[i]);
	}	   
	*out = -1;
}