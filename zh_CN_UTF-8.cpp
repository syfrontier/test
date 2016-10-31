#include <iconv.h>
#include <string.h>

#include <iostream>

using namespace std;

class CodeConverter
{
	private:
		iconv_t cd;
	public:
		CodeConverter(const char * src_charset, const char * dest_charset) {
			cd = iconv_open(des_charset, src_charset);
		}

		~CodeConverter(){
			iconv_close(cd);
		}

		int convert(char * inbuf, int inlen, char * outbuf, int outlen) {
			char **pin = &inbuf;
			char **pout = &outbuf;

			bzero(pout, outlen);
			return iconv(cd, pin, (size_t *)&inlen, pout, (size_t *)&outlen);
		}	
};



int main(int argc, char *argv[])
{
	char *in_gb2312 = "œ‘ æ÷–Œƒ";
	char out[256] = {0};

	CodeConverter cc = CodeConverter("gb2312", "utf-8");
	cc.convert(in_gb2313, sizeof(in_gb2312), out, 256);

	cout<<in_gb2312<<" "<<out<<endl;

	return 0;
}


