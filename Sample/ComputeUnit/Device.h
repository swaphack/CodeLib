#pragma once

#include "macros.h"

cl_platform_id* get_platforms();

cl_device_id* get_device_id(cl_platform_id& platform);

char* read_file(const char* filepath, size_t& size);
