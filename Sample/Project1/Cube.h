#define CUBE_WIDTH 1024
#define CUBE_HEIGTH 1024
#define CUBE_DEPTH 1024

class Cube
{
public:
	Cube(int width, int heigth, int depth);
	~Cube();
public:
	void init(int width, int heigth, int depth);
protected:
private:
	char* _cells;
};