#include "macros.h"

#include "Device.h"

#include <cstdio>
#include <string>

int main(int argc, char** argv)
{
	cl_int status;
	cl_platform_id* platforms = get_platforms();
	if (platforms == NULL)
	{
		return -1;
	}

	cl_platform_id platform = platforms[0];

	cl_device_id* devices = get_device_id(platform);
	if (devices == NULL)
	{
		return -1;
	}
	cl_context context = clCreateContext(NULL, 1, devices, NULL, NULL, NULL);
	cl_command_queue commandQueue = clCreateCommandQueueWithProperties(context, devices[0], 0, NULL);


	const char* filename = "main.cl";
	const char* doorname = "main_func";
	size_t filesize = 0;
	const char* content = read_file(filename, filesize);
	if (content == NULL)
	{
		return -1;
	}

	cl_program program = clCreateProgramWithSource(context, 1, &content, &filesize, NULL);
	status = clBuildProgram(program, 1, devices, NULL, NULL, NULL);
	if (status != CL_SUCCESS)
	{
		char *buildLog;
		size_t buildLogSize;
		clGetProgramBuildInfo(program, *devices, CL_PROGRAM_BUILD_LOG, 0, NULL, &buildLogSize);
		buildLog = (char *)malloc(sizeof(char)*buildLogSize);
		clGetProgramBuildInfo(program, *devices, CL_PROGRAM_BUILD_LOG, buildLogSize, buildLog, NULL);
		printf(buildLog);
		free(buildLog);

		return -1;
	}

	int idx = 0;
	int count = strlen(argv[0]);
	std::string path = argv[0];

	cl_mem inputParam1 = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(int), &count, NULL);
	cl_mem inputParam2 = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, count * sizeof(char), (char*)path.c_str(), NULL);
	cl_mem outputParam1 = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int), NULL, NULL);

	cl_kernel kernel = clCreateKernel(program, doorname, NULL);
	status = clSetKernelArg(kernel, 0, sizeof(cl_mem), &inputParam1);
	status = clSetKernelArg(kernel, 1, sizeof(cl_mem), &inputParam2);
	status = clSetKernelArg(kernel, 2, sizeof(cl_mem), &outputParam1);

	cl_event eventPoint;
	size_t workSize = 1;

	status = clEnqueueNDRangeKernel(commandQueue, kernel, 1, NULL, &workSize, NULL, 0, NULL, &eventPoint);
	clWaitForEvents(1, &eventPoint);
	clReleaseEvent(eventPoint);

	int output = 0;
	status = clEnqueueReadBuffer(commandQueue, outputParam1, CL_TRUE, 0, sizeof(int), &output, 0, NULL, NULL);

	status = clReleaseKernel(kernel);
	status = clReleaseProgram(program);
	status = clReleaseMemObject(inputParam1);
	status = clReleaseMemObject(inputParam2);
	status = clReleaseMemObject(outputParam1);
	status = clReleaseCommandQueue(commandQueue);
	status = clReleaseContext(context);

	free((char*)content);

	free(devices);

	return 0;
}