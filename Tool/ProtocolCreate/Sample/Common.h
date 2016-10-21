#pragma once


#define PROTOCOL_NAME "Name"
#define PROTOCOL_PROTOCOLID "ProtocolID"
#define PROTOCOL_DESCRIBE "Describe"

#define PARAM_NAME "Name"
#define PARAM_TYPE "Type"
#define PARAM_LENGTH "Length"
#define PARAM_DESCRIBE "Describe"


#define PARAM_PROTOCOLID "ProtocolID"

#define RETURE_IF(condition, format, ...) \
	{ if (condition) { printf(format, __VA_ARGS__); return; }}

#define RETURE_FALSE_IF(condition, format, ...) \
	{ if (condition) { printf(format, __VA_ARGS__); return false; }}