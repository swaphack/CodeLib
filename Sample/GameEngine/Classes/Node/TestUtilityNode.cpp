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

void TestUtilityNode::initNodes()
{

}

void TestUtilityNode::testString()
{
	DateTime* t = DateTime::getNow();
	PRINT("%d-%d-%d %02d:%02d:%02d\n", t->getYear(), t->getMonth(), t->getMonthDay(), t->getHour(), t->getMinute(), t->getSecond());

	const std::string& data = "{json; big; none}";

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


