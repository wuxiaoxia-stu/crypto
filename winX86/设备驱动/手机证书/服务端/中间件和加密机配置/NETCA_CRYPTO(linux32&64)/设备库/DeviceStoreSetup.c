#include <stdio.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF_LEN 256

int main()
{
	FILE *fp = NULL;
	const char deviceStore[MAX_BUF_LEN] = {"DeviceStore"};
	const char deviceStore64[MAX_BUF_LEN] = {"DeviceStore64"};
	const char deviceStorePath[MAX_BUF_LEN] = {0};
	const char deviceStore64Path[MAX_BUF_LEN] = {0};
	sprintf(deviceStorePath, "/etc/.NETCA/%s", deviceStore);
	sprintf(deviceStore64Path, "/etc/.NETCA/%s", deviceStore64);
	
	fp = fopen(deviceStorePath, "w");
	if(fp == NULL)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		return ;
	}
	fputs("[SoftwareDevice]\n", fp);
	fputs("class=Software\n", fp);
	fputs("sopath=/usr/local/lib/libnetcasoftkeyprov.so\n", fp);
	fputs("type=52\n", fp);
	fputs("signature=mFc8XrlBHN6RBYfbYuO+h1kh7TtB+VC43oj9Yz/9DznIb2hs+1fMzyLKp0oKwV6Q+7GLsfhSiWRyDWFlFIt8lZFX1nUGnkF6/BY9CZy4sNP/2o2KUto/yUpgn37jR8JvGgQXocd+kRzDKDMKXrBmB1C/ZXW0UKWMNSQWioo5Rtk=\n", fp);
	fputs("ImportOnlyEncKeypair=0\n", fp);
	fclose(fp);
	
	fp = fopen(deviceStore64Path, "w");
	if(fp == NULL)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		return ;
	}
	fputs("[SoftwareDevice]\n", fp);
	fputs("class=Software\n", fp);
	fputs("sopath=/usr/local/lib64/libnetcasoftkeyprov.so\n", fp);
	fputs("type=52\n", fp);
	fputs("signature=pCYJEcq6P+Rfen3DrIwigDZCE2joTwiFPc0L3lwH2qYPx0RcG+CuO9z3C9ZjmuXxXYDQ6cpReUfUxjHAiIGOR/TmvOZfqLWzWQdp3umaHdQWZGoa0H7P3WNGJF2iZLLdNKA1y7gSAsv+C+8wfE7wKc1TlCzPlSXp/kEjSAMwKbI=\n", fp);
	fputs("ImportOnlyEncKeypair=0\n", fp);
	fclose(fp);
	
	return 1;
}
