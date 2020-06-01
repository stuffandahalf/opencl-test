#define CL_TARGET_OPENCL_VERSION	120

#include <stdio.h>
#ifdef __APPLE__
#include <opencl/OpenCL.h>
#else
#include <CL/cl.h>
#endif

#define MAX_STR_SIZE		256
#define MAX_PLATFORMS		5

int main(int argc, char *argv[])
{
	cl_int ret;
	
	cl_uint num_platforms;
	cl_platform_id platform_ids[MAX_PLATFORMS];
	ret = clGetPlatformIDs(MAX_PLATFORMS, platform_ids, &num_platforms);
	for (cl_uint i = 0; i < num_platforms; i++) {
		char str[MAX_STR_SIZE];
		
		clGetPlatformInfo(platform_ids[i], CL_PLATFORM_NAME, MAX_STR_SIZE,
			str, NULL);
		printf("%s\t", str);

		clGetPlatformInfo(platform_ids[i], CL_PLATFORM_VENDOR, MAX_STR_SIZE,
			str, NULL);
		printf("%s\t", str);

		clGetPlatformInfo(platform_ids[i], CL_PLATFORM_VERSION,
			MAX_STR_SIZE, str, NULL);
		printf("%s\n", str);
	}

	return 0;
}

