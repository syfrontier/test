/*#include <iconv.h>
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
	char *in_gb2312 = "显示中文";
	char out[256] = {0};

	CodeConverter cc = CodeConverter("gb2312", "utf-8");
	cc.convert(in_gb2313, sizeof(in_gb2312), out, 256);

	cout<<in_gb2312<<" "<<out<<endl;

	return 0;
}
*/

#include <wchar.h>     
#include <locale.h>     
#include <stdlib.h>     
#include <stdio.h>     
#include <string.h>

int main(void)      
{      
    setlocale(LC_ALL,"zh_CN.UTF-8");    
    wchar_t a[100] = L"你好%d000AAAaaa,,:";
    char t[64] = {0}, tmp[16] = {0};
    int i = 0, len;
    
    wprintf(L"this is a test !\n"); 
    len = wcslen(a);
    wprintf(L"%d\n",len);      
    //wprintf(L"%X\n",a);
    
    for (i = 0;i < len; i++) {
        bzero(tmp, sizeof(tmp));
	if (a[i] >= 0 && a[i] <= 127)
        {
          sprintf(tmp, "%c", a[i]);
        }else {
          sprintf(tmp, "\\\\&#x%X;", a[i]);
        }
        strcat(t, tmp);
    }
    
    wprintf(L"%s\n", t);
    
    return 0;  
}



