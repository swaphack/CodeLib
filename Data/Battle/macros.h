#pragma once

#define ADD_PROPERTY(name, key) \
	void Set##name(float value) { getProperty()->SetValue((int)key, value); } \
	float Get##name() { return getProperty()->GetValue((int)key); } \

