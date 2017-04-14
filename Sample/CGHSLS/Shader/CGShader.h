#include <Cg/cg.h>

class CGShader
{
private:
	CGShader();
	~CGShader();
public:
	static CGShader* getInstance();
public:
	void init();
	void destory();
protected:
private:
	CGcontext mContext;

};