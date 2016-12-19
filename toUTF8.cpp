#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>

using namespace std;

class CodeConverter
{
public:
    static int ToUTF8(wchar_t * inbuf, char * outbuf, int outlen)
    {
        char tmp[16] = {0}, t[256] = {""};
        int i = 0, len = 0;

        len = wcslen(inbuf);
        
        for (i = 0; i < len; i++)
        {
            bzero(tmp, sizeof(tmp));
            if (inbuf[i] >= 0 && inbuf[i] <= 127)
            {
                sprintf(tmp, "%c", inbuf[i]);
            }
            else
            {      
                sprintf(tmp, "\\&#x%X\\;", inbuf[i]);
            }
            strcat(outbuf, tmp);
            if (strlen(outbuf) >= outlen)
            {
               return -1;
            }
        }

	wprintf(L"%s\n", outbuf);
	sprintf(t, outbuf, len);
	wprintf(L"%s\n", t);
        system(t);
        system("sync");
	return 0;
    }	
};

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "zh_CN.UTF-8");
	wchar_t format_cn[16] = L"显示中文%d";
	char out[256] = {"./test "};

	CodeConverter::ToUTF8(format_cn, out, sizeof(out));

        return 0;
}
