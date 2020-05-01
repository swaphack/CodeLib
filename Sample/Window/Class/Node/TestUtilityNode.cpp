#include "TestUtilityNode.h"

#include "system.h"

using namespace sys;

TestUtilityNode::TestUtilityNode()
{

}

TestUtilityNode::~TestUtilityNode()
{
	SAFE_DELETE(_concurFile);
	SAFE_DELETE(_httpDownload);
}

void TestUtilityNode::testFunc()
{

}

void TestUtilityNode::testString()
{
	Time* t = Time::getNow();
	PRINT("%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());

	const char* data = "{json; big; none}";

	String str = String(data);

	std::vector<String> dest;
	str.split("| ", dest);

	bool bContain = str.contains(";]");
	bContain = str.contains("}");
	bContain = str.contains("{j");
	bContain = str.contains("{ja");

	str.concat("hello");

	str.concat("hello", ", CN");

	str.concat("hello", ", CN", ", PNG");
}

void TestUtilityNode::testMatrix()
{
	float data2x2[4] = {
		1, 2,
		-1, -3
	};


	math::Matrix mat22(data2x2, 2, 2);
	PRINT("src:\n%s\n", mat22.toString().c_str());
	math::Matrix inverse22 = mat22.getInverse();
	PRINT("transpose:\n%s\n", inverse22.toString().c_str());
	math::Matrix mul22 = mat22 * inverse22;
	PRINT("mul:\n%s\n", mul22.toString().c_str());

	float data3x3[9] = {
		1, 2, 3,
		3, 2, 1,
		1, 4, 5
	};


	math::Matrix mat33(data3x3, 3, 3);
	PRINT("src:\n%s\n", mat33.toString().c_str());
	math::Matrix inverse33 = mat33.getInverse();
	PRINT("transpose:\n%s\n", inverse33.toString().c_str());

	math::Matrix mul33 = mat33 * inverse33;
	PRINT("mul:\n%s\n", mul33.toString().c_str());
}

void TestUtilityNode::testHttpDownload()
{
	std::string url = "http://pgcvideo.cdn.xiaodutv.com/3655477038_3129027130_20200415121806.mp4?Cache-Control%3Dmax-age%3A8640000%26responseExpires%3DFri%2C_24_Jul_2020_12%3A18%3A16_GMT=&xcode=829315dc4b5218e61407710580f6c8325009948d0a4a4c20&time=1587101501&_=1587017616119";

	std::string localFilePath = "temp.mp4";
	sys::Directory::createFile(localFilePath);

	if (_concurFile == nullptr)
	{
		_concurFile = new sys::ConcurrentFile(localFilePath);
	}

	if (_httpDownload == nullptr)
	{
		_httpDownload = new sys::HttpDownload();
	}

	_httpDownload->setDownloadingFunc([this](int32_t tag, const char* data, int32_t len){
		_concurFile->write(data, len);
	});
	_httpDownload->startTask(url, localFilePath, [this](int32_t tag, const std::string& content){
		_concurFile->finish();
		SAFE_DELETE(_concurFile);
	});
}


