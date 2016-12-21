#include "Device.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

cl_platform_id* get_platforms()
{
	cl_uint platformNum;
	cl_int status = clGetPlatformIDs(0, NULL, &platformNum);
	if (status != CL_SUCCESS || platformNum <= 0)
	{
		return NULL;
	}

	cl_platform_id* platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id));
	status = clGetPlatformIDs(platformNum, platforms, NULL);
	if (status != CL_SUCCESS)
	{
		free(platforms);
		return NULL;
	}
	return platforms;
}

cl_device_id* get_device_id(cl_platform_id& platform)
{
	cl_uint deviceNum = 0;
	cl_device_id* devices = NULL;
	cl_int status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 0, NULL, &deviceNum);
	if (status != CL_SUCCESS || deviceNum <=0 )
	{
		return NULL;
	}
	
	devices = (cl_device_id*)malloc(sizeof(cl_device_id));
	status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, deviceNum, devices, NULL);
	if (status != CL_SUCCESS)
	{
		free(devices);
		return NULL;
	}
	return devices;
}

char* read_file(const char* filepath, size_t& size)
{
	if (filepath == NULL)
	{
		return NULL;
	}

	FILE* fptr = nullptr;
	fptr = fopen(filepath, "rb+");
	if (fptr == nullptr)
	{
		return nullptr;
	}

	fseek(fptr, 0, SEEK_SET);
	fseek(fptr, 0, SEEK_END);
	size = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);

	char* str = (char*)malloc(size * sizeof(char));

	fread(str, sizeof(char), size, fptr);

	fclose(fptr);

	return str;
}
